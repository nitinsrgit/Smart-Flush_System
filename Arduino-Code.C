#include <LiquidCrystal.h> 
#include <NewPing.h> 
#define gled 11 
#define rled 12 
#define buz A0 
#define relay A1 
#define SENSOR_NUM 2 // Number of sensors. 
#define MAX_DISTANCE 300 // Maximum distance (in cm) to ping. 
LiquidCrystal lcd(4, 5, 6, 7, 8, 9); 
NewPing ultrasonic[SENSOR_NUM] = { // Sensor object array. 
 NewPing(10, 13, MAX_DISTANCE), // left Sensor 
 NewPing(2, 3, MAX_DISTANCE) //Right Sensor 
}; 
int distance[SENSOR_NUM]; 
void setup() 
{ 
 Serial.begin(9600); 
 pinMode (gled, OUTPUT); 
 pinMode (rled, OUTPUT); 
 pinMode (buz, OUTPUT); 
 pinMode (relay, OUTPUT); 
 digitalWrite (gled, LOW); 
 digitalWrite (rled, LOW); 
 digitalWrite (buz, LOW); 
 digitalWrite(relay, LOW); 
55 | P a g e
 lcd.begin(16, 2); 
 lcd.clear(); 
 lcd.setCursor(0, 0); 
 lcd.print(" SMART FLUSH "); 
 lcd.setCursor(0, 1); 
 lcd.print(" "); 
 delay(2000); 
} 
void loop() { 
 for (int i = 0; i < SENSOR_NUM; i++) { 
 distance[i] = ultrasonic[i].ping_cm(); 
 } 
 checkcon(); 
 Serial.print(distance[0]); 
 Serial.print(" , "); 
 Serial.println(distance[1]); 
} 
void checkcon() { 
 if ((distance[0] > 0) and (distance[0] <6)) { 
 digitalWrite(relay, HIGH); 
 digitalWrite(rled, HIGH); 
 digitalWrite(buz, HIGH); 
 delay(2000); 
 digitalWrite(relay, LOW); 
 digitalWrite(rled, LOW); 
 digitalWrite(buz, LOW); 
56 | P a g e
 } 
 if ((distance[1] > 0) and (distance[1] <6)) { 
 digitalWrite(relay, HIGH); 
 digitalWrite(gled, HIGH); 
 digitalWrite(buz, HIGH); 
 delay(5000); 
 digitalWrite(relay, LOW); 
 digitalWrite(gled, LOW); 
 digitalWrite(buz, LOW); 
 }
