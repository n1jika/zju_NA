#include <stdio.h>

#define Max_size 10000 /* max number of dishes */

void Price( int n, double p[] );

int main()
{
    int n, i;
    double p[Max_size];

    scanf("%d", &n);
    for (i=0; i<n; i++) 
        scanf("%lf", &p[i]);
    Price(n, p);
    for (i=0; i<n; i++)
        printf("%.2f ", p[i]);
    printf("\n");

    return 0;
}

#include <stdlib.h>
#include <math.h>

#define EPS 1e-8
#define MAX_ITER 1000

void Price(int n, double p[]) {
    double *c = (double *)malloc(n * sizeof(double));
    double *new_c = (double *)malloc(n * sizeof(double));
    
    for (int i = 0; i < n; i++) {
        c[i] = p[i] / 2.0;
    }
    
    int iter = 0;
    double diff = EPS + 1;
    
    while (diff > EPS && iter < MAX_ITER){
        diff = 0.0;
        for (int i = 0; i < n; i++) {
            int prev = (i - 1 + n) % n;
            int next = (i + 1) % n;
            new_c[i] = (p[i] - 0.5 * (c[prev] + c[next])) / 2.0;
            diff += fabs(new_c[i] - c[i]);
        }
        
        double *temp = c;
        c = new_c;
        new_c = temp;
        
        iter++;
    }
    
    for (int i = 0; i < n; i++) {
        p[i] = c[i];
    }
    
    free(c);
    free(new_c);
}