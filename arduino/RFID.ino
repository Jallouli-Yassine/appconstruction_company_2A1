#include <MFRC522.h>
#include <LiquidCrystal.h>
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

MFRC522 mfrc522(SS_PIN, RST_PIN);//declaration rfid
LiquidCrystal lcd(8, 7, 4, 3, 5, 6);//declaration lcd

void setup()
{
    Serial.begin(9600);
    pinMode(LED_G, OUTPUT);
    pinMode(LED_R, OUTPUT);
    pinMode(BUZZER, OUTPUT);
    /*
    lcd.begin(16, 2);

    */
    lcd.begin(16,2);
    lcd.print("SCAN YOUR CARD..");
    SPI.begin();     // Initiate  SPI bus (lire les donne)
    mfrc522.PCD_Init();   // Initiate MFRC522
}

void loop()
{

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
        dataEmployee=Serial.readString();

        //data=Serial.read();
        if(dataEmployee!="ERROR")
        {
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("welcome");
            lcd.setCursor(0, 1);
            lcd.print(dataEmployee);
            digitalWrite(LED_G, HIGH);
            tone(BUZZER, 300);
            delay(ACCESS_DELAY);

            digitalWrite(LED_G, LOW);
            noTone(BUZZER);
            delay(3000);
            lcd.clear();
            lcd.print("SCAN YOUR CARD..");

        }
        else if (dataEmployee=="ERROR")
        {
            lcd.clear();
            lcd.setCursor(0, 0);

            lcd.print("employee n'existe pas");
            for (int positionCounter = 0; positionCounter < 24; positionCounter++)
            {
                // scroll one position right:
                lcd.scrollDisplayLeft();
                // wait a bit:
                delay(350);
            }
            //tone(BUZZER, 300);
            noTone(BUZZER);
            delay(3000);
            lcd.clear();
            lcd.print("SCAN YOUR CARD..");
        }
    }
}

