#include <stdio.h>
#include <math.h>

#define ZERO 1e-13 /* X is considered to be 0 if |X|<ZERO */
#define MAXN 11    /* Max Polynomial Degree + 1 */

double Polynomial_Root(int n, double c[], double a, double b, double EPS);

int main()
{
    int n;
    double c[MAXN], a, b;
    double EPS = 0.00005;
    int i;

    scanf("%d", &n);
    for (i=n; i>=0; i--) 
        scanf("%lf", &c[i]);
    scanf("%lf %lf", &a, &b);
    printf("%.4f\n", Polynomial_Root(n, c, a, b, EPS));

    return 0;
}

double f(double x, int n, double c[]);
double f1(double x, int n, double c[]);
double f2(double x, int n, double c[]);

double f(double x, int n, double c[]){
    int i;
    double sum = 0.0;
    for(i = n; i >= 0; i--){
        sum = sum * x + c[i];
    }
    return sum;
}

double f1(double x, int n, double c[]){
    int i;
    double sum = 0.0;
    for(i = n; i >= 1; i--){
        sum = sum * x + c[i] * i;
    }
    return sum;
}

double f2(double x, int n, double c[]){
    int i;
    double sum = 0.0;
    for(i = n; i >= 2; i--){
        sum = sum * x + c[i] * i * (i - 1);
    }
    return sum;
}

double Polynomial_Root(int n, double c[], double a, double b, double EPS){
    double i = 0.0;
    double p, cha;
    int flag = 1;
    if(f(a, n, c) * f(b, n, c) > 0) flag = 0;
    p = a + (b - a) * i / 2;
    while(fabs(f(p, n, c)) > ZERO){
        if(((f1(p, n, c) * f1(p, n, c)) - (f(p, n, c) * f2(p, n, c))) < ZERO) flag = 0;
        cha = (f(p, n, c) * f1(p, n, c)) / ((f1(p, n, c) * f1(p, n, c)) - (f(p, n, c) * f2(p, n, c)));
        if(fabs(cha) < EPS) return p;
        p -= cha;
        if(p < a || p > b){
            i = i + 1;
            p = a + (b - a) * i / 2;
        }
        if(i > 2){
            flag = 0;
            break;
        }
    }
    if(flag == 1) return p;
}