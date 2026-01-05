#include <Wire.h> // I2C communication library | I2C සන්නිවේදන library
#include <LiquidCrystal_I2C.h> // I2C LCD Display library | I2C LCD Display library එක

// Pin setup | පින් සැකසුම
const int irSensorPin = 2; // IR sensor connected to digital pin 2 | IR sensor එක ඩිජිටල් පින් 2 වෙත සම්බන්ධ කර ඇත

// RPM calculation variables | RPM ගණනය කිරීමේ විචල්යයන්
volatile int count = 0; // Counts the number of white strip detections | සුදු පටි හඳුනාගැනීම් ගණන ගණනය කරයි
unsigned long lastMillis = 0; // Last time measurement for RPM calculation | RPM ගණනය කිරීම සඳහා අවසාන කාල මිනුම
int rpm = 0; // RPM value to display as an integer | නිදර්ශනය කිරීමට RPM අගය (පූර්ණ සංඛ්යාවක් ලෙස)
int divisor = 1; // To handle multiple strips (1 for single strip, 2 for diameter) | බහු පටි සැකසීම සඳහා (1=තනි පටියක්, 2=විෂ්කම්භය)

// Initialize the LCD at I2C address 0x27, 16 columns, 2 rows | I2C ලිපිනය 0x27, 16 තීරු, 2 පේළි වල LCD ආරම්භ කරන්න
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // IR sensor pin configuration | IR sensor එක පින් වින්‍යාසගත කිරීම
  pinMode(irSensorPin, INPUT);  // Set IR sensor pin as input | IR sensor එක පින් ආදානයක් ලෙස සකසන්න
  attachInterrupt(digitalPinToInterrupt(irSensorPin), countWhiteStripe, RISING); // Interrupt on rising edge | rising edge වෙන විට interrupt එකක් සකසන්න

  // LCD initialization | LCD ආරම්භක කිරීම
  lcd.begin();              // Start LCD | LCD ආරම්භ කරන්න
  lcd.setBacklight(1);      // Turn on backlight | ආලෝකය ක්‍රියාත්මක කරන්න
  lcd.clear();              // Clear the screen | තිරය පැහැදිලි කරන්න
  lcd.print("RPM Counter"); // Display title | ශීර්ෂය නිරූපණය කරන්න
  delay(2000); // Display title for 2 seconds | ශීර්ෂය තත්පර 2ක් පෙන්වන්න
}

void loop() {
  unsigned long currentMillis = millis(); // Get current time | වර්තමාන කාලය ලබා ගන්න
  
  // Calculate RPM every 1 second (1000 milliseconds) | සෑම තත්පරයකට වරක් RPM ගණනය කරන්න (මිලිතත්පර 1000)
  if (currentMillis - lastMillis >= 1000) {
    lastMillis = currentMillis; // Update last measurement time | අවසන් මිනුම් කාලය යාවත්කාලීන කරන්න
    
    // Calculate RPM as an integer: (count * 60) / time in seconds | RPM පූර්ණ සංඛ්යාවක් ලෙස ගණනය කරන්න: (ගණන * 60) / තත්පර වල කාලය
    rpm = (count * 60) / divisor; // Adjust RPM based on divisor (1 or 2) | බෙදීම් අගය මත RPM සකස් කරන්න (1 හෝ 2)
    
    // Display RPM on the LCD | LCD මත RPM නිරූපණය කරන්න
    lcd.clear(); // Clear LCD display | LCD දර්ශනය පැහැදිලි කරන්න
    lcd.print("RPM: "); // Display label | ලේබලය නිරූපණය කරන්න
    lcd.print(rpm); // Display RPM as an integer | RPM පූර්ණ සංඛ්යාවක් ලෙස නිරූපණය කරන්න
    count = 0; // Reset count for next calculation | ඊළඟ ගණනය සඳහා ගණන යළි සකසන්න
  }
}

// Interrupt service routine for white stripe detection | සුදු පටිය හඳුනාගැනීම සඳහා interrupt සේවා රටීනය
void countWhiteStripe() {
  // Increment count every time the white tape passes the IR sensor | සුදු පටිය IR sensor එක හරහා ගමන් කරන සෑම අවස්ථාවකම ගණන වැඩි කරන්න
  count++;
}