#include <FastLED.h>

#define LED_PIN     8     //我的LED信号线IN接在8引脚
#define NUM_LEDS    60    //我的灯带一共级联了12颗LED
CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(20);  //可以设置全局亮度，调低亮度不刺眼
}

int h = 0;

void loop() {
  for(int i=0;i<10;i++){
    for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CHSV( h, 255, 255); //用HSV色彩空间，不断改变H即可
    FastLED.show();
    }
    delay(2);
    h = (h + 20) % 255;
    }

  for(int i=0;i<10;i++){
    for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CHSV( (h + (255 / NUM_LEDS) * i), 255, 255); //用HSV色彩空间，不断改变H即可
    FastLED.show();
    }
    delay(2);
    h = (h + 3) % 255;
    }

  for(int i=0;i<19;i++){
    for(int i=0;i<NUM_LEDS;i++){
      leds[i] = CHSV( (h + (255 / NUM_LEDS) * i), 255, 255);
      FastLED.show();
      }
      delay(100);
     for(int i=0;i<NUM_LEDS;i++){ 
      // 显示一下黑色，黑色就是熄灭
      leds[i] = CRGB::Black;
      FastLED.show();
     }
     delay(100);
     h = (h + 3) % 255;
    }


  for(int i=0;i<20;i++){
    for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CHSV( h, 255, 255); //用HSV色彩空间，不断改变H即可
    FastLED.show();
    }
    delay(2);
    h = (h + 3) % 255;

    for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CHSV( (h + (255 / NUM_LEDS) * i), 255, 255); //用HSV色彩空间，不断改变H即可
    FastLED.show();
    }
    delay(2);
    h = (h + 3) % 255;
    }

  for(int i=0;i<10;i++){
    for(int i=0;i<NUM_LEDS;i++){
      leds[i] = CHSV(h , 255, 255);
      }
      FastLED.show();
      delay(100);
     for(int i=0;i<NUM_LEDS;i++){ 
      // 显示一下黑色，黑色就是熄灭
      leds[i] = CRGB::Black;
      FastLED.show();
     }
     delay(100);
     h = (h + 20) % 255;
    }
}
