#include <stdio.h>
#include <string.h>

struct DATUM {
    int dan;
    int mjesec;
    int godina;
};

struct STUDENT {
    int brojIndeksa;
    char ime[50];
    char prezime[50];
    struct DATUM datumRodjenja;
    double prosjek;
};

int main() 
{
    int n;
    printf("Unesite broj studenata: ");
    scanf("%d", &n);

    struct STUDENT studenti[100];

    // Ucitavanje podataka o studentima
    for(int i = 0; i < n; i++) 
    {
        printf("Student %d:\n", i + 1);
        printf("Broj indeksa: ");
        scanf("%d", &studenti[i].brojIndeksa);

        printf("Prezime: ");
        scanf(" %[^\n]", studenti[i].prezime);

        printf("Ime: ");
        scanf(" %[^\n]", studenti[i].ime);

        printf("Datum rodjenja (dd mm gggg): ");
        scanf("%d %d %d", &studenti[i].datumRodjenja.dan,
                           &studenti[i].datumRodjenja.mjesec,
                           &studenti[i].datumRodjenja.godina);

        printf("Prosjek: ");
        scanf("%lf", &studenti[i].prosjek);
    }

    // Sortiranje po datumu rodjenja (najstariji prvi)
    for(int i = 0; i < n - 1; i++) 
    {
        for(int j = i + 1; j < n; j++)
        {
            // Provjera godine, mjeseca i dana (zahvalli se etf-u na gadan if)
            if((studenti[j].datumRodjenja.godina < studenti[i].datumRodjenja.godina) ||
                (studenti[j].datumRodjenja.godina == studenti[i].datumRodjenja.godina &&
                 studenti[j].datumRodjenja.mjesec < studenti[i].datumRodjenja.mjesec) ||
                (studenti[j].datumRodjenja.godina == studenti[i].datumRodjenja.godina &&
                 studenti[j].datumRodjenja.mjesec == studenti[i].datumRodjenja.mjesec &&
                 studenti[j].datumRodjenja.dan < studenti[i].datumRodjenja.dan))
            {  
                struct STUDENT temp = studenti[i];
                studenti[i] = studenti[j];
                studenti[j] = temp;
            }
        }
    }

    // Formatirani ispis
    printf("\nRB. %-15s %-15s %-10s %-7s\n", "PREZIME", "IME", "DATUM RODJ.", "PROSJEK");
    printf("=== =============== =============== =========== =======\n");

    for(int i = 0; i < n; i++)
    {
        struct STUDENT s = studenti[i];
        printf("%d. %-15s %-15s %02d.%02d.%04d %7.2lf\n",
               i + 1,
               s.prezime,
               s.ime,
               s.datumRodjenja.dan,
               s.datumRodjenja.mjesec,
               s.datumRodjenja.godina,
               s.prosjek);
    }

    printf("=== =============== =============== =========== =======\n");

    return 0;
}
