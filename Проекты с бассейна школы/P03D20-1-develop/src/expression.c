#include "expression.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Определения типов токенов
#define OPERAND 1
#define OPERATOR 2
#define FUNCTION 3

// Прототипы внутренних функций

TokenMapping validTokens[] = {
    {"+", OPERATOR_PLUS},    {"-", OPERATOR_MINUS},    {"*", OPERATOR_MULTIPLY}, {"/", OPERATOR_DIVIDE},
    {"(", OPEN_PARENTHESIS}, {")", CLOSE_PARENTHESIS}, {"sin", FUNCTION_SIN},    {"cos", FUNCTION_COS},
    {"tan", FUNCTION_TAN},   {"ctg", FUNCTION_CTG},    {"sqrt", FUNCTION_SQRT},  {"ln", FUNCTION_LN},
};

TokenList* inputExpression(char* expression) {
    TokenList* tokens = (TokenList*)malloc(sizeof(TokenList));
    if (tokens == NULL) {
        perror("Ошибка выделения памяти для списка токенов");
        exit(EXIT_FAILURE);
    }

    tokens->tokens = NULL;
    tokens->size = 0;

    char* token = strtok(expression, " ");
    while (token != NULL) {
        int tokenCode = findTokenByValue(token);
        if (tokenCode != -1) {
            addToken(tokens, token, tokenCode);
        } else {
            fprintf(stderr, "ERROR - %s\n", token);
            freeTokenList(tokens);
            free(tokens);
            return NULL;
        }
        token = strtok(NULL, " ");
    }
    return tokens;
}

TokenList* tokenize(char* expression) {
    TokenList* tokens = (TokenList*)malloc(sizeof(TokenList));
    if (tokens == NULL) {
        perror("Ошибка выделения памяти для списка токенов");
        exit(EXIT_FAILURE);
    }

    tokens->tokens = NULL;
    tokens->size = 0;

    char* token = strtok(expression, " ");
    while (token != NULL) {
        int type = getTokenType(token);
        addToken(tokens, token, type);
        token = strtok(NULL, " ");
    }

    return tokens;
}

void freeTokenList(TokenList* tokens) {
    for (int i = 0; i < tokens->size; i++) {
        free(tokens->tokens[i].value);
    }
    free(tokens->tokens);
    free(tokens);
}

int getTokenType(char* token) {
    if (isDigit(token[0])) {
        return OPERAND;
    } else if (strlen(token) == 1 &&
               (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/')) {
        return OPERATOR;
    } else {
        return FUNCTION;
    }
}

void addToken(TokenList* list, char* value, int type) {
    list->tokens = realloc(list->tokens, (list->size + 1) * sizeof(Token));
    if (list->tokens == NULL) {
        perror("Error NOT MEMMORY!!");
        exit(EXIT_FAILURE);
    }

    Token newToken;
    newToken.value = strdup(value);
    newToken.type = type;

    if (newToken.value == NULL) {
        perror("ERROR NOY MEMMORYY!!");
        exit(EXIT_FAILURE);
    }

    list->tokens[list->size++] = newToken;
}

int findTokenByValue(char* value) {
    int numTokens = sizeof(addToken) / sizeof(validTokens[0]);
    for (int i = 0; i < numTokens; i++) {
        if (strcmp(validTokens[i].value, value) == 0) {
            return validTokens[i].token;
        }
    }
    return -1;
}

int isDigit(char c) { return c >= '0' && c <= '9'; }
