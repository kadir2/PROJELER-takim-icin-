#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define button 4

RF24 radio(9, 10);     // NRF24L01 CSN ve CE pinleri


const byte adres[6] = "ZAzkB";  // İletişim adresi

void setup() {
  Serial.begin(115200);  // Seri haberleşme hızını 115200 olarak ayarlıyoruz
  radio.begin();
  radio.openWritingPipe(adres);
  radio.setPALevel(RF24_PA_MAX);
  pinMode(A0,INPUT);
  pinMode(button,INPUT);
}

void loop() {
  float deger[4]; 

    deger[0]=0;
  deger[0] = digitalRead(button); 
  deger[1] = analogRead(A0);
  deger[2] = analogRead(A1);
  deger[3] = analogRead(A2);
  Serial.print("  dijital okunan buton: ");
  Serial.print("  analog okunan x: ");
  Serial.print("  analog okunan y: ");
  Serial.println("  analog okunan Z: ");
  Serial.print("\t");
  Serial.print(deger[0]);
  Serial.print("\t\t\t");
  Serial.print(deger[1]);
  Serial.print("\t\t");
  Serial.print(deger[2]);
  Serial.print("\t\t\t");
  Serial.println(deger[3]);
  Serial.print("\n");

  

  radio.stopListening();
  radio.write(&deger, sizeof(deger));

  delay(5);  
}
