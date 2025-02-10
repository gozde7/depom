//
//  main.c
//  ödev1
//
//  Created by gözde on 7.02.2025.
//
#include <stdio.h>
#include <time.h>

// Tarih ve saat bilgisini saklamak için struct tanımlıyorum burda kullanacağım değişkenleride tanımlıyorum
struct DateTime {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
};

// Zaman bilgilerini saklamak için union tanımlıyorum
union TimeData {
    struct DateTime dt;
    time_t epoch;
};

// Kullanıcının girdiği tarih ve saat bilgilerini epoch zamanına çeviren fonksiyon epoch belirli bir tarihten girdiğimiz tarihe kadar olan süreyi saniye olarak hesaplar
time_t convertToEpoch(struct DateTime dt) {
    struct tm timeStruct = {0};
    timeStruct.tm_year = dt.year - 1900;
    timeStruct.tm_mon = dt.month - 1;
    timeStruct.tm_mday = dt.day;
    timeStruct.tm_hour = dt.hour;
    timeStruct.tm_min = dt.minute;
    timeStruct.tm_sec = dt.second;
    return mktime(&timeStruct);
}

int main(void) {
    union TimeData t1, t2;
    time_t epoch1, epoch2;
    
    // Kullanıcıdan ilk tarih ve saat bilgisini aldım bu bizim referansımızdır epoch zamanı girdiğimiz değerlere bakarak hesaplar
    printf("Birinci tarihi girin (Yıl Ay Gün Saat Dakika Saniye): ");
    scanf("%d %d %d %d %d %d", &t1.dt.year, &t1.dt.month, &t1.dt.day, &t1.dt.hour, &t1.dt.minute, &t1.dt.second);
    
    // Kullanıcıdan ikinci tarih ve saat bilgisini aldım
    printf("İkinci tarihi girin (Yıl Ay Gün Saat Dakika Saniye): ");
    scanf("%d %d %d %d %d %d", &t2.dt.year, &t2.dt.month, &t2.dt.day, &t2.dt.hour, &t2.dt.minute, &t2.dt.second);
    
    // Epoch zamanına çevirme
    epoch1 = convertToEpoch(t1.dt);
    epoch2 = convertToEpoch(t2.dt);
    
    // Sonuçları ekrana yazdırdım epoch saniye olarak hesaplar ve bizde burda ekrana yazdırıcaz
    printf("\nBirinci tarih için Epoch zamanı: %ld\n", epoch1);
    printf("İkinci tarih için Epoch zamanı: %ld\n", epoch2);
    printf("İki tarih arasındaki fark: %ld saniye\n", (epoch2 - epoch1));
    
    return 0;
}

// birinci epoch'u ikinciden çıkarmıştır ve iki tarih arasındaki süreyi çıkararak bulmuştur.
