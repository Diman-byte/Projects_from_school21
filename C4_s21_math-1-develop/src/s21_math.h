#ifndef S21_MATH_H
#define S21_MATH_H

#include <stdio.h>
#include <stdlib.h>

#define PI 3.14159265358979324
#define MINUS_PI -3.14159265358979324

#define EPS_POW 1e-2
#define EPS 1e-10

#define INF +1.0 / 0.0
#define MINUS_INF -1.0 / 0.0

#ifndef NAN
#define NAN (__builtin_nanf(""))
// #define NAN 0.0 / 0.0
#endif

#define MINUS_NAN -0.0 / 0.0

#define MAX_DOUBLE 1.7976931348623157e308

int s21_abs(int x);
long double s21_acos(double x);
long double s21_asin(double x);
long double s21_atan(double x);
long double s21_ceil(double x);
long double s21_cos(double x);
long double s21_exp(double x);
long double s21_fabs(double x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);
long double s21_log(double x);
long double s21_pow(double base, double exp);
long double s21_sin(double x);
long double s21_sqrt(double x);
long double s21_tan(double x);

#endif
