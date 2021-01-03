İÇİNDEKİLER

GİRİŞ
KOD AÇIKLAMASI
2.1 KÜTÜPHANELER
2.2 DEĞİŞKENLER
2.3 FONKSİYONLAR
4 ANA FONKSİYON
1. GİRİŞ

Matris işlemleri için yapılan program matrislerde toplama, çıkarma,
çarpım işlemlerinin yanı sıra matrisin involutifliğini kontrol etme,
determinantını alma, tersini alma gibi işlemler yapmaktadır.

2. KOD AÇIKLAMASI
2.1 Kütüphaneler
“#include <stdio.h>” kütüphanesi temel C kütüphanesidir. Standart
input output dosyalarını eklemeye yarar.

“# include <windows.h>” kütüphanesi Windows dışındaki sistemlerde
yazılmış bazı kodları Windows kullanan sistemlerin tanımasını sağlar.

“#include <stdbool.h>” kütüphanesi kontrol işlem komutlarını içerir.

2.2 Değişkenler
“m1”, ”m2” değişkenleri kullanıcıya sunulan seçeneklerden bir cevap
almak için oluşturulan yapılardır.

“I” değişkeni birim matristir, “mToplama”, “mCikarma” matrislerin

toplamının ve farkının değerlerini döndürür.

2.3 Fonksiyonlar

“gotoxy” , konsolda oluşturulan arayüzün konumunu belirlemek için
kullanılan fonksiyondur.

“cerceve” , arayüzün kenarlarını oluşturmak için kullanılan
fonksiyondur.

“matrisYaz” , kullanıcının yazacağı değerleri alan fonksiyondur.

“topla” , A ve B matrislerinin toplama işleminin gerçekleştiği
fonksiyondur.

“cikar” , A ve B matrislerinin çıkarma işleminin gerçekleştiği
fonksiyondur.

“carp” , A ve B matrislerinin çarpma işleminin gerçekleştiği
fonksiyondur.

“det3” , A matrisinin determinantının alındığı fonksiyondur.

“isInvolutif” , A matrisinin involutif olup olmadığını döndüren
fonksiyondur.

“det2”, “kofactorDizisi”,”ekMatris” fonksiyonları A matrisinin ek
matrisini döndüren fonksiyonlardır.

“mT” , A matrisinin tersi işleminin gerçekleştiği fonksiyondur.

“toplamYaz”, “farkYaz”, “carpimYaz”, “matrisinTersi”, “toolbar”
fonksiyonları arayüzde belirlenen yazdırma işlemlerinin gerçekleşmesi
için kullanılan fonksiyonlardır.

2.4 Ana Fonksiyon

“system(“color 0D”);” kodu konsolun rengini belirtir.

“MessageBox” komutu program çalıştırıldığında ekrana gelen uyarı
yazısını belirtir.

“printf” komutu metni yazdırmak için kullanılan komuttur.

“if-else” şart-koşul kipini sağlayan komuttur. (Eğer kod yanlış
girildiyse hata ver!)

“scanf” kullanıcıdan veri almayı sağlayan komuttur.

“switch-case” komutları kullanıcının seçeneklerini almasına göre
hareketin belirleneceği kod bölümüdür.
