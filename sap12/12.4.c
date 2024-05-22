/*
Aplicația 12.4: Se dau urmatoarele 6 culori: alb, galben, rosu, verde, albastru si negru.
Costruiti toate steagurile formate din 3 culori care indeplinesc urmatoarele conditii:
- orice steag trebuie sa contina culoarea verde sau culoarea galben la mijloc.
- culorile din fiecare steag trebuie sa fie distincte.

void back(int k)
{
    for(int i=1;i<=n;i++)
    {
     v[k]=i;
     if (valid(k))
        if(solutie(k))
            afisare();
        else
            back(k+1);
    }
}

*/
#include <stdio.h>
int n=3;
int v[10];
char culori[7][30] = {" ", "alb", "galben", "rosu", "verde", "albastru", "negru"};
//alb, galben, rosu, verde, albastru si negru.
//1    2       3     4       5           6

int valid(int p) 
{
    for (int i = 1; i < p; ++i) 
    {
        if (v[i] == v[p]) 
        {
            return 0;
        }
    }
    return 1;
}

int solutie(int p) 
{
    if(p==3)
    {
        if(v[2]==2 || v[2]==4)
            return 1;
        return 0;
    }
    return 0;
}

void afisare(void)
{
    int i;
    for (i=1;i<=n;i++)
    {
        printf("%d",v[i]);
        printf("%s ",culori[v[i]]);
    }
    printf("\n");
}

void back(int k)
{
    for(int i=1;i<=6;i++)
    {
     v[k]=i;
     if (valid(k))
        if(solutie(k))
            afisare();
        else
            back(k+1);
    }
}

int main(void)
{
    back(1);

}
