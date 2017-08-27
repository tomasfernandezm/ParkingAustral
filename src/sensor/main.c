
#define FALSE 0
#define TRUE 1
#define DELTA 0.3
#define MAXPLACES 20

boolean entrySensor;
boolean exitSensor;
boolean carIsEntering;
boolean carIsExiting;
boolean timerStarted = FALSE;
int count = 0;
long initCounter = 0;
boolean wasCounted = 0;

setup(){

}

loop(){

    /*
        Se detecta que el sensor de entrada está activado y no había ningun auto o saliendo o entrando. Por ende, hay un auto entrando.
        Se activa el flag de autoEntrando y se arranca el delta t.
    */
    if(entrySensor && !carIsEntering && !carIsExiting){
        carIsEntering = TRUE;
        initCounter = millis(); // se arranca el delta t
    }

    /*
        Se detecta que el sensor de salida está activado y no había ningun auto o saliendo o entrando. Por ende, hay un auto saliendo.
        Se activa el flag de autoSaliento y se arranca el delta t.
    */
    if(exitSensor && !carIsEntering && !carIsExiting){
        carIsExiting = TRUE;
        initCounter = millis();
    }
}