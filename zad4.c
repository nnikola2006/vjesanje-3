#include <stdio.h>

struct RAZLOMAK {
    int br; // brojilac
    int im; // imenilac
};

int main() 
{
    struct RAZLOMAK a, b, c; // a = prvi, b = drugi, c = rezultat

    // Ucitavanje dva razlomka
    scanf("%d %d", &a.br, &a.im); // unos prvog razlomka
    scanf("%d %d", &b.br, &b.im); // unos drugog razlomka

    // Sabiranje: a.br/a.im + b.br/b.im
    c.br = a.br * b.im + b.br * a.im; // brojilac rezultata
    c.im = a.im * b.im;               // imenilac rezultata

    // Kracenje razlomka
    int brojilacZaGCD = c.br;  
    int imenilacZaGCD = c.im;  
    int ostatak;               
    int gcd;                  

    // Euklidov algoritam (neki baja)
    while(imenilacZaGCD != 0) 
    {
        ostatak = brojilacZaGCD % imenilacZaGCD;
        brojilacZaGCD = imenilacZaGCD;
        imenilacZaGCD = ostatak;
    }
    gcd = brojilacZaGCD; // najveci zajednicki djelilac

    // Skrati razlomak
    c.br /= gcd;
    c.im /= gcd;

    // Ispis
    printf("%d %d\n", c.br, c.im);

    return 0;
}
