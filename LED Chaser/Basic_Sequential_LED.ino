// LED pins definition | LED පින් අර්ථ දැක්වීම
int LED1 = 2;
int LED2 = 3;
int LED3 = 4;
int LED4 = 5;
int LED5 = 6;
int LED6 = 7;
int LED7 = 8;
int LED8 = 9;
int LED9 = 10;
int LED10 = 11;
int LED11 = 12;
int LED12 = 13;
int t=30; // Delay time in milliseconds | ප්‍රමාද කාලය මිලිතත්වලින්



void setup() {
   // Set all LED pins as OUTPUT | සියලු LED පින් OUTPUT ලෙස සකසන්න
   pinMode(LED1, OUTPUT);
   pinMode(LED2, OUTPUT);
   pinMode(LED3, OUTPUT);
   pinMode(LED4, OUTPUT);
   pinMode(LED5, OUTPUT);
   pinMode(LED6, OUTPUT);
   pinMode(LED7, OUTPUT);
   pinMode(LED8, OUTPUT);
   pinMode(LED9, OUTPUT);
   pinMode(LED10, OUTPUT);
   pinMode(LED11, OUTPUT);
   pinMode(LED12, OUTPUT);
    
}

void loop(){
// First pattern: Turn on LEDs one by one from right to left (LED12 to LED1) | පළමු නිරූපණය: LED එකින් එක දකුණේ සිට වමට (LED12 සිට LED1 දක්වා) අලුත් කරන්න
  digitalWrite(LED12, HIGH);    
  delay(t);                 
  digitalWrite(LED11, HIGH);    
  delay(t);                  
  digitalWrite(LED10, HIGH); 
  delay(t);                 
  digitalWrite(LED9, HIGH);  
  delay(t);                  
  digitalWrite(LED8, HIGH);    
  delay(t);                 
  digitalWrite(LED7, HIGH);    
  delay(t);                 
  digitalWrite(LED6, HIGH);  
  delay(t);               
  digitalWrite(LED5, HIGH); 
  delay(t);  
  digitalWrite(LED4, HIGH);    
  delay(t);
  digitalWrite(LED3, HIGH);    
  delay(t);
  digitalWrite(LED2, HIGH);    
  delay(t);
  digitalWrite(LED1, HIGH);    
  delay(t);
   
// Turn off LEDs one by one from right to left (LED12 to LED1) | LED එකින් එක දකුණේ සිට වමට (LED12 සිට LED1 දක්වා) නිවා දමන්න                  
  digitalWrite(LED12, LOW);    
  delay(t);                
  digitalWrite(LED11, LOW);    
  delay(t);                  
  digitalWrite(LED10, LOW);   
  delay(t);               
  digitalWrite(LED9, LOW);     
  delay(t);               
  digitalWrite(LED8, LOW);  
  delay(t);                 
  digitalWrite(LED7, LOW);  
  delay(t);                  
  digitalWrite(LED6, LOW);     
  delay(t);                  
  digitalWrite(LED5, LOW);   
  delay(t); 
  digitalWrite(LED4, LOW);    
  delay(t);
  digitalWrite(LED3, LOW);    
  delay(t);
  digitalWrite(LED2, LOW);    
  delay(t);
  digitalWrite(LED1, LOW);    
  delay(t);

// Second pattern: Turn on LEDs one by one from left to right (LED1 to LED12) | දෙවන නිරූපණය: LED එකින් එක වමේ සිට දකුණට (LED1 සිට LED12 දක්වා) අලුත් කරන්න
  digitalWrite(LED1, HIGH);    
  delay(t); 
  digitalWrite(LED2, HIGH);    
  delay(t); 
  digitalWrite(LED3, HIGH);    
  delay(t); 
  digitalWrite(LED4, HIGH);    
  delay(t); 
  digitalWrite(LED5, HIGH); 
  delay(t);
  digitalWrite(LED6, HIGH);  
  delay(t);
  digitalWrite(LED7, HIGH);  
  delay(t);
  digitalWrite(LED8, HIGH);  
  delay(t);
  digitalWrite(LED9, HIGH);  
  delay(t);
  digitalWrite(LED10, HIGH);  
  delay(t);
  digitalWrite(LED11, HIGH);  
  delay(t);
  digitalWrite(LED12, HIGH);  
  delay(t);
  
// Turn off LEDs one by one from left to right (LED1 to LED12) | LED එකින් එක වමේ සිට දකුණට (LED1 සිට LED12 දක්වා) නිවා දමන්න
  digitalWrite(LED1, LOW);    
  delay(t);
  digitalWrite(LED2, LOW);    
  delay(t);
  digitalWrite(LED3, LOW);    
  delay(t);   
  digitalWrite(LED4, LOW);    
  delay(t);
  digitalWrite(LED5, LOW);    
  delay(t);
  digitalWrite(LED6, LOW);    
  delay(t);
  digitalWrite(LED7, LOW);    
  delay(t);
  digitalWrite(LED8, LOW);    
  delay(t);
  digitalWrite(LED9, LOW);    
  delay(t);
  digitalWrite(LED10, LOW);    
  delay(t);
  digitalWrite(LED11, LOW);    
  delay(t);
  digitalWrite(LED12, LOW);    
  delay(t);

// Repeat the first pattern (right to left) | පළමු නිරූපණය නැවත කරන්න (දකුණේ සිට වමට)
  digitalWrite(LED12, HIGH);    
  delay(t);                 
  digitalWrite(LED11, HIGH);    
  delay(t);                  
  digitalWrite(LED10, HIGH); 
  delay(t);                 
  digitalWrite(LED9, HIGH);  
  delay(t);                  
  digitalWrite(LED8, HIGH);    
  delay(t);                 
  digitalWrite(LED7, HIGH);    
  delay(t);                 
  digitalWrite(LED6, HIGH);  
  delay(t);               
  digitalWrite(LED5, HIGH); 
  delay(t);  
  digitalWrite(LED4, HIGH);    
  delay(t);
  digitalWrite(LED3, HIGH);    
  delay(t);
  digitalWrite(LED2, HIGH);    
  delay(t);
  digitalWrite(LED1, HIGH);    
  delay(t);
   
                    
  digitalWrite(LED12, LOW);    
  delay(t);                
  digitalWrite(LED11, LOW);    
  delay(t);                  
  digitalWrite(LED10, LOW);   
  delay(t);               
  digitalWrite(LED9, LOW);     
  delay(t);               
  digitalWrite(LED8, LOW);  
  delay(t);                 
  digitalWrite(LED7, LOW);  
  delay(t);                  
  digitalWrite(LED6, LOW);     
  delay(t);                  
  digitalWrite(LED5, LOW);   
  delay(t); 
  digitalWrite(LED4, LOW);    
  delay(t);
  digitalWrite(LED3, LOW);    
  delay(t);
  digitalWrite(LED2, LOW);    
  delay(t);
  digitalWrite(LED1, LOW);    
  delay(t);

// Repeat the second pattern (left to right) | දෙවන නිරූපණය නැවත කරන්න (වමේ සිට දකුණට)
  digitalWrite(LED1, HIGH);    
  delay(t);
  digitalWrite(LED2, HIGH);    
  delay(t);
  digitalWrite(LED3, HIGH);    
  delay(t);
  digitalWrite(LED4, HIGH);    
  delay(t); 
  digitalWrite(LED5, HIGH); 
  delay(t);
  digitalWrite(LED6, HIGH);  
  delay(t);
  digitalWrite(LED7, HIGH);  
  delay(t);
  digitalWrite(LED8, HIGH);  
  delay(t);
  digitalWrite(LED9, HIGH);  
  delay(t);
  digitalWrite(LED10, HIGH);  
  delay(t);
  digitalWrite(LED11, HIGH);  
  delay(t);
  digitalWrite(LED12, HIGH);  
  delay(t);

// Turn off LEDs left to right again | LED නැවත වමේ සිට දකුණට නිවා දමන්න
  digitalWrite(LED1, LOW);    
  delay(t);
  digitalWrite(LED2, LOW);    
  delay(t);
  digitalWrite(LED3, LOW);    
  delay(t);  
  digitalWrite(LED4, LOW);    
  delay(t);
  digitalWrite(LED5, LOW);    
  delay(t);
  digitalWrite(LED6, LOW);    
  delay(t);
  digitalWrite(LED7, LOW);    
  delay(t);
  digitalWrite(LED8, LOW);    
  delay(t);
  digitalWrite(LED9, LOW);    
  delay(t);
  digitalWrite(LED10, LOW);    
  delay(t);
  digitalWrite(LED11, LOW);    
  delay(t);
  digitalWrite(LED12, LOW);    
  delay(t);

// Final repetition of first pattern (right to left) | පළමු නිරූපණය අවසන් වතාවට නැවත කරන්න (දකුණේ සිට වමට)
  digitalWrite(LED12, HIGH);    
  delay(t);                 
  digitalWrite(LED11, HIGH);    
  delay(t);                  
  digitalWrite(LED10, HIGH); 
  delay(t);                 
  digitalWrite(LED9, HIGH);  
  delay(t);                  
  digitalWrite(LED8, HIGH);    
  delay(t);                 
  digitalWrite(LED7, HIGH);    
  delay(t);                 
  digitalWrite(LED6, HIGH);  
  delay(t);               
  digitalWrite(LED5, HIGH); 
  delay(t);  
  digitalWrite(LED4, HIGH);    
  delay(t);
  digitalWrite(LED3, HIGH);    
  delay(t);
  digitalWrite(LED2, HIGH);    
  delay(t);
  digitalWrite(LED1, HIGH);    
  delay(t);
   
                    
  digitalWrite(LED12, LOW);    
  delay(t);                
  digitalWrite(LED11, LOW);    
  delay(t);                  
  digitalWrite(LED10, LOW);   
  delay(t);               
  digitalWrite(LED9, LOW);     
  delay(t);               
  digitalWrite(LED8, LOW);  
  delay(t);                 
  digitalWrite(LED7, LOW);  
  delay(t);                  
  digitalWrite(LED6, LOW);     
  delay(t);                  
  digitalWrite(LED5, LOW);   
  delay(t); 
  digitalWrite(LED4, LOW);    
  delay(t);
  digitalWrite(LED3, LOW);    
  delay(t);
  digitalWrite(LED2, LOW);    
  delay(t);
  digitalWrite(LED1, LOW);    
  delay(t);

// Final repetition of second pattern (left to right) | දෙවන නිරූපණය අවසන් වතාවට නැවත කරන්න (වමේ සිට දකුණට)
  digitalWrite(LED1, HIGH);    
  delay(t); 
  digitalWrite(LED2, HIGH);    
  delay(t); 
  digitalWrite(LED3, HIGH);    
  delay(t); 
  digitalWrite(LED4, HIGH);    
  delay(t); 
  digitalWrite(LED5, HIGH); 
  delay(t);
  digitalWrite(LED6, HIGH);  
  delay(t);
  digitalWrite(LED7, HIGH);  
  delay(t);
  digitalWrite(LED8, HIGH);  
  delay(t);
  digitalWrite(LED9, HIGH);  
  delay(t);
  digitalWrite(LED10, HIGH);  
  delay(t);
  digitalWrite(LED11, HIGH);  
  delay(t);
  digitalWrite(LED12, HIGH);  
  delay(t);

// Turn off all LEDs to complete the cycle | සියලු LED නිවා දමා චක්‍රය සම්පූර්ණ කරන්න
  digitalWrite(LED1, LOW);    
  delay(t);
  digitalWrite(LED2, LOW);    
  delay(t);
  digitalWrite(LED3, LOW);    
  delay(t);
  digitalWrite(LED4, LOW);    
  delay(t);
  digitalWrite(LED5, LOW);    
  delay(t);
  digitalWrite(LED6, LOW);    
  delay(t);
  digitalWrite(LED7, LOW);    
  delay(t);
  digitalWrite(LED8, LOW);    
  delay(t);
  digitalWrite(LED9, LOW);    
  delay(t);
  digitalWrite(LED10, LOW);    
  delay(t);
  digitalWrite(LED11, LOW);    
  delay(t);
  digitalWrite(LED12, LOW);    
  delay(t);}
