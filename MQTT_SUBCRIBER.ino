#include <ESP8266WiFi.h>
#include <PubSubClient.h>

const int ledPin = D1;
int pinTone = D2;

//const char* ssid = "Rut";
//const char* password = "OoooRuToooO";
const char* ssid = "Rut";
const char* password = "OoooRuToooO";
const char* mqtt_server = "broker.hivemq.com";
const int mqtt_port = 1883;

const int postingInterval = 1000;

long lastMsg = 0;

WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  //ไฟ
  pinMode(ledPin, OUTPUT);
  //เสียง
  pinMode(pinTone, OUTPUT);
  
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}

void setup_wifi() {
  delay(10);
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("Connected, IP address: ");
  Serial.println(WiFi.localIP());
}

void callback(char* topic, byte* payload, unsigned int length) {
  //Handle your payload here
  String msg = "";
  
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    msg += (char)payload[i];
  }
  Serial.println(msg);

  //เงื่อนไขการเปิดไฟและเสียง
  if (msg == "ON"){
     digitalWrite(ledPin,HIGH);
     
    /* analogWrite(pinTone,4186);
     delay(50);
     analogWrite(pinTone,4435);
     delay(50);*/
     analogWrite(pinTone,4186);
     delay(10);
     analogWrite(pinTone,4335);
     delay(100);
     analogWrite(pinTone,4496);
     delay(50);
     analogWrite(pinTone,4555);
     delay(100);
     analogWrite(pinTone,4666);
     delay(50);
     analogWrite(pinTone,4975);
     delay(10);
  }
  else{
    digitalWrite(ledPin,LOW);
    analogWrite(pinTone,LOW);
    }
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    
    // client.connect(".....") ต้องไม่เหมือนกัน
    if (client.connect("ESP8266Client_Light")) {
      Serial.println("connected");
      char* topic = "/iot/sks/";
      client.subscribe(topic); 
    } else
      delay(5000);
  }
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }

  client.loop();

  long now = millis();

  if (now - lastMsg > postingInterval) {
    lastMsg = now;
  }
  
  
}
