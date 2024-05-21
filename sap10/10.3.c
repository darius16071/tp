#include <stdio.h>
/*
Aplicația 10.3: Determinați recursiv cifra maximă a unui număr natural.
𝑐𝑖𝑓𝑟𝑎_𝑚𝑎𝑥(𝑛) = {
𝑛, 𝑑𝑎𝑐ă 𝑛 < 10
𝑐𝑖𝑓𝑟𝑎_max(𝑛%10, 𝑐𝑖𝑓𝑟𝑎_𝑚𝑎𝑥(𝑛/10)), 𝑑𝑎𝑐ă 𝑛 >= 10
*/
int cifra_max(int n) {
    if (n < 10) 
    {
        return n;
    } 
    else 
    {
        int ultima_cifra = n % 10;

        int max_rest = cifra_max(n / 10);

        if (ultima_cifra > max_rest)
        {
            return ultima_cifra;
        } 
        else 
        {
            return max_rest;
        }
    }
}

int main()
{
    int numar;
    scanf("%d", &numar);

    int rezultat = cifra_max(numar);
    printf("Cifra maximă a numărului %d este: %d\n", numar, rezultat);
    
    return 0;
}
