/*
8.4
Să se scrie un program care implementează o listă de categorii, fiecare categorie având asociată o
listă de produse. O categorie se definește prin numele său. Un produs se definește prin nume și preț. Programul
va prezenta utilizatorului un meniu cu următoarele opțiuni: 1-adaugă categorie; 2-adaugă produs (prima oară cere
o categorie și apoi un produs pe care îl adaugă la acea categorie); 3-afișare categorii (afișează doar numele tuturor
categoriilor); 4-afișare produse (cere o categorie și afișează toate produsele din ea); 5-ieșire
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct produs {
    char nume[100]; 
    float pret;
    struct produs *pred; 
    struct produs *urm; 
} produs;

typedef struct categorie{
    char nume[30];
    produs *prim;
    produs *ultim; 

    struct categorie *pred;
    struct categorie *urm;

}categorie;

produs *produs_nou(const char *nume,int pret)
{
    produs *p;
    p=(produs*)malloc(sizeof(produs));
    if (!p) {
        printf("Memorie insuficienta.\n");
        exit(EXIT_FAILURE);
    }
    strcpy(p->nume,nume);
    p->pret=pret;

    p->urm=NULL;
    p->pred=NULL;
    return p;
}

categorie *categorie_noua(const char *nume)
{
    categorie *c = (categorie*)malloc(sizeof(categorie));
    if (!c) {
        printf("Memorie insuficienta.\n");
        exit(EXIT_FAILURE);
    }
    strcpy(c->nume, nume);

    c->prim = NULL;
    c->ultim = NULL;
    c->urm = NULL;
    c->pred = NULL;
    return c;
}

void categorie_adauga_produs(categorie *c, produs *p)
{
    p->pred = c->ultim;
    if (c->ultim)
    {
        c->ultim->urm = p;
    }
    else 
    {
        c->prim = p;
    }
    c->ultim = p;
}

void afiseaza_categorii(categorie *prima_categorie) {
    categorie *c;
    for (c = prima_categorie; c; c = c->urm) {
        printf("%s\n", c->nume);
    }
}

void afiseaza_produse(categorie *prima_categorie, const char *nume_categorie) {
    categorie *c;
    for (c = prima_categorie; c; c = c->urm) {
        if (strcmp(c->nume, nume_categorie) == 0) {
            produs *p;
            for (p = c->prim; p; p = p->urm) {
                printf("%s - Pret: %.2f\n", p->nume, p->pret);
            }
            return;
        }
    }
    printf("Categorie inexistentă.\n");
}

int main() {
    categorie *prima_categorie = NULL;
    int optiune;
    char nume_categorie[30];
    char nume_produs[30];
    float pret_produs;

    do {
        printf("\nMeniu:\n");
        printf("1. Adaugă categorie\n");
        printf("2. Adaugă produs\n");
        printf("3. Afișare categorii\n");
        printf("4. Afișare produse\n");
        printf("5. Ieșire\n");
        printf("Opțiune: ");
        scanf("%d", &optiune);

        switch (optiune) {
            case 1:
                printf("Introduceți numele categoriei: ");
                scanf("%s", nume_categorie);
                if (!prima_categorie)
                {
                    prima_categorie = categorie_noua(nume_categorie);
                }
                else 
                {
                    categorie *ultima_categorie = prima_categorie;
                    while (ultima_categorie->urm)
                    {
                        ultima_categorie = ultima_categorie->urm;
                    }
                    ultima_categorie->urm = categorie_noua(nume_categorie);
                    ultima_categorie->urm->pred = ultima_categorie;
                }
                break;
            case 2:
                printf("Introduceți numele categoriei la care vreți să adăugați produsul: ");
                scanf("%s", nume_categorie);
                printf("Introduceți numele produsului: ");
                scanf("%s", nume_produs);
                printf("Introduceți prețul produsului: ");
                scanf("%f", &pret_produs);

                // Cautam categoria unde adaufgam
                categorie *c;
                for (c = prima_categorie; c; c = c->urm) {
                    if (strcmp(c->nume, nume_categorie) == 0) {
                        produs *p = produs_nou(nume_produs, pret_produs);
                        categorie_adauga_produs(c, p);
                        printf("Produs adăugat cu succes la categoria %s.\n", nume_categorie);
                        break;
                    }
                }
                if (!c) {
                    printf("Categorie inexistentă.\n");
                }
                break;
            case 3:
                printf("Categoriile existente sunt:\n");
                afiseaza_categorii(prima_categorie);
                break;
            case 4:
                printf("Introduceți numele categoriei pentru care vreți să afișați produsele: ");
                scanf("%s", nume_categorie);
                afiseaza_produse(prima_categorie, nume_categorie);
                break;
            case 5:
                printf("Ieșire din program.\n");
                break;
            default:
                printf("Opțiune invalidă. Reîncercați.\n");
        }
    } while (optiune != 5);

    
    categorie *c = prima_categorie;
    while (c) {
        produs *p = c->prim;
        while (p) {
            produs *temp = p->urm;
            free(p);
            p = temp;
        }
        categorie *temp = c->urm;
        free(c);
        c = temp;
    }
    
    return 0;
}








