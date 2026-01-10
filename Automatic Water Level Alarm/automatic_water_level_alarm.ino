// Include necessary libraries | අවශ්‍ය පුස්තකාල ඇතුළත් කරන්න
#include <Wire.h>              // I2C communication library | I2C සන්නිවේදන library එක
#include <LiquidCrystal_I2C.h> // I2C LCD library | I2C LCD library එක
#include <NewPing.h>           // Library for Ultrasonic sensor | Ultrasonic sensor සඳහා library එක

// Define pins for the ultrasonic sensor | ultrasonic sensor සඳහා පින් අර්ථ දැක්වීම
#define trigPin 12 // Trigger pin for ultrasonic sensor | ultrasonic sensor සඳහා ට්‍රිගර් පින්
#define echoPin 13 // Echo pin for ultrasonic sensor | ultrasonic sensor සඳහා එකෝ පින්

// Buzzer pin | බසර් පින්
#define buzzer 8 // Buzzer connected to digital pin 8 | බසරය ඩිජිටල් පින් 8 වෙත සම්බන්ධ කර ඇත

// Maximum distance of the water tank (in cm) and the distance threshold for the buzzer | ජල ටැංකියේ උපරිම උස (සෙ.මී.) සහ බසරය සඳහා දුර අවම සීමාව
const int maxTankDepth = 100; // Set this to the actual height of your water tank in cm | ඔබේ ජල ටැංකියේ සැබෑ උස සෙ.මී. වලින් සකසන්න
const int buzzerThreshold = 80; // Buzzer should activate when the tank is 80% full | ටැංකිය 80% පිරෙන විට බසරය ක්‍රියාත්මක විය යුතුය

// LCD setup for I2C (address 0x27) | I2C සඳහා LCD සැකසුම (ලිපිනය 0x27)
LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address 0x27, 16 columns, 2 rows | I2C ලිපිනය 0x27, තීරු 16, පේළි 2
// Note: If LCD doesn't work, try address 0x3F | සටහන: LCD ක්‍රියා නොකරන්නේ නම්, ලිපිනය 0x3F උත්සාහ කරන්න

// Setup NewPing library (trigger pin, echo pin, maximum distance) | NewPing පුස්තකාලය සැකසීම (ට්‍රිගර් පින්, එකෝ පින්, උපරිම දුර)
NewPing sonar(trigPin, echoPin, maxTankDepth);

void setup() {
  // Initialize the LCD with columns, rows, and character size | තීරු, පේළි සහ අකුරු ප්‍රමාණය සමග LCD ආරම්භ කරන්න
  lcd.begin(16, 2); // 16 columns, 2 rows | තීරු 16, පේළි 2
  lcd.backlight(); // Turn on LCD backlight | LCD ආලෝකය ක්‍රියාත්මක කරන්න
  
  // Display startup message on LCD | LCD මත ආරම්භක පණිවිඩය පෙන්වන්න
  lcd.setCursor(0, 0); // Set cursor to first column, first row | කර්සරය පළමු තීරුව, පළමු පේළියට සකසන්න
  lcd.print("Water Level"); // Print title | ශීර්ෂය මුද්‍රණය කරන්න
  lcd.setCursor(0, 1); // Set cursor to first column, second row | කර්සරය පළමු තීරුව, දෙවන පේළියට සකසන්න
  lcd.print("Measurement"); // Print subtitle | උප ශීර්ෂය මුද්‍රණය කරන්න
  
  delay(2000);  // Wait 2 seconds before starting measurement | මිනුම් ආරම්භ කිරීමට පෙර තත්පර 2ක් රැඳෙන්න

  // Set up the pin modes | පින් මාදිලි සැකසීම
  pinMode(buzzer, OUTPUT); // Set buzzer pin as output | බසර් පින් ප්‍රතිදානයක් ලෙස සකසන්න
  digitalWrite(buzzer, LOW); // Ensure buzzer is off at the start | ආරම්භයේදී බසරය නිවී ඇති බවට වග බලා ගන්න
  
  // Begin serial communication for debugging (optional) | දෝෂ නිරාකරණය සඳහා සීරියල් සන්නිවේදනය ආරම්භ කරන්න (විකල්ප)
  Serial.begin(9600); // 9600 baud rate | බවුඩ් අනුපාත 9600
}

