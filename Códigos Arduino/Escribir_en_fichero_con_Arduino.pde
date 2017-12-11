import processing.serial.*;
PrintWriter output;
Serial mySerial;
String val;
String anterior="Entrar";
void setup()
{
   println(Serial.list()[0]);
   mySerial = new Serial( this, Serial.list()[0], 9600 );
}
void draw() {
  if (mySerial.available()> 0) {
    String value = mySerial.readStringUntil('\n');
  if (value != null) {
      println("Valor de anterior: "+anterior);
      println("Valor de value: "+value);
      if(value=="Terminar") exit();
      if(anterior!=value)
      {
      output = createWriter( "C:/Users/Isaac/Desktop/var.js" );
      value = "var gameBoard = ["+value+"];";
      output.println(value);
      anterior=value;
      output.flush();
      output.close();
      }
    }
  }
}