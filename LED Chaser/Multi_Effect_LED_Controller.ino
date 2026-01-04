// Define delay times for different effects | විවිධ ආකාර සඳහා ප්‍රමාද කාලයන් අර්ථ දැක්වීම
#define t   30   // Standard delay | සම්මත ප්‍රමාදය
#define t1  20   // Fast delay for chasing effects | පසුපස්සේ යන ආකාර සඳහා වේගවත් ප්‍රමාදය
#define t2  100  // Medium delay for smooth effects | සුමට ආකාර සඳහා මධ්‍යස්ථ ප්‍රමාදය
#define t3  50   // Medium-fast delay | මධ්‍යස්ථ-වේගවත් ප්‍රමාදය

void setup() {
  // Set up pins 2 to 13 as outputs | පින් 2 සිට 13 දක්වා ප්‍රතිදාන ලෙස සකසන්න
  for (int i = 2; i <= 13; i++) {
    pinMode(i, OUTPUT);
  }
}

void loop() {
  // Execute each effect twice in sequence | සෑම ආකාරයක්ම දෙවරක් අනුපිළිවෙලින් ක්‍රියාත්මක කරන්න
  effect_1();
  effect_1();

  effect_2();
  effect_2();

  effect_3();
  effect_3();

  effect_4();
  effect_4();

  effect_5();
  effect_5();

  effect_6();
  effect_6();

  effect_7();
  effect_7();
}

// Effect 1: Three-LED chaser moving left to right and right to left | ආකාරය 1: තුන්-LED පසුපස්සේ යන ආකාරය වමේ සිට දකුණට සහ දකුණේ සිට වමට ගමන් කරයි
void effect_1() {
  // Move three-LED group from left to right | තුන්-LED කණ්ඩායම වමේ සිට දකුණට ගෙන යන්න
  for(int i=2; i<14; i++) {
    digitalWrite(i, HIGH);
    delay(t1);
    digitalWrite(i+1, HIGH);
    delay(t1);
    digitalWrite(i+2, HIGH);
    delay(t1);
    digitalWrite(i, LOW);
    delay(t1);
    digitalWrite(i+1, LOW);
    delay(t1);
  }
  
  // Move three-LED group from right to left | තුන්-LED කණ්ඩායම දකුණේ සිට වමට ගෙන යන්න
  for(int i=13; i>1; i--) {
    digitalWrite(i, HIGH);
    delay(t1);
    digitalWrite(i-1, HIGH);
    delay(t1);
    digitalWrite(i-2, HIGH);
    delay(t1);
    digitalWrite(i, LOW);
    delay(t1);
    digitalWrite(i-1, LOW);
    delay(t1);
  }
}

// Effect 2: Two chasers moving in opposite directions | ආකාරය 2: ප්‍රතිවිරුද්ධ දිශාවලට ගමන් කරන පසුපස්සේ යන ආකාර දෙකක්
void effect_2() {
  int count = 13; // Tracks the position of the second chaser | දෙවන පසුපස්සේ යන ආකාරයේ ස්ථානය ලුහුබැඳීම
  
  // Move first chaser left to right, second chaser right to left | පළමු පසුපස්සේ යන ආකාරය වමේ සිට දකුණට, දෙවන පසුපස්සේ යන ආකාරය දකුණේ සිට වමට ගෙන යන්න
  for (int i = 2; i < 13; i++) {
    clear();
    digitalWrite(i, HIGH);      // First chaser | පළමු පසුපස්සේ යන ආකාරය
    digitalWrite(count, HIGH); // Second chaser | දෙවන පසුපස්සේ යන ආකාරය
    count--;
    
    // Prevent LEDs from appearing stationary in the middle | මැද එල්ඊඩී නවතිනවා වැනි පෙනුම වළක්වන්න
    if (count != 7) {
      delay(t2);
    }
  }

  // Move first chaser right to left, second chaser left to right | පළමු පසුපස්සේ යන ආකාරය දකුණේ සිට වමට, දෙවන පසුපස්සේ යන ආකාරය වමේ සිට දකුණට ගෙන යන්න
  for (int i = 13; i > 2; i--) {
    clear();
    digitalWrite(i, HIGH);      // First chaser | පළමු පසුපස්සේ යන ආකාරය
    digitalWrite(count, HIGH); // Second chaser | දෙවන පසුපස්සේ යන ආකාරය
    count++;
    
    // Prevent LEDs from appearing stationary in the middle | මැද එල්ඊඩී නවතිනවා වැනි පෙනුම වළක්වන්න
    if (count != 8) {
      delay(t2);
    }
  }
}

