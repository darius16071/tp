/*
Aplicația 10.8: Să se implementeze cu o functie recursivă căutarea binară pe un vector ordonat (Binary Search -
bsearch). Functia trebuie să returneze dacă numărul căutat există sau nu în vector. Principiul după care
funcționează bsearch este că vectorul se împarte la fiecare pas în 2 vectori de dimensiuni egale (sau aproximativ
egale) și continuă căutarea doar în unul dintre ei (apelează recursiv funcția de căutare doar pe jumătate din vectorul
inițial), cel din partea stângă sau cel din partea dreaptă, în funcție de valoarea numărului căutat.
Exemplu:
v = 1, 5, 8, 12, 17, 20, 33, 40 , n = 33
imparte v in 2 vectori egali :v1 = 1, 5, 8, 12 v2 = 17, 20, 33, 40
continua cautarea lui n = 33 in vectorul v2
acum v = 17, 20, 33, 40, n=33
imparte v in 2 vectori egali :v1 = 17, 20 v2 = 33, 40
continua cautarea lui n = 33 in vectorul v2
acum v = 33, 40, n=33
imparte v in 2 vectori egali :v1 = 33 v2 = 40
continua cautarea lui n = 33 in vectorul v1
acum v = 33, n=33
l-a gasit
*/
#include <stdio.h>

int bsearch_rec(int v[], int stanga, int dreapta, int n) {
    if (stanga > dreapta) {
        return 0; // Elementul nu a fost găsit
    }

    int mijloc = (stanga + dreapta) / 2;

    if (v[mijloc] == n) 
        return 1; 

    else if (v[mijloc] < n)
        return bsearch_rec(v, mijloc + 1, dreapta, n);

    else
        return bsearch_rec(v, stanga, mijloc - 1, n);
}

int main() {
    int v[] = {1, 5, 8, 12, 17, 20, 33, 40};
    int dimensiune = sizeof(v) / sizeof(v[0]);
    int n = 33;
    
    int rezultat = bsearch_rec(v, 0, dimensiune - 1, n);

    if (rezultat) {
        printf("Elementul %d a fost gasit.\n", n);
    } else {
        printf("Elementul %d nu a fost gasit.\n", n);
    }

    return 0;
}
