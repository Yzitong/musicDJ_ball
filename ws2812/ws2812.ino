#include <ESP8266WiFi.h>   //安装esp8266arduino开发环境
#include <PubSubClient.h>
/* 依赖 PubSubClient 2.4.0 */
#include <ArduinoJson.h>
/* 依赖 ArduinoJson 5.13.4 */
#include<FastLED.h>
#define LED_PIN     8     //我的LED信号线IN接在8引脚
#define NUM_LEDS    60    //我的灯带一共级联了60颗LED
CRGB leds[NUM_LEDS];


/* 连接您的WIFI SSID和密码 */
#define WIFI_SSID        "wic300"//替换自己的WIFI
#define WIFI_PASSWD      "yzt100200"//替换自己的WIFI

/* 设备证书信息*/
#define PRODUCT_KEY       "a1G1JgufHHA"
#define DEVICE_NAME       "esp8266"
#define DEVICE_SECRET     "90b3bd15e34f6a5f5280ace853272fa3"
#define REGION_ID         "cn-shanghai"

/* 线上环境域名和端口号，不需要改 */
#define MQTT_SERVER       PRODUCT_KEY ".iot-as-mqtt." REGION_ID ".aliyuncs.com"
#define MQTT_PORT         1883
#define MQTT_USRNAME      DEVICE_NAME "&" PRODUCT_KEY

#define CLIENT_ID         "9FFD35BC-8FBB-44CC-A2F9-BB565EF29617"|securemode=3,signmethod=hmacsha1,timestamp=132323232|"
// 请使用以上说明中的加密工具或参见MQTT-TCP连接通信文档加密生成password。
// 加密明文是参数和对应的值（clientIdesp8266deviceName${deviceName}productKey${productKey}timestamp1234567890）按字典顺序拼接
// 密钥是设备的DeviceSecret
#define MQTT_PASSWD       "90b3bd15e34f6a5f5280ace853272fa3"

unsigned long lastMs = 0;
int r=0;
int g=0;
int b=0;
WiFiClient espClient;
PubSubClient  client(espClient);

void callback(char *topic, byte *payload, unsigned int length)
{
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  char message[400];
  message[length]='\0';
  for (int i=0;i<length;i++) {
    Serial.print((char)payload[i]);
    message[i]=(char)payload[i];// 串口打印订阅信息
  }

  StaticJsonBuffer<400> jsonBuffer2;
  JsonObject &root = jsonBuffer2.parseObject(message);
 
  int r_led = root["data"][0];
  int g_led = root["data"][1];
  int b_led = root["data"][2];

  r=r_led;
  g=g_led;
  b=b_led;

  Serial.println(r_led);
  Serial.println(g_led);
  Serial.println(b_led);
}

void wifiInit()
{
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASSWD);
  Serial.begin(115200);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(1000);
    Serial.println("WiFi not Connect");
  }

  Serial.println("Connected to AP");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.print("espClient [");
  client.setServer(MQTT_SERVER, MQTT_PORT);   /* 连接WiFi之后，连接MQTT服务器 */
  client.setCallback(callback);
}
/*
void mqttCheckConnect()
{
  while (!client.connected())
  {
    Serial.println("Connecting to MQTT Server ...");
    if (client.connect(CLIENT_ID, MQTT_USRNAME, MQTT_PASSWD))
    {
      Serial.println("MQTT Connected!");
    }
    else
    {
      Serial.print("MQTT Connect err:");
      Serial.println(client.state());
      delay(5000);
    }
  }
}
*/

void setup()
{
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(115200);
  Serial.println("Start");
  wifiInit();
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(20);  //可以设置全局亮度，调低亮度不刺眼
}

void loop()
{
  if (millis() - lastMs >= 5000)
  {
    lastMs = millis();
    //mqttCheckConnect();
  }

  client.loop();
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CHSV( r, g, b); //用HSV色彩空间，不断改变H即可
    FastLED.show();
  }
  delay(2);
}

