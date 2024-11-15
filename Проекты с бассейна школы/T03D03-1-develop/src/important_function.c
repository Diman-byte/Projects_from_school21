#include <stdio.h>
#include <math.h>

double foo(double x);

int main() {
    double x;
    char z;
    int check = scanf("%lf", &x);

    z = getchar();  //check na float

    if(z != ' ' && z != '\n'){
        printf("n/a\n");  
        return 0;
    }
    if(check != 1){
        printf("n/a\n");
        return 0;
    }
    else {
        printf("%.1lf\n", foo(x));
        return 0;
    }
}


double foo(double x){
    return 7e-3 * pow(x, 4) + ((22.8 * pow(x, 1/3) - 1e3) * x + 3) / (x * x / 2) - x * pow(10 + x, 2/x) - 1.01;
}

//ssh -keygen  //генерация ключа