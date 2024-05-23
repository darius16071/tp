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


void sterge_primul(Nod** prim) {
    if (*prim != NULL) {
        Nod* aux = *prim;
        *prim = (*prim)->urm;
        free(aux);
    }
}


void permuta_lista(Nod** prim, int k) {
    for (int i = 0; i < k; i++) {
        if (*prim != NULL) {
            Nod* aux = *prim;
            adauga_la_sfarsit(prim, aux->id);
            sterge_primul(prim);
        }
    }
}


void afiseaza_lista(Nod* prim, FILE* out) {
    Nod* aux = prim;
    while (aux != NULL) {
        fprintf(out, "%d ", aux->id);
        aux = aux->urm;
    }
    fprintf(out, "\n");
}

int main() {
    FILE* fin = fopen("date.in", "r");
    FILE* fout = fopen("date.out", "w");
    if (!fin || !fout) {
        printf("Eroare la deschiderea fisierelor\n");
        return 1;
    }

    int k;
    fscanf(fin, "%d", &k);

    Nod* prim = NULL;
    int id;
    while (fscanf(fin, "%d", &id) != EOF) {
        adauga_la_sfarsit(&prim, id);
    }

    permuta_lista(&prim, k);

    afiseaza_lista(prim, fout);

    while (prim != NULL) {
        sterge_primul(&prim);
    }

    fclose(fin);
    fclose(fout);

    return 0;
}
