/*
Aplicația 12.2: Se citeste un numar natural n. Afisati permutarile multimii 1,2,3...n in care pana la jumatate
elementele sunt in ordine descrescatoare, iar de la jumatate pana la final in ordine crescatoare.
Exemplu:
n=5
permutarile care respecta conditia sunt:
3 2 1 4 5
4 2 1 3 5
4 3 1 2 5
5 2 1 3 4
5 3 1 2 4
5 4 1 2 3

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
int n;
int v[100];

int valid(int p)//daca e permutare
{
    int i;
    for (i=1;i<p;i++)
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
    int mijloc, i, j;
    if (p==n)
    {
        mijloc = n/2 + n%2;
        for (i=1;i<mijloc;i++)
        {
            for (j=i+1;j<=mijloc;j++)
            {
                if (v[i]<v[j])
                {
                    return 0;
                }
            }
        }
        for (i=mijloc;i<n;i++)
        {
            for (j=i+1;j<=n;j++)
            {
                if (v[i]>v[j])
                {
                    return 0;
                }
            }
        }
        return 1;
    }
    else
    {
        return 0;
    }
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


int main() {
    printf("Introduceti n ");
    scanf("%d", &n);

    back(1);

    return 0;
}
