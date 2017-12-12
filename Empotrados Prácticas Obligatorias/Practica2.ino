int value=0;
int output=0;
void setup() {
  // put your setup code here, to run once:
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(A0,INPUT);
  Serial.begin(9600);
}

void loop() {
  value=analogRead(A0);
  output=map(value,0,800,0,255);
  Serial.println(value);
  analogWrite(9,output);
  analogWrite(11,255-output);
  if(output>125){
    analogWrite(10,125+(255-output));
  }else{
    analogWrite(10,125+(125-output));
  }

}
