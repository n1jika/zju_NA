#include <stdio.h>

void Series_Sum( double sum[] );

int main()
{
    int i;
    double x, sum[3001];
    
    Series_Sum( sum );

    x = 0.0;
    for (i=0; i<3001; i++)
        printf("%6.2f %16.12f\n", x + (double)i * 0.10, sum[i]);

    return 0;
}

void Series_Sum( double sum[] ){
    for(int i = 0; i < 11; i++){
        sum[i] = 0;
        double x = (double)i * 0.10;
        for(int j = 1; j <= 6935; j++){
            sum[i] += 1.0 / ((double)j * ((double)j + x) * ((double)j + 1.0) * ((double)j + 2.0));
        }
        sum[i] = sum[i] * (2.0 - x);
        sum[i] += 1.0 / 4.0;
        sum[i] = sum[i] * (1.0 - x);
        sum[i] += 1.0;
    }
    for(int i = 11; i < 3001; i++){
        sum[i] = 0;
        double x = (double)i * 0.10;
        sum[i] = (x - 1.0) * sum[i - 10] / x + 1.0 / (x * x);
    }
}