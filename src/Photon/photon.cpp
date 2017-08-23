#define led D7

int int_value; 


int i;
int led_state = 0;

void setup() {
    
    pinMode(led,OUTPUT);

    Particle.variable("int_val", &int_value, INT);

    Particle.function("int_fun",int_function);


    i = 0;
}


void loop() {

    int_value = i;
    
    i = i + 1;

    delay(10000);
    
}


int int_function(String command) {

    if (command=="wifi_rssi") {
        return WiFi.RSSI();
    }
    if (command=="blink") {
        led_state = !led_state;
        digitalWrite(led,led_state);
        return led_state;
    }
    
}