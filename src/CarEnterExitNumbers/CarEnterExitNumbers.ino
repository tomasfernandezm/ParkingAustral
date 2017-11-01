// ~~~~~~~~~~~~~~~ Arduino pins declarations ~~~~~~~~~~~~~~~~~~~~~~~~
const int entryPhotoResistorPin = A1;
const int exitPhotoResistorPin = A2;
const int entryLaserPin = 3;
const int exitLaserPin = 4;

const int entrySignal = 5;
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

// ~~~~~~~~~~~~~~~ Counter pins & variable declarations ~~~~~~~~~~~~~~~~~~~~~~~~
int tensLedPins[] = {10,11, 12, 13};
int onesLedPins [] = {6, 7, 8, 9};
int bitAmount = 4;
int tens = 2;
int ones = 0;


void setup(){
  pinMode(entryLaserPin, OUTPUT);
  pinMode(exitLaserPin, OUTPUT);
  pinMode(entrySignal, OUTPUT);
  pinMode(exitSignal, OUTPUT);

  digitalWrite(entryLaserPin, HIGH);
  digitalWrite(exitLaserPin, HIGH);
  digitalWrite(entrySignal, LOW);
  digitalWrite(exitSignal, LOW);

  for(int i = 0;i < bitAmount; i++){
        pinMode(tensLedPins[i], OUTPUT);
        pinMode(onesLedPins[i], OUTPUT);
   }

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
      Serial.print("Un auto entro!!\n");
      Serial.print(availablePlaces);

      digitalWrite(entrySignal, HIGH);
      delay(50);
      digitalWrite(entrySignal, LOW);
      

      if(ones == 0){
          ones = 9;
          tens--;
      }else{
          ones--;
      }

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
      Serial.print("Un auto salio!!\n");
      Serial.print(availablePlaces);

      digitalWrite(exitSignal, HIGH);
      delay(50);
      digitalWrite(exitSignal, LOW);
      

      if(ones == 9){
          ones = 0;
          tens++;
      }else{
          ones++;
      }

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

  showBinaryNumber(ones, onesLedPins);
  showBinaryNumber(tens, tensLedPins);
}

void showBinaryNumber(int num, int ledPins[]) {
    for (int i=0; i < bitAmount; i++) {
      if (num%2)
        digitalWrite(ledPins[i], HIGH);
      else
        digitalWrite(ledPins[i], LOW);
      num/=2;
    }
}
