#include <stdio.h>

double factoriel(int number){
    double sum = 1;
    for (int i=1; i<=number ; i++){
        sum *= i;
    }
    return sum;
}

double powmy(double base, int exponent){
    double sum = 0;
    for(int i=0 ; i<exponent ; i++){
        sum += base;
    }
    return sum;
}

double sin(double x){
    double sum = 0;
    for(int i=0 ; i<=8 ; i++){
        sum += (powmy((double)(-1), i+1) * powmy(x, 2*i-1)) / factoriel(2*i-1);
    }
}

double cos(double x){
    double sum = 0;
    for(int i=0 ; i<=8 ; i++){
        sum += (powmy((double)(-1), i+1) * powmy(x, 2*i)) / factoriel(2*i);
    }
}

double tan(double x){
    return sin(x) / cos(x) ;
}

double cot(double x){
    return cos(x) / sin(x) ;
}

int main() {
    // Write C code here
    printf("%lf", cos(3.1415));

    return 0;
