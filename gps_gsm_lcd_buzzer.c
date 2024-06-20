#include <SoftwareSerial.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4); 
#include <TinyGPS++.h>
#include <SoftwareSerial.h>
/* Create object named bt of the class SoftwareSerial */
SoftwareSerial GPS_SoftSerial(4, 5);/* (Rx, Tx) */
/* Create an object named gps of the class TinyGPSPlus */
TinyGPSPlus gps;

volatile float minutes, seconds;
volatile int degree, secs, mins;
char input[12];
int count = 0;
int buzzer = 12;
int mail=8;
int gps1 = 0;
String Lat, Lon;
String textMessage ;
int sms_status = 0;

void setup()
{
   lcd.init();                      // initialize the lcd 
  // Print a message to the LCD.
  lcd.backlight();
  pinMode(buzzer, OUTPUT);
  pinMode(mail, OUTPUT);
  pinMode(7, INPUT_PULLUP);
  digitalWrite(mail , LOW);
  Serial.begin(9600);
  Serial.print("AT+CMGF=1\r");
  delay(100);
  Serial.print("AT+CNMI=2,2,0,0,0\r");
  lcd.setCursor(3,0);
  lcd.print("welcome");
  delay(2000);
  lcd.clear();
  GPS_SoftSerial.begin(9600);
}
void loop()
{
  lcd.setCursor(0,1);
  lcd.print("    Normal");
  int botton_state = digitalRead(7);
  Serial.println(botton_state);
   smartDelay(1000); /* Generate precise delay of 1ms */
        unsigned long start;
        double lat_val, lng_val, alt_m_val;
        uint8_t hr_val, min_val, sec_val;
        bool loc_valid, alt_valid, time_valid;
        lat_val = gps.location.lat(); /* Get latitude data */
        loc_valid = gps.location.isValid(); /* Check if valid location data is available */
        lng_val = gps.location.lng(); /* Get longtitude data */
        alt_m_val = gps.altitude.meters();  /* Get altitude data in meters */
        alt_valid = gps.altitude.isValid(); /* Check if valid altitude data is available */
        hr_val = gps.time.hour(); /* Get hour */
        min_val = gps.time.minute();  /* Get minutes */
        sec_val = gps.time.second();  /* Get seconds */
        time_valid = gps.time.isValid();  /* Check if valid time data is available */
        DegMinSec(lat_val);
        DegMinSec(lng_val);
if (!loc_valid)
        {          
          gps1=0;
        }
 if (loc_valid)
        {          
          gps1=1;
        }
  if (botton_state == 0)
  {
    count += 1;
    sms_status = 0;
    //digitalWrite(buzzer , HIGH);
    digitalWrite(mail , HIGH);
    delay(1000);
    digitalWrite(buzzer , LOW);
    digitalWrite(mail , LOW);
    if (count == 5) {
      count = 0;
    }
  }
  if (count==1 && sms_status == 0) {
   digitalWrite(buzzer , HIGH);
        lcd.setCursor(0,0);
        lcd.print("sms sending");
        lcd.setCursor(0,1);
        lcd.print("  To Debjani ");
    Serial.print("\r");
    delay(1000);
    Serial.print("AT+CMGF=1\r");
    delay(1000);
    Serial.print("AT+CMGS=\"+91703XXXXXXX\"\r");
    delay(1000);
    if (gps1 == 1) {
      Serial.print("I am in Danger Debjani !!! help me .click for live location :"  "https://www.latlong.net/c/?" + String("lat") + String(lat_val) + String("&long") + String(lng_val) );
    }
    delay(1000);
    Serial.write(0x1A);
    digitalWrite(buzzer , LOW);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("sms sent");
      delay(3000);
      lcd.clear();
    sms_status = 1;
  }
  if (count==2 && sms_status == 0) {
   digitalWrite(buzzer , HIGH);
      lcd.setCursor(0,0);
      lcd.print("sms sending");
      lcd.setCursor(0,1);
      lcd.print("  To Aadya");
    Serial.print("\r");
    delay(1000);
    Serial.print("AT+CMGF=1\r");
    delay(1000);
    Serial.print("AT+CMGS=\"+91870XXXXXXX\"\r");
    delay(1000);
    if (gps1 == 1) {
      Serial.print("I am in Danger  Aadya !!! help me .click for live location :"  "https://www.latlong.net/c/?" + String("lat") + String(lat_val) + String("&long") + String(lng_val) );
    }
    delay(1000);
    Serial.write(0x1A);
    digitalWrite(buzzer , LOW);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("sms sent");
      delay(3000);
      lcd.clear();
    sms_status = 1;
  }
 if (count==3 && sms_status == 0) {
   digitalWrite(buzzer , HIGH);
      lcd.setCursor(0,0);
      lcd.print("sms sending");
      lcd.setCursor(0,1);
      lcd.print("  To Saumya");
    Serial.print("\r");
    delay(1000);
    Serial.print("AT+CMGF=1\r");
    delay(1000);
    Serial.print("AT+CMGS=\"+91700XXXXXXX\"\r");
    delay(1000);
    if (gps1 == 1) {
Serial.print("I am in Danger  Saumya !!! help me .click for live location :"  "https://www.latlong.net/c/?" + String("lat") + String(lat_val) + String("&long") + String(lng_val) );
    }
    delay(1000);
    Serial.write(0x1A);

    digitalWrite(buzzer , LOW);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("sms sent");
      delay(3000);
      lcd.clear();
    sms_status = 1;
  } 
  if (count==4 && sms_status == 0) {
   digitalWrite(buzzer , HIGH);
      lcd.setCursor(0,0);
      lcd.print("sms sending");
      lcd.setCursor(0,1);
      lcd.print("  To Saloni");
    Serial.print("\r");
    delay(1000);
    Serial.print("AT+CMGF=1\r");
    delay(1000);
    Serial.print("AT+CMGS=\"+91882XXXXXXX\"\r");
    delay(1000);
    if (gps1 == 1) {
      Serial.print("I am in Danger  Saloni !!! help me .click for live location :"  "https://www.latlong.net/c/?" + String("lat") + String(lat_val) + String("&long") + String(lng_val) );
    }
    delay(1000);
    Serial.write(0x1A);

    digitalWrite(buzzer , LOW);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("sms sent");
      delay(3000);
      lcd.clear();
    sms_status = 1;
  }
static void smartDelay(unsigned long ms)
{
  unsigned long start = millis();
  do
  {
    while (GPS_SoftSerial.available())  /* Encode data read from GPS while data is available    on serial port */
      gps.encode(GPS_SoftSerial.read());
    /* Encode basically is used to parse the string received by the GPS and to store it in a buffer so that information can be extracted from it */
  } while (millis() - start < ms);
}

void DegMinSec( double tot_val)   /* Convert data in decimal degrees into degrees minutes seconds form */
{
  degree = (int)tot_val;
  minutes = tot_val - degree;
  seconds = 60 * minutes;
  minutes = (int)seconds;
  mins = (int)minutes;
  seconds = seconds - minutes;
  seconds = 60 * seconds;
  secs = (int)seconds;
}
