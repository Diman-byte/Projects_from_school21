#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unity.h>

#include "evaluation.h"

// gcc -o TEST evaluation.c test_evaluation.c src/unity.c -I src
double* someData = NULL;

int isOperator(char* token);

void setUp() { someData = (double*)malloc(sizeof(double) * 10); }

void tearDown() {
    free(someData);
    someData = NULL;
}
void test_evaluarteRPN() {
    RPNExpression rpn;
    rpn.size = 5;
    rpn.expression = (char**)malloc(rpn.size * sizeof(char*));
    rpn.expression[0] = "2.0";
    rpn.expression[1] = "3.0";
    rpn.expression[2] = "+";
    rpn.expression[3] = "4.0";
    rpn.expression[4] = "*";

    double result = evaluateRPN(&rpn, 0.0);
    double expected = 14.0;
    TEST_ASSERT_EQUAL_DOUBLE(expected, result);
    freeRPNExpression(&rpn);
}

void test_evaluateRPN_DivisionByZero() {
    RPNExpression rpn;
    rpn.size = 3;
    rpn.expression = (char**)malloc(rpn.size * sizeof(char*));
    rpn.expression[0] = "2.0";
    rpn.expression[1] = "0.0";
    rpn.expression[2] = "/";
    double result = evaluateRPN(&rpn, 0.0);
    double expected = INFINITY;
    TEST_ASSERT_EQUAL_DOUBLE(expected, result);

    freeRPNExpression(&rpn);
}

void test_isOperator() {
    TEST_ASSERT_EQUAL_INT(1, isOperator("+"));
    TEST_ASSERT_EQUAL_INT(1, isOperator("-"));
    TEST_ASSERT_EQUAL_INT(1, isOperator("*"));
    TEST_ASSERT_EQUAL_INT(1, isOperator("u-"));
    TEST_ASSERT_EQUAL_INT(1, isOperator("sin"));

    TEST_ASSERT_EQUAL_INT(0, isOperator("xyz"));
}

int main() {
    UNITY_BEGIN();
    RUN_TEST(test_evaluarteRPN);
    RUN_TEST(test_evaluateRPN_DivisionByZero);
    RUN_TEST(test_isOperator);

    UNITY_END();
}

/*

test_evaluation.c:32:test_evaluarteRPN:FAIL: Unity Double Precision Disabled
Ошибка: Деление на  ноль.
*/
