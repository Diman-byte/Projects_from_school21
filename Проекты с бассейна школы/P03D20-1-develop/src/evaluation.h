#ifndef EVALUATION_H
#define EVALUATION_H

#define OPERAND 1
#define OPERATOR 2
#define FUNCTION 3

#define ADDITION 1
#define SUBTRACTION 2
#define MULTIPLICATION 3
#define DIVISION 4
#define UNARY_MINUS 5
#define OPEN_PARENTHESIS 6
#define CLOSE_PARANTHESIS 7
#define FUNCTION_SIN 8
#define FUNCTION_COS 9
#define FUNCTION_TAN 10
#define FUNCTION_CTG 11
#define FUNCTION_SQRT 12
#define FUNCTION_LN 13

// Структура для ОПЗ (обратной польской записи)
typedef struct {
    char** expression;  // Массив строк с ОПЗ
    int size;           // Размер ОПЗ
} RPNExpression;

typedef struct {
    char* value;
    int type;
} Token;

typedef struct {
    Token* tokens;
    int size;
} TokenList;

// Прототипы функций
RPNExpression* infixToRPN(TokenList* tokens);
double evaluateRPN(RPNExpression* rpn, double x);
void freeRPNExpression(RPNExpression* rpn);
int isOperator(char* token);
int getOperatorPriority(char operator);
int isFunction(char* token);

#endif /* EVALUATION_H */
