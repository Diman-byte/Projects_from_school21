#include <stdio.h>

int sum(int a, int b);
int diff(int a, int b);
int prod(int a, int b);
int div(int a, int b);

int main()
{
    int a, b;
    char ch;
    int check = scanf("%d%d", &a, &b);
    if(check < 2) {
        printf("n/a\n");  
        return 0;
    }

    ch = getchar();  //check na float

    if(ch != ' '&& ch != '\n'){
        printf("n/a\n");  
        return 0;
    }

    if (b == 0) {
        printf("%d %d %d n/a\n", sum(a, b), diff(a, b), prod(a, b));
        return 0;
    }
    else {
        printf("%d %d %d %d\n", sum(a, b), diff(a, b), prod(a, b), div(a, b));
        return 0;
    }
}

int sum(int a, int b){
    return a + b;
}

int diff(int a, int b){
    return a - b;
}

int prod(int a, int b){
    return a * b;
}

int div(int a, int b){
    return a / b;
}