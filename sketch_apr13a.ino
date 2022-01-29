int buton1 = 2;
int buton2 = 3;
int buton3 = 4;
int buton4 = 5;
int buton5 = 6;
int buton6 = 7;

int besTLadet = 20;
int onTLadet = 20;
int yirmiTLadet = 10;
int elliTLadet = 30;
int yuzTLadet = 5;

int kopuklemeFiyat = 15;
int yikamaFiyat = 10;
int kurulamaFiyat = 5;
int cilalamaFiyat = 50;


int yesil_led = 10;
int kirmizi_led = 11;

int islem1 = 0;
int islem2 = 0;
int islem3 = 0;
int islem4 = 0;
int islem5 = 0;
int islem6 = 0;

int para_secme = 1;
int hizmet_secme = 1;
int para = 0;

void setup() {
  randomSeed(analogRead(0));
  Serial.begin(9600);
  bakiyeYuklemeBilgilendirme();
  pinMode(buton1, INPUT);
  pinMode(buton2, INPUT);
  pinMode(buton3, INPUT);
  pinMode(buton4, INPUT);
  pinMode(buton5, INPUT);
  pinMode(buton6, INPUT);
  pinMode(yesil_led, OUTPUT);
  pinMode(kirmizi_led, OUTPUT);
}

void loop() {
  while (para_secme == 1) {
    if ( digitalRead(buton1) == HIGH && para_secme == 1) {
      para += 5;
      Serial.println("Bakiyeniz 5 TL arttırılıyor.");
      delay(1000);
      Serial.println("Bakiyeniz arttırıldı.");
      Serial.print("Mevcut bakiye : ");
      Serial.println(para);
    }
    else if ( digitalRead(buton2) == HIGH && para_secme == 1) {
      para += 10;
      Serial.println("Bakiyeniz 10 TL arttırılıyor.");
      delay(1000);
      Serial.println("Bakiyeniz arttırıldı.");
      Serial.print("Mevcut bakiye : ");
      Serial.println(para);
    }
    else if ( digitalRead(buton3) == HIGH && para_secme == 1) {
      para += 20;
      Serial.println("Bakiyeniz 20 TL arttırılıyor.");
      delay(1000);
      Serial.println("Bakiyeniz arttırıldı.");
      Serial.print("Mevcut bakiye : ");
      Serial.println(para);
    }
    else if ( digitalRead(buton4) == HIGH && para_secme == 1) {
      para += 50;
      Serial.println("Bakiyeniz 50 TL arttırılıyor.");
      delay(1000);
      Serial.println("Bakiyeniz arttırıldı.");
      Serial.print("Mevcut bakiye : ");
      Serial.println(para);
    }
    else if ( digitalRead(buton5) == HIGH && para_secme == 1) {
      para += 100;
      Serial.println("Bakiyeniz 100 TL arttırılıyor.");
      delay(1000);
      Serial.println("Bakiyeniz arttırıldı.");
      Serial.print("Mevcut bakiye : ");
      Serial.println(para);
    }
    else if ( digitalRead(buton6) == HIGH && para_secme == 1) {
      para_secme = 0;
      Serial.println("Para atma işlemi bitiriliyor.");
      delay(1000);
      Serial.print("Kullanılabilir bakiye: ");
      Serial.println(para);
      hizmetSecmeBilgilendirme();
    }
  }


  while (hizmet_secme == 1) {
    if ( digitalRead(buton1) == HIGH && hizmet_secme == 1) {
      islem1++;
      Serial.println("Köpükleme seçeneği 1 arttırıldı");
      delay(1000);
    }
    else if ( digitalRead(buton2) == HIGH && hizmet_secme == 1) {
      islem2++;
      Serial.println("Yıkama seçeneği 1 arttırıldı.");
      delay(1000);
    }
    else if ( digitalRead(buton3) == HIGH && hizmet_secme == 1) {
      islem3++;
      Serial.println("Kurulama seçeneği 1 arttırıldı");
      delay(1000);
    }
    else if ( digitalRead(buton4) == HIGH && hizmet_secme == 1) {
      islem4++;
      Serial.println("Cilalama seçeneği 1 arttırıldı.");
      delay(1000);
    }
    else if ( digitalRead(buton5) == HIGH && hizmet_secme == 1) {
      hizmet_secme = 0;
      Serial.println("Hizmet seçimi bitirildi.");
      delay(1000);
      paraSansi();
    }
    else if ( digitalRead(buton6) == HIGH && hizmet_secme == 1) {
      islemSifirla();
      Serial.println("Seçimler sıfırlandı tekrar seçiniz.");
      delay(1000);
    }
  }


}

