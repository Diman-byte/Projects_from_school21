#ifndef EXPRESSION_H
#define EXPRESSION_H

#define OPERATOR_PLUS 1
#define OPERATOR_MINUS 2
#define OPERATOR_MULTIPLY 3
#define OPERATOR_DIVIDE 4
#define OPEN_PARENTHESIS 5
#define CLOSE_PARENTHESIS 6
#define FUNCTION_SIN 7
#define FUNCTION_COS 8
#define FUNCTION_TAN 9
#define FUNCTION_CTG 10
#define FUNCTION_SQRT 11
#define FUNCTION_LN 12

typedef struct {
    char* value;  // Значение токена (например, "x", "+", "sin")
    int type;     // Тип токена (операнд, оператор, функция и т.д.)
} Token;

// Структура списка токенов
typedef struct {
    Token* tokens;  // Массив токенов
    int size;       // Размер списка
} TokenList;

typedef struct {
    char* value;
    int token;
} TokenMapping;

TokenList* inputExpression(char* expression);
int getTokenType(char* token);
void addToken(TokenList* list, char* value, int type);
TokenList* tokenize(char* expression);
void freeTokenList(TokenList* tokens);
int isDigit(char c);
int findTokenByValue(char* value);

#endif /* EXPRESSION_H */

/*
    inputExpression{

        getTokenType{
            isDigit
        }

        addToken
    }

    freeTokenList
*/
