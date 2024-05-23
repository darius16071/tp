/*
Aplicația 8.1: Să se modifice exemplul 1 astfel încât el să numere de câte ori apare fiecare cuvânt în propoziție.
Pentru aceasta, cuvintele vor fi adăugate doar cu litere mici și fiecare cuvânt va avea asociat un contor. Dacă un
cuvânt nou nu există în propoziție, el va fi adăugat. Altfel, dacă el există deja, doar se va incrementa contorul
cuvântului existent. La afișare, pentru fiecare cuvânt se va afișa și contorul său.


Aplicația 8.2: La exemplul 1 să se adauge operația de inserare a unui cuvânt. Pentru aceasta se cere un cuvânt
de inserat și un cuvânt succesor. Dacă succesorul există în propoziție, cuvântul de inserat va fi inserat înaintea sa.
Dacă succesorul nu există în lista, cuvântul de inserat va fi adăugat la sfârșitul listei.

*/

typedef struct Cuvant
{
    char text[16];
    int count;
    struct Cuvant *pred;
    struct Cuvant *urm;
} Cuvant;

Cuvant *Cuvant_nou(const char *text)
{
    Cuvant *cuv = (Cuvant *)malloc(sizeof(Cuvant));
    if (!cuv)
    {
        printf("memorie insuficienta");
        exit(EXIT_FAILURE);
    }
    strcpy(cuv->text, text);
    cuv->count = 1;
    return cuv;
}

typedef struct
{
    Cuvant *prim;
    Cuvant *ultim;
} Propozitie;

void Propozitie_init(Propozitie *p)
{
    p->prim = p->ultim = NULL;
}

Cuvant *Propozitie_cauta(Propozitie *p, const char *text)
{
    Cuvant *cuv;
    for (cuv = p->prim; cuv; cuv = cuv->urm)
    {
        if (!strcmp(cuv->text, text))
            return cuv;
    }
    return NULL;
}

void Propozitie_adauga(Propozitie *p, Cuvant *cuv)
{
    Cuvant *existent = Propozitie_cauta(p, cuv->text);
    if (existent)
    {
        existent->count++;
        free(cuv);
    }
    else
    {
        cuv->pred = p->ultim;
        if (p->ultim)
        {
            p->ultim->urm = cuv;
        }
        else
        {
            p->prim = cuv;
        }
        p->ultim = cuv;
        cuv->urm = NULL;
    }
}

void Propozitie_sterge(Propozitie *p, Cuvant *cuv)
{
    if (cuv->pred)
    {
        cuv->pred->urm = cuv->urm;
    }
    else
    {
        p->prim = cuv->urm;
    }
    if (cuv->urm)
    {
        cuv->urm->pred = cuv->pred;
    }
    else
    {
        p->ultim = cuv->pred;
    }
    free(cuv);
}

void Propozitie_elibereaza(Propozitie *p)
{
    Cuvant *cuv, *urm;
    for (cuv = p->prim; cuv; cuv = urm)
    {
        urm = cuv->urm;
        free(cuv);
    }
    Propozitie_init(p);
}

void Propozitie_inserare(Propozitie *p, const char *text_inserat, const char *text_succesor)
{
    Cuvant *inserat = Cuvant_nou(text_inserat);
    Cuvant *succ = Propozitie_cauta(p, text_succesor);

    if (succ)
    {
        inserat->pred = succ->pred;
        inserat->urm = succ;
        if (succ->pred)
        {
            succ->pred->urm = inserat;
        }
        else
        {
            p->prim = inserat;
        }
        succ->pred = inserat;
    }
    else
    {
        Propozitie_adauga(p, inserat);
    }
}
