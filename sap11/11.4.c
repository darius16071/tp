/*
Aplicația 11.4: La un campionat iau parte n jucători, fiecare definit prin nume (max 15 caractere) și valoare (int).
Jucătorii sunt distribuiți în m grupe, n divizibil cu m. Distribuția jucătorilor în grupe se face după valoarea lor, astfel
încât cei mai valoroși m jucători să fie fiecare în altă grupă, apoi următorii m cei mai valoroși rămași să fie și ei în
grupe diferite și tot așa, până când toți jucătorii sunt distribuiți. Să se afișeze împărțirea jucătorilor pe grupe, pentru
valori citite dintr-un fișier.
greedy
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nume[16];
    int valoare;
} Jucator;

int comparaJucatori(const void *a, const void *b) {
    Jucator *jucatorA = (Jucator *)a;
    Jucator *jucatorB = (Jucator *)b;
    return jucatorB->valoare - jucatorA->valoare;
}

int main() {
    int n, m;

    FILE *input = fopen("jucatori.txt", "r");
    if (input == NULL) {
        printf("Nu se poate deschide fișierul 'jucatori.txt'.\n");
        return 1;
    }

    fscanf(input, "%d %d", &n, &m);

    Jucator *jucatori = (Jucator *)malloc(n * sizeof(Jucator));

    for (int i = 0; i < n; i++) {
        fscanf(input, "%s %d", jucatori[i].nume, &jucatori[i].valoare);
    }

    fclose(input);

    qsort(jucatori, n, sizeof(Jucator), comparaJucatori);

    Jucator **grupe = (Jucator **)malloc(m * sizeof(Jucator *));
    for (int i = 0; i < m; i++) {
        grupe[i] = (Jucator *)malloc((n / m) * sizeof(Jucator));
    }

    for (int i = 0; i < n; i++) {
        grupe[i % m][i / m] = jucatori[i];
    }

    for (int i = 0; i < m; i++) {
        printf("Grupa %d:\n", i + 1);
        for (int j = 0; j < n / m; j++) {
            printf("  %s %d\n", grupe[i][j].nume, grupe[i][j].valoare);
        }
    }

    for (int i = 0; i < m; i++) {
        free(grupe[i]);
    }
    free(grupe);
    free(jucatori);

    return 0;
}
