#include "FastLED.h"

FASTLED_USING_NAMESPACE

#if defined(FASTLED_VERSION) && (FASTLED_VERSION < 3001000)
#warning "Requires FastLED 3.1 or later; check github for latest code."
#endif

//#define FASTLED_FORCE_SOFTWARE_SPI
#define DEBUG_PIN   33

#define DATA_PIN    4
//#define CLK_PIN   13
#define LED_TYPE    WS2812
#define COLOR_ORDER GRB
#define NUM_LEDS    72
CRGB leds[NUM_LEDS];

#define BRIGHTNESS         31

long summation = 0;
int praw = 0;
int pref = 0;
float s = 2;


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


// List of patterns to cycle through.  Each is defined as a separate function below.

//-----   -----  -----    -----    |  |-----
//|      |      |        |         |  |
//|      |      |        |         |  |
//-----  |       -----    -----    |  |-----
//|      |      |              |   |  |     |
//|      |      |              |   |  |     |
//-----   -----  -----   -----     |  |-----

  
void loop()
{
  FastLED.clearData();

  pref = 2;
  praw = (analogRead(36)-1815);    
  summation = summation + praw;                                                            
// E
  if(summation < 10000*s)
  {
    for( int f = 0; f < NUM_LEDS; f++)
    {
      leds[f]|=CRGB(255,0,0);
    }
  }
  if(10000*s < summation && summation < 50000*s)
  {
      leds[1]|=CRGB(255,0,0);
      leds[2]|=CRGB(255,0,0);
      leds[3]|=CRGB(255,0,0);
      leds[34]|=CRGB(255,0,0);
      leds[35]|=CRGB(255,0,0);
      leds[36]|=CRGB(255,0,0);
      leds[67]|=CRGB(255,0,0);
      leds[68]|=CRGB(255,0,0);
      leds[69]|=CRGB(255,0,0);
  }

// C
  if(60000*s < summation && summation < 70000*s)
  {
    for( int f = 0; f < NUM_LEDS; f++)
    {
      leds[f]|=CRGB(0,255,0);
    }
  }

  if(70000*s < summation && summation < 110000*s)
  {
      leds[1]|=CRGB(0,255,0);
      leds[2]|=CRGB(0,255,0);
      leds[3]|=CRGB(0,255,0);
      leds[67]|=CRGB(0,255,0);
      leds[68]|=CRGB(0,255,0);
      leds[69]|=CRGB(0,255,0); 
  }

// E 
  if(120000*s < summation && summation < 130000*s)
  {
    for( int f = 0; f < NUM_LEDS; f++)
    {
      leds[f]|=CRGB(0,0,255);
    }
  }

  if(130000*s < summation && summation < 170000*s)
  {
      leds[1]|=CRGB(0,0,255);
      leds[2]|=CRGB(0,0,255);
      leds[3]|=CRGB(0,0,255);
      leds[34]|=CRGB(0,0,255);
      leds[35]|=CRGB(0,0,255);
      leds[36]|=CRGB(0,0,255);
      leds[67]|=CRGB(0,0,255);
      leds[68]|=CRGB(0,0,255);
      leds[69]|=CRGB(0,0,255); 
  }

// 5
  if(180000*s < summation && summation < 190000*s)
  {
    for( int f = 35; f < NUM_LEDS; f++)
    {
      leds[f]|=CRGB(75,0,75);
    }
      leds[1]|=CRGB(75,0,75);
      leds[2]|=CRGB(75,0,75);
      leds[3]|=CRGB(75,0,75);
  }

  if(190000*s < summation && summation < 220000*s)
  {
      leds[1]|=CRGB(75,0,75);
      leds[2]|=CRGB(75,0,75);
      leds[3]|=CRGB(75,0,75);
      leds[34]|=CRGB(75,0,75);
      leds[35]|=CRGB(75,0,75);
      leds[36]|=CRGB(75,0,75);
      leds[67]|=CRGB(75,0,75);
      leds[68]|=CRGB(75,0,75);
      leds[69]|=CRGB(75,0,75); 
  }

  if(220000*s < summation && summation < 230000*s)
  {
    for( int f = 0; f < 35; f++)
    {
      leds[f]|=CRGB(75,0,75);
    }
      leds[67]|=CRGB(75,0,75);
      leds[68]|=CRGB(75,0,75);
      leds[69]|=CRGB(75,0,75); 
  }

// 1
  if(240000*s < summation && summation < 250000*s)
  {
    for( int f = 0; f < NUM_LEDS; f++)
    {
      leds[f]|=CRGB(0,75,75);
    }
  }

// 6 
  if(260000*s < summation && summation < 270000*s)
  {
    for( int f = 0; f < NUM_LEDS; f++)
    {
      leds[f]|=CRGB(75,75,0);
    }
      leds[1]|=CRGB(75,75,0);
      leds[2]|=CRGB(75,75,0);
      leds[3]|=CRGB(75,75,0);
  }

  if(270000*s < summation && summation < 300000*s)
  {
      leds[1]|=CRGB(75,75,0);
      leds[2]|=CRGB(75,75,0);
      leds[3]|=CRGB(75,75,0);
      leds[34]|=CRGB(75,75,0);
      leds[35]|=CRGB(75,75,0);
      leds[36]|=CRGB(75,75,0);
      leds[67]|=CRGB(75,75,0);
      leds[68]|=CRGB(75,75,0);
      leds[69]|=CRGB(75,75,0); 
  }

  if(300000*s < summation && summation < 310000*s)
  {
    for( int f = 0; f < 35; f++)
    {
      leds[f]|=CRGB(75,75,0);
    }
      leds[67]|=CRGB(75,75,0);
      leds[68]|=CRGB(75,75,0);
      leds[69]|=CRGB(75,75,0); 
  }

  
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
Serial.print(praw);  
Serial.print("\n");
}

  
}
