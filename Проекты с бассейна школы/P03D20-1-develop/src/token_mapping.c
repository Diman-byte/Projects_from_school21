#include "token_mapping.h"

#include <stdio.h>

TokenMapping validTokens[] = {
    {"+", OPERATOR_PLUS},    {"-", OPERATOR_MINUS},    {"*", OPERATOR_MULTIPLY}, {"/", OPERATOR_DIVIDE},
    {"(", OPEN_PARENTHESIS}, {")", CLOSE_PARENTHESIS}, {"sin", FUNCTION_SIN},    {"cos", FUNCTION_COS},
    {"tan", FUNCTION_TAN},   {"ctg", FUNCTION_CTG},    {"sqrt", FUNCTION_SQRT},  {"ln", FUNCTION_LN},
};

int findTokenByValue(char* value) {
    int numTokens = sizeof(validTokens) / sizeof(validTokens[0]);
    for (int i = 0; i < numTokens; i++) {
        if (strcmp(validTokens[i].value, value) == 0) {
            return validTokens[i].token;
        }
    }
    return -1;
}