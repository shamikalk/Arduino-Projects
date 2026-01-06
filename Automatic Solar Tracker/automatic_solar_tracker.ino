// Include the servo motor library | servo මෝටර් library එක ඇතුළත් කරන්න
#include <Servo.h>

// Define the LDR sensor pins | LDR sensor පින් අර්ථ දැක්වීම
#define LDR1 A0 // First LDR sensor pin | පළමු LDR සංවේදක පින්
#define LDR2 A1 // Second LDR sensor pin | දෙවන LDR සංවේදක පින්

// Define the error value (tolerance for light difference) | දෝෂ අගය අර්ථ දැක්වීම (ආලෝක වෙනස සඳහා ඉවසීම)
#define error 10 // You can change this value as needed | අවශ්‍ය පරිදි මෙම අගය වෙනස් කළ හැකිය

// Starting point (initial position) of the servo motor | servo මෝටරයේ ආරම්භක ලක්ෂ්‍යය (ආරම්භක ස්ථානය)
int Spoint = 90; // 90 degrees is the center position | අංශක 90 මධ්‍ය ස්ථානයයි

// Create an object for the servo motor | servo මෝටරය සඳහා වස්තුවක් සාදන්න
Servo servo;

void setup() {
  // Include servo motor PWM pin | servo මෝටර් PWM පින් ඇතුළත් කරන්න
  servo.attach(11); // Servo signal pin connected to digital pin 11 | සර්වෝ සංඥා පින් ඩිජිටල් පින් 11 වෙත සම්බන්ධ කර ඇත
  
  // Set the starting point of the servo | servo එකේ ආරම්භක ලක්ෂ්‍යය සකසන්න
  servo.write(Spoint); // Move servo to starting position | servo එකේ ආරම්භක ස්ථානයට ගෙන යන්න
  delay(1000); // Wait 1 second for servo to reach position | servo එකේ ස්ථානයට ළඟා වන තෙක් තත්පර 1ක් රැඳෙන්න
}

void loop() {
  // Get the LDR sensor values | LDR සංවේදක අගයන් ලබා ගන්න
  int ldr1 = analogRead(LDR1); // Read value from first LDR (0-1023) | පළමු LDR වලින් අගය කියවන්න (0-1023)
  int ldr2 = analogRead(LDR2); // Read value from second LDR (0-1023) | දෙවන LDR වලින් අගය කියවන්න (0-1023)

  // Calculate the absolute difference between the two LDR values | LDR අගයන් දෙක අතර නිරපේක්ෂ වෙනස ගණනය කරන්න
  int value1 = abs(ldr1 - ldr2); // Difference: LDR1 - LDR2 | වෙනස: LDR1 - LDR2
  int value2 = abs(ldr2 - ldr1); // Difference: LDR2 - LDR1 | වෙනස: LDR2 - LDR1
  
  // Note: value1 and value2 will always be equal since they are absolute differences
  // සටහන: value1 සහ value2 සැමවිටම සමාන වේ (නිරපේක්ෂ වෙනස්කම් වන බැවින්)

  // Check these values using an IF condition | IF කොන්දේසියක් භාවිතයෙන් මෙම අගයන් පරීක්ෂා කරන්න
  if ((value1 <= error) || (value2 <= error)) {
    // If the difference is within the error tolerance, do nothing
    // වෙනස දෝෂ ඉවසීම තුළ පවතී නම්, කිසිවක් නොකරන්න
    // This means light intensity is approximately equal on both sides
    // මෙයින් අදහස් කරන්නේ දෙපැත්තෙන්ම ආලෝක තීව්‍රතාව ආසන්න වශයෙන් සමාන බවයි
  } else {
    // If the difference exceeds the error tolerance, adjust servo position
    // වෙනස දෝෂ ඉවසීම ඉක්මවන්නේ නම්, සර්වෝ ස්ථානය සකස් කරන්න
    if (ldr1 > ldr2) {
      // If LDR1 (left) receives more light than LDR2 (right)
      // LDR1 (වම) වැඩි ආලෝකයක් ලබා ගන්නේ LDR2 (දකුණ) ට වඩා නම්
      Spoint = --Spoint; // Decrement servo position (move toward left/less light) | සර්වෝ ස්ථානය අඩු කරන්න (වමට/අඩු ආලෝකය දෙසට ගමන් කරන්න)
    }
    if (ldr1 < ldr2) {
      // If LDR2 (right) receives more light than LDR1 (left)
      // LDR2 (දකුණ) වැඩි ආලෝකයක් ලබා ගන්නේ LDR1 (වම) ට වඩා නම්
      Spoint = ++Spoint; // Increment servo position (move toward right/more light) | සර්වෝ ස්ථානය වැඩි කරන්න (දකුණට/වැඩි ආලෝකය දෙසට ගමන් කරන්න)
    }
  }
  
  // Write the calculated position value to the servo motor | ගණනය කළ ස්ථාන අගය සර්වෝ මෝටරයට ලියන්න
  servo.write(Spoint); // Move servo to the new position | servo එකේ නව ස්ථානයට ගෙන යන්න
  delay(80); // Small delay for stability and to prevent rapid movements | ස්ථායිතාව සඳහා සහ වේගවත් චලන වළක්වා ගැනීම සඳහා කුඩා ප්‍රමාදයක්
}