//Example Sketch using multiple analog sensors into one analog input pin
//Blynk WiFi example
//Tutorials and more at http://www.cabuu.com

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "mxAd7bVwZypafqP_-HmFowNY65nb8PLN";

char ssid[] = "vivo 1727";
char pass[] = "Anu12345";

int Value_D7;
int Value_D8;
int Pin_D7 = 13;
int Pin_D8 = 15;

void setup() {

  Serial.begin(9600);   //Start serial monitor
  Blynk.begin(auth, ssid, pass);
  pinMode(Pin_D7, OUTPUT);
  pinMode(Pin_D8, OUTPUT);
  pinMode(A0, INPUT);
  

}

void loop() {

  Blynk.run();

  digitalWrite(Pin_D7, HIGH);     //Turn D7 On
  delay(100);                     
  Value_D7 = analogRead(0);       //Read Analog pin D7
  digitalWrite(Pin_D7, LOW);      //Turn D7 Off

  //Repeat for D8
  digitalWrite(Pin_D8, HIGH);     //Turn D8 On
  delay(100);                     
  Value_D8 = analogRead(0);       //Read Analog pin D8
  if (digitalRead(Value_D8)) {
    Serial.println("Intruder Detected!");
    Blynk.virtualWrite(V1, "Intruder Detected!");
  }
  digitalWrite(Pin_D8, LOW);      //Turn D8 Off
  delay(100);                     

  //Print the results to the serial monitor
  Serial.print("D7 = ");
  Serial.print(Value_D7);
  Serial.print(" / D8 = ");
  Serial.println(Value_D8);

  Blynk.virtualWrite(V20, Value_D7);  
  Blynk.virtualWrite(V21, Value_D8);  

}
