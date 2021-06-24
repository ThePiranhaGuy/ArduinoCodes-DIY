// Assignment 1 of week 3
// DIY projects
#include "DHT.h"

#define DHTPIN 8     // what pin we're connected to

#define DHTTYPE DHT22   // DHT 22  (AM2302)
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

DHT dht(DHTPIN, DHTTYPE,4);

int flag = 0;

void setup() {
  pinMode(13,OUTPUT);
  Serial.begin(9600); 
  Serial.println("DHTxx test!");
 
  dht.begin();
}

void loop() {
  

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius
  float t = dht.readTemperature();

  
  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) ) {
    return;
  }
     if(t<=15&&h<25)
     {
     if(flag==0)
     {
	 digitalWrite(13,HIGH);
	 delay(1000);
	 Serial.println("The LED was on for 1 seconds");
	 flag=1;
	 digitalWrite(13,LOW);
      }
      }
      else if(t<=15 && h>60)
      {
      if(flag==0){
	 digitalWrite(13,HIGH);
	 delay(500);
	 Serial.println("The LED was on for 0.5 seconds");
	 flag=1;
	 digitalWrite(13,LOW);	 
       }
       }
      else if(t>=28 &&h<25)
      {
      if(flag == 0){
	 digitalWrite(13,HIGH);
	 delay(1000);
	 Serial.println("The LED was on for 1 seconds");
	 flag = 1;
	 digitalWrite(13,LOW);	 
       }
       }
      else if(t>=28 && h>60)
      {
      if(flag==0){
	 digitalWrite(13,HIGH);
	 delay(500);
	 Serial.println("The LED was on for 0.5 seconds");
	 flag = 1;
	 digitalWrite(13,LOW);	 
       }
       }
      else{
      flag = 0;
      }
    
     
  Serial.print("Humidity: "); 
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: "); 
  Serial.print(t);
  Serial.println(" *C");
  // Wait a few seconds between measurements.
  delay(2000);


}
