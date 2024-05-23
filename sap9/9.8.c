/*
Aplicația 9.8: Sa se scrie o functie care primeste ca parametru adresa primului nod al unei liste liniare simplu
inlantuite cu cel putin 3 noduri si muta primul nod al listei dupa ultimul nod al listei.
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

void muta_primul_dupa_ultimul(Nod** prim) {
    if (*prim == NULL || (*prim)->urm == NULL || (*prim)->urm->urm == NULL) {
        printf("Lista trebuie sa contina cel putin 3 noduri pentru a face mutarea.\n");
        return;
    }

    Nod* ultim = *prim;
    while (ultim->urm != NULL) {
        ultim = ultim->urm;
    }

    Nod* primul = *prim;
    *prim = primul->urm;
    primul->urm = NULL;
    ultim->urm = primul;
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

    printf("Lista initiala: ");
    afiseaza_lista(prim);

    muta_primul_dupa_ultimul(&prim);

    printf("Lista dupa mutare: ");
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
