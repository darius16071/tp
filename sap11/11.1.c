/*
Aplicația 11.1: Se cere un n<100, iar apoi coordonatele reale (x,y) a n puncte din plan. Fiecare punct reprezintă
poziția unde va trebui dată o gaură într-o placă. Bormașina se află inițial la locația (0,0). Să se afișeze ordinea de
dat găuri, astfel încât întotdeauna bormașina să fie mutată la punctul cel mai apropiat de ea.

GREEDY
*/

#include <stdio.h>
#include <math.h>
#include <float.h>

#define MAX_POINTS 100

typedef struct {
    double x, y;
    int visited;
} Point;

double distance(Point a, Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int findNearestPoint(Point points[], int n, Point current) {
    int nearestIndex = -1;
    double minDistance = DBL_MAX;
    
    for (int i = 0; i < n; i++) {
        if (!points[i].visited) {
            double dist = distance(current, points[i]);
            if (dist < minDistance) {
                minDistance = dist;
                nearestIndex = i;
            }
        }
    }
    
    return nearestIndex;
}

int main() {
    int n;
    printf("Introduceți numărul de puncte (n < 100): ");
    scanf("%d", &n);
    
    Point points[MAX_POINTS];
    for (int i = 0; i < n; i++) {
        printf("Introduceți coordonatele punctului %d: ", i + 1);
        scanf("%lf %lf", &points[i].x, &points[i].y);
        points[i].visited = 0;
    }
    
    Point current = {0, 0};
    for (int i = 0; i < n; i++) {
        int nearestIndex = findNearestPoint(points, n, current);
        if (nearestIndex != -1) {
            points[nearestIndex].visited = 1;
            current = points[nearestIndex];
            printf("Gaura %d: (%lf, %lf)\n", i + 1, current.x, current.y);
        }
    }
    
    return 0;
}
