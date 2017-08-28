
int ledPins[] = {2, 3, 4, 5, 6, 7, 8, 9};
int bitAmount = 4;

void setup(){
    for(int i = 0;i < bitAmount; i++){
        pinMode(ledPins[i], OUTPUT);
    }
}

void loop(){
    for(int i = 0;i < 10; i++){
        showBinaryNumber(i);
        delay(500);
    }
}

void showBinaryNumber(int num) {
    for (int i=0; i < bitAmount; i++) {
      if (num%2)
        digitalWrite(ledPins[i], HIGH);
      else
        digitalWrite(ledPins[i], LOW);
      num/=2;
    } 
}