/*
Aplicația 8.3: Să se scrie un program care primește un nume de fișier în linia de comandă. Programul va citi toate
liniile din fișier într-o listă care este mereu sortată în ordine alfabetică. O linie poate avea maxim 1000 de caractere.
Pentru ca lista să fie mereu sortată alfabetic, adăugarea unei linii noi se face prin inserarea ei la poziția corectă din
listă, astfel încât să se mențină proprietatea de sortare. În final se va afișa lista.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CARACTERE 1001

typedef struct Nod {
    char linie[MAX_CARACTERE];
    struct Nod *urmator;
} Nod;

void adauga_linie_sortat(Nod **prim, const char *linie) {
    Nod *nou = (Nod *)malloc(sizeof(Nod));
    if (!nou) {
        printf("Memorie insuficienta\n");
        exit(EXIT_FAILURE);
    }
    strcpy(nou->linie, linie);
    nou->urmator = NULL;

    if (*prim == NULL || strcmp((*prim)->linie, linie) > 0) {
        nou->urmator = *prim;
        *prim = nou;
    } else {
        Nod *curent = *prim;
        while (curent->urmator != NULL && strcmp(curent->urmator->linie, linie) < 0) {
            curent = curent->urmator;
        }
        nou->urmator = curent->urmator;
        curent->urmator = nou;
    }
}

void afiseaza_lista(Nod *prim) {
    while (prim != NULL) {
        printf("%s\n", prim->linie);
        prim = prim->urmator;
    }
}

void elibereaza_lista(Nod *prim) {
    while (prim != NULL) {
        Nod *temp = prim;
        prim = prim->urmator;
        free(temp);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <nume_fisier>\n", argv[0]);
        return 1;
    }

    FILE *fisier = fopen(argv[1], "r");
    if (!fisier) {
        printf("Nu s-a putut deschide fisierul\n");
        return 1;
    }

    Nod *prim = NULL;
    char linie[MAX_CARACTERE];
    while (fgets(linie, sizeof(linie), fisier) != NULL) {
        linie[strcspn(linie, "\n")] = '\0';
        adauga_linie_sortat(&prim, linie);
    }

    fclose(fisier);

    printf("Lista sortata alfabetic:\n");
    afiseaza_lista(prim);

 
    elibereaza_lista(prim);

    return 0;
}
