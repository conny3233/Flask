#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

// Wi-Fi 설정
const char* ssid = "your_SSID";      // Wi-Fi 이름 
const char* password = "your_PASSWORD"; // Wi-Fi 비밀번호

// LED 핀    설정
const int ledPin = 2; // GPIO 2 (D4)

ESP8266WebServer server(80);  // HTTP 서버    포트 80 
// LED를    켜는    함수
void turnOnLED() {
  digitalWrite(ledPin, HIGH);  // LED 켬
  server.send(200, "text/plain", "LED is ON"); 
}
// LED를    끄는    함수 
void turnOffLED() {
  digitalWrite(ledPin, LOW);   // LED 끔
  server.send(200, "text/plain", "LED is OFF"); 
}

void setup() {
  // 시리얼    통신    시작 
  Serial.begin(115200);

  // Wi-Fi 연결
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) { 
    delay(500);
    Serial.print(".");   
  }
  Serial.println("WiFi connected");
    
  // LED 핀을    출력    모드로    설정
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);  // 초기에는 LED 끔 
  
  // HTTP 요청을    처리할    함수    설정
  server.on("/turn_on", HTTP_GET, turnOnLED);   
  server.on("/turn_off", HTTP_GET, turnOffLED);

  // 서버    시작   
  server.begin();
  Serial.println("Server started"); 
}

void loop() {
  server.handleClient();  // 클라이언트    요청    처리 
}
