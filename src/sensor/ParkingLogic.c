// ~~~~~~~~~~~~~~~ Arduino pins declarations ~~~~~~~~~~~~~~~~~~~~~~~~
const int entryPhotoResistorPin = A1;
const int exitPhotoResistorPin = A2;
const int entryLaserPin = 7;
const int exitLaserPint = 8;

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

setup(){
  pinMode(entryLaserPin, OUTPUT);
  pinMode(exitLaserPin, OUTPUT);
  Serial.begin(9600);
}

loop(){
  entryLightLevel = analogRead(entryPhotoResistorPin);
  exitLightLevel = analogRead(exitPhotoResistorPin);

  int entryTriggered = entryLightLevel < 100 ? 1 : 0;
  int exitTriggered = exitLightLevel < 100 ? 1 : 0;

  if(entryTriggered && !exitTriggered && !isExiting){
    isEntering = 1;
    activatedFirstAndSecondSensor = 0;
  }
  else if(!entryTriggered && exitTriggered && !isEntering){
    isExiting = 1;
    activatedFirstAndSecondSensor = 0;
  }

  else if(isEntering){
    else if(entryTriggered && exitTriggered){
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
      Serial.print("Quedan " + availablePlaces + " lugares\n");
    }else{
      isEntering = 0;
    }
  }
  else if(isExiting){
    if(entryTriggered && exitTriggered){
      activatedFirstAndSecondSensor = 1;
      activatedFirstSensor = 0;
    }
    else if(exitTriggered){
      activatedFirstSensor = 1;
    }
    else if(activatedFirstSensor && activatedFirstAndSecondSensor){
      availablePlaces += 1;
      isExiting = 0;
      Serial.print("Un auto salió!!\n");
      Serial.print("Quedan " + availablePlaces + " lugares\n");
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
