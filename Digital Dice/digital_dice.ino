// Digital Dice with 7-Segment Display and Buzzer | 7-කොටස් දර්ශකය සහ බසර් සමග ඩිජිටල් දාදු කැටය
#define aPin 7  // Segment A pin | කොටස A පින් එක
#define bPin 8  // Segment B pin | කොටස B පින් එක
#define cPin 2  // Segment C pin | කොටස C පින් එක
#define dPin 3  // Segment D pin | කොටස D පින් එක
#define ePin 4  // Segment E pin | කොටස E පින් එක
#define fPin 6  // Segment F pin | කොටස F පින් එක
#define gPin 5  // Segment G pin | කොටස G පින් එක

// Pin configuration | පින් සැකසුම
#define PIN_BUTTON A0 // Button pin for rolling dice | දාදු කැට පෙරළීම සඳහා බොත්තම් පින් එක
#define PIN_BUZZER 10 // Buzzer pin for sound effects | ශබ්ද ප්‍රයෝග සඳහා බසර් පින් එක

const byte PIN_CHAOS = A5; // Unconnected analog pin used to initialize RNG | RNG ආරම්භ කිරීම සඳහා භාවිතා කරන සම්බන්ධ නොකළ ඇනලොග් පින් එක

// Other configuration | වෙනත් සැකසුම්
const unsigned int BEEP_FREQUENCY = 3000; // Buzzer frequency in Hz | බසර් සංඛ්‍යාතය Hz වලින්

int On = 0; // Segment ON state (0 for Common anode, 1 for Common cathode) | කොටස ON තත්වය (0 යනු Common anode සඳහා, 1 යනු Common cathode සඳහා)
int Off = 1; // Segment OFF state | කොටස OFF තත්වය

void setup() {
  // Initialize random number generator with noise from unconnected pin | සම්බන්ධ නොකළ පින් එකෙන් ශබ්දය භාවිතා කරමින් අහඹු අංක උත්පාදකය ආරම්භ කරන්න
  randomSeed(analogRead(PIN_CHAOS));
  Serial.begin(9600);  // Initialize serial communication at 9600 baud | 9600 බෝඩ් අනුපාතයෙන් සීරියල් සන්නිවේදනය ආරම්භ කරන්න

  // Set segment pins as outputs | කොටස් පින් outputs ලෙස සකසන්න
  pinMode(aPin, OUTPUT);
  pinMode(bPin, OUTPUT);
  pinMode(cPin, OUTPUT);
  pinMode(dPin, OUTPUT);
  pinMode(ePin, OUTPUT); 
  pinMode(fPin, OUTPUT);
  pinMode(gPin, OUTPUT);
  
  // Set button and buzzer pins | බොත්තම් සහ බසර් පින් සකසන්න
  pinMode(PIN_BUTTON, INPUT_PULLUP);    // On button pin as input with pullup | බොත්තම් පින් එක input ලෙස pullup සමග සකසන්න
  pinMode(PIN_BUZZER, OUTPUT);      // On buzzer pin as output | බසර් පින් එක output ලෙස සකසන්න
 
  // Indicate that system is ready | පද්ධතිය සූදානම් බව දැක්වීම
  for (int i = 9; i >= 0; i--) {
    showNumber(i);
    tone(PIN_BUZZER, BEEP_FREQUENCY, 100); // Short beep for countdown | ගණනය කිරීම සඳහා කෙටි බීප් ශබ්දය
    delay(300); 
  }  
  tone(PIN_BUZZER, BEEP_FREQUENCY, 250);  // Beep when done | අවසන් වූ විට බීප් ශබ්දය
  delay(1000);              // Wait for 1 second | තත්පර 1ක් බලාගන්න

  Serial.println("System ready"); // Print ready message to serial monitor | සූදානම් පණිවිඩය සීරියල් මොනිටරයට මුද්‍රණය කරන්න
}

void loop() {
  // Wait for button to be pressed, then run the test routine | බොත්තම එබෙන තෙක් බලාගෙන සිටින්න, පසුව පරීක්ෂණ රුටීනය ක්‍රියාත්මක කරන්න
  int buttonState = digitalRead(PIN_BUTTON);
  if (buttonState == LOW) { // Button pressed (LOW because of INPUT_PULLUP) | බොත්තම් එබීම (INPUT_PULLUP නිසා LOW)
    Serial.println("Button pressed, rolling the dice...");
    rollTheDice(10, 100);          // Show the rolling animation with fast speed | වේගවත් වේගයෙන් පෙරළෙන සජීවිකරණය පෙන්වන්න
    rollTheDice(5, 200);          // Slower animation | මන්දගාමී සජීවිකරණය
    rollTheDice(3, 300);          // Even slower | ඊටත් වඩා මන්දගාමී
    rollTheDice(1, 100);          // Final number | අවසාන අංකය
    tone(PIN_BUZZER, BEEP_FREQUENCY, 400);  // Beep when done | අවසන් වූ විට බීප් ශබ්දය
  }
}

// Function to simulate dice rolling animation | දාදු කැට පෙරළීමේ සජීවිකරණය අනුකරණය කිරීමේ ශ්‍රිතය
void rollTheDice(int count, int delayLength) {
  for (int i = 0; i < count; i++) {
    int number = random(1,  7);      // Get random number from 1 to 6 | 1 සිට 6 දක්වා අහඹු අංකයක් ලබා ගන්න
    Serial.print("Rolling: ");
    Serial.println(number);
    tone(PIN_BUZZER, BEEP_FREQUENCY, 5);  // Beep very shortly ("click") for rolling effect | පෙරළීමේ බලපෑම සඳහා ඉතා කෙටි බීප් ශබ්දය ("ක්ලික්")
    showNumber(number);           // Show the number on display | දර්ශකය මත අංකය පෙන්වන්න
    delay(delayLength);           // Wait for specified time | නියමිත කාලයක් බලාගන්න
  }
}

