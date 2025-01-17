#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN     0    // Define GPIO 0 for RC522 reset pin
#define SS_PIN      5    // Define GPIO 5 for RC522 SS (Slave Select) pin
#define SERVO_PIN   26   // Define GPIO 26 for servo control pin

MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance

void setup() {
  Serial.begin(115200);         // Initialize serial communication
  SPI.begin();                  // Initialize SPI bus
  mfrc522.PCD_Init();           // Initialize MFRC522
  pinMode(26, OUTPUT);
}

void loop() {
  if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
    Serial.println("Card detected");
    Serial.println("Open!!!");
    for (int i = 0; i < 6; i++) { // Perform servo action 5 times
      // Rotate servo to 90 degrees
      digitalWrite(26, HIGH);
      delayMicroseconds(758);
      digitalWrite(26, LOW);
      delayMicroseconds(19500);
      
    }
    delayMicroseconds(1500);
    delay(10000);
     
    Serial.println("Close down");
    for (int i = 0; i < 6; i++) {
      // Rotate servo to 0 degrees (close position)
      digitalWrite(26, HIGH);
      delayMicroseconds(2180);
      digitalWrite(26, LOW);
      delayMicroseconds(19500);
      
      
    }  
    }
  }