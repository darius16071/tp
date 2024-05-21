/*
Aplicația 10.5: Se considera sirul-de-caractere de tip Fibbonaci in care primii doi termeni sunt sirurile de caractere
s1 si s2 (pot fi transmise ca si parametri functiei), iar orice alt termen se obtine prin concatenarea celor doi termeni
anteriori. Sa se implementeze o functie care un numar natural n (si orice alti parametri considerati necesari) si
afiseaza termenul de pe pozitia n din sirul construit conform celor de mai sus.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* fib_string(int n, const char* s1, const char* s2) {
    if (n == 0)
    {
        return strdup(s1);
    } 
    else if (n == 1)
    {
        return strdup(s2);
    } 
    else 
    {
        char* term1 = fib_string(n - 1, s1, s2);
        char* term2 = fib_string(n - 2, s1, s2);
        char* result = (char*)malloc(strlen(term1) + strlen(term2) + 1);
        strcpy(result, term1);
        strcat(result, term2);
        free(term1);
        free(term2);
        return result;
    }
}

int main() {
    int n;
    char s1[100], s2[100];

    printf("Introduceți valoarea lui n: ");
    scanf("%d", &n);

    printf("Introduceți primul șir (s1): ");
    scanf("%s", s1);

    printf("Introduceți al doilea șir (s2): ");
    scanf("%s", s2);

    char* rezultat = fib_string(n, s1, s2);
    printf("Termenul de pe poziția %d din șirul de caractere Fibonacci este: %s\n", n, rezultat);

    free(rezultat);

    return 0;
}
