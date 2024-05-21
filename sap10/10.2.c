/*
Aplicația 10.2: Calculați recursiv suma cifrelor unui număr natural.
𝑠𝑢𝑚𝑎_𝑐𝑖𝑓𝑟𝑒𝑙𝑜𝑟(𝑛) = {
𝑛, 𝑑𝑎𝑐ă 𝑛 < 10
𝑛%10 + 𝑠𝑢𝑚𝑎_𝑐𝑖𝑓𝑟𝑒𝑙𝑜𝑟(𝑛/10), 𝑑𝑎𝑐ă 𝑛 >= 10
*/
#include <stdio.h>

int suma_cifrelor(int n) 
{
    if (n < 10) {
        return n;
    } else {
        return n%10 + suma_cifrelor(n/10);
    }
}

int main() {
    int num1, num2;
    
    scanf("%d", &num1);
    
    int result = suma_cifrelor(num1);
    printf("%d\n",result);
    
    return 0;
}

