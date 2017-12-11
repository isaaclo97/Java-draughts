#include <Wire.h>
 
const int pcfAddress  = 0x24;
const int pcfAddress1 = 0x39;
const int pcfAddress2 = 0x20;
const int pcfAddress3 = 0x20;
void setup()
{
   Wire.begin();
   Serial.begin(9600);
}
 
void loop()
{
   //Cuando se pulse el boton que imprima
   Serial.println(reverse(leerFila(pcfAddress)));
   Serial.println(reverse(leerFila(pcfAddress1)));
   Serial.println("------------------");
   delay(1000);
   //Serial.println(leerFila(pcfAddress2));
   //Serial.println(leerFila(pcfAddress3));
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
      sol='\n'+sol+'0';
    }
    else
    {
      sol=aux[i]+sol;
      sol='0'+sol;
    }
  }
  return sol;
}
