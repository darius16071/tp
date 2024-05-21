/*
Aplicația 10.4: Sa se determine recursiv al n-lea termen Fibonacci.
𝑓𝑖𝑏(𝑛) = {
1, 𝑑𝑎𝑐ă 𝑛 = 1 𝑠𝑎𝑢 𝑛 = 0
𝑓𝑖𝑏(𝑛 − 1) + 𝑓𝑖𝑏(𝑛 − 2), 𝑑𝑎𝑐ă 𝑛 > 1
*/
#include <stdio.h>
int fib(int n) 
{
    if (n == 0 || n == 1) 
    {
        return 1;
    } 
    else 
    {
        return fib(n - 1) + fib(n - 2);
    }
}

int main() 
{
    int n;
    scanf("%d", &n);
    
    int rezultat = fib(n);
    printf("Al %d-lea termen Fibonacci este: %d\n", n, rezultat);
    
    return 0;
}
