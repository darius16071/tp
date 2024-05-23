/*
Aplicația 8.5: Să se imlementeze o listă dublu înlănțuită care gestionează un parc de automobile. Informaţiile
relative la un automobil sunt: codul mașinii (număr între 1 si 9000), numărul de locuri (între 1 și 9), puterea (în cai
putere între 1 și 500), marca, culoarea, anul fabricaţiei maşinii (între 1800 și 2017). Parcul conține n automobile,
datele sunt citite de la tastatură. Să se scrie următoarele funcții de gestiune a mașinilor:
a) Introducerea unui automobil nou în listă la începutul listei;
b) Ștergerea unui anumit automobil din listă, al cărui cod e citit de la tastatură;
c) Afișarea întregii liste pe ecran;
d) Afișarea pe ecran doar a automobilelor cu un anumit număr de locuri, citit de la tastatură;
e) Ordonarea listei în funcție de anul fabricației.
Să se definească structura pentru o mașină cu ajutorul structurilor cu câmpuri pe biți astfel încât spațiul ocupat să
fie minim.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned int cod: 14;
    unsigned int locuri: 4;
    unsigned int putere: 9;
    unsigned int an_fabricatie: 8;
    char marca[20];
    char culoare[20];
} Masina;

typedef struct Node {
    Masina masina;
    struct Node *pred;
    struct Node *urm;
} Nod;

Nod* nodNou(Masina masina) {
    Nod* nod = (Nod*)malloc(sizeof(Nod));
    if (nod == NULL) {
        printf("Memorie insuficienta\n");
        exit(EXIT_FAILURE);
    }
    nod->masina = masina;
    nod->pred = NULL;
    nod->urm = NULL;
    return nod;
}

void inserareInceput(Nod** cap, Masina masina) {
    Nod* nod = nodNou(masina);
    if (*cap == NULL) {
        *cap = nod;
    } else {
        nod->urm = *cap;
        (*cap)->pred = nod;
        *cap = nod;
    }
}

void stergereDupaCod(Nod** cap, unsigned int cod) {
    Nod* curent = *cap;
    while (curent != NULL) {
        if (curent->masina.cod == cod) {
            if (curent->pred != NULL) {
                curent->pred->urm = curent->urm;
            } else {
                *cap = curent->urm;
            }
            if (curent->urm != NULL) {
                curent->urm->pred = curent->pred;
            }
            free(curent);
            return;
        }
        curent = curent->urm;
    }
    printf("Automobilul cu codul %d nu a fost gasit.\n", cod);
}

void afisareLista(Nod* cap) {
    Nod* curent = cap;
    printf("Lista automobilelor din parc:\n");
    while (curent != NULL) {
        printf("Cod: %d, Locuri: %d, Putere: %d CP, An Fabricatie: %d, Marca: %s, Culoare: %s\n", 
               curent->masina.cod, curent->masina.locuri, curent->masina.putere, 
               curent->masina.an_fabricatie, curent->masina.marca, curent->masina.culoare);
        curent = curent->urm;
    }
}

void afisareDupaLocuri(Nod* cap, unsigned int locuri) {
    Nod* curent = cap;
    printf("Automobilele cu %d locuri:\n", locuri);
    while (curent != NULL) {
        if (curent->masina.locuri == locuri) {
            printf("Cod: %d, Locuri: %d, Putere: %d CP, An Fabricatie: %d, Marca: %s, Culoare: %s\n", 
               curent->masina.cod, curent->masina.locuri, curent->masina.putere, 
               curent->masina.an_fabricatie, curent->masina.marca, curent->masina.culoare);
        }
        curent = curent->urm;
    }
}

int comparareDupaAn(const void* a, const void* b) {
    Masina* masinaA = (Masina*)a;
    Masina* masinaB = (Masina*)b;
    return masinaA->an_fabricatie - masinaB->an_fabricatie;
}

void sortareDupaAn(Nod** cap) {
    int count = 0;
    Nod* curent = *cap;
    while (curent != NULL) {
        count++;
        curent = curent->urm;
    }

    Masina* masini = (Masina*)malloc(count * sizeof(Masina));
    if (masini == NULL) {
        printf("Memorie insuficienta\n");
        exit(EXIT_FAILURE);
    }

    curent = *cap;
    int i = 0;
    while (curent != NULL) {
        masini[i++] = curent->masina;
        curent = curent->urm;
    }

    qsort(masini, count, sizeof(Masina), comparareDupaAn);

    curent = *cap;
    i = 0;
    while (curent != NULL) {
        curent->masina = masini[i++];
        curent = curent->urm;
    }

    free(masini);
}

void eliberareLista(Nod* cap) {
    Nod* curent = cap;
    while (curent != NULL) {
        Nod* temp = curent;
        curent = curent->urm;
        free(temp);
    }
}

int main() {
    Nod* cap = NULL;

    int num_masini;
    printf("Introduceti numarul de automobile in parc: ");
    scanf("%d", &num_masini);

    for (int i = 0; i < num_masini; ++i) {
        Masina masina;
        printf("\nIntroduceti datele pentru automobilul %d:\n", i + 1);
        printf("Cod: ");
        scanf("%u", &masina.cod);
        printf("Numar locuri (1-9): ");
        scanf("%u", &masina.locuri);
        printf("Putere (1-500 CP): ");
        scanf("%u", &masina.putere);
        printf("An fabricatie (1800-2017): ");
        scanf("%u", &masina.an_fabricatie);
        printf("Marca: ");
        scanf("%s", masina.marca);
        printf("Culoare: ");
        scanf("%s", masina.culoare);
        inserareInceput(&cap, masina);
    }

    printf("\nLista initiala:\n");
    afisareLista(cap);

    unsigned int cod_sters;
    printf("\nIntroduceti codul automobilului pe care doriti sa il stergeti: ");
    scanf("%u", &cod_sters);
    stergereDupaCod(&cap, cod_sters);

    printf("\nLista dupa stergerea automobilului cu codul %u:\n", cod_sters);
    afisareLista(cap);

    unsigned int locuri_afisare;
    printf("\nIntroduceti numarul de locuri pentru afisarea automobilelor: ");
    scanf("%u", &locuri_afisare);
    afisareDupaLocuri(cap, locuri_afisare);

    sortareDupaAn(&cap);
    printf("\nLista sortata dupa anul fabricatiei:\n");
    afisareLista(cap);

    eliberareLista(cap);

    return 0;
}
