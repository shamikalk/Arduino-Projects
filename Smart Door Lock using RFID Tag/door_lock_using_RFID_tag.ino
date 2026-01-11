// Include necessary libraries | අවශ්‍ය පුස්තකාල ඇතුළත් කරන්න
#include <SPI.h>        // SPI communication library | SPI සන්නිවේදන library එක
#include <MFRC522.h>    // RFID reader library | RFID කියවනය library එක
#include <Servo.h>      // Servo motor control library | Servo මෝටර් එක පාලන library එක

// Pin Definitions | පින් අර්ථ දැක්වීම්
#define RST_PIN 9      // RFID module reset pin | RFID module reset පින්
#define SS_PIN 10      // RFID module slave select pin | RFID module slave select පින්
#define BUZZER_PIN 8   // Buzzer pin for audible feedback | ශ්‍රව්‍ය ප්‍රතිපෝෂණය සඳහා බසර් පින්
#define SERVO_PIN 7    // Servo motor control pin | Servo මෝටර් එක පාලන පින්

// Create instances of RFID reader and Servo | RFID කියවනය සහ Servo යන්ත්‍රවල උදාහරණ නිර්මාණය කරන්න
MFRC522 rfid(SS_PIN, RST_PIN); // Create MFRC522 RFID reader instance | MFRC522 RFID කියවනය උදාහරණය නිර්මාණය කරන්න
Servo myServo;                 // Create a Servo instance for motor control | මෝටර් පාලනය සඳහා Servo උදාහරණයක් නිර්මාණය කරන්න

// Predefined list of authorized RFID card UIDs (example UIDs) | අවසර ලත් RFID කාඩ්පත් UID ලැයිස්තුව (උදාහරණ UID)
String authorizedUIDs[] = {
    "43 66 24 13", // Replace with your actual authorized card UIDs | ඔබේ සැබෑ අවසර ලත් කාඩ්පත් UID වලින් ප්‍රතිස්ථාපනය කරන්න
    "E5 F6 G7 H8"   // Example format: UID bytes in hexadecimal with spaces | උදාහරණ ආකෘතිය: හෙක්සාඩෙසිමල් UID බයිට් අවකාශ සමග
};
int numberOfAuthorizedUids = sizeof(authorizedUIDs) / sizeof(authorizedUIDs[0]); // Calculate number of authorized UIDs | අවසර ලත් UID ගණන ගණනය කරන්න

void setup() {
    Serial.begin(9600);      // Initialize serial communication at 9600 baud | බවුඩ් අනුපාත 9600 දී සීරියල් සන්නිවේදනය ආරම්භ කරන්න
    SPI.begin();             // Initialize SPI bus for RFID communication | RFID සන්නිවේදනය සඳහා SPI බස් ආරම්භ කරන්න
    rfid.PCD_Init();         // Initialize MFRC522 RFID reader | MFRC522 RFID කියවනය ආරම්භ කරන්න
    delay(50);               // Short delay for stable RFID initialization | ස්ථායී RFID ආරම්භක කිරීම සඳහා කෙටි ප්‍රමාදය

    myServo.attach(SERVO_PIN); // Attach the servo motor to the specified pin | Servo මෝටර් එක නියමිත පින් වෙත අමුණන්න
    myServo.write(0);          // Initialize the servo at 0 degrees (locked position) | Servo අංශක 0 (අගුළු දමන ලද ස්ථානය) දී ආරම්භ කරන්න
    pinMode(BUZZER_PIN, OUTPUT); // Set buzzer pin as output for sound feedback | ශබ්ද ප්‍රතිපෝෂණය සඳහා බසර් පින් ප්‍රතිදානයක් ලෙස සකසන්න

    Serial.println("Scan your RFID card..."); // Startup message | ආරම්භක පණිවිඩය
    Serial.println("===========================================");
}

