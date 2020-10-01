#include <stdio.h>
#include <math.h>
// cogu kisimda gosterge(pointer"*") kullandim daha kullanisli.
int bisection (float *ortalama, float a, float b, int *tkrr)
{
    *ortalama=(a+b)/2;
    ++(*tkrr);
    printf("\nTekrarlanma numarasi: %d X = %f\n", *tkrr, *ortalama);
}

//return dongusu icerisindeki pow komutu da fonksiyonde degerin katsayisini yazmakta cok yardimci oldu.
//ayriyetten kullanici icin kendi fonksiyonunu kendisi yazmasi icin n,m,l ve k degerlerinden olusan fonksiyon olusturdum.
float f(int n, int m, int l, int k, float x)
{
    return (n*pow(x,m)-l*x-k);
}

int main ()
{

//hp --> Hata Payi demektir.
//tkrr --> Tekrar demektir.
//maxtkrr --> Maximum (en fazla) Tekrar demektir.
//bazi printf ve scanf satirlarini daha acik gormem amaciyla ayrintili yazdim.
int tkrr = 0, maxtkrr, n, m, l, k;
float  x, a, b, hp, x1;
printf("\nLutfen n*x^m+l*x+k fonksiyonu icin n,m,l ve k degerlerini giriniz\n");
scanf("%d %d %d %d", &n, &m, &l, &k);
printf("\nLutfen a degerini giriniz:");
scanf("%f", &a);
printf("\nLutfen b degerini giriniz:");
scanf("%f", &b);
printf("\nLutfen hata payini giriniz:");
scanf("%f", &hp);
printf("\nLutfen maximum tekrarlanmayi giriniz:");
scanf("%d", &maxtkrr);


bisection (&x, a, b, &tkrr);

//dongulerde format hatam olabilir.
do
    {
    if (f(n, m, l, k, a)*f(n, m, l, k, x) < 0)
        b=x;
    else
        a=x;
bisection (&x1, a, b, &tkrr);
//mutlak deger dongusu icin fabs() komutunu kullandim.
       if (fabs(x1-x) < hp)
        {
    printf("%d tekrarlanmadan sonra, kok = %f\n", tkrr, x1);
        return 0;
        }
            x=x1;
    }
while (tkrr < maxtkrr);
printf("\nCozum bulunamiyor ve ya tekrarlanmalar yeterli degil!");
return 0;
}
