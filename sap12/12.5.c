/*
Aplicația 12.5: Se cere un 0<n<=100 și apoi n valori reale, fiecare reprezentând volumul unui obiect. În final se
cere v, volumul unei cutii. Se cere să se umple cutia cu unele dintre obiecte date, astfel încât volumul ei să fie
utilizat în mod optim.
*/
#include <stdio.h>
int n,v[100];
float vvolum[100];
float volum;

int valid(int p) 
{
    for (int i=1;i<p;++i) 
    {
        if (v[i]==v[p]) 
        {
            return 0;
        }
    }
    return 1;
}

int solutie(int p)
{
    int i;
    float suma=0.0;
    for(i=1;i<=p;i++)
        suma=suma+vvolum[v[i]];
    if(suma<=volum)
        return 1;
    return 0;
}

void afisare(void)
{
    int i;
    for (i=1;i<=n;i++)
    {
        printf("%d",vvolum[v[i]]);
    }
    printf("\n");
}

void back(int p)
{
    int i;
    for (i=1;i<=n;i++)
    {
        v[p]=i;
        if (valid(p))
        {
            if (solutie(p))
            {
                afisare();
            }
            else
            {
                back(p+1);
            }
        }
    }
}
int main(void)
{
    printf("Introduceti n si volum cutie ");
    scanf("%d %.2f", &n, &volum);

    int i;
    for(i=1;i<=n;i++)
        scanf("%.2f",&vvolum[i]);

    back(1);
}
