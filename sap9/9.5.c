/*
Aplicația 9.5: Se considera o lista liniara dublu inlantuita. Sa se scrie o functie care primeste ca parametru adresa
primului nod al listei si sterge primul si ultimul nod din lista.
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

void sterge_primul_si_ultimul(Lista* lista) {
    if (lista->prim == NULL) {
        return;
    }
    
    if (lista->prim == lista->ultim) {
        free(lista->prim);
        lista->prim = NULL;
        lista->ultim = NULL;
        return;
    }

    Nod* primul = lista->prim;
    Nod* ultimul = lista->ultim;

    lista->prim = primul->urm;
    lista->prim->pred = NULL;
    free(primul);

    lista->ultim = ultimul->pred;
    lista->ultim->urm = NULL;
    free(ultimul);
}

int main() {
    Lista lista = {NULL, NULL};

    adauga_la_sfarsit(&lista, 1);
    adauga_la_sfarsit(&lista, 2);
    adauga_la_sfarsit(&lista, 3);
    adauga_la_sfarsit(&lista, 4);

    printf("Lista initiala:\n");
    afiseaza_lista(&lista);

    sterge_primul_si_ultimul(&lista);

    printf("Lista dupa stergerea primului si ultimului nod:\n");
    afiseaza_lista(&lista);

    // Eliberăm memoria rămasă
    while (lista.prim != NULL) {
        Nod* aux = lista.prim;
        lista.prim = lista.prim->urm;
        free(aux);
    }

    return 0;
}
