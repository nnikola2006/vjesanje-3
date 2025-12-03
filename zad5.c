#include <stdio.h>
#include <math.h>

struct TROUGAO {
    double a;
    double b;    
    double c;
};

int main() 
{
    struct TROUGAO t;

    do 
    {
        printf("Unesite tri stranice trougla: ");
        scanf("%lf %lf %lf", &t.a, &t.b, &t.c);

        if(t.a <= 0 || t.b <= 0 || t.c <= 0) 
        {
            printf("Stranice moraju biti pozitivne.\n");
        } 
        else if(t.a + t.b <= t.c || t.a + t.c <= t.b || t.b + t.c <= t.a) 
        {
            printf("Nevalidan trougao, unesite ponovo.\n");
        } 
        else 
        {
            break; // trougao je validan
        }
    } while (1);

    // Obim
    double obim = t.a + t.b + t.c;

    // Površina
    double s = obim / 2.0;
    double povrsina = sqrt(s * (s - t.a) * (s - t.b) * (s - t.c));

    printf("Obim trougla: %.2lf\n", obim);
    printf("Povrsina trougla: %.2lf\n", povrsina);

    return 0;
}
