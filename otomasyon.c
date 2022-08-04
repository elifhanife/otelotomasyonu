#include <ctype.h> //kutuphaneler
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//global degiskenler
int gun,ay,yil,saat,dk,cikis,ek_servisler,Menu;
char isim[40],soyisim[40];
int mutfakrezervayonsecim,mutfakyemeksecim;
char ad[100],soyad[100];
int dakika,mutfak,tus_1;
char sil, sil2;
long int tc, phone, number; 
int secim, day, addcustomer, bed, tus1, tus2, tus3, ekle, ekle1;
char client[50];
char gender;
char room[6]; 
char view[20];
int secim2, tus_2; 
//otomasyon kullanicisinin girisi
char login[64]; 
char password[64];
int x = 0;
int y = 0;

//BaChel Resort logo 
int caticiz(){
  
    printf("          <>                                 <>\n");
    printf("         <>                                 <>  \n");
    printf("        <>                                 <>    \n");
    printf("       |  |                               |  |    \n");
    printf("    /--|  |-------------------------------|  |--\\ \n");
    printf("   /   |  |                               |  |   \\ \n");
    printf("  /                  BaChel Resort                \\ \n");
    printf(" /                                                 \\ \n");
    printf("-----------------------------------------------------  \n");
return 0; 
}
//BaChel Resort logo 
int katciz(){
    
    printf("|   _____                                   _____    | \n"); 
    printf("|  |_____|     __________    __________    |_____|   | \n");
    printf("|   _____     |__________|  |__________|    _____    | \n");
    printf("|  |_____|    |__________|  |__________|   |_____|   | \n");
    printf("|   _____                                   _____    | \n");
    printf("|  |_____|              _______            |_____|   | \n");
    printf("|                       |_    |                      | \n");
    printf("|                       |     |                      | \n");
    printf("|                       |     |                      | \n");
    printf("------------------------------------------------------\n");
return 0; 
}

//Otomasyon kullanici girisi icin fonksiyon
void kullanicigiris(){
  
  printf("\n\n");
  while (x == 0) {
    printf("Kullanici Adinizi Giriniz: ");
    scanf("%s", login);

    if (!(strcmp(login, "admin"))) {
      x = 1;
    } else {
      printf("Kullanici Adi Yanlis\n");
      x = 0;
    }
  }
  while (y == 0) {
    printf("Sifrenizi Giriniz: ");
    scanf("%s", password);

    if (!(strcmp("1234", password))) {
      y = 1;
    } else {
      printf("Girilen sifre Yanlis\n");
      y = 0;
    }
  }
}

