
/*
    Prototype of the sensor system. Some issues are:
        - see if car is in the system. Don't operate until the car has left the system.
        - possible Karnaugh implementation.
*/

// ~~~~~~~~~~~~~~~ Arduino pins declarations ~~~~~~~~~~~~~~~~~~~~~~~~
const int entryPhotoResistorPin = A1;
const int exitPhotoResistorPin = A1;
const int entryLaserPin = 7;
const int exitLaserPint = 8;

// ~~~~~~~~~~~~~~~ System variable declarations ~~~~~~~~~~~~~~~~~~~~~~~~

int entryLightLevel = 0;
int exitLightLevel = 0;
int availablePlaces = 20;
int isEntering = 0;
int isExiting = 0;
int hasOperated = 0;
int isCar = 0;
double delta = 0;
double timeMin = 20;

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void setup(){
    pinMode(entryLaserPin, OUTPUT);
    pinMode(exitLaserPin, OUTPUT);
}

void loop(){
    entryLightLevel = analogRead(entryPhotoResistorPin);
    exitLightLevel = analogRead(exitPhotoResistorPin);

    int entryTriggered = entryLightLevel < 100 ? 1 : 0;
    int exitTriggered = exitLightLevel < 100 ? 1 : 0;


    if(entryTriggered && !exitTriggered && !isExiting)){
        isEntering = 1;
    }else if(entryTriggered && exitTriggered){
        if(!delta) /* START DELTA */
        else if(delta < 20) isCar = 0;
        else isCar = 1;
    }
    else if(!entryTriggered && exitTriggered && isEntering && !hasOperated && isCar){
        isEntering = 0;
        hasOperated = 1;
        availablePlaces--;
    }else if(entryTriggered && !exitTriggered && !isEntering){
        isExiting = 1;
    }else if(entryTriggered && !exitTriggered && isExiting && !hasOperated && isCar){
        isExiting = 0;
        availablePlaces++;
        hasOperated = 1;
    }else if(!entryTriggered && !exitTriggered){
        hasOperated = 0;
        isCar = 0;
    }
    
    delay(500);
}