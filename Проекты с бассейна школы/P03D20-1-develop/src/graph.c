#include <stdio.h>

#include "evaluation.h"
#include "expression.h"
#include "rendering.h"

int main() {
    // Ввод математического выражения от пользователя
    char expression[100];  // Максимальная длина выражения (можно увеличить)
    printf("Введите математическое выражение: ");
    scanf("%s", expression);

    // Разбор математического выражения и получение списка токенов
    TokenList* tokens = tokenize(expression);

    // Преобразование в ОПЗ
    RPNExpression* rpn = infixToRPN(tokens);

    // Вычисление значения выражения (подставьте значение переменной x)
    double x = 3.14;  // Пример значения x
    double result = evaluateRPN(rpn, x);

    // Отрисовка графика на основе результата вычислений
    renderGraph(result);

    // Освобождение памяти
    freeTokenList(tokens);
    freeRPNExpression(rpn);

    return 0;
}

/*
    expression.c - Разбор мат выражения и создание списка токенов

    evaluation.с - Реализуют алгоритмы для преобразования выражения в обратную польскую записть ОПЗ и
   вычисления значения выражентя на основе ОПЗ

    rendering.c - Отвечают за отрисовку графика функции

*/