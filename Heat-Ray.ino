//Project Optika Heat-Ray berbasis mikrokontroller
//Mengassign setiap pin untuk setiap variabel konstan


int LDRKANAN = A0;
int LDRKIRI = A1;
int LDRATAS = A2;
int LDRBAWAH = A3;

//Mendeklarasikan variabel yang akan digunakan sebagai tempat mengassign input dan proses nantinya
int sinyalkanan;
int sinyalkiri;
int sinyalatas;
int sinyalbawah;
int error;
int error1;


int posisiservo = 90;
int posisiservo1 = 140;

//Menggunakan Library Servo untuk mengendalikan pergerakan servo
#include <Servo.h>

//Mendeklarasikan setiap Servo yang akan digunakan
Servo servo ;
Servo servo1 ;


//masuk ke Fungsi Set-up
void setup() {
  Serial.begin(9600);
  //Menugaskan Pin LDR untuk menjadi pin Input
  pinMode(LDRKANAN,INPUT);
  pinMode(LDRKIRI,INPUT);
  pinMode(LDRBAWAH,INPUT);
  pinMode(LDRATAS,INPUT);
  //Menugaskan pin 6 dan 7 sebagai pin pemberi sinyal PWM untuk servo
  servo.attach(7);
  servo1.attach(6);
  //Mengatur posisi servo saat pertama kali alat menyala
  servo.write(posisiservo);
  servo1.write(posisiservo1);
  //Delay adalah fungsi blocking agar semua perintah telah dieksekusi sebelum berlanjut ke perintah selanjutnya
  delay(2000);

  //Fungsi ini hanya berjalan sekali
}

void loop() {
  //Mengambil input sinyal analog
  sinyalkanan = analogRead(LDRKANAN);
  sinyalkiri = analogRead(LDRKIRI);
  sinyalatas = analogRead(LDRATAS);
  sinyalbawah = analogRead(LDRBAWAH);
  delay(1000);
  //Fungsi Print untuk melakukan debugging
  Serial.println("Kanan : " + String(sinyalkanan));
  Serial.println("Kiri : "+ String(sinyalkiri));
  Serial.println("Atas : " + String(sinyalatas));
  Serial.println("Bawah : "+ String(sinyalbawah));

  //Memulai proses perbandingan sensor LDR pada masing-masing sumbu
  error = abs(sinyalkanan - sinyalkiri);
  error1 = abs(sinyalatas - sinyalbawah);

  //Kondisional untuk mengambil keputusan arah gerak servo
  if (error > 20) {
     
     if (sinyalkanan > sinyalkiri and posisiservo < 130){// Baris ini berfungsi sebagai comaparisan operator dan pembatas gerakan servo
        posisiservo = posisiservo + 20; //Baris ini menentukan arah gerak servo dan sejauh mana servo harus bergerak
        servo.write(posisiservo);
        delay(100);
  

     }
     else if (sinyalkanan < sinyalkiri and posisiservo > 50){// Baris ini berfungsi sebagai comaparisan operator dan pembatas gerakan servo
        posisiservo = posisiservo - 20; //Baris ini menentukan arah gerak servo dan sejauh mana servo harus bergerak
        servo.write(posisiservo);
        delay(100);
     
  }
  }
    if (error1 > 10) {
     if (sinyalbawah > sinyalatas and posisiservo1 >= 140){// Baris ini berfungsi sebagai comaparisan operator dan pembatas gerakan servo
        posisiservo1 = posisiservo1 - 10; //Baris ini menentukan arah gerak servo dan sejauh mana servo harus bergerak
        servo1.write(posisiservo1);
        delay(100);
  

     }
     else if (sinyalatas > sinyalbawah and posisiservo1 <= 180){// Baris ini berfungsi sebagai comaparisan operator dan pembatas gerakan servo
        posisiservo1 = posisiservo1 + 10; //Baris ini menentukan arah gerak servo dan sejauh mana servo harus bergerak
        servo1.write(posisiservo1);
        delay(100);
     
  }


}
  }
