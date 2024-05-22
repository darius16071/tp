/*
 De-a lungul unei șosele trebuie amplasate una lângă alta următoarele entități: case, blocuri, grădini,
ateliere. O entitate se poate învecina doar cu una de același tip (ex: casă cu casă) sau conform următoarelor reguli
(orice relație o implică și pe cea inversă): un bloc poate avea ca vecini case; o casă sau un atelier poate avea ca
vecini grădini. Se cer de la tastatură numerele c,b,g,a care reprezintă respectiv numărul de case, blocuri, grădini
și ateliere. Să se determine toate variantele în care acestea pot fi aranjate.


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
int c,b,g,a;
char cladiri[5][30] = {" ", "case", "bloc", "gradina", "atelier"};
//casa bloc gradina atelier
//1    2       3     4     

int valid(int p) 
{
    if(p!=1)
    {
        if(v[p]==1)//casa
        {
            if(v[p-1]==1 || v[p-1]==2 || v[p-1]==3)
                return 1;
        }

        if(v[p]==2)//bloc
        {
            if(v[p-1]==1|| v[p-1]==2)
                return 1;
        }

        if(v[p]==3)//gradina
        {
            if(v[p-1]==1 || v[p-1]==4 || v[p-1]==3)
                return 1;
        }

        if(v[p]==4)//atelier
        {
            if(v[p-1]==3 || v[p-1]==4 )
                return 1;
        }
    }
    else
    {
        return 1;
    }
    return 0;
}

int solutie(int p) 
{
    int cntc=0;
    int cntb=0;
    int cntg=0;
    int cnta=0;
    if(p==n)
    {
        int i;
        for(i=1;i<=p;i++)
        {
            if(v[i]==1)
                cntc++;
            if(v[i]==2)
                cntb++;
            if(v[i]==3)
                cntg++;
            if(v[i]==4)
                cnta++;
        }
        if(cntc==c && cntb==b && cntg==g && cnta==a)
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
        printf("%d",v[i]);
        printf("%s ",cladiri[v[i]]);
    }
    printf("\n");
}

void back(int k)
{
    if(k>n)
        return;
    
    for(int i=1;i<=4;i++)
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
     printf("Introduceti c ");
    scanf("%d", &c);
     printf("Introduceti b ");
    scanf("%d", &b);
     printf("Introduceti g ");
    scanf("%d", &g);
     printf("Introduceti  a");
    scanf("%d", &a);

    n=c+b+g+a;

    back(1);

}
