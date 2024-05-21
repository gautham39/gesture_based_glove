#include <Wire.h>
#include "rgb_lcd.h"


// FLEX SENSOR

const uint8_t flex_thumb= 25; //ADC2_CH8 of ESP32
const uint8_t flex_index= 26; //ADC2_CH9 of ESP32
const uint8_t flex_middle= 27; //ADC2_CH7 of ESP32
const uint8_t flex_ring= 14; //ADC2_CH6 of ESP32
const uint8_t flex_little= 12; //ADC2_CH5 of ESP32
int value_thumb = 0; // ADC values
int value_index = 0;
int value_middle = 0;
int value_ring= 0;
int value_little = 0;

// BUZZER 

const uint8_t buzzer = 34;

// LCD DISPLAY

rgb_lcd lcd;
const int colorR = 255;
const int colorG = 0;
const int colorB = 0;

// GSM MODULE

void setup() {
  Serial.begin(9600); // Serial monitor
  pinMode(flex_thumb,INPUT);
  pinMode(flex_index,INPUT);
  pinMode(flex_middle,INPUT);
  pinMode(flex_ring,INPUT);
  pinMode(flex_little,INPUT);
  pinMode(buzzer,OUTPUT);

  // LCD
   lcd.begin(16, 2);
   lcd.setRGB(colorR, colorG, colorB);
   lcd.setCursor(0, 0); 
   lcd.print("Smart Glove!");
   
   //GSM
   Serial2.begin(9600,SERIAL_8N1,16,17); // configuring UART2 - rx- pin 16 tx- pin 17
   //test_sim800_module();

   
   delay(1000);
  

}

void loop()
{
  value_thumb = analogRead(flex_thumb);
  Serial.println(value_thumb);
  value_index = analogRead(flex_index);
  value_middle = analogRead(flex_middle);
  value_ring = analogRead(flex_ring);
  value_little = analogRead(flex_little);
  if(500 > value_thumb > 200) // flex sensor of thumb is bent
  {
     Serial.println("I need water");
     digitalWrite(buzzer,HIGH);
     delay(500);
     digitalWrite(buzzer,LOW);
     lcd.setCursor(0, 0); // display on the LCD
     lcd.print("I need water");


  }
  else if(350 > value_index > 230) // flex sensor of index is bent
  {
    Serial.println("I need food");
    digitalWrite(buzzer,HIGH);
    delay(500);
    digitalWrite(buzzer,LOW);
    lcd.setCursor(0, 0); // display on the LCD
   // lcd.print("I need FOOD");
  }
  else if((350 >value_thumb >230)&& (350> value_index > 230) && (350> value_middle>230)&& (350> value_ring > 230)&&(350 > value_little > 230) ) // all fingers bent 
  {
     Serial.println("HELP HELP");
     //send_SMS(); //to send sms through gsm module
     lcd.setCursor(0, 0); // display on the LCD
     lcd.print("HELP HELP");
     digitalWrite(buzzer,HIGH); // Buzzer alert 
     delay(500);
     digitalWrite(buzzer,LOW);
     delay(300);
     digitalWrite(buzzer,HIGH);
     delay(500);
     digitalWrite(buzzer,LOW);
     
  }
}

void test_sim800_module()
{
  Serial2.println("AT");
  updateSerial();
  Serial.println();
  Serial2.println("AT+CSQ");
  updateSerial();
  Serial2.println("AT+CCID");
  updateSerial();
  Serial2.println("AT+CREG?");
  updateSerial();
  Serial2.println("ATI");
  updateSerial();
  Serial2.println("AT+CBC");
  updateSerial();
}

void updateSerial()
{
  delay(500);
  while (Serial2.available())
  {
    Serial.write(Serial2.read());//Forward what Software Serial received to Serial Port
  }
}

void send_SMS()
{
  Serial2.println("AT+CMGF=1"); // Configuring TEXT mode
  updateSerial();
  Serial2.println("AT+CMGS=\"+919703310867\"");//change ZZ with country code and xxxxxxxxxxx with phone number to sms
  updateSerial();
  Serial2.print("HELP HELP"); //text content
  updateSerial();
  Serial.println();
  Serial.println("Message Sent");
  Serial2.write(26);
}

