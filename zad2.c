#include <stdio.h>

int main()
{
    int n1, m1, n2, m2; 
    double A[10][10], B[10][10], C[10][10]; // kompajler izbacuje gresku ako stavim n1,m1 itd.
    do{
        printf("Unesite dimenzije prve matrice (n m): ");
        scanf("%d %d", &n1, &m1);
    } while(n1 <= 0 || n1 > 10 || m1 <= 0 || m1 > 10);

    // Ucitavanje prve matrice
    for(int i = 0; i < n1; i++)
        for(int j = 0; j < m1; j++)
            scanf("%lf", &A[i][j]);

    // Ucitavanje druge matrice
    do{
        printf("Unesite dimenzije druge matrice (n m): ");
        scanf("%d %d", &n2, &m2);
    } while(n2 <= 0 || n2 > 10 || m2 <= 0 || m2 > 10);

    // Ucitavanje druge matrice
    for(int i = 0; i < n2; i++)
        for(int j = 0; j < m2; j++)
            scanf("%lf", &B[i][j]);

    // Sabiranje
    if(n1 == n2 && m1 == m2)
    {
        printf("Zbir matrica:\n");
        for(int i = 0; i < n1; i++) 
        {
            for(int j = 0; j < m1; j++) 
            {
                C[i][j] = A[i][j] + B[i][j];
                printf("%.2lf ", C[i][j]);
            }
            printf("\n");
        }
    } 
    else 
    {
        printf("Matrice se ne mogu sabrati.\n");
    }

    // Mnozenje
    if(m1 == n2)
    {
        printf("Proizvod matrica:\n");
        for(int i = 0; i < n1; i++)
        {
            for(int j = 0; j < m2; j++)
            {
                C[i][j] = 0;
                for(int k = 0; k < m1; k++)
                    C[i][j] += A[i][k] * B[k][j];
                
                printf("%.2lf ", C[i][j]);
            }
            printf("\n");
        }
    } 
    else
    {
        printf("Matrice se ne mogu pomnoziti.\n");
    }

    return 0;
}
