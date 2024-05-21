/*
Aplicația 11.2: Se cere un n strict pozitiv și patru valori reale: ma, mb, m, d. ma și mb reprezintă masele a două
corpuri situate la distanța d unul de celălalt. m este masa unui corp care pornește din a și ajunge în b, din n pași
egali. Să se calculeze în fiecare punct al traseului lui m forța F de atracție gravitațională care acționează asupra
lui. F va fi cu semn: negativ înseamnă că m este atras către ma, iar pozitiv către mb. Formula atracției gravitaționale
dintre două corpuri m1 și m2, situate la distanța d unul de celălalt este: F=G*m1*m2/d2
, unde G=6.674e-11. Masele
sunt exprimate în kilograme, distanțele în metri, iar forțele în newtoni.

DIVIDE ET IMPERA
*/
#include <stdio.h>
#include <math.h>

#define G 6.674e-11 

typedef struct {
    double position;
    double force;
} ForceResult;

ForceResult calculateForce(double ma, double mb, double m, double d, double x) {
    ForceResult result;
    double dist_ma = x;
    double dist_mb = d - x;

    double force_ma = G * ma * m / (dist_ma * dist_ma);
    double force_mb = G * mb * m / (dist_mb * dist_mb);

    result.position = x;
    result.force = force_mb - force_ma;

    return result;
}

void divideEtImpera(double ma, double mb, double m, double d, int n, int start, int end, ForceResult results[]) {
    if (start > end) {
        return;
    }

    if (start == end) {
        double x = (double)start * d / n;
        results[start] = calculateForce(ma, mb, m, d, x);
        return;
    }

    int mid = (start + end) / 2;
    divideEtImpera(ma, mb, m, d, n, start, mid, results);
    divideEtImpera(ma, mb, m, d, n, mid + 1, end, results);
}

int main() {
    int n;
    double ma, mb, m, d;

    printf("Introduceți numărul de pași n: ");
    scanf("%d", &n);
    printf("Introduceți masa corpului ma (kg): ");
    scanf("%lf", &ma);
    printf("Introduceți masa corpului mb (kg): ");
    scanf("%lf", &mb);
    printf("Introduceți masa corpului mobil m (kg): ");
    scanf("%lf", &m);
    printf("Introduceți distanța d (m): ");
    scanf("%lf", &d);

    ForceResult results[n + 1];
    divideEtImpera(ma, mb, m, d, n, 0, n, results);

    for (int i = 0; i <= n; i++) {
        printf("Pasul %d: Poziția = %lf, Forța F = %e N\n", i, results[i].position, results[i].force);
    }

    return 0;
}
