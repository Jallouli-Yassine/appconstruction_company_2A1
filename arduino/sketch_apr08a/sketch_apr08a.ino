#include <MFRC522.h>
#include <LiquidCrystal.h>
#define contrast 8
String dataEmployee;
char data;
int i;
#define LED_G 2 //define green LED pin
#define LED_R 3 
#define BUZZER 4 //buzzer pin
#define ACCESS_DELAY 2000
#define DENIED_DELAY 1000
int nb_tours = 0;
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);
LiquidCrystal lcd(5, 6, 7, 8, 11, 12);

void setup() {
  Serial.begin(9600);
  pinMode(contrast, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_R, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  digitalWrite(contrast, LOW);
  /*
  lcd.begin(16, 2);

  */
  lcd.begin(16,2);
  SPI.begin();     // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
}

void loop() {
  /*
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("Put your card ");
  lcd.setCursor(5, 1);
  */
  //delay(300);


  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent())
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial())
  {
    return;
  }

  String content = "";
  String msg = "";
  byte letter;

  for (byte i = 0; i < mfrc522.uid.size; i++)
  {
    /*Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
      Serial.print(mfrc522.uid.uidByte[i], HEX);*/
    content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? "0" : ""));
    content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }


  content.toUpperCase();

  msg = content + "#";
  //send data
  //delay (5000);

  for (i = 0; i < msg.length(); i++)
  {
    Serial.write(msg[i]);
    delay (100);
  }

    if (Serial.available() > 0)
  {
      //dataEmployee=Serial.readString();
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print(dataEmployee);
      data=Serial.read();
  if(data=='1')
    {
  lcd.setCursor(0, 0);
  lcd.print("Welcome!!");
    digitalWrite(LED_G, HIGH);
    tone(BUZZER, 300);
    delay(ACCESS_DELAY);
    digitalWrite(LED_G, LOW);
    noTone(BUZZER);
    }else if (data=='0')
    {
        lcd.setCursor(0, 0);
  lcd.print("error!!");
    digitalWrite(LED_R, HIGH);
    tone(BUZZER, 300);
    delay(ACCESS_DELAY);
    digitalWrite(LED_R, LOW);
    noTone(BUZZER);
    }
    
    //data_qt = Serial.readString();
    //lcd.clear();
/*
    lcd.setCursor(0, 1);
    lcd.print(data_qt);
    */
    //delay(800);
    /*
    for (int positionCounter = 0; positionCounter < 40; positionCounter++)
    {
      //lcd.scrollDisplayLeft();
      delay(250);
      if (positionCounter == 39 && nb_tours != 3)
      {
        positionCounter = 0;
        nb_tours++;
      }
      
      if (nb_tours == 2)
      {
        //lcd.clear();
        positionCounter = 40;
      }
    }
*/
  }

  
  //delay (1500);
  //recieve qt data
  /*
  if (Serial.available() > 0)
  {
   data_qt = Serial.read();

    
    lcd.clear();
    lcd.print(data_qt);
    
  }*/
}
