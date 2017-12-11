#include <Wire.h>
 
const int pcfAddress  = 0x24;
const int pcfAddress1 = 0x39;
const int pcfAddress2 = 0x20;
const int pcfAddress3 = 0x26;
void setup()
{
   Wire.begin();
   Serial.begin(9600);
}
 
void loop()
{
   //Cuando se pulse el boton que imprima
   Serial.println(reverse(leerFila(pcfAddress1))); 
   Serial.println(reverse(leerFila(pcfAddress3)));
   Serial.println(reverse(leerFila(pcfAddress2)));
   Serial.println(reverse(leerFila(pcfAddress)));
   Serial.println("------------------");
   delay(3000);
}

String leerFila(int x)
{
   short channel = 1;
   byte value = 0;
 
   // Leer dato de canal 'channel'
   Wire.requestFrom(x, 1 << channel);
   if (Wire.available())
   {
      value = Wire.read();
   }
   Wire.endTransmission();
   char a[8];
   String res;
   itoa(value,a,2);
   res=a;
   for(int i=res.length(); i<8;i++)
   {
    res='0'+res;
   }
   return res;
}
String reverse(String aux)
{
  String sol;
  for(int i=0; i<8;i++)
  {
    if(i==3)
    {
      sol=aux[i]+sol;
      sol="\n0"+sol;
    }
    else
    {
      if(i!=0)
      sol='0'+sol;
      sol=aux[i]+sol;
      if(i==2)
      sol='0'+sol;
    }
  }
  return sol;
}