void hizmetSecmeBilgilendirme() {
  Serial.println("\n--------Seçebilceğiniz Hizmetler--------\n");
  Serial.print("1.Buton Köpükleme ");
  Serial.println(kopuklemeFiyat);
  Serial.print("2.Buton Yıkama ");
  Serial.println(yikamaFiyat);
  Serial.print("3.Buton Kurulama ");
  Serial.println(kurulamaFiyat);
  Serial.print("4.Buton Cilalama ");
  Serial.println(cilalamaFiyat);
  Serial.println("5.Buton Bitiş");
  Serial.println("6.Buton Seçimleri Sıfırlama");
}

void bakiyeYuklemeBilgilendirme() {
  Serial.println("1.Buton 5 TL Sayısı");
  Serial.println("2.Buton 10 TL Sayısı");
  Serial.println("3.Buton 20 TL Sayısı");
  Serial.println("4.Buton 50 TL Sayısı");
  Serial.println("5.Buton 100 TL Sayısı");
  Serial.println("6.Buton Para Atma Bitiş");

}


void kirmiziLed() {
  digitalWrite(kirmizi_led, HIGH);
  delay(2000);
  digitalWrite(kirmizi_led, LOW);
  delay(2000);
}

void yesilLed() {
  digitalWrite(yesil_led, HIGH);
  delay(2000);
  digitalWrite(yesil_led, LOW);
  delay(2000);
}

void software_Reset()
{
  asm volatile ("  jmp 0");
}

void paraSansi() {
  int sans = random(1, 5);
  if ( sans == 2) {
    Serial.println("Paranız sıkıştı. Para iade ediliyor.Tekrardan başlatılıyor.");
    kirmiziLed();
    software_Reset();
  }
  else {
    yesilLed();
    hizmetleriGerceklestir();
  }
}

void hizmetleriGerceklestir() {
  int maliyet  = (islem1 * kopuklemeFiyat) + (islem2 * yikamaFiyat) + (islem3 * kurulamaFiyat) + (islem4 * cilalamaFiyat);
  if (maliyet > para) {
    Serial.println("Bakiyeniz yetersiz. Paranız iade ediliyor. Lütfen daha sonra tekrar deneyin.");
  }
  else {
    para = para - maliyet;
    Serial.print("Hizmet bedeli: ");
    Serial.print(maliyet);
    Serial.println(" TL");
    paraUstu();

  }
}

void paraUstu() {
  islemSifirla();
  if (para  / 100 > 0 && yuzTLadet > 0) {
    islem5 = para / 100;
    para = para % 100;
  }  if ( para / 50 > 0 && elliTLadet > 0) {
    islem4 = para / 50;
    para = para % 50;
  }  if ( para / 20 > 0 && yirmiTLadet > 0) {
    islem3 = para / 20;
    para = para % 20;
  }  if ( para / 10 > 0 && onTLadet > 0) {
    islem2 = para / 10;
    para = para % 10;
  }  if ( para / 5 > 0 && besTLadet > 0) {
    islem1 = para / 5;
    para = para % 5;
  }

  Serial.println("----Para üstünüz----");
  if (islem5 > 0) {
    if (yuzTLadet > 0) {
      Serial.print(islem5);
      Serial.println(" adet 100 TL banknot");
    }
    else {
      Serial.print(islem5);
      Serial.println("Adet 100 TL banknot için kasada yeterli para yoktur.");
    }
  }
  if (islem4 > 0) {
    if (elliTLadet > 0) {
      Serial.print(islem4);
      Serial.println(" adet 50 TL banknot");
    }
    else {
      Serial.print(islem4);
      Serial.println(" Adet 50 TL banknot için kasada yeterli para yoktur.");
    }
  }
  if (islem3 > 0) {
    if (yirmiTLadet > 0) {
      Serial.print(islem3);
      Serial.println(" adet 20 TL banknot");
    }
    else {
      Serial.print(islem3);
      Serial.println(" Adet 20 TL banknot için kasada yeterli para yoktur.");
    }
  }
  if (islem2 > 0) {
    if (onTLadet > 0) {
      Serial.print(islem2);
      Serial.println(" adet 10 TL banknot");
    }
    else {
      Serial.print(islem2);
      Serial.println(" Adet 10 TL banknot için kasada yeterli para yoktur.");
    }
  }
  if (islem1 > 0) {
    if (besTLadet > 0) {
      Serial.print(islem1);
      Serial.println(" adet 5 TL banknot");
    }
    else {
      Serial.print(islem1);
      Serial.println(" Adet 5 TL banknot için kasada yeterli para yoktur.");
    }
  }


}


void islemSifirla() {
  islem1 = 0;
  islem2 = 0;
  islem3 = 0;
  islem4 = 0;
  islem5 = 0;
  islem6 = 0;

}
