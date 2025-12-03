#include <stdio.h>
#include <math.h>

struct KOMPLEKS{
    double re;
    double im;
};

int main()
{
    int n;
    do{
        scanf("%d", &n);
    } while(n <= 0 || n > 100);

    // nije definisana max velicina n pa je niz nama 100 moze biti koliko god velik
    struct KOMPLEKS a[100];

    // Ucitavanje n kompleksnih brojeva
    for(int i = 0; i < n; i++)
        scanf("%lf %lf", &a[i].re, &a[i].im);

    // Sortiranje opadajuce po modulu
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            // Modul prvog
            double m1 = a[i].re * a[i].re + a[i].im * a[i].im;

            // Modul drugog
            double m2 = a[j].re * a[j].re + a[j].im * a[j].im;

            // Poređenje modula (bez sqrt, jer realno ne treba kad je 25 > 16, onda je i 5 > 4)
            // al kao nije greska stavit
            if(m2 > m1)
            {
                struct KOMPLEKS temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    // Ispis
    for(int i = 0; i < n; i++)
        printf("(%.2lf, %.2lf)\n", a[i].re, a[i].im);

    return 0;
}
