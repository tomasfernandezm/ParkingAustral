
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
int carIsEntering = 0;
int carIsExiting = 0;
int carInSystem = 0;

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void setup(){
    pinMode(entryLaserPin, OUTPUT);
    pinMode(exitLaserPin, OUTPUT);
}

void loop(){
    entryLightLevel = analogRead(entryPhotoResistorPin);
    exitLightLevel = analogRead(exitPhotoResistorPin);

    /*
        A car is entering and has activated the entrySensor
    */
    if(entryLightLevel < 100 && carIsEntering == 0 && exitLightLevel > 100){
        carIsEntering = 1;
        carInSystem = 1;
    }
    /*
        A car is entering, has already passed the entrySensor and has activated the exitSensor 
    */
    else if(entryLightLevel > 100 && carIsEntering == 1 && exitLightLevel < 100){
        carIsEntering = 0;
        availablePlaces--;
    }
    /*
        A car is exiting
    */
    else if(entryLightLevel > 100 && carIsExiting == 0 && exitLightLevel < 100){
        carIsExiting = 1;
        carInSystem = 1;
    }
    /*
        A car is exiting, has already passed the entrySensor and has activated the exitSensor
    */
    else if(entryLightLevel < 100 && carIsExiting == 1 && exitLightLevel > 100){
        carIsExiting = 0;
        availablePlaces--;
    }

    delay(500);
}