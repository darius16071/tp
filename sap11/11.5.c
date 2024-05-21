/*
Aplicația 11.5: Să se scrie o funcție care primește un număr întreg 0<=n<1000 și îl afișează în formă literară. Să
se apeleze funcția pentru numere introduse de la tastatură, pană la apariția valorii 1000.
Exemple: 108 → o suta opt; 520 → cinci sute douazeci; 16 → saisprezece 
*/
#include <stdio.h>
#include <string.h>

const char *unitati[] = {"", "unu", "doi", "trei", "patru", "cinci", "sase", "sapte", "opt", "noua"};
const char *zecimal10_19[] = {"zece", "unsprezece", "doisprezece", "treisprezece", "paisprezece", "cincisprezece", "saisprezece", "saptesprezece", "optsprezece", "nouasprezece"};
const char *zecimal[] = {"", "", "douazeci", "treizeci", "patruzeci", "cincizeci", "saizeci", "saptezeci", "optzeci", "nouazeci"};
const char *sute[] = {"", "o suta", "doua sute", "trei sute", "patru sute", "cinci sute", "sase sute", "sapte sute", "opt sute", "noua sute"};

void numarInCuvinte(int n) {
    if (n == 0) {
        printf("zero");
        return;
    }

    int s = n / 100; 
    int z = (n / 10) % 10; 
    int u = n % 10; 

    if (s > 0) {
        printf("%s ", sute[s]);
    }

    if (z == 1) 
    {
        printf("%s ", zecimal10_19[u]);
    } 
    else 
    {
        if (z > 1) 
        {
            printf("%s ", zecimal[z]);
        }
        if (u > 0) 
        {
            printf("%s ", unitati[u]);
        }
    }
}

int main() {
    int n;
    while (1) {
        printf("Introduceți un numar intre 0 si 999 (sau 1000 pentru a opri): ");
        scanf("%d", &n);
        if (n == 1000) {
            break;
        }
        if (n < 0 || n >= 1000) {
            printf("Numărul nu este valid. Încercați din nou.\n");
            continue;
        }
        numarInCuvinte(n);
        printf("\n");
    }
    return 0;
}
