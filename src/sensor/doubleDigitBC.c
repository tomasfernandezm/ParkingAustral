int tensLedPins[] = {2, 3, 4, 5};
int onesLedPins [] = {6, 7, 8, 9};
int bitAmount = 4;
int tens = 0;
int ones = 0;

void setup(){
    for(int i = 0;i < bitAmount; i++){
        pinMode(tensLedPins[i], OUTPUT);
        pinMode(onesLedPins[i], OUTPUT);
    }
}

void loop(){
    showBinaryNumber(ones, onesLedPins);
    showBinaryNumber(tens, tensLedPins);
    if(ones == 9){
        ones = 0;
        tens++;
    }else{
        ones++;
    }
    delay(500);
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
