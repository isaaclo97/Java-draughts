 int turno = 1;
    int state = 0;
    int encendido = 0;
    const int pinBoton = 2;

    void setup() {
        pinMode(pinBoton, INPUT);
        Serial.begin(9600);
    }

    void loop() {
        state = digitalRead(pinBoton);
        if (state == HIGH) {
            if (encendido == 0) {
                if (turno == 1) {
                    turno++;
                } else {
                    turno = 1;
                }
                Serial.println(turno);
                encendido = 1;
            }
        } else {
            encendido = 0;
        }
    }
