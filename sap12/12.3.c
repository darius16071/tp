/*
Aplicația 12.3: Se citesc doua numere naturale n si k, k fiind mai mic decat numarul de cifre ale numarului n. Afisati
cel mai mare numar care se poate forma eliminand k cifre din numarul n.
Exemplu:
n=3452234
k=4
numarul cautat este 534
*/
#include <stdio.h>

int nr,k,n;
int v[100];
int maxi=-999;
int cifre[20];

void pune_cifre(int nr)
{
    int aux;
    n=0;
    aux=nr;
    while(aux)
    {
        n++;
        aux=aux/10;
    }
    printf("n este %d \n",n);

    int i;
    aux=nr;
    for(i=0;i<n;i++)
    {

        cifre[n-i]=aux%10;
        aux=aux/10;
    }    
}

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
    int i;
    if(p==n-k)
    {
       return 1;
    }
    return 0;
}

int numar(void)
{
    int i, nou=0;
    for (i=1; i<=(n-k);i++)
    {
        nou = nou * 10 + cifre[v[i]];
    }
    return nou;
}

void afisare(void)
{
    int i;
    for (i=1;i<=k;i++)
    {
        printf("%d ",v[i]);
    }
    printf("\n");
}

void back(int p)
{
    int i,aux;
    for (i=1;i<=n;i++)
    {
        v[p]=i;
        if (valid(p))
        {
            if (solutie(p))
            {
                afisare();
                aux= numar();
                printf("nr %d\n",aux);
                if(aux>maxi)
                    maxi=aux;
            }
            else
            {
                back(p+1);
            }
        }
    }
}

int main() {
    printf("nr si k ");
    scanf("%d %d",&nr,&k);

    pune_cifre(nr);

    back(1);

    printf("maxi este %d \n",maxi);
    
    return 0;
}