// Effect 3: Sequential LED turn on/off from both directions | ආකාරය 3: දෙපැත්තෙන් අනුක්‍රමිකව LED අලුත් කිරීම/නිවා දැමීම
void effect_3() {
  // Turn on LEDs sequentially from left to right | LED වමේ සිට දකුණට අනුක්‍රමිකව අලුත් කරන්න
  for(int i=2; i<14; i++) {
    digitalWrite(i, HIGH);
    delay(t3);
  }
  
  // Turn off LEDs sequentially from left to right | LED වමේ සිට දකුණට අනුක්‍රමිකව නිවා දමන්න
  for(int i=2; i<14; i++) {
    digitalWrite(i, LOW);
    delay(t3);
  }

  // Turn on LEDs sequentially from right to left | LED දකුණේ සිට වමට අනුක්‍රමිකව අලුත් කරන්න
  for(int i = 14; i>=2; i--) {
    digitalWrite(i, HIGH);
    delay(t3);
  }
  
  // Turn off LEDs sequentially from right to left | LED දකුණේ සිට වමට අනුක්‍රමිකව නිවා දමන්න
  for(int i = 14; i>=2; i--) {
    digitalWrite(i, LOW);
    delay(t3);
  }
}

// Effect 4: Alternating LED pattern (even/odd positions) | ආකාරය 4: විකල්ප LED රටා (ඉරට්ටේ/ඔත්තේ ස්ථාන)
void effect_4() {
  // Turn on LEDs at even positions | ඉරට්ටේ ස්ථානවල LED අලුත් කරන්න
  for(int j = 2; j <= 13; j++) {
    digitalWrite(j, HIGH);
    delay(t2);
    j=j+1;  // Skip to next even position | ඊළඟ ඉරට්ටේ ස්ථානයට පනින්න
  }
  
  // Turn off LEDs at even positions | ඉරට්ටේ ස්ථානවල LED නිවා දමන්න
  for(int j = 2; j <= 13; j++) {
    digitalWrite(j, LOW);
    delay(t2);
  }

  // Turn on LEDs at odd positions | ඔත්තේ ස්ථානවල LED අලුත් කරන්න
  for(int k = 15; k > 2; k--) {
    digitalWrite(k, HIGH);
    delay(t2);
    k=k-1;  // Skip to next odd position | ඊළඟ ඔත්තේ ස්ථානයට පනින්න
  }
  
  // Turn off LEDs at odd positions | ඔත්තේ ස්ථානවල LED නිවා දමන්න
  for(int k = 15; k > 2; k--) {
    digitalWrite(k, LOW);
    delay(t2);
  }
}

