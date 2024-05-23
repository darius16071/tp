/*
Aplicația 9.10: Sa se construiasca o lista liniara simplu inlantuita care sa contina numere naturale. Sa se scrie o
functie care sa separe elementele pare de cele impare in 2 liste separate.
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

void separa_pare_si_impare(Nod* prim, Nod** lista_pare, Nod** lista_impare) {
    while (prim != NULL) {
        if (prim->id % 2 == 0) {
            adauga_la_sfarsit(lista_pare, prim->id);
        } else {
            adauga_la_sfarsit(lista_impare, prim->id);
        }
        prim = prim->urm;
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
    Nod* lista_pare = NULL;
    Nod* lista_impare = NULL;

    adauga_la_sfarsit(&prim, 1);
    adauga_la_sfarsit(&prim, 2);
    adauga_la_sfarsit(&prim, 3);
    adauga_la_sfarsit(&prim, 4);
    adauga_la_sfarsit(&prim, 5);

    printf("Lista initiala: ");
    afiseaza_lista(prim);

    separa_pare_si_impare(prim, &lista_pare, &lista_impare);

    printf("Lista numere pare: ");
    afiseaza_lista(lista_pare);

    printf("Lista numere impare: ");
    afiseaza_lista(lista_impare);

    Nod* temp;
    while (prim != NULL) {
        temp = prim;
        prim = prim->urm;
        free(temp);
    }
    while (lista_pare != NULL) {
        temp = lista_pare;
        lista_pare = lista_pare->urm;
        free(temp);
    }
    while (lista_impare != NULL) {
        temp = lista_impare;
        lista_impare = lista_impare->urm;
        free(temp);
    }

    return 0;
}
