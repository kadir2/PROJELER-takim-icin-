#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define button 15  // buton pin ataması
#define A0 36      //  (GPIO 36)
#define A1 39      //  (GPIO 39)
#define A2 34      //  (GPIO 34)

/*                        TEST topla min max
unsigned long first=0;
unsigned int toplax=0;
unsigned int toplay=0;
unsigned int toplaz=0;
int adet=0;
int mini=2000;
int maxi=1000;
*/



RF24 radio(5, 4);     // CE VE CSN

const byte adres[6] = "ZAzkB";  // İletişim adresi

void setup() {
  Serial.begin(115200);  // Seri haberleşme hızı
  radio.begin();
  radio.openWritingPipe(adres);
  radio.setPALevel(RF24_PA_MAX);
  pinMode(A0, INPUT);
  pinMode(button, INPUT);
}

void loop() {
  float deger[4]; 
  float giden[4]={0,0,0,0};

  deger[0] = digitalRead(button); 
  deger[1] = analogRead(A0);
  deger[2] = analogRead(A1);
  deger[3] = analogRead(A2);

unsigned long sayac = millis();


  int axisx = deger[1];           //  xort=1899				xmin=1740 xmax=2053     
  int axisy = deger[2];           //  yort=1920				ymin=1801	ymax=2064
  int axisz = deger[3];

if(axisx<=2100 && axisx>=1720)
axisx=2048;
if(axisy<=2100 && axisy>=1720)
axisy=2048;
if(axisz<=2100 && axisz>=1720)
axisz=2048;

axisx=map(axisx,0,4095,-255,255);
axisy=map(axisy,0,4095,-255,255);
axisz=map(axisz,0,4095,-255,255);


  Serial.print("Dijital okunan buton: ");
  Serial.print(deger[0]);
  Serial.print("\tAnalog okunan X: ");
  Serial.print(axisx);
  Serial.print("\tAnalog okunan Y: ");
  Serial.print(axisy);
  Serial.print("\tAnalog okunan Z: ");
  Serial.println(axisz);






giden[0]=deger[0];
giden[1]=axisx;
giden[2]=axisy;
giden[3]=axisz;


  radio.stopListening();
  radio.write(&giden, sizeof(giden));



 /* 
adet++;                         TEST verileri topla
toplax=toplax + axisx;
toplay=toplay + axisy;  
toplaz=toplaz + axisz;

if(mini>axisx){
  mini=axisx;
}
if(maxi<axisx){
  maxi=axisx;
}
if((sayac-first) >= 10000){
  first=sayac;
Serial.println(toplax);
Serial.println(toplay);
Serial.println(adet);
Serial.println(mini);
Serial.println(maxi);
delay(10000);
}
*/


  delay(5);  
}