// Effect 5: Wave-like propagation effect | ආකාරය 5: රළ සමාන ප්‍රචාරණ ආකාරය
void effect_5() {
  // Multiple wave propagation cycles | බහු රළ ප්‍රචාරණ චක්‍ර
  for(int pin = 13; pin >= 2; pin--) {
    digitalWrite(pin, HIGH);
    delay(t1);
    digitalWrite(pin+1, LOW);
    delay(t1);
  }
  
  for(int pin = 13; pin >= 2; pin--) {
    digitalWrite(pin+1, HIGH);
    delay(t1);
    digitalWrite(pin+2, LOW);
    delay(t1);
  }
  
  for(int pin = 13; pin >= 2; pin--) {
    digitalWrite(pin+2, HIGH);
    delay(t1);
    digitalWrite(pin+3, LOW);
    delay(t1);
  }
  
  for(int pin = 13; pin >= 2; pin--) {
    digitalWrite(pin+3, HIGH);
    delay(t1);
    digitalWrite(pin+4, LOW);
    delay(t1);
  }
  
  for(int pin = 13; pin >= 2; pin--) {
    digitalWrite(pin+4, HIGH);
    delay(t1);
    digitalWrite(pin+5, LOW);
    delay(t1);
  }
  
  for(int pin = 13; pin >= 2; pin--) {
    digitalWrite(pin+5, HIGH);
    delay(t1);
    digitalWrite(pin+6, LOW);
    delay(t1);
  }
  
  for(int pin = 13; pin >= 2; pin--) {
    digitalWrite(pin+6, HIGH);
    delay(t1);
    digitalWrite(pin+7, LOW);
    delay(t1);
  }
  
  for(int pin = 13; pin >= 2; pin--) {
    digitalWrite(pin+7, HIGH);
    delay(t1);
    digitalWrite(pin+8, LOW);
    delay(t1);
  }
  
  for(int pin = 9; pin >= 2; pin--) {
    digitalWrite(pin+8, HIGH);
    delay(t1);
    digitalWrite(pin+9, LOW);
    delay(t1);
  }
  
  for(int pin = 9; pin >= 2; pin--) {
    digitalWrite(pin+9, HIGH);
    delay(t1);
    digitalWrite(pin+10, LOW);
    delay(t1);
  }
  
  for(int pin = 9; pin >= 2; pin--) {
    digitalWrite(pin+10, HIGH);
    delay(t1);
    digitalWrite(pin+11, LOW);
    delay(t1);
  }
  
  // Final wave propagation | අවසාන රළ ප්‍රචාරණය
  for(int pin = 14; pin >= 2; pin--) {
    digitalWrite(pin+11, HIGH);
    delay(t1);
  }
  
  // Turn off all LEDs | සියලුම LED නිවා දමන්න
  for(int pin = 13; pin >= 2; pin--) {
    digitalWrite(pin, LOW);
    delay(t1);
  }
}

// Effect 6: Complex flashing and chasing pattern | ආකාරය 6: සංකීර්ණ මිණිපෙත්ත සහ පසුපස්සේ යන රටා
void effect_6() {
  // Multiple flashing patterns with different offsets | විවිධ විස්ථාපන සහිත බහු මිණිපෙත්ත රටා
  for(int j=2; j<14; j++){
    digitalWrite(j, LOW);
    delay(t);
    digitalWrite(j, HIGH);
    delay(t);
    digitalWrite(j-2, LOW);
    delay(t);
    digitalWrite(j, HIGH);
  }
  
  for(int k = 15; k>2; k--){
    digitalWrite(k, LOW);
    delay(t);
    digitalWrite(k, HIGH);
    delay(t);
    digitalWrite(k+2, LOW);
    delay(t);
    digitalWrite(k, HIGH);
  }
  
  for(int k = 2; k<14; k++){
    digitalWrite(k, LOW);
    delay(t);
    digitalWrite(k, HIGH);
    delay(t);
    digitalWrite(k-2, LOW);
    delay(t);
    digitalWrite(k, HIGH);
  }
  
  for(int k = 15; k>2; k--){
    digitalWrite(k, LOW);
    delay(t);
    digitalWrite(k, HIGH);
    delay(t);
    digitalWrite(k+4, LOW);
    delay(t);
    digitalWrite(k, HIGH);
  }
  
  for(int k = 2; k<14; k++){
    digitalWrite(k, LOW);
    delay(t);
    digitalWrite(k, HIGH);
    delay(t);
    digitalWrite(k-4, LOW);
    delay(t);
    digitalWrite(k, HIGH);
  } 
}

// Effect 7: Simple chasing effect with offset | ආකාරය 7: විස්ථාපනය සහිත සරල පසුපස්සේ යන ආකාරය
void effect_7() {
  // Chasing pattern from left to right | වමේ සිට දකුණට පසුපස්සේ යන රටා
  for(int j=2; j<14; j++){
    digitalWrite(j, HIGH);
    delay(t);
    digitalWrite(j+2, LOW);
    delay(t);
  }
  
  // Chasing pattern from right to left | දකුණේ සිට වමට පසුපස්සේ යන රටා
  for(int k = 15; k>2; k--){
    digitalWrite(k, HIGH);
    delay(t);
    digitalWrite(k+2, LOW);
    delay(t);
  }
}

// Function to switch all LEDs off | සියලුම LED නිවා දැමීමේ කාර්යය
void clear(void) {
  for (int i = 2; i <= 13; i++) {
    digitalWrite(i, LOW);
  }
}
