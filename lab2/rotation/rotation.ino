#include "FastLED.h"

FASTLED_USING_NAMESPACE

#if defined(FASTLED_VERSION) && (FASTLED_VERSION < 3001000)
#warning "Requires FastLED 3.1 or later; check github for latest code."
#endif

//#define FASTLED_FORCE_SOFTWARE_SPI
#define DEBUG_PIN   33

#define DATA_PIN    4
#define LED_TYPE    WS2812
#define COLOR_ORDER GRB
#define NUM_LEDS    72
CRGB leds[NUM_LEDS];

#define BRIGHTNESS         21

int pa = 0;
int pal = 0;
int paraw = 0;


boolean debugon = 1;
boolean drawgrat = 1;

uint8_t gHue = 0; // rotating "base color" used by many of the patterns

void setup() 
{
  delay(1000); // 3 second delay for recovery

  pinMode(DEBUG_PIN, OUTPUT);  //set debug pin as output
  
  
  Serial.begin(115200);
  // tell FastLED about the LED strip configuration
  //FastLED.addLeds<LED_TYPE,DATA_PIN,COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  //FastLED.addLeds<LED_TYPE,DATA_PIN,CLK_PIN,COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  //FastLED.addLeds<APA102,11,13,RGB,DATA_RATE_MHZ(16)>(leds,NUM_LEDS);  //10
  // set master brightness control
  FastLED.addLeds<WS2812,DATA_PIN,COLOR_ORDER>(leds,NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);

}

 
void loop()
{
  FastLED.clearData();


  pal = 35;
  
  paraw = (analogRead(36)-1840)*10;                                                                     

  pa = map (paraw, -2048, 2047,0,NUM_LEDS);
  
  if(pa > (NUM_LEDS - 1)) {pa=(NUM_LEDS - 1);}  if  (pa < 0) {pa = 0;}

  if(pa == pal){leds[pa]|=CRGB(255,0,0);}

  leds[pa-1] = CRGB(75,0,75);
  leds[pa] = CRGB(75,0,75);
  leds[pa+1] = CRGB(75,0,75);


if (drawgrat)
{
  for (int g =0; g < 72; g=g+11) 
  {
      leds[g+2]|=CRGB(0,75,75); // center the grat
  }
  
}

  FastLED.show();  


if (debugon)
{
Serial.print(paraw);
Serial.print("\n");
}

  
}