//Müsteri Ekleme secenekleri icin kullanilan fonksiyon.
void musteri_ekleme(){ 
    printf("1- Kayit Listeleme\n");  
    printf("2- Müsteri Ekleme\n");  
    printf("3- Kayit Silme\n");  
    printf("Görüntülenmesi istenen hizmeti giriniz: ");  
    scanf("%d",&ekle);  
}
//Musteri Ekleme Kismina kayitli olanlari listeleyen fonksiyon.
  void olanlar() {
  FILE*musteri;
  musteri=fopen("musteri_ekle.txt","r"); printf("\n");
  while(!feof(musteri)){
    putchar(fgetc(musteri));  
  }
  fclose(musteri);
}
//Musterilerin Eklendigi Fonksiyon.
    void ekleme(){ 
    printf("Musteri Ad ve Soyad: \n");  fgets(client, sizeof(client), stdin);  gets(client);

    printf("Cinsiyet: \n");             scanf("%c", &gender);        
    
    printf("TC: \n");                   scanf("%ld", &tc);
    
    printf("Telefon Numarasi: \n");     scanf("%ld", &phone);
    
    printf("Kalacak Gun Sayisi: \n");   scanf("%d", &day);                      printf("\n");
    
    FILE *musteri=fopen("musteri_ekle.txt","a");
      
    fprintf(musteri,"Musteri ismi:\t%s\nCinsiyet:\t%c\nTC:\t%ld\nTelefon NO:\t%ld\nGun Sayisi:\t%d\n\n ",client, gender, tc, phone, day);
    fclose(musteri);
    printf("\nKayit Eklendi\n");
}
//Eklenen Musterilerin sifirlandigi Fonksiyon.
  void silme(){
  printf("silmek istediginize emin misiniz? (e/h): "); scanf("%s",&sil);
  if(sil=='e')
  {
    FILE *musteri=fopen("musteri_ekle.txt","w"); 
    fprintf(musteri,"");
    fclose(musteri);   
    printf("Kayitlar silindi\n");          
  }
     
}
//Oda Secenekleri icin kullanilan fonskiyon.  
  void oda_secenek(){
  printf("1- Kayit Listeleme\n");  
  printf("2- Musteri Ekleme\n");  
  printf("3- Kayit Silme\n");  
  printf("Goruntulenmesi istenen hizmeti giriniz: ");  
  scanf("%d",&ekle1);  
}
//Kayitli odalari goruntuleyen fonksiyon.   
  void oda_secenek1() {
  FILE*oda;
  oda=fopen("oda_kayit.txt","r"); printf("\n");
  while(!feof(oda)){
    putchar(fgetc(oda));  
  }
  fclose(oda);
}
//Oda Seceneklerinin ayarlandigi fonksiyon.       
    void oda_secenek2(){
    printf("Oda Secenekleri ile ilgili Sorulari Cevaplayiniz: \n\n");
    printf("Oda Boyutunu yaziniz (Normal, Buyuk, Kral): \n");       fgets(room, sizeof(room), stdin);       gets(room);
    
    printf("Istediginiz yatak sayisini giriniz: \n");               scanf("%d", &bed);
    
    printf("Istediginiz manzarayi seciniz (Deniz ve Yol manzarali odalarimiz bulunmaktadir.): \n");   fgets(view, sizeof(view), stdin); 
     gets(view);
     
    FILE *oda=fopen("oda_kayit.txt","a");
      
    fprintf(oda,"Oda Boyutu:\t%s\n Yatak Sayisi:\t%d\n Manzara:\t%s\n ",room, bed, view);
    fclose(oda);
    printf("\nKayit Eklendi\n");
}
//Odalarin sifirlandigi fonksiyon.
   void oda_secenek3(){
  printf("silmek istediginize emin misiniz? (e/h): "); scanf("%s",&sil);
  if(sil=='e')
  {
    FILE *oda=fopen("oda_kayit.txt","w"); 
    fprintf(oda,"");
    fclose(oda);   
    printf("Kayitlar silindi \n");          
  }
     
}

//HAVUZ BOLUMU
//Havuza kayit ekleme  
void havuzKisi() {
  do {
  int kisi;
  printf("\nTarih girin (gg.aa.yyyy): "); scanf("%d%d%d",&gun,&ay,&yil);
  printf("Saat girin: "); scanf("%d%d",&saat,&dk);  
  printf("Eklenecek kisi sayisi: "); scanf("%d",&kisi);

  FILE*dosya_1;
  dosya_1=fopen("havuz.txt","a");
  fprintf(dosya_1,"Tarih=%d.%d.%d\t",gun,ay,yil);
  fprintf(dosya_1,"Saat=%d.%d\n",saat,dk);
  fprintf(dosya_1,"Bugunku kisi sayisi:%d\n\n",kisi);
  fclose(dosya_1);
  printf("Yeni kayit olusturuldu!\n");
  printf("Devam etmek icin 1'e,cikmak icin baska bir tusa basin!  "); scanf("%d",&cikis);
}while(cikis==1); 
}
//Havuz dosyasini goruntuleme
void havuzDurum() { int gun;
  FILE*dosya_1;
  dosya_1=fopen("havuz.txt","r"); printf("\n");
  while(!feof(dosya_1)){
    putchar(fgetc(dosya_1));
  }
  fclose(dosya_1);
}

