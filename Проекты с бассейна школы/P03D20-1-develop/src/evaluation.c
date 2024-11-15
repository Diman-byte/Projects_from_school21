#include "evaluation.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Определения типов операторов
#define ADDITION 1
#define SUBTRACTION 2
#define MULTIPLICATION 3
#define DIVISION 4

RPNExpression* infixToRPN(TokenList* tokens) {
    RPNExpression* rpn = (RPNExpression*)malloc(sizeof(RPNExpression));
    if (rpn == NULL) {
        perror("ERROR NOT MEMMORY");
        exit(EXIT_FAILURE);
    }
    rpn->expression = (char**)malloc(tokens->size * sizeof(char*));
    if (rpn->expression == NULL) {
        perror("ERROR NOT MEMMORY");
        exit(EXIT_FAILURE);
    }

    rpn->size = 0;

    char* stack[100];
    int top = 1;

    for (int i = 0; i < tokens->size; i++) {
        Token currentToken = tokens->tokens[i];

        if (currentToken.type == OPERAND) {
            rpn->expression[rpn->size++] = strdup(currentToken.value);
        } else if (isOperator(currentToken.value)) {
            while (top >= 0 &&
                   getOperatorPriority(stack[top][0]) >= getOperatorPriority(currentToken.value[0])) {
                rpn->expression[rpn->size++] = strdup(stack[top--]);
            }
            stack[++top] = currentToken.value;
        }
    }
    while (top >= 0) {
        rpn->expression[rpn->size++] = strdup(stack[top--]);
    }
    return rpn;
}

double evaluateRPN(RPNExpression* rpn, double x) {
    double stack[100];
    int top = -1;

    TokenList* tokens = (TokenList*)malloc(sizeof(TokenList));
    tokens->tokens = (Token*)malloc(rpn->size * sizeof(Token));
    tokens->size = rpn->size;

    for (int i = 0; i < rpn->size; i++) {
        Token currentToken;
        currentToken.value = rpn->expression[i];
        currentToken.type = isOperator(currentToken.value) ? OPERATOR : OPERAND;
        tokens->tokens[i] = currentToken;
    }

    for (int i = 0; i < tokens->size; i++) {
        Token currentToken = tokens->tokens[i];
        if (currentToken.type == OPERAND) {
            top++;
            stack[top] = atof(currentToken.value);
        } else if (currentToken.type == OPERATOR) {
            double operand2 = stack[top--];
            double operand1 = stack[top--];
            double result = 0.0;

            switch (currentToken.value[0]) {
                case '+':
                    result = operand1 + operand2;
                    break;

                case '-':
                    result = operand1 - operand2;
                    break;

                case '*':
                    result = operand1 * operand2;
                    break;

                case '/':
                    if (operand2 != 0) {
                        result = operand1 / operand2;
                    } else {
                        printf("Ошибка: Деление на  ноль.\n");
                        exit(EXIT_FAILURE);
                    }
                    break;

                default:
                    printf("ERROR\n");
                    exit(EXIT_FAILURE);
            }

            stack[++top] = result;
        }
    }

    free(tokens->tokens);
    free(tokens);

    return stack[top];
}

void freeRPNExpression(RPNExpression* rpn) {
    if (rpn) {
        for (int i = 0; i < rpn->size; i++) {
            free(rpn->expression[i]);
        }
        free(rpn->expression);
        free(rpn);
    }
}

int isOperator(char* token) {
    return (strcmp(token, "+") == 0 || strcmp(token, "-") == 0 || strcmp(token, "*") == 0 ||
            strcmp(token, "/") == 0 || strcmp(token, "u-") == 0 || isFunction(token));
}

int getOperatorPriority(char operator) {
    switch (operator) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

int isFunction(char* token) {
    if (strcmp(token, "sin") == 0 || strcmp(token, "cos") == 0 || strcmp(token, "tan") == 0 ||
        strcmp(token, "ctg") == 0 || strcmp(token, "sqrt") == 0 || strcmp(token, "ln") == 0) {
        return 1;
    }

    return 0;
}
