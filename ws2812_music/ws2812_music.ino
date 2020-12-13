#include <FastLED.h>

#define LED_PIN     8     //我的LED信号线IN接在8引脚
#define NUM_LEDS    60    //我的灯带一共级联了12颗LED
CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(20);  //可以设置全局亮度，调低亮度不刺眼
}

void loop(){
  for( int colorStep=0; colorStep<256; colorStep++ ) {

      int g = colorStep; //Redness starts at zero and goes up to full
      int r = 255-colorStep; //Blue starts at full and goes down to zero
      int b = 255;             //No green needed to go from blue to red

     //Now loop though each of the LEDs and set each one to the current color

      for(int x = 0; x < NUM_LEDS; x++){
          leds[x] = CRGB(r,g,b);
      }


      FastLED.show();

      delay(10); 
  }
  
  for( int colorStep=0; colorStep<256; colorStep++ ) {

      int r = colorStep; //Redness starts at zero and goes up to full
      int g = 255-colorStep; //Blue starts at full and goes down to zero
      int b = 255;             //No green needed to go from blue to red

     //Now loop though each of the LEDs and set each one to the current color

      for(int x = 0; x < NUM_LEDS; x++){
          leds[x] = CRGB(r,g,b);
      }


      FastLED.show();

      delay(10); 
   }

  for(int i=0;i<60;i++){
    leds[i]=CRGB(255,0,255);
  }
  FastLED.show();
  delay(10000000000000);
}
