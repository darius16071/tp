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

int main() {
    FILE* fin = fopen("date.in", "r");
    if (!fin) {
        printf("Eroare la deschiderea fisierului\n");
        return 1;
    }

    Nod* lista_pare = NULL;
    Nod* lista_impare = NULL;
    int id;

    while (fscanf(fin, "%d", &id) != EOF) {
        if (id % 2 == 0) {
            adauga_la_sfarsit(&lista_pare, id);
        } else {
            adauga_la_sfarsit(&lista_impare, id);
        }
    }

    fclose(fin);

    printf("Lista numerelor pare:\n");
    afiseaza_lista(lista_pare);

    printf("Lista numerelor impare:\n");
    afiseaza_lista(lista_impare);

    while (lista_pare != NULL) {
        Nod* aux = lista_pare;
        lista_pare = lista_pare->urm;
        free(aux);
    }

    while (lista_impare != NULL) {
        Nod* aux = lista_impare;
        lista_impare = lista_impare->urm;
        free(aux);
    }

    return 0;
}
