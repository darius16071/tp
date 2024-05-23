/*
Aplicația 9.9: Sa se construiasca o lista liniara simplu inlantuita cu elemente numere intregi. Sa se stearga din
lista elementele pare.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Nod {
    int id;
    struct Nod* urm;
} Nod;

void adauga_la_sfarsit(Nod** prim, int id) {
    Nod* nou = (Nod*)malloc(sizeof(Nod));
    if (nou == NULL) {
        printf("Memorie insuficienta\n");
        exit(EXIT_FAILURE);
    }
    nou->id = id;
    nou->urm = NULL;

    if (*prim == NULL) {
        *prim = nou;
    } else {
        Nod* temp = *prim;
        while (temp->urm != NULL) {
            temp = temp->urm;
        }
        temp->urm = nou;
    }
}

void sterge_elementele_pare(Nod** prim) {
    while (*prim != NULL && (*prim)->id % 2 == 0) {
        Nod* temp = *prim;
        *prim = (*prim)->urm;
        free(temp);
    }

    if (*prim == NULL) {
        return;
    }

    Nod* curent = *prim;
    while (curent->urm != NULL) {
        if (curent->urm->id % 2 == 0) {
            Nod* temp = curent->urm;
            curent->urm = curent->urm->urm;
            free(temp);
        } else {
            curent = curent->urm;
        }
    }
}

void afiseaza_lista(Nod* prim) {
    while (prim != NULL) {
        printf("%d ", prim->id);
        prim = prim->urm;
    }
    printf("\n");
}

int main() {
    Nod* prim = NULL;

    adauga_la_sfarsit(&prim, 1);
    adauga_la_sfarsit(&prim, 2);
    adauga_la_sfarsit(&prim, 3);
    adauga_la_sfarsit(&prim, 4);
    adauga_la_sfarsit(&prim, 5);

    printf("Lista initiala: ");
    afiseaza_lista(prim);

    sterge_elementele_pare(&prim);

    printf("Lista dupa stergerea elementelor pare: ");
    afiseaza_lista(prim);

    // Eliberăm memoria rămasă
    Nod* temp;
    while (prim != NULL) {
        temp = prim;
        prim = prim->urm;
        free(temp);
    }

    return 0;
}
