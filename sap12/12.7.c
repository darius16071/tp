/*
Aplicația 12.7: Se cere 0<n<=100 și apoi n valori pozitive întregi, reprezentând laturile unor pătrate. În final se
cere 0<p<=100, valoare întreagă, reprezentând latura unui pătrat. Se cere să se determine dacă există un
aranjament al celor n pătrate în interiorul pătratului de latură p, astfel încât toate pătratele să fie conținute în acesta
și să nu existe suprapuneri între pătrate.
*/
#include <stdio.h>
int n,latura;
int v[100];
int laturi[100];

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
    int am=0,as=0,i;
    am=latura*latura;
    for(i=1;i<=p;i++)
        as=as+v[i]*v[i];
    if(as <= am && p==n)
        return 1;
    return 0;
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
                ok=1;
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
    printf("Introduceti numarul de patrate si latura patratului mare: ");
    scanf("%d %d", &n, &latura);
    
    printf("Introduceti laturile patratelor mici:\n");
    for (int i = 0; i < n; ++i) {
        scanf("%d", &laturi[i]);
    }
    
    if (back(1)) {
        printf("Da, este posibil sa se aranjeze toate patratele in interiorul patratului mare.\n");
    } else {
        printf("Nu, nu este posibil sa se aranjeze toate patratele in interiorul patratului mare.\n");
    }
    
    return 0;
}