void loop() {
    // Look for new RFID cards in proximity | සමීපයේ නව RFID කාඩ්පත් සොයන්න
    if (!rfid.PICC_IsNewCardPresent()) {
        return; // No new card present, exit function | නව කාඩ්පත් නැත, ශ්‍රිතයෙන් පිටවන්න
    }

    // Select one of the RFID cards for reading | කියවීම සඳහා RFID කාඩ්පත් එකක් තෝරන්න
    if (!rfid.PICC_ReadCardSerial()) {
        return; // Couldn't read card serial data, exit function | කාඩ්පත් සීරියල් දත්ත කියවීමට නොහැකි විය, ශ්‍රිතයෙන් පිටවන්න
    }

    // Create a UID string from the scanned card | ස්කෑන් කරන ලද කාඩ්පත්වලින් UID නූලක් නිර්මාණය කරන්න
    String scannedUID = "";
    for (byte i = 0; i < rfid.uid.size; i++) {
        // Convert each byte to hexadecimal, adding leading zero if needed | අවශ්‍ය නම් ඉදිරිපස බිංදුව එකතු කරමින් එක් එක් බයිට් හෙක්සාඩෙසිමල් බවට පරිවර්තනය කරන්න
        scannedUID += String(rfid.uid.uidByte[i] < 0x10 ? "0" : "") + String(rfid.uid.uidByte[i], HEX);
        if (i < rfid.uid.size - 1) scannedUID += " "; // Add space between bytes for readability | කියවීමේ පහසුව සඳහා බයිට් අතර අවකාශය එකතු කරන්න
    }
    scannedUID.toUpperCase(); // Convert UID to uppercase for consistent comparison | ස්ථීර සංසන්දනය සඳහා UID විශාල අකුරු වලට පරිවර්තනය කරන්න

    // Print the scanned UID to Serial Monitor | ස්කෑන් කරන ලද UID සීරියල් මොනිටරයට මුද්‍රණය කරන්න
    Serial.print("Scanned UID: ");
    Serial.println(scannedUID);

    // Check if the scanned UID is in the authorized list | ස්කෑන් කරන ලද UID අවසර ලත් ලැයිස්තුවේ ඇත්දැයි පරීක්ෂා කරන්න
    bool isAuthorized = false;
    for (int i = 0; i < numberOfAuthorizedUids; i++) {
        if (scannedUID.equalsIgnoreCase(authorizedUIDs[i])) {
            isAuthorized = true; // Card is authorized | කාඩ්පත අවසර ලත් එකකි
            break; // Exit loop once found | සොයාගත් පසු ලූපයෙන් පිටවන්න
        }
    }

    // Control the servo motor and sound the buzzer based on authorization status | අවසර තත්ත්වය මත පදනම්ව සර්වෝ මෝටරය පාලනය කර බසරය නාද කරන්න
    if (isAuthorized) {
        // Authorized access - positive feedback | අවසර ලත් ප්‍රවේශය - ධනාත්මක ප්‍රතිපෝෂණය
        tone(BUZZER_PIN, 1000, 200); // Play a high-pitched sound (1000Hz) for 200ms | ඉහළ ස්වරයක් (1000Hz) මිලිතත්පර 200ක් වාදනය කරන්න
        myServo.write(90);           // Rotate the servo to 90 degrees (unlocked position) | සර්වෝව අංශක 90 (අගුලු හරින ලද ස්ථානය) වෙත භ්‍රමණය කරන්න
        Serial.println("Status: Present (Authorized) - Access Granted");
        delay(5000);                 // Wait for 5 seconds with the servo at 90 degrees (access period) | සර්වෝව අංශක 90 දී තත්පර 5ක් රැඳෙන්න (ප්‍රවේශ කාල සීමාව)
        myServo.write(0);            // Return the servo to 0 degrees (locked position) | සර්වෝව අංශක 0 (අගුළු දමන ලද ස්ථානය) වෙත ආපසු ගෙන එන්න
    } else {
        // Unauthorized access - negative feedback | අවසර නොලත් ප්‍රවේශය - ඍණාත්මක ප්‍රතිපෝෂණය
        tone(BUZZER_PIN, 500, 200); // Play a low-pitched sound (500Hz) for 200ms | අඩු ස්වරයක් (500Hz) මිලිතත්පර 200ක් වාදනය කරන්න
        myServo.write(0);           // Keep the servo at 0 degrees (locked position) | සර්වෝව අංශක 0 (අගුළු දමන ලද ස්ථානය) දී තබා ගන්න
        Serial.println("Status: Absent (Unauthorized) - Access Denied");
    }

    // Wait before scanning the next card | ඊළඟ කාඩ්පත ස්කෑන් කිරීමට පෙර රැඳෙන්න
    delay(2000); // 2-second delay to prevent multiple reads of same card | එකම කාඩ්පතේ බහු කියවීම් වළක්වා ගැනීම සඳහා තත්පර 2ක ප්‍රමාදය
    rfid.PICC_HaltA(); // Halt the current card to prepare for next scan | ඊළඟ ස්කෑන් සඳහා සූදානම් වීමට වර්තමාන කාඩ්පත නවතා දමන්න
}