#include <stdio.h>

int max(int a, int b);

int main() {
    int a, b;
    char ch;
    int check = scanf("%d%d", &a, &b);
    if(check < 2) {
        printf("n/a\n");  
        return 0;
    }

    ch = getchar();  //check na float

    if(ch != ' ' && ch != '\n'){
        printf("n/a\n");  
        return 0;
    }

    else{
        printf("%d\n", max(a, b));
        return 0;
    }
}

int max(int a, int b){
    if (a > b){
        return a;
    }
    else{
        return b;
    }
}