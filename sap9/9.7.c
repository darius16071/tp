/*
Aplicația 9.7: Se considera o lista liniara dublu inlantuita ale carei noduri sunt memorare cifre. Sa se scrie o functie
care primeste ca parametru adresa primului nod al listei si verifica daca numarul care se compune din cifrele
memorare in lista in ordine este sau nu palindrom. Functia va returna 1 daca este palindrom si 0 in caz contrar.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Nod {
    int cifra;
    struct Nod* urm;
    struct Nod* pred;
} Nod;

typedef struct {
    Nod* prim;
    Nod* ultim;
} Lista;

Nod* element_nou(int cifra) {
    Nod* c = (Nod*)malloc(sizeof(Nod));
    if (!c) {
        printf("Memorie insuficienta\n");
        exit(EXIT_FAILURE);
    }
    c->cifra = cifra;
    c->urm = NULL;
    c->pred = NULL;
    return c;
}

void adauga_la_sfarsit(Lista* lista, int cifra) {
    Nod* c = element_nou(cifra);
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
        printf("%d ", aux->cifra);
        aux = aux->urm;
    }
    printf("\n");
}

int este_palindrom(Lista* lista) {
    if (lista->prim == NULL) {
        return 1;
    }

    Nod* inceput = lista->prim;
    Nod* sfarsit = lista->ultim;

    while (inceput != sfarsit && inceput->pred != sfarsit) {
        if (inceput->cifra != sfarsit->cifra) {
            return 0;
        }
        inceput = inceput->urm;
        sfarsit = sfarsit->pred;
    }

    return 1;
}

int main() {
    Lista lista = {NULL, NULL};

    adauga_la_sfarsit(&lista, 1);
    adauga_la_sfarsit(&lista, 2);
    adauga_la_sfarsit(&lista, 3);
    adauga_la_sfarsit(&lista, 2);
    adauga_la_sfarsit(&lista, 1);

    printf("Lista initiala:\n");
    afiseaza_lista(&lista);

    if (este_palindrom(&lista)) {
        printf("Numarul este palindrom.\n");
    } else {
        printf("Numarul nu este palindrom.\n");
    }

    // Eliberăm memoria rămasă
    while (lista.prim != NULL) {
        Nod* aux = lista.prim;
        lista.prim = lista.prim->urm;
        free(aux);
    }

    return 0;
}
