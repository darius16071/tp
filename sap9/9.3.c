#include <stdio.h>
#include <stdlib.h>

typedef struct Nod {
    int id;
    struct Nod* urm;
} Nod;

Nod* element_nou(int id) {
    Nod* c = (Nod*)malloc(sizeof(Nod));
    if (!c) {
        printf("Memorie insuficienta\n");
        exit(EXIT_FAILURE);
    }
    c->id = id;
    c->urm = NULL;
    return c;
}

void adauga_la_sfarsit(Nod** prim, int id) {
    Nod* c = element_nou(id);
    if (*prim == NULL) {
        *prim = c;
    } else {
        Nod* aux = *prim;
        while (aux->urm != NULL) {
            aux = aux->urm;
        }
        aux->urm = c;
    }
}

void afiseaza_lista(Nod* prim) {
    Nod* aux = prim;
    while (aux != NULL) {
        printf("%d ", aux->id);
        aux = aux->urm;
    }
    printf("\n");
}

void insereaza_jumatate(Nod* prim) {
    Nod* aux = prim;
    while (aux != NULL) {
        if (aux->id % 2 == 0) {
            Nod* nou = element_nou(aux->id / 2);
            nou->urm = aux->urm;
            aux->urm = nou;
            aux = nou->urm;
        } else {
            aux = aux->urm;
        }
    }
}

int main() {
    Nod* prim = NULL;
    adauga_la_sfarsit(&prim, 2);
    adauga_la_sfarsit(&prim, 3);
    adauga_la_sfarsit(&prim, 4);
    adauga_la_sfarsit(&prim, 5);
    adauga_la_sfarsit(&prim, 6);

    printf("Lista initiala:\n");
    afiseaza_lista(prim);

    insereaza_jumatate(prim);

    printf("Lista dupa inserare:\n");
    afiseaza_lista(prim);

    while (prim != NULL) {
        Nod* aux = prim;
        prim = prim->urm;
        free(aux);
    }

    return 0;
}
