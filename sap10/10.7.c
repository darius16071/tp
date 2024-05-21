/*
: Serii de puteri. Calculaţi, cu o precizie dată, valoarea lui ex după dezvoltarea în serie Taylor:
ex = 1 + x1
/1! + x2
/2! + x3
/3! + ...
Calculaţi suma până când termenul curent devine mai mic decât o valoare dată (de ex. 10-6
). Pentru a evita
recalcularea lui n! transmiteţi ca parametru şi termenul curent, şi calculaţi-l pe următorul după relaţia: xn
/n! = xn1
/(n-1)! * x/n.
*/
#include <stdio.h>

float serieTaylor(float *val, float *ant, int *n, int x, float precizie) 
{
    if (*ant < precizie) 
    {
        return *val;
    } 
    else 
    {
        *n = *n + 1;
        *ant = *ant * x / *n;
        *val= *val + *ant;
        return serieTaylor(val, ant, n, x, precizie);
    }
}

int main() {
    int x;
    float precizie;
    printf("Introduceți valoarea lui x: ");
    scanf("%d", &x);
    printf("Introduceți precizia dorită: ");
    scanf("%f", &precizie);

    float valoare = 1.0;
    float termenAnterior = 1.0;
    int n = 1;

    float rezultat = serieTaylor(&valoare, &termenAnterior, &n, x, precizie);

    printf("Valoarea aproximată a lui e^%d este: %f\n", x, rezultat);

    return 0;
}
