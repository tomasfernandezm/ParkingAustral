// ~~~~~~~~~~~~~~~ Arduino pins declarations ~~~~~~~~~~~~~~~~~~~~~~~~
const int entryPhotoResistorPin = A1;
const int exitPhotoResistorPin = A2;
const int entryLaserPin = 7;
const int exitLaserPin = 8;

// ~~~~~~~~~~~~~~~ System variable declarations ~~~~~~~~~~~~~~~~~~~~~~~~

int entryLightLevel = 0;
int exitLightLevel = 0;
int availablePlaces = 20;
int isExiting = 0;
int operated = 0;
int activatedFirstAndSecondSensor = 0;
int activatedFirstSensor = 0;
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

  if(!entryTriggered && exitTriggered){
    isExiting = 1;
    activatedFirstAndSecondSensor = 0;
    Serial.print("A");
  }
  else if(entryTriggered && exitTriggered){
    activatedFirstAndSecondSensor = 1;
    activatedFirstSensor = 0;
    Serial.print("B");
  }
  else if(entryTriggered && isExiting){
    activatedFirstSensor = 1;
    Serial.print("C");
  }
  else if(isExiting && activatedFirstSensor && activatedFirstAndSecondSensor){
    availablePlaces += 1;
    isExiting = 0;
    Serial.print("Un auto salió!!\n");
    Serial.print(availablePlaces);
  }else{
    isExiting = 0;
    activatedFirstSensor = 0;
    activatedFirstAndSecondSensor = 0;
  }
}