// Function to display number on 7-segment display | 7-කොටස් දර්ශකය මත අංකය පෙන්වීමේ ශ්‍රිතය
void showNumber(int x) {
  // Determine On/Off states based on display type | දර්ශක වර්ගය මත පදනම්ව On/Off තත්වයන් තීරණය කරන්න
  if (Off == 0) {
    On = 1; // For common anode display | Common anode දර්ශක සඳහා
  } else {
    On = 0; // For common cathode display | Common cathode දර්ශක සඳහා
  }

  Serial.print("Showing number: ");
  Serial.println(x);

  // Call appropriate function based on number | අංකය මත පදනම්ව අදාළ ශ්‍රිතය කැඳවන්න
  switch (x) {
    case 1: one();   break;
    case 2: two();   break;
    case 3: three(); break;
    case 4: four();  break;
    case 5: five();  break;
    case 6: six();   break;
    // Additional numbers can be uncommented if needed | අවශ්‍ය නම් අමතර අංක uncomment කළ හැක
    // case 7: seven(); break;
    // case 8: eight(); break;
    // case 9: nine();  break;
    // default: zero(); break;
  }
}

// Function to display number 1 | අංකය 1 පෙන්වීමේ ශ්‍රිතය
void one() {
  digitalWrite(aPin, Off); //      
  digitalWrite(bPin, On);  //      |
  digitalWrite(cPin, On);  //      |
  digitalWrite(dPin, Off); //      |
  digitalWrite(ePin, Off); //      |
  digitalWrite(fPin, Off);
  digitalWrite(gPin, Off);
}

// Function to display number 2 | අංකය 2 පෙන්වීමේ ශ්‍රිතය
void two() {
  digitalWrite(aPin, On);  //  ____
  digitalWrite(bPin, On);  //      | 
  digitalWrite(cPin, Off); //  ____|
  digitalWrite(dPin, On);  // |     
  digitalWrite(ePin, On);  // |____
  digitalWrite(fPin, Off);
  digitalWrite(gPin, On);
}

// Function to display number 3 | අංකය 3 පෙන්වීමේ ශ්‍රිතය
void three() {
  digitalWrite(aPin, On);  //  ____
  digitalWrite(bPin, On);  //      |
  digitalWrite(cPin, On);  //  ____|
  digitalWrite(dPin, On);  //      |
  digitalWrite(ePin, Off); //  ____|
  digitalWrite(fPin, Off); 
  digitalWrite(gPin, On);
}

// Function to display number 4 | අංකය 4 පෙන්වීමේ ශ්‍රිතය
void four() {
  digitalWrite(aPin, Off); //  
  digitalWrite(bPin, On);  // |    |
  digitalWrite(cPin, On);  // |____|
  digitalWrite(dPin, Off); //      |
  digitalWrite(ePin, Off); //      |
  digitalWrite(fPin, On);
  digitalWrite(gPin, On);
}

// Function to display number 5 | අංකය 5 පෙන්වීමේ ශ්‍රිතය
void five() {
  digitalWrite(aPin, On);  //  ____
  digitalWrite(bPin, Off); // |
  digitalWrite(cPin, On);  // |____
  digitalWrite(dPin, On);  //      |
  digitalWrite(ePin, Off); //  ____|
  digitalWrite(fPin, On);  
  digitalWrite(gPin, On);
}

// Function to display number 6 | අංකය 6 පෙන්වීමේ ශ්‍රිතය
void six() {
  digitalWrite(aPin, On);  //  ____
  digitalWrite(bPin, Off); // |
  digitalWrite(cPin, On);  // |____
  digitalWrite(dPin, On);  // |    |
  digitalWrite(ePin, On);  // |____|
  digitalWrite(fPin, On);
  digitalWrite(gPin, On);
}

// Additional number functions (commented out for dice) | අමතර අංක ශ්‍රිත (දාදු කැට සඳහා comment කර ඇත)
/*
void seven() {
  digitalWrite(aPin, On);  //  ____
  digitalWrite(bPin, On);  //      |
  digitalWrite(cPin, On);  //      |
  digitalWrite(dPin, Off); //      |
  digitalWrite(ePin, Off); //      |
  digitalWrite(fPin, Off);
  digitalWrite(gPin, Off);
}

void eight() {
  digitalWrite(aPin, On); //  ____
  digitalWrite(bPin, On); // |    |
  digitalWrite(cPin, On); // |____|
  digitalWrite(dPin, On); // |    |
  digitalWrite(ePin, On); // |____|
  digitalWrite(fPin, On); 
  digitalWrite(gPin, On); 
}

void nine() {
  digitalWrite(aPin, On);  //  ____
  digitalWrite(bPin, On);  // |    |
  digitalWrite(cPin, On);  // |____|
  digitalWrite(dPin, On);  //      |
  digitalWrite(ePin, Off); //  ____|
  digitalWrite(fPin, On); 
  digitalWrite(gPin, On);
}

void zero() {                 
  digitalWrite(aPin, On); //  ____
  digitalWrite(bPin, On); // |    |
  digitalWrite(cPin, On); // |    |
  digitalWrite(dPin, On); // |    |
  digitalWrite(ePin, On); // |____|
  digitalWrite(fPin, On); 
  digitalWrite(gPin, Off);   
}
*/