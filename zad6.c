#include <stdio.h>
#include <string.h>

struct ARTIKAL {
    int id;     
    char naziv[50];     // naziv artikla
    double kolicina;
    double cijena;      // cijena po jedinici
};

int main() 
{
    int n;
    printf("Unesite broj artikala: ");
    scanf("%d", &n);

    struct ARTIKAL artikli[100];

    // Ucitavanje artikala
    for(int i = 0; i < n; i++) 
    {
        printf("Artikal %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &artikli[i].id);
        printf("Naziv: ");
        scanf(" %[^\n]", artikli[i].naziv); // cita cijeli red sa razmacima
        printf("Kolicina: ");
        scanf("%lf", &artikli[i].kolicina);
        printf("Cijena: ");
        scanf("%lf", &artikli[i].cijena);
    }

    // Sortiranje po ID-u (rastuce)
    for(int i = 0; i < n - 1; i++) 
    {
        for(int j = i + 1; j < n; j++)
        {
            if(artikli[j].id < artikli[i].id) 
            {
                struct ARTIKAL temp = artikli[i];
                artikli[i] = artikli[j];
                artikli[j] = temp;
            }
        }
    }

    // Ispis zaglavlja
    printf("\n");
    printf("===== ==================== ====== ====== =========\n");
    printf("ID    NAZIV                KOL.   CIJENA UKUPNO\n");
    printf("===== ==================== ====== ====== =========\n");

    double ukupno = 0.0;

    for(int i = 0; i < n; i++) 
    {
        double ukupno_artikla = artikli[i].kolicina * artikli[i].cijena;
        ukupno += ukupno_artikla;
        printf("%-5d %-20s %6.2lf %6.2lf %9.2lf\n",
               artikli[i].id, artikli[i].naziv,
               artikli[i].kolicina, artikli[i].cijena, ukupno_artikla);
    }

    printf("==================================================\n");
    printf("UKUPNO: %10.2lf\n", ukupno);
    printf("==================================================\n");

    return 0;
}
