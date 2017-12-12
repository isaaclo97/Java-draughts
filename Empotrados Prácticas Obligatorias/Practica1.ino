int botonValue = 0; // value read from the pot
int outputValue = 0; // value output to the PWM (analog out)
int led1= 9;
int led2= 10;
int led3= 11;
int led4= 12;
int contador=0;
int encendido=0;
int matriz[16][4] =
  {   { 0,0,0,0 },    // 0
     { 0,0,0,1 },    // 1
     { 0,0,1,0 },    // 2
     { 0,0,1,1 },    // 3
     { 0,1,0,0 },    // 4
     { 0,1,0,1 },    // 5
     { 0,1,1,0 },    // 6
     { 0,1,1,1 },    // 7
     { 1,0,0,0 },    // 8
     { 1,0,0,1 },    // 9
     { 1,0,1,0 },    // 10
     { 1,0,1,1 },    // 11
     { 1,1,0,0 },    // 12
     { 1,1,0,1 },    // 13
     { 1,1,1,0 },    // 14
     { 1,1,1,1 }};
void setup() {
// initialize serial communications at 9600 bps:
Serial.begin(9600);
pinMode(led1,OUTPUT);
pinMode(led2,OUTPUT);
pinMode(led3,OUTPUT);
pinMode(led4,OUTPUT);
pinMode(8,INPUT);
}
void loop() {
// read the analog in value:
botonValue = digitalRead(8);
Serial.print("Valor Boton = " );
Serial.print(botonValue);
Serial.print("\n" );
Serial.print("Valor Contador = " );
Serial.print(contador);
Serial.print("\n" );
if(botonValue==HIGH){
  if(encendido==0){
    contador++;
    if(contador==16){
      contador=0;
    }
    encendido=1;
    digitalWrite(led1,matriz[contador][0]);
    digitalWrite(led2,matriz[contador][1]);
    digitalWrite(led3,matriz[contador][2]);
    digitalWrite(led4,matriz[contador][3]);
  }
  else{
    digitalWrite(led1,matriz[contador][0]);
    digitalWrite(led2,matriz[contador][1]);
    digitalWrite(led3,matriz[contador][2]);
    digitalWrite(led4,matriz[contador][3]);
  }
}
else{
    encendido=0;
    digitalWrite(led1,matriz[contador][0]);
    digitalWrite(led2,matriz[contador][1]);
    digitalWrite(led3,matriz[contador][2]);
    digitalWrite(led4,matriz[contador][3]);
}
delay(10);
}
