#include <Wire.h>
 
const int pcfAddress  = 0x24;
const int pcfAddress1 = 0x39;
const int pcfAddress2 = 0x20;
const int pcfAddress3 = 0x26;
String inicial = "[2,0,2,0,2,0,2,0],\n[0,2,0,2,0,2,0,2],\n[0,0,0,0,0,0,0,0],\n[0,0,0,0,0,0,0,0],\n[0,0,0,0,0,0,0,0],\n[0,0,0,0,0,0,0,0],\n[1,0,1,0,1,0,1,0],\n[0,1,0,1,0,1,0,1] ";
String actual[] = {"22222222","00000000","00000000","11111111"};
int turno=1;
int inicio=1;
int color;
int encendido=0;
const int pinBoton=2;
int state=0;
void setup()
{
   pinMode(pinBoton,INPUT);
   Wire.begin();
   Serial.begin(9600);
}
 
void loop()
{
   //Cuando se pulse el boton que imprima
   if(inicio==1)
   {
   Serial.println(inicial);
   inicio++;
   }
   else{
   state = digitalRead(pinBoton);
        if (state == HIGH) {
            if (encendido == 0) {
                if (turno == 1) {
                    turno++;
                } 
                else {
                    turno = 1;
                }
                //Serial.println(turno);
                encendido = 1;
                String movimiento;
   movimiento= corchetes(comas(reverse(mover(cambiar(leerFila(pcfAddress1)),turno,0))),1); 
   movimiento+="\n";
   movimiento+=corchetes(comas(reverse(mover(cambiar(leerFila(pcfAddress3)),turno,1))),1);
   movimiento+="\n";
   movimiento+=corchetes(comas(reverse(mover(cambiar(leerFila(pcfAddress2)),turno,2))),1);
   movimiento+="\n";
   movimiento+=corchetes(comas(reverse(mover(cambiar(leerFila(pcfAddress )),turno,3))),5);
   movimiento+=' ';
   Serial.println(movimiento);
   //Serial.println("------------------");
            }
        } else {
            encendido = 0;
        }
   delay(10);
   }
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
      sol="\n0"+sol; //sol="\n0"+sol;
    }
    else
    {
      if(i!=0)
      sol="0"+sol;
      sol=aux[i]+sol;
      if(i==2)
      sol="0"+sol;
      
    }
  }
  //Faltan poner comas y corchetes adecuadamente para que el processing lo lea correctamente
  return sol;
}
  String comas(String aux)
  {
    String sol;
    for(int i=0; i<=16;i++)
    {
      if(i==0)
      sol=aux[i];
      else if(i==8||i==9)
      sol+=aux[i];
      else
      sol=sol+","+aux[i];
    }
    return sol;
  }
    String corchetes(String aux,int ultimo)
  {
    String sol="[";
    for(int i=0; i<aux.length();i++)
    {
      if(i==15)
      sol+="],";
      if(i==16)
      sol+="[";
      sol+=aux[i];
     // Serial.println(sol);
    }
    if(ultimo!=1)
    sol+="]";
    else
    sol+="],";
    return sol;
  }
  String cambiar(String aux)
  {
    String sol;
    for(int i=0; i<aux.length();i++)
    {
      if(aux[i]=='1')
      sol+='0';
      else
      sol+='1';
    }
    return sol;
  }
  String mover(String aux,int turno,int comprobar)
  {
    String sol = actual[comprobar];
    //Serial.println(turno);
    //Serial.println(sol);
    //Serial.println(aux);
    for(int i=0; i<aux.length();i++)
    {
      if(aux[i]==49&&sol[i]==48)
      sol[i]=turno+'0';
      else if(aux[i]==48&&sol[i]!=48)
      sol[i]='0';
    }
    //Serial.println(sol);
    actual[comprobar]=sol;
    //Serial.println(sol);*/
    return sol;
  }
