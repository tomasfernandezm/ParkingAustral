
const int laserPin = 9;
const int sensorPin = 0;
const int ledPin = 3;

const int lightLevel = 0;

void setup{
    pinMode(laserPin, OUTPUT);
    pinMode(ledPin, OUTPUT);
    Serial.begin(9600);
}

void loop(){

    lightLevel = analogRead(sensorPin);

    if(laserLight > 100){
        laserLight = map(laserLight, 0, 1023, 0, 255);
        analogWrite(ledPin, lightLevel);
    }else{
        analogWrite(ledPin, 0);
    }
    delay(500);
}