//SPOR SALONU BOLUMU
//Spor salonuna musteri ekleme
void sporKisi() {
  do {
  printf("\nTarih girin (gg.aa.yyyy): "); scanf("%d %d %d",&gun,&ay,&yil);
  printf("Saat girin: "); scanf("%d%d",&saat,&dk);  
  printf("Musterinin isim ve soyisim bilgilerini girin: "); scanf("%s %s",isim,soyisim);
  FILE*dosya_2;
  dosya_2=fopen("sporSalonu.txt","a");
  fprintf(dosya_2,"Tarih=%d.%d.%d\t",gun,ay,yil);
  fprintf(dosya_2,"Saat=%d.%d\n",saat,dk);
  fprintf(dosya_2,"%s %s icin kayit olusturuldu.\n\n ",isim,soyisim);
  fclose(dosya_2);
  printf("Yeni kayit olusturuldu!\n");
  printf("Devam etmek icin 1'e,cikmak icin baska bir tusa basin!  "); scanf("%d",&cikis);
}while(cikis==1); 
}
// sporSalonu dosyasini goruntuleme
void sporDurum() {
  FILE*dosya_2;
  dosya_2=fopen("sporSalonu.txt","r"); printf("\n");
  while(!feof(dosya_2)){
    putchar(fgetc(dosya_2));  
  }
  fclose(dosya_2);
}
//sporSalonu dosyasini silme
void sporSil() {
  printf("silmek istediginize emin misiniz? (e/h): "); scanf("%s",&sil);
  if(sil=='e') {
    FILE *dosya_2=fopen("sporSalonu.txt","w"); 
    fprintf(dosya_2,"");
    fclose(dosya_2);   
    printf("Kayitlar silindi\n");
  }
  else 
  printf("silme islemi basarisiz\n ! ");
}

// SPA-SAUNA-MASAJ BOLUMU
// Spa-Masaj-Sauna musteri ekleme
void spaKisi() {
    do {
    printf("\nTarih girin (gg.aa.yyyy): "); scanf("%d %d %d",&gun,&ay,&yil);
    printf("Saat girin: "); scanf("%d%d",&saat,&dk);  
    printf("Musterinin isim ve soyisim bilgilerini girin: "); scanf("%s %s",isim,soyisim);
    FILE*dosya_3;
    dosya_3=fopen("spa.txt","a");
    fprintf(dosya_3,"Tarih=%d.%d.%d\t",gun,ay,yil);
    fprintf(dosya_3,"Saat=%d.%d\n",saat,dk);
    fprintf(dosya_3,"%s %s icin kayit olusturuldu.\n\n ",isim,soyisim);
    fclose(dosya_3);
    printf("Yeni kayit olusturuldu!\n");
    printf("Devam etmek icin 1'e,cikmak icin baska bir tusa basin!  "); scanf("%d",&cikis);
    }while(cikis==1);
}
// spa dosyasini goruntuleme
void spaDurum() {
  FILE*dosya_3;
  dosya_3=fopen("spa.txt","r"); printf("\n");
  while(!feof(dosya_3)){
    putchar(fgetc(dosya_3));  
  }
  fclose(dosya_3);
}
// spa dosyasini silme
void spaSil() {
   printf("silmek istediginize emin misiniz? (e/h): "); scanf("%s",&sil);
  if(sil=='e') {
    FILE *dosya_3=fopen("spa.txt","w"); 
    fprintf(dosya_3,"");
    fclose(dosya_3);   
    printf("Kayitlar silindi \n");
  }
  else 
  printf("silme islemi basarisiz\n ! ");
}

//Restoran Kismi
//Restorana musteri kaydetme menusu fonksiyonu
void MutfakRezervasyonMenusu(){
printf("1- Kayit Listeleme\n");  
printf("2- Müsteri Ekleme\n");  
printf("3- Kayit Silme\n");  
printf("Goruntulenmesi istenen hizmeti giriniz: ");  
scanf("%d",&mutfakrezervayonsecim);  
}

//Restoran Yemek Menusu fonksiyonu
void MutfakYemekMenusu(){
printf("1- Baslangiclar\n");  
printf("2- Ana Yemekler\n");  
printf("3- Kahvalti\n");  
printf("4- Meze ve Salatalar\n"); 
printf("5- Tatlilar\n"); 
printf("6- Icecekler\n"); 
printf("Goruntulenmesi istenen hizmeti giriniz: ");  
scanf("%d",&mutfakyemeksecim);  
}
//Restoran musteri goruntuleme fonksiyonu
void Listeleme(){
    FILE *dosya;
    dosya=fopen("rezervasyon.txt","r");
    printf("\n");
    while(!feof(dosya)){  
    putchar(fgetc(dosya)); 
    }
    fclose(dosya);  
}
//Restorana musteri ekleme fonksiyonu
void Ekleme(){ 
     printf("Musterinin Adi: "); scanf("%s",isim);
     printf("Musterinin Soyadi: "); scanf("%s",soyisim);
     printf("Istenilen Saat ve Dakika: "); scanf ("%d %d",&saat,&dakika);
      
    FILE *dosya=fopen("rezervasyon.txt","a");
      
    fprintf(dosya,"Isim:%s  Soyisim:%s  Saat:%d.%d\n",isim,soyisim,saat,dakika);
    fclose(dosya);
    printf("\nKayit Eklendi\n");
}
//Restoran musteri silme fonksiyonu
void Silme(){
  printf("silmek istediginize emin misiniz? (e/h): "); scanf("%s",&sil);
  if(sil=='e'){
    FILE *dosya=fopen("rezervasyon.txt","w"); 
    fprintf(dosya,"");
    fclose(dosya);   
    printf("Kayitlar silindi \n");          
  }
  else 
  printf("Silme islemi basarisiz\n ! ");
     
}
 //Ana yemekleri goruntuleme fonksiyonu
