#include<FastLED.h>
#define NUM_LEDS 12  //number of led for each strip
#define COLOR_ORDER GRB
#define LED_TYPE    WS2812B
#define BRIGHTNESS 25   //fastled brightness
#define LED_PIN 13   //first led pin
#define LED_PIN1 12
#define LED_PIN2 11
#define LED_PIN3 10
#define LED_PIN4 9
#define LED_PIN5 8
#define LED_PIN6 7
#define LED_PIN7 6
#define LED_PIN8 5
#define LED_PIN9 4
#define LED_PIN10 3
#define LED_PIN11 2   //last led pin

CRGB leds[NUM_LEDS];
CRGB leds1[NUM_LEDS];
CRGB leds2[NUM_LEDS];
CRGB leds3[NUM_LEDS];
CRGB leds4[NUM_LEDS];
CRGB leds5[NUM_LEDS];
CRGB leds6[NUM_LEDS];
CRGB leds7[NUM_LEDS];
CRGB leds8[NUM_LEDS];
CRGB leds9[NUM_LEDS];
CRGB leds10[NUM_LEDS];
CRGB leds11[NUM_LEDS];

int inByte = 0;         
int led[26];
int leddi[26];

void setup()
{
  Serial.begin(125000);
 FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);
 FastLED.addLeds<LED_TYPE, LED_PIN1, COLOR_ORDER>(leds1, NUM_LEDS);
 FastLED.addLeds<LED_TYPE, LED_PIN2, COLOR_ORDER>(leds2, NUM_LEDS);
 FastLED.addLeds<LED_TYPE, LED_PIN3, COLOR_ORDER>(leds3, NUM_LEDS);
 FastLED.addLeds<LED_TYPE, LED_PIN4, COLOR_ORDER>(leds4, NUM_LEDS);
 FastLED.addLeds<LED_TYPE, LED_PIN5, COLOR_ORDER>(leds5, NUM_LEDS);
 FastLED.addLeds<LED_TYPE, LED_PIN6, COLOR_ORDER>(leds6, NUM_LEDS);
 FastLED.addLeds<LED_TYPE, LED_PIN7, COLOR_ORDER>(leds7, NUM_LEDS);
 FastLED.addLeds<LED_TYPE, LED_PIN8, COLOR_ORDER>(leds8, NUM_LEDS);
 FastLED.addLeds<LED_TYPE, LED_PIN9, COLOR_ORDER>(leds9, NUM_LEDS);
 FastLED.addLeds<LED_TYPE, LED_PIN10, COLOR_ORDER>(leds10, NUM_LEDS);
 FastLED.addLeds<LED_TYPE, LED_PIN11, COLOR_ORDER>(leds11, NUM_LEDS);
 
FastLED.setBrightness(BRIGHTNESS);
}

void loop()
{
  while (Serial.available() > 0) {
    int value  = Serial.parseInt();
    char cc =  Serial.read();
    if (cc == 'a') {
      led[0], value ;
    }
    if (cc == 'b') {
      led[1]= value ;
    }
    if (cc == 'c') {
      led[2]= value ;
    }
    if (cc == 'd') {
      led[3]= value ;
    }
    if (cc == 'e') {
      led[4]= value ;
    }
    if (cc == 'f') {
      led[5]= value ;
    }
    if (cc == 'g') {
      led[6]= value ;
    }
    if (cc == 'h') {
      led[7]=value ;
    }
    if (cc == 'i') {
      led[8]=value;
    }
    if (cc == 'y') {
      led[9]=value;
    }
    if (cc == 'k') {
      led[10]=value;
    }
    if (cc == 'l') {
      led[11]=value;
    }
    if (cc == 'm') {
      led[12]=value;
    }
   //i was using only 12 strip if u wish to use more u can go up to 26 without modification
    if (cc == 'n') { 
      led[13]=value;
    }
    if (cc == 'o') {
      led[14]=value;
    }
    if (cc == 'p') {
      led[15]=value;
    
    }
    if (cc == 'q') {
      led[16]=value;
    }
    if (cc == 'r') {
      led[17]=value;
    }
    if (cc == 's') {
      led[18]=value;
    }
    if (cc == 't') {
      led[19]=value;
    }
    if (cc == 'u') {
      led[20]=value;
    }
    if (cc == 'v') {
      led[21]=value;
    }
    if (cc == 'w') {
      led[22]=value;
    }
    if (cc == 'x') {
      led[23]=value;
    }
    if (cc == 'y') {
      led[24]=value;
    }
    if (cc == 'z') {    //if z is received switch off all the led
     // led[25]=value;
    for(int z=0;z<12;z++)
  {
    leds[z] = CRGB::Black;
    leds1[z] = CRGB::Black;
    leds2[z] = CRGB::Black;
    leds3[z] = CRGB::Black;
    leds4[z] = CRGB::Black;
    leds5[z] = CRGB::Black;
    leds6[z] = CRGB::Black;
    leds7[z] = CRGB::Black;
    leds8[z] = CRGB::Black;
    leds9[z] = CRGB::Black;
    leds10[z] = CRGB::Black;
    leds11[z] = CRGB::Black;
  }
    
    }
  
  
  }
scrivi();
}


void scrivi()
{
  for(int z=0;z<12;z++)
  {
    leds[z] = CRGB::Black;
    leds1[z] = CRGB::Black;
    leds2[z] = CRGB::Black;
    leds3[z] = CRGB::Black;
    leds4[z] = CRGB::Black;
    leds5[z] = CRGB::Black;
    leds6[z] = CRGB::Black;
    leds7[z] = CRGB::Black;
    leds8[z] = CRGB::Black;
    leds9[z] = CRGB::Black;
    leds10[z] = CRGB::Black;
    leds11[z] = CRGB::Black;
  }
  fill_rainbow( leds,  led[1], 0, 15);
  fill_rainbow( leds1, led[2], 0, 15);
  fill_rainbow( leds2, led[3], 0, 15);
  fill_rainbow( leds3, led[4], 0, 15);
  fill_rainbow( leds4, led[5], 0, 15);
  fill_rainbow( leds5, led[6], 0, 15);
  fill_rainbow( leds6, led[7], 0, 15);
  fill_rainbow( leds7, led[8], 0, 15);
  fill_rainbow( leds8, led[9], 0, 15);
  fill_rainbow( leds9, led[10], 0, 15);
  fill_rainbow( leds10, led[11], 0, 15);
  fill_rainbow( leds11, led[12], 0, 15);
  
  FastLED.show();
}



