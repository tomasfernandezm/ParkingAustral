
const int pin = 9;

void setup() {
    pinMode(pin, OUTPUT);  //definir pin como salida
}

void loop(){
    digitalWrite(pin, HIGH);   // poner el Pin en HIGH -> prende el laser
    delay(500);               // esperar 5 segundos
    digitalWrite(pin, LOW);    // poner el Pin en LOW -> apaga el 
    delay(500);               // esperar 20 segundos
}