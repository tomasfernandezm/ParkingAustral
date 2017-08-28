
const int sensorPin = 0;
const int ledPin = 9;

int lightLevel, high = 0, low = 1023;

void setup(){
    // We don't need anything special to use the analog input
    pinMode(ledPin, OUTPUT);
}

void loop(){

    // We use the analogRead() function to measuer the voltage coming from the photoresistor. It can range between 0 (0 Volts) and 1023 (5 Volts).

    lightLevel = analogRead(sensorPin);

    // If we had to use the analogWrite() we would have to map it to a value between 0 and 255.

    manualTune();

    analogWrite(ledPin, lightLevel);
}

void manualTune()
{
  // As we mentioned above, the light-sensing circuit we built
  // won't have a range all the way from 0 to 1023. It will likely
  // be more like 300 (dark) to 800 (light). If you run this sketch
  // as-is, the LED won't fully turn off, even in the dark.

  // You can accommodate the reduced range by manually
  // tweaking the "from" range numbers in the map() function.
  // Here we're using the full range of 0 to 1023.
  // Try manually changing this to a smaller range (300 to 800
  // is a good guess), and try it out again. If the LED doesn't
  // go completely out, make the low number larger. If the LED
  // is always too bright, make the high number smaller.

  // Remember you're JUST changing the 0, 1023 in the line below!

  lightLevel = map(lightLevel, 0, 1023, 0, 255);
  lightLevel = constrain(lightLevel, 0, 255);

  // Now we'll return to the main loop(), and send lightLevel
  // to the LED.
}