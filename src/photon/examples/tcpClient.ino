TCPClient client;
byte server[] = { 192, 168, 0, 6}

void setup() {
    pinMode(D7, OUTPUT);
}

void loop() {
    if(client.connect(server, 3000)){
        digitalWrite(D7, HIGH);
    }
    delay(1000);
}