void AnaYemekler(){
    FILE *dosya1;
    dosya1=fopen("anayemekler.txt","r");
    printf("\n");
    while(!feof(dosya1)){  
    putchar(fgetc(dosya1)); 
    }
    fclose(dosya1);  
}
 //Baslangic yemeklerini goruntuleme fonksiyonu
void Baslangic(){
    FILE *dosya2;
    dosya2=fopen("baslangic.txt","r");
    printf("\n");
    while(!feof(dosya2)){  
    putchar(fgetc(dosya2)); 
    }
    fclose(dosya2);  
}
//Icecekleri goruntuleme fonksiyonu
void Icecekler(){
    FILE *dosya3;
    dosya3=fopen("icecekler.txt","r");
    printf("\n");
    while(!feof(dosya3)){  
    putchar(fgetc(dosya3)); 
    }
    fclose(dosya3);  
}
 //Kahvalti seceneklerini goruntuleme fonksiyonu
void Kahvalti(){
    FILE *dosya4;
    dosya4=fopen("kahvalti.txt","r");
    printf("\n");
    while(!feof(dosya4)){  
    putchar(fgetc(dosya4)); 
    }
    fclose(dosya4);  
}
 //Meze ve Salata seceneklerini goruntuleme fonksiyonu
void MezeveSalata(){
    FILE *dosya5;
    dosya5=fopen("mezelervesalatalar.txt","r");
    printf("\n");
    while(!feof(dosya5)){  
    putchar(fgetc(dosya5)); 
    }
    fclose(dosya5);  
}
 //Tatli seceneklerini goruntuleme fonksiyonu
void Tatli(){
    FILE *dosya6;
    dosya6=fopen("tatlilar.txt","r");
    printf("\n");
    while(!feof(dosya6)){  
    putchar(fgetc(dosya6)); 
    }
    fclose(dosya6);  
}
//Restoran Fonksiyonlari Sonu

