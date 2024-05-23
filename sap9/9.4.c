/*
Aplicația 9.4: Se considera o lista liniara dublu inlantuita cu numar par de noduri. Sa se scrie o functie care
primeste ca parametru adresa primului nod al listei si interschimba primul nod cu cel de-al doilea, al treilea cu cel
de-al patrulea si asa mai departe.
*/
/*
Să se implementeze o listă dublu înlănțuită în care se pot efectua următoarele operații prin intermediul unui meniu.
 Unu adăugare a unui element în ordine descrescătoare în funcție de o cheie alfanumerică.
  2 ștergerea unui element în funcție de cheia alfanumerică specificată. 
  3. Concatenarea a 2 liste dublu, intuite într-o singură listă.
   4 afișarea întregii liste dublu înlănțuite. 
   5 ieșire din program. 

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct element
{
    int id;
    struct element *pred;
    struct element *urm;
}element;

typedef struct 
{
    element *prim;
    element *ultim;
}lista;

element *element_nou(int id)
{
    element *c=(element*)malloc(sizeof(element));
    if(!c)
    {
        printf("memorie insuficienta");
        exit(EXIT_FAILURE);
    }
    c->id=id;
    c->pred=NULL;
     c->urm=NULL;
    return c;
}

void adauga(lista *l, element *c)
{
    if (l->prim == NULL)
    {
        l->prim = c;
        l->ultim = c;
        return;
    }

    element *aux = l->prim;
    while (aux)
    {
        if (c->id > aux->id)
        {
            if (aux == l->ultim)//daca ajung la ultimu element
            {
                aux->urm = c;//in loc de null pun c
                c->pred = aux;//leg c de lista
                l->ultim = c;//ultimu devine c
                return;
            }
            aux = aux->urm;
        }
        else
        {
            if (aux == l->prim)//cazu cu primu
            {
                c->urm = aux;
                aux->pred = c;
                l->prim = c;
                return;
            }
            else
            {
                c->urm = aux;
                c->pred = aux->pred;
                aux->pred->urm = c;
                aux->pred = c;
                return;
            }
        }
    }
}


void sterge(lista *l, int id)
{
    element *aux = l->prim;
    while (aux) 
    {
        if (aux->id == id) {
            if (aux == l->prim && aux == l->ultim) //singuru elem din lista
            {
                l->prim = NULL;
                l->ultim = NULL;
                free(aux);
                return;
            } else if (aux == l->prim)//primu
             {
                l->prim = aux->urm;
                aux->urm->pred = NULL;
                free(aux);
                return;
            } else if (aux == l->ultim) //ultimu
            {
                l->ultim = aux->pred;
                aux->pred->urm = NULL;
                free(aux);
                return;
            } else //intre
            {
                aux->pred->urm = aux->urm;
                aux->urm->pred = aux->pred;
                free(aux);
                return;
            }
        }
        aux = aux->urm;
    }
    printf("Elementul cu id-ul %d nu a fost gasit.\n", id);
}

void interschiba(lista *l)
{
    element *aux = l->prim;
    while (aux != NULL && aux->urm != NULL) {
        element *primul = aux;
        element *alDoilea = aux->urm;

        // interschimbăm nodurile
        primul->urm = alDoilea->urm;
        alDoilea->pred = primul->pred;
        primul->pred = alDoilea;
        alDoilea->urm = primul;

        if (primul->urm != NULL) {
            primul->urm->pred = primul;
        } else {
            l->ultim = primul;
        }

        if (alDoilea->pred != NULL) {
            alDoilea->pred->urm = alDoilea;
        } else {
            l->prim = alDoilea;
        }

        // avansăm cu doi pași
        aux = primul->urm;
    }

}

void afiseaza(lista *l) {
    printf("Lista dublu inlantuita:\n");
    element *aux = l->prim;
    while (aux) {
        printf("%d ", aux->id);
        aux = aux->urm;
    }
    printf("\n");
}


int main(void) {
    lista l;
    l.prim = NULL;
    l.ultim = NULL;

    int optiune, id;
    while (1) {
        printf("\nMeniu:\n");
        printf("1. Adauga element\n");
        printf("2. Sterge element\n");
        printf("3. Afiseaza lista\n");
        printf("4. Iesire\n");
        printf("Optiune: ");
        scanf("%d", &optiune);

        switch (optiune) {
            case 1:
                printf("Introduceti id-ul elementului: ");
                scanf("%d", &id);
                adauga(&l, element_nou(id));
                break;
            case 2:
                printf("Introduceti id-ul elementului de sters: ");
                scanf("%d", &id);
                sterge(&l, id);
                break;
            case 3:
                afiseaza(&l);
                break;
            case 4:
                printf("Iesire din program.\n");
                return 0;
            default:
                printf("Optiune invalida. Reincercati.\n");
        }
    }
    return 0;
}
