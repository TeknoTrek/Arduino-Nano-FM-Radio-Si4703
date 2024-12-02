#include <LiquidCrystal.h>
#include <Si4703_Breakout.h>
#include <Wire.h>

#define buton 7
#define dt_pin 9
#define clk_pin 8

int sayac = 0;
int ilk_durum;
int son_durum;
int btn_durum;

const int resetPin = 2;
const int SDIO = A4;
const int SCLK = A5;


Si4703_Breakout radio(resetPin, SDIO, SCLK);
int channel;
int volume;
char rdsBuffer[10];
LiquidCrystal lcd(12, 11, 6, 5, 4, 3);
float goster = channel / 10.;

void setup()
{

lcd.begin(16, 2);
lcd.setCursor(1,0);
lcd.print("FM ");

  pinMode (dt_pin, INPUT);
  pinMode (clk_pin, INPUT);
  pinMode (buton, INPUT);

  son_durum = digitalRead(dt_pin);

        radio.powerOn();
        radio.setVolume(14);
        channel = 937; 
        radio.setChannel(channel);

        lcd.setCursor(5,0);
        lcd.print(channel / 10.);
        lcd.print(" MHz");
        lcd.setCursor(3,1);
        lcd.print("TEKNOTREK");


}

void loop()
{
  
  ilk_durum = digitalRead(dt_pin);

  if (ilk_durum != son_durum) {

    if (digitalRead(clk_pin) != ilk_durum) {
      channel ++;

    } else {
      channel --;

    }

    //int mod = channel % 10;
    //int kanal = channel - mod;
   // Serial.print("channel: ");
    //flot goster = channel / 10.;
    //Serial.println( goster);

   // kanal = kanal /10;
   // Serial.print(kanal);
    //Serial.print(".");
   // Serial.println(mod);
    // Frequency indicator
   // lcd.setCursor(5, 0);
  //  if(frequency < 100) lcd.write(' ');
   // lcd.print(channel / 10., 1);
   // Serial.println(channel);
    lcd.clear();
    lcd.setCursor(1,0);
    lcd.print("FM ");
    lcd.setCursor(5,0);
    lcd.print(channel / 10.);
    lcd.print(" MHz");
    radio.setChannel(channel);
    lcd.setCursor(3,1);
    lcd.print("TEKNOTREK");


  }
  son_durum = ilk_durum;

    


}

