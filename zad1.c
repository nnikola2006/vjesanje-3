#include <stdio.h>

int main()
{
    // IMA ZADATAK RIJESEN NA MOODLE ALI PALA STRANICA 

    int n;
    do{
        scanf("%d", &n);
    } while(n < 0 || n > 100);
    

    int a[200] = {0};   // dovoljno za 100! (ima 158 cifara)
    a[0] = 1;           // počinjemo od broja 1
    int duzina_broja = 1; // trenutna dužina broja

    for(int i = 2; i <= n; i++) 
    {
        int carry = 0;

        for(int j = 0; j < duzina_broja; j++)
        {
            int x = a[j] * i + carry;
            a[j] = x % 10;     // nova cifra
            carry = x / 10;    // prenos
        }
        
        // dodavanje preostalih cifara
        while(carry > 0) 
        {     
            a[duzina_broja] = carry % 10;
            carry /= 10;
            duzina_broja++;
        }
    }

    // ispis rezultata (od najteže cifre)
    for(int i = duzina_broja - 1; i >= 0; i--)
        printf("%d", a[i]);

    return 0;
}