int main(){
setlocale(LC_ALL, "Turkish");
caticiz();
katciz();
kullanicigiris();
  do {
    printf("-------------------ANA MENU-------------------");
    printf("\n\n");
    printf("1- Musteri Giris\n");
    printf("2- Ek Hizmetler\n");
    printf("3- Restoran\n");
    printf("Goruntulenmesi istenen hizmeti giriniz: ");
    scanf("%d", &secim2);
    printf("\n\n");

    switch (secim2) {
    case 1:
    do{
    printf("-------------------MUSTERI GIRIS-------------------\n");
    printf("1) Musteri Ekleme: \n");
    printf("2) Oda Secenekleri: \n");
    printf("Istenen Secenegi giriniz: ");
    scanf("%d", &addcustomer);
    printf("\n\n");
    
    
    switch(addcustomer){
        case 1:
        printf("-----------------MUSTERI EKLEME-----------------\n");
        musteri_ekleme();
        do{
            switch(ekle){
            case 1:  olanlar();  printf("\n\n");  break;
            case 2:  ekleme();  printf("\n\n");   break;
            case 3:  silme();   printf("\n\n");  break;  
          }

        printf(" Musteri ekleme menusunden cikmak icin 8'e, bir daha goruntulemek icin herhangi bir sayiya basiniz: \t");
        scanf("%d", &tus2);
      }while (tus2 != 8); 
        break;
        
        case 2:
        
        printf("----------------ODA SECENEKLERI----------------\n");
        oda_secenek();
        do{
        switch(ekle1){
            case 1:     oda_secenek1();     printf("\n\n");             break;
            case 2:     oda_secenek2();     printf("\n\n");             break;
            case 3:     oda_secenek3();     printf("\n\n");             break;
        }
        printf("Oda menusunden cikmak icin 8 e, bir daha goruntulemek icin herhangi bir sayiya basiniz: \t");
        scanf("%d", &tus1);
        }while(tus1 !=8);   
        break;
    }

printf(" Musteri Giris bolumunden cikmak icin 8 e, bir daha goruntulemek icin herhangi bir sayiya basiniz: \t");
scanf("%d", &tus3);
}while(tus3 != 8);
        
    break;

  case 2:
    do{
    printf("Hangi bolumle ilgili islem yapmak istiyorsunuz?\n");
    printf("1.Kapali Havuz\n");
    printf("2.Spor Salonu\n");
    printf("3.Spa-Sauna-Masaj\n");
    scanf("%d",&ek_servisler);
    printf("\n");
    switch(ek_servisler) {
    case 1:
      printf("----------------Kapali Havuz----------------\n\n");
      printf("Yapmak istediginiz islem nedir?\n");
      printf("1.Kayit ekleme\n2.Mevcut durumu goruntuleme\n"); scanf("%d",&Menu);
      switch(Menu) {
        case 1:         havuzKisi();                break;  
        case 2:         havuzDurum();               break;
       }
    break;

      case 2:
          printf("----------------Spor Salonu----------------\n");
          printf("Yapmak istediginiz islem nedir?\n");
          printf("1.Yeni kayit ekleme\n2.Kayit goruntuleme\n3.Kayit silme\n "); scanf("%d",&Menu);
        switch(Menu) {
        case 1:         sporKisi();         break;
        case 2:         sporDurum();        break;
        case 3:         sporSil();          break;
        }
      break;
      
      case 3:
      printf("----------------Spa-Sauna-Masaj----------------\n");
      printf("Yapmak istediginiz islem nedir?\n");  
      printf("1.Yeni kayit ekleme\n2.Kayit goruntuleme\n3.Kayit silme\n "); scanf("%d",&Menu);
      switch(Menu) {
        case 1:           spaKisi();          break;
        case 2:         spaDurum();           break;
        case 3:           spaSil();           break;
      }
      break;
    }
    printf("Cikmak icin 8'e, Ek Hizmetler menusune donmek icin herhangi bir tusa basiniz: "); scanf("%d",&cikis);
    }while(cikis!=8); 
  break;
  
    case 3:
      do {
        printf("-------------------RESTORAN-------------------\n");
        printf("1- Rezervasyon \n");
        printf("2- Yemek Menusu\n");
        printf("Goruntulenmesi istenen hizmeti giriniz: ");
        scanf("%d", &mutfak);
        printf("\n\n");
        switch (mutfak) {
        case 1:
          printf("-------------------REZERVASYON-------------------\n");
          do{
          MutfakRezervasyonMenusu();
  
          switch(mutfakrezervayonsecim){ 
            case 1:  Listeleme();  printf("\n\n");  break;
            case 2:  Ekleme();  printf("\n\n");   break;
            case 3:  Silme();   printf("\n\n");  break;              
          }
          printf("Cikmak icin 8'e, Rezervasyon menusune dönmek icin herhangi bir tusa basiniz: ");
          scanf("%d", &tus_1);
          } while (tus_1 != 8);
          break;
    
        case 2:         
          printf("-------------------YEMEK MENUSU-------------------\n");
          do{
          MutfakYemekMenusu();
  
          switch(mutfakyemeksecim){ 
            case 1:  Baslangic();  printf("\n\n");  break;
            case 2:  AnaYemekler();  printf("\n\n");   break;
            case 3:  Kahvalti();   printf("\n\n");  break;   
            case 4:  MezeveSalata();   printf("\n\n");  break;  
            case 5:  Tatli();   printf("\n\n");  break;  
            case 6:  Icecekler();   printf("\n\n");  break;   
          }
          printf("Cikmak icin 8'e, Yemek menusune donmek icin herhangi bir tusa basiniz: ");
          scanf("%d", &tus_1);
          } while (tus_1 != 8);          
          break;
        }
        printf("Cikmak icin 8'e, Restoran menusune donmek icin herhangi "
             "bir tusa basiniz: ");
        scanf("%d", &tus_1);
      } while (tus_1 != 8);
    break;
    default:
    printf("Yanlis Islem\n");
    break;
    }

    printf("Otomasyondan tamamen cikmak icin 8'e, Ana Menuye donmek icin "
         "herhangi bir tusa basiniz: ");
    scanf("%d", &tus_2);

  }while (tus_2 != 8);
  return 0;
}

