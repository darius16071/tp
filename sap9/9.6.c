/*
Aplicația 9.6: Se considera o lista liniara dublu inlantuita. Sa se scrie o functie care primeste ca parametru adresa
primului nod al listei si muta ultimul nod in fata primului.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Nod {
    int id;
    struct Nod* urm;
    struct Nod* pred;
} Nod;

typedef struct {
    Nod* prim;
    Nod* ultim;
} Lista;

Nod* element_nou(int id) {
    Nod* c = (Nod*)malloc(sizeof(Nod));
    if (!c) {
        printf("Memorie insuficienta\n");
        exit(EXIT_FAILURE);
    }
    c->id = id;
    c->urm = NULL;
    c->pred = NULL;
    return c;
}

void adauga_la_sfarsit(Lista* lista, int id) {
    Nod* c = element_nou(id);
    if (lista->prim == NULL) {
        lista->prim = c;
        lista->ultim = c;
    } else {
        c->pred = lista->ultim;
        lista->ultim->urm = c;
        lista->ultim = c;
    }
}

void afiseaza_lista(Lista* lista) {
    Nod* aux = lista->prim;
    while (aux != NULL) {
        printf("%d ", aux->id);
        aux = aux->urm;
    }
    printf("\n");
}

void muta_ultimul_in_fata(Lista* lista) {
    if (lista->prim == NULL || lista->prim == lista->ultim) {
        return;
    }

    Nod* ultimul = lista->ultim;
    lista->ultim = ultimul->pred;
    lista->ultim->urm = NULL;

    ultimul->pred = NULL;
    ultimul->urm = lista->prim;
    lista->prim->pred = ultimul;
    lista->prim = ultimul;
}

int main() {
    Lista lista = {NULL, NULL};

    adauga_la_sfarsit(&lista, 1);
    adauga_la_sfarsit(&lista, 2);
    adauga_la_sfarsit(&lista, 3);
    adauga_la_sfarsit(&lista, 4);

    printf("Lista initiala:\n");
    afiseaza_lista(&lista);

    muta_ultimul_in_fata(&lista);

    printf("Lista dupa mutarea ultimului nod in fata primului:\n");
    afiseaza_lista(&lista);

    // Eliberăm memoria rămasă
    while (lista.prim != NULL) {
        Nod* aux = lista.prim;
        lista.prim = lista.prim->urm;
        free(aux);
    }

    return 0;
}
