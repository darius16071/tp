/*
Aplicația 12.8: Se cere d de tip întreg reprezentând lungimea unei drepte și 0<n<=100 un număr de segmente. În
câte feluri se poate împărți dreapta dată în n segmente consecutive, având fiecare lungimi întregi pozitive, astfel
încât fiecare segment să fie strict mai mare decât cel de dinaintea sa?
*/
#include <stdio.h>
int n,latura;
int v[100];
int laturi[100];

int d;

int valid(int p)//daca e permutare
{
    int i;
    for (i=1;i<p;i++)
    {
        if (v[i]>=v[p])
        {
            return 0;
        }
    }
    return 1;
}

int solutie(int p)
{
    int suma=0,i;
    for(i=1;i<p;i++)
        suma=suma+v[i];
    if(suma==d && p==n)
        return 1;
    return 0;
}

void afisare(void)
{
    int i;
    for (i=1;i<=n;i++)
    {
        printf("%d ",v[i]);
    }
    printf("\n");
}

int ok=0;
int back(int p)
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
                ok++;
                return ok;
            }
            else
            {
                back(p+1);
            }
        }
    }
}

int main() {
    printf("d si n ");
    scanf("%d %d", &d, &n);
    
   
    printf("nr de posibilitati este %d \n",back(1));
    
    return 0;
}
