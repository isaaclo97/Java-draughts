#include <Wire.h>
 
const int pcfAddress = 0x20;
 
void setup()
{
   Wire.begin();
   Serial.begin(9600);
}
 
void loop()
{
   short channel = 1;
   byte value = 0;
 
   // Leer dato de canal 'channel'
   Wire.requestFrom(pcfAddress, 1 << channel);
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
   Serial.println(res);
}
