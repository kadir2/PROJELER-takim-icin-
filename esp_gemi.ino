#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <ESP32Servo.h>



#define led 33

RF24 radio(5, 4);   // ce csn

const byte adres[6] = "ZAzkB";    // İletişim adresi
  float dizi[4];                  //4 değer okunacak
  unsigned long first_time = 0;

  Servo servomm;        //servo oluştur
  int servopin = 16;    //18 e bağlanacak
  unsigned long servo_timer = 0;

void setup() {
  pinMode(21,OUTPUT);
  pinMode(22,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);

  pinMode(25,OUTPUT);
  pinMode(26,OUTPUT);
  
  pinMode(led,OUTPUT); //led çıkış olarak atandı
  servomm.attach(servopin); // servo motoru bağlandı

  Serial.begin(115200);  // Seri haberleşme hızını 115200 olarak ayarlıyoruz
  radio.begin();
  radio.openReadingPipe(0, adres);
  radio.setPALevel(RF24_PA_MAX);
  radio.startListening();

}

void loop() {
  
    dizi[0]=1;
    dizi[1]=0;
    dizi[2]=0;
    dizi[3]=0;
  if (radio.available()) {

    radio.read(&dizi, sizeof(dizi));

     Serial.print("buton durum");       // buton durum  analog gelen:x  analog gelen:y  analog servo
     Serial.print("  analog gelen:x");  // 1            519             519             519
     Serial.print("  analog gelen:y");
     Serial.println("  analog servo");

     Serial.print("  "); 
     Serial.print(dizi[0]);
     Serial.print("\t\t");
     Serial.print(dizi[1]);
     Serial.print("\t\t");
     Serial.print(dizi[2]);
     Serial.print("\t\t");
     Serial.println(dizi[3]);
     Serial.println("\n");


  }
    
  else {
    Serial.println("ulaşılamıyor..");
    //delay(5);
  }  
  

  unsigned long current_time = millis();


/*
  int veri_don = dizi[1];
  int veri_hiz = dizi[2];
  int veri_aci = dizi[3];
  int turn;
  int hiz;
  int aci;

     hiz = map(veri_hiz,0,1023,-255,255);
     turn = map(veri_don,0,1023,-255,255);
    

     aci = map(veri_aci,0,1023,0,179);
*/
   int turn = dizi[1];
   int hiz = dizi[2];
   int aci = dizi[3];
   
   if(!radio.available()){
    turn = 0.1;
    hiz = 0.1;
  }
        Serial.print("\t\t\t\t\t\t\t\t\t");
      Serial.print("turn:  ");       //  turn: hız:  servo açı
      Serial.print("hız:  ");        //  127    127   180
      Serial.println("servo açı");
      
        Serial.print("\t\t\t\t\t\t\t\t\t");
      Serial.print(turn);
      Serial.print("\t");
      Serial.print(hiz);
      Serial.print("\t");
      Serial.println(aci);
  

if(turn>4 || turn<-2){
if(turn > 4){               //dönüş
digitalWrite(21 , HIGH);
digitalWrite(22 , LOW);
analogWrite(25 , turn); //sol motor ileri

}
else if(turn < -2){
digitalWrite(12 , LOW);
digitalWrite(13 , HIGH);
analogWrite(26 , (-turn));
}
else{
digitalWrite(21 , LOW);
digitalWrite(22 , LOW);
digitalWrite(12 , LOW);
digitalWrite(13 , LOW);
}
//delay(5);
}

else{
if(hiz > 4){                 //düz gidiş
digitalWrite(21 , HIGH);
digitalWrite(22 , LOW);
digitalWrite(12 , LOW);
digitalWrite(13 , HIGH);
analogWrite(25 , hiz);
analogWrite(26 , hiz);

}
else if(hiz < -2){
digitalWrite(21 , LOW);
digitalWrite(22 , HIGH);
digitalWrite(12 , HIGH);
digitalWrite(13 , LOW);
analogWrite(25 , -hiz);
analogWrite(26 , -hiz);
}
else{
digitalWrite(21 , LOW);
digitalWrite(22 , LOW);
digitalWrite(12 , LOW);
digitalWrite(13 , LOW);
    }
 //delay(5);

}

if((current_time - first_time) >= 1000 ){
  
  first_time = current_time;
  int led_state = digitalRead(led);
  digitalWrite(led, !led_state);
}




if(dizi[0]==0){
for(int i=0;i<10;i++){
servomm.write(10);
}
}
else{
servomm.write(100);
}



/*
if(aci<90){
servomm.write(1);
}
else if(aci>91){
servomm.write(179);
}
else {
servomm.write(90);
}

if((current_time - servo_timer) >= 10000){
servo_timer = current_time;
servomm.write(90);
servomm.write(90);
servomm.write(90);
Serial.println("tytvubhıvedsjubfghvelorgjvdfegırfdgnvelgohawesrdtfygujwsedrftgyhunjıazsxdcrftvgybhunjımkewsdrftgyhutytvubhıvedsjubfghvelorgjvdfegırfdgnvelgohawesrdtfygujwsedrftgyhunjıazsxdcrftvgybhunjımkewsdrftgyhutytvubhıvedsjubfghvelorgjvdfegırfdgnvelgohawesrdtfygujwsedrftgyhunjıazsxdcrftvgybhunjımkewsdrftgyhu");
}
*/
}