void loop() {
  // Get the distance measured by the ultrasonic sensor | ultrasonic sensor මගින් මැන ගත් දුර ලබා ගන්න
  int distance = sonar.ping_cm(); // Distance in centimeters | දුර සෙන්ටිමීටර වලින්
  
  // Calculate the water level as a percentage (0% = empty, 100% = full) | ප්‍රතිශතයක් ලෙස ජල මට්ටම ගණනය කරන්න (0% = හිස්, 100% = පිරි)
  int waterLevel = map(distance, 0, maxTankDepth, 100, 0);
  // Note: map() converts distance to percentage:
  // distance=0cm (sensor at water surface) → 100% full
  // distance=maxTankDepth (sensor at tank bottom) → 0% full
  // සටහන: map() ශ්‍රිතය දුර ප්‍රතිශතයකට පරිවර්තනය කරයි:
  // දුර=0cm (සංවේදකය ජල මතුපිට) → 100% පිරි
  // දුර=උපරිම ගැඹුර (සංවේදකය ටැංකියේ පතුලේ) → 0% පිරි
  
  // Ensure the water level is within a valid range (0 to 100%) | ජල මට්ටම වලංගු පරාසයක් තුළ (0 සිට 100% දක්වා) පවතින බවට වග බලා ගන්න
  waterLevel = constrain(waterLevel, 0, 100);

  // Print the water level to the Serial Monitor for debugging | දෝෂ නිරාකරණය සඳහා ජල මට්ටම සීරියල් මොනිටරයට මුද්‍රණය කරන්න
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print(" cm, Water Level: ");
  Serial.print(waterLevel);
  Serial.println(" %");
  
  // Display the water level on the LCD | LCD මත ජල මට්ටම පෙන්වන්න
  lcd.clear(); // Clear the LCD screen | LCD තිරය පැහැදිලි කරන්න
  lcd.setCursor(0, 0); // Set cursor to first column, first row | කර්සරය පළමු තීරුව, පළමු පේළියට සකසන්න
  lcd.print("Water Level: ");
  lcd.print(waterLevel);
  lcd.print("%");
  
  // Display a simple bar indicator for the water level | ජල මට්ටම සඳහා සරල තීරු දර්ශකයක් පෙන්වන්න
  lcd.setCursor(0, 1); // Set cursor to first column, second row | කර්සරය පළමු තීරුව, දෙවන පේළියට සකසන්න
  int bars = map(waterLevel, 0, 100, 0, 16); // Map percentage to number of bars (0-16) | ප්‍රතිශතය තීරු සංඛ්‍යාවට සිතියම් ගත කරන්න (0-16)
  for (int i = 0; i < bars; i++) {
    lcd.print("|"); // Print vertical bar for each percentage increment | සෑම ප්‍රතිශත ඉහළ යෑමක් සඳහා සිරස් තීරුවක් මුද්‍රණය කරන්න
  }

  // Check if the water level is 80% or higher, and sound the buzzer for 3 seconds | ජල මට්ටම 80% හෝ ඊට වැඩිදැයි පරීක්ෂා කර බසරය තත්පර 3ක් විරාමයෙන් නංවන්න
  if (waterLevel >= buzzerThreshold) {
    digitalWrite(buzzer, HIGH);  // Activate buzzer (turn on) | බසරය ක්‍රියාත්මක කරන්න (ක්‍රියාත්මක කරන්න)
    delay(3000);                 // Keep it on for 3 seconds | තත්පර 3ක් ක්‍රියාත්මකව තබා ගන්න
    digitalWrite(buzzer, LOW);   // Turn off buzzer | බසරය නිවා දමන්න
  }

  // Wait before taking the next measurement (adjust as needed) | ඊළඟ මිනුම ගැනීමට පෙර රැඳෙන්න (අවශ්‍ය පරිදි සකසන්න)
  delay(1000); // 1 second delay between measurements | මිනුම් අතර තත්පර 1ක ප්‍රමාදය
}