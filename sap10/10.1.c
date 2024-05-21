/*
Aplicația 10.1: Calculați recursiv cel mai mare divizor comun a două numere.
𝑐𝑚𝑚𝑑𝑐(𝑎, 𝑏) = {
𝑎, 𝑑𝑎𝑐ă 𝑏 = 0
𝑐𝑚𝑚𝑑𝑐(𝑏, 𝑎%𝑏), 𝑑𝑎𝑐ă 𝑏 > 0

*/
#include <stdio.h>

int cmmdc(int a, int b) 
{
    if (b == 0) {
        return a;
    } else {
        return cmmdc(b, a % b);
    }
}

int main() {
    int num1, num2;
    
    scanf("%d", &num1);
    scanf("%d", &num2);
    
    int result = cmmdc(num1, num2);
    printf("Cel mai mare divizor comun al numerelor %d și %d este: %d\n", num1, num2, result);
    
    return 0;
}

