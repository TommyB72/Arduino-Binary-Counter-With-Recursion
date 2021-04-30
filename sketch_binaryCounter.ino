byte leds[] = {9,6,5,3}; //output pins for the LEDs
int delayTime = 500; //delay time before add to the count

void setup() {
  for(byte i = 0; i < sizeof(leds); i++) pinMode(leds[i], OUTPUT); //set up each pin as an output
}

void loop() {
  CheckPinPowerRecursion(0);  //start the counter with 0
  delay(delayTime);
}

void CheckPinPowerRecursion(byte p){
  if(digitalRead(leds[p]) == false) digitalWrite(leds[p], HIGH);//if the LED is not powered, power it
  else if(p==sizeof(leds)-1) TurnOffAllLEDs(); //if the LED is powered, but is the last LED, turn off all LEDs to start over
  else{ //if the LED is powered, and isn't last LED
    digitalWrite(leds[p], LOW); //turn it off
    CheckPinPowerRecursion(p+1); //and check the next LED in sequence
  }
}

void TurnOffAllLEDs(){ //iterate through all LEDs and turn them off
  for(byte i = 0; i < sizeof(leds); i++)
    digitalWrite(leds[i], LOW);
}
