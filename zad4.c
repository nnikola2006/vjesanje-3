#include <stdio.h>

struct RAZLOMAK {
    int br; // brojilac
    int im; // imenilac
};

int main() 
{
    struct RAZLOMAK a, b, c; // a = prvi, b = drugi, c = rezultat

    // Ucitavanje dva razlomka
    do 
    {
        printf("Unesite prvi razlomak (brojilac >0, imenilac !=0): ");
        scanf("%d %d", &a.br, &a.im);
    } while (a.br <= 0 || a.im == 0);
    do 
    {
        printf("Unesite drugi razlomak (brojilac >0, imenilac !=0): ");
        scanf("%d %d", &b.br, &b.im);
    } while (b.br <= 0 || b.im == 0);

    // Sabiranje: a.br/a.im + b.br/b.im
    c.br = a.br * b.im + b.br * a.im; // brojilac rezultata
    c.im = a.im * b.im;               // imenilac rezultata

    // Kracenje razlomka
    int brojilacZaNZD = c.br;  
    int imenilacZaNZD = c.im;  
    int ostatak;               
    int NZD;                  

    // Euklidov algoritam (neki baja)
    while(imenilacZaNZD != 0) 
    {
        ostatak = brojilacZaNZD % imenilacZaNZD;
        brojilacZaNZD = imenilacZaNZD;
        imenilacZaNZD = ostatak;
    }
    NZD = brojilacZaNZD; // najveci zajednicki djelilac

    // Skrati razlomak
    c.br /= NZD;
    c.im /= NZD;

    // Ispis
    printf("%d %d\n", c.br, c.im);

    return 0;
}
