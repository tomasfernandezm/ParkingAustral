// ~~~~~~~~~~~~~~~ Arduino pins declarations ~~~~~~~~~~~~~~~~~~~~~~~~
const int entryPhotoResistorPin = A1;
const int exitPhotoResistorPin = A2;
const int entryLaserPin = 3;
const int exitLaserPin = 4;

const int entrySignal = 1;
const int exitSignal = 2;

// ~~~~~~~~~~~~~~~ System variable declarations ~~~~~~~~~~~~~~~~~~~~~~~~

int entryLightLevel = 0;
int exitLightLevel = 0;
int availablePlaces = 20;
int isEntering = 0;
int isExiting = 0;
int carInSystem = 0;
int activatedFirstSensor = 0;
int activatedFirstAndSecondSensor = 0;
int activatedSecondSensor = 0;
int carEntered = 0;

void setup(){
  pinMode(entryLaserPin, OUTPUT);
  pinMode(exitLaserPin, OUTPUT);
  pinMode(entrySignal, OUTPUT);
  pinMode(exitSignal, OUTPUT);
  digitalWrite(entrySignal, LOW);
  digitalWrite(entryLaserPin, HIGH);
  digitalWrite(exitLaserPin, HIGH);
  Serial.begin(9600);
}

void loop(){
  entryLightLevel = analogRead(entryPhotoResistorPin);
  exitLightLevel = analogRead(exitPhotoResistorPin);

  int entryTriggered = entryLightLevel > 100 ? 1 : 0;
  int exitTriggered = exitLightLevel > 100 ? 1 : 0;

  if(entryTriggered && !exitTriggered && !isExiting){
    isEntering = 1;
    activatedFirstAndSecondSensor = 0;
  }
  else if(!entryTriggered && exitTriggered && !isEntering){
    isExiting = 1;
    activatedFirstAndSecondSensor = 0;
  }

  else if(isEntering){
    if(entryTriggered && exitTriggered){
      activatedFirstAndSecondSensor = 1;
      activatedSecondSensor = 0;
    }
    else if(exitTriggered){
      activatedSecondSensor = 1;
    }
    else if(activatedSecondSensor && activatedFirstAndSecondSensor){
      availablePlaces -= 1;
      isEntering = 0;
      Serial.print("Un auto entró!!\n");
      Serial.print(availablePlaces);
      digitalWrite(entrySignal, HIGH);
      digitalWrite(entrySignal, LOW);
    }else{
      isEntering = 0;
    }
  }
  else if(isExiting){
    if(entryTriggered && exitTriggered){
      activatedFirstAndSecondSensor = 1;
      activatedFirstSensor = 0;
    }
    else if(entryTriggered){
      activatedFirstSensor = 1;
    }
    else if(activatedFirstSensor && activatedFirstAndSecondSensor){
      availablePlaces += 1;
      isExiting = 0;
      Serial.print("Un auto salió!!\n");
      Serial.print(availablePlaces);
    }else{
      isExiting = 0;
    }
  }
  else{
    isEntering = 0;
    isExiting = 0;
    activatedFirstSensor = 0;
    activatedSecondSensor = 0;
    activatedFirstAndSecondSensor = 0;
  }
}

