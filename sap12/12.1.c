/*
Aplicația 12.1: Se citesc doua numere naturale n si k. Generati si afisati toate toate numerele naturale formate din
n cifre care contin exact k cifre de 1.

*/
#include <stdio.h>
int n,k;
int v[100];

int valid(int p)
{
    return 1;
}

int solutie(int p)
{
    int i;
    if(p==n)
    {
        if(v[1]==0)
            return 0;
        
        int cnt=0;
        for(i=1;i<n;i++)
            if(v[i]==1)
                cnt++;
        if(k==cnt)
            return 1;
        else
            return 0;
    }
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

void back(int p)
{
    int i;
    if(p>n)
        return;
    
    for (i=0;i<=9;i++)
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

int main() {
    printf("n si k ");
    scanf("%d %d",&n,&k);

    back(1);
    
    return 0;
}
