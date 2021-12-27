// Fairy light controller.           Pins 10 and 11 connect to a string of LED's, with alternating polarity.
//                                   Pins 7 and GND connect to a push button to change setting.#

// Bit of a work in progress - need to mess around with the delay functions in the switch statements as they are delaying the incrementing of the selection value.
// Also want to add a twinkle effect where both LED's are blended with eachother, fading back and forth, like the original controller had.

const int LED1 = 10;  // LED string pins, polarity doesn't matter
const int LED2 = 11;  

const int button = 7; // pushbutton pin

int sel = 0; // initial case for selection switch

void setup() {
  
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT); // set pins as output

  pinMode(button, INPUT_PULLUP); // set pushbutton as input

  Serial.begin(9600); // debugging

}

void setLED(int ledPos, int speed) // default for speed is around 500ms
{
  if(ledPos == 0)
  {
    digitalWrite(LED1, HIGH);
    delay(speed);
    digitalWrite(LED2, LOW);
    delay(speed);
  }

  if(ledPos == 1)
  {
    digitalWrite(LED1, LOW);
    delay(speed);
    digitalWrite(LED2, HIGH);
    delay(speed);
  }
}

void setLEDfade(int ledPos, int fadeSpeed)
{
  if(ledPos == 0)
  {
    for(int fadeValue = 0 ; fadeValue <= 255 ; fadeValue +=fadeSpeed) {
    analogWrite(10, fadeValue);
    digitalWrite(11, LOW);
    delay(20);
  }

  for(int fadeValue = 255 ; fadeValue >= 0 ; fadeValue -=fadeSpeed) {
    analogWrite(10, fadeValue);
    digitalWrite(11, LOW);
    delay(20);
  }
  }
  if(ledPos == 1)
  {
    for(int fadeValue = 0 ; fadeValue <= 255 ; fadeValue +=fadeSpeed) {
    analogWrite(11, fadeValue);
    digitalWrite(10, LOW);
    delay(20);
  }

  for(int fadeValue = 255 ; fadeValue >= 0 ; fadeValue -=fadeSpeed) {
    analogWrite(11, fadeValue);
    digitalWrite(10, LOW);
    delay(20);
  }

    
  }
}

void loop() {
  // put your main code here, to run repeatedly:

  if (digitalRead(button) == LOW) { // when button pin is pulled low, increment sel by 1
    sel += 1;
    delay(200);
  }

  if (sel > 4) { // when sel reaches top limit, loop back to 0
    sel = 0;
  }

  switch (sel) { // LED patterns go here

    case 0: // static lights - delay of 2ms is invisible to the human eye, so lights appear static
    Serial.println("case 0");
    setLED(0,2);
    setLED(1,2);
    break;
    
    case 1: // flashing back and forth slowly
    Serial.println("case 1");
    setLED(0,500);
    setLED(1,500);
    break;
    
    case 2: // flashing back and forth even faster
    Serial.println("case 2");
    setLED(0,250);
    setLED(1,250);
    break;
    
    case 3:
    Serial.println("case 3"); // fading back and forth slowly
    setLEDfade(0,2);
    setLEDfade(1,2);
    break;
    
    case 4:
    Serial.println("case 4"); // fading back and forth faster
    setLEDfade(0,5);
    setLEDfade(1,5);
    break;

  }

}
