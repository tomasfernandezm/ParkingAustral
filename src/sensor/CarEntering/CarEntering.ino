// ~~~~~~~~~~~~~~~ Arduino pins declarations ~~~~~~~~~~~~~~~~~~~~~~~~
const int entryPhotoResistorPin = A1;
const int exitPhotoResistorPin = A2;
const int entryLaserPin = 7;
const int exitLaserPin = 8;

// ~~~~~~~~~~~~~~~ System variable declarations ~~~~~~~~~~~~~~~~~~~~~~~~

int entryLightLevel = 0;
int exitLightLevel = 0;
int availablePlaces = 20;
int isEntering = 0;
int operated = 0;
int activatedFirstAndSecondSensor = 0;
int activatedSecondSensor = 0;
int carEntered = 0;

void setup(){
  pinMode(entryLaserPin, OUTPUT);
  pinMode(exitLaserPin, OUTPUT);
  digitalWrite(entryLaserPin, LOW);
  digitalWrite(exitLaserPin, HIGH);
  Serial.begin(9600);
}

void loop(){
  entryLightLevel = analogRead(entryPhotoResistorPin);
  exitLightLevel = analogRead(exitPhotoResistorPin);

  int entryTriggered = entryLightLevel > 100 ? 1 : 0;
  int exitTriggered = exitLightLevel > 100 ? 1 : 0;

  if(entryTriggered && !exitTriggered){
    isEntering = 1;
    activatedFirstAndSecondSensor = 0;
    // Serial.print("A");
  }
  else if(entryTriggered && exitTriggered){
    activatedFirstAndSecondSensor = 1;
    activatedSecondSensor = 0;
    // Serial.print("B");
  }
  else if(exitTriggered && isEntering){
    activatedSecondSensor = 1;
    // Serial.print("C");
  }
  else if(isEntering && activatedSecondSensor && activatedFirstAndSecondSensor){
    availablePlaces -= 1;
    isEntering = 0;
    Serial.print("Un auto entró!!\n");
    Serial.print(availablePlaces);
    // Serial.print("D");
  }else{
    isEntering = 0;
    activatedSecondSensor = 0;
    activatedFirstAndSecondSensor = 0;
    // Serial.print("E");
  }
}

