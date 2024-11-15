#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "expression.h"

int main() {
    char expression[100];
    printf("Enter mat vr: ");
    scanf("%s", expression);

    TokenList* tokens = tokenize(expression);

    printf("Список токенов:\n");

    for (int i = 0; i < tokens->size; i++) {
        Token token = tokens->tokens[i];
        printf("Token %d: %s (Type: %d)\n", i + 1, token.value, token.type);
    }

    freeTokenList(tokens);
    return 0;
}
