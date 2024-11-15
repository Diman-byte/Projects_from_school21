#include "s21_math.h"

int s21_abs(int x) { return x < 0 ? x *= -1 : x; }

long double s21_acos(double x) {
  if (x <= 1 && x >= -1)
    x = PI / 2. - s21_asin(x);
  else if (x == x)
    x = NAN;
  return x;
}

long double s21_asin(double x) {
  long double result = x;
  if (x < -1 || x > 1) {
    result = NAN;
  } else if (s21_fabs(x - 1) < EPS || s21_fabs(x + 1) < EPS) {
    result = (long double)PI / 2 * x;
  } else {
    long double term = x;
    for (int i = 1; s21_fabs(term) > EPS; i++) {
      term *= x * x * (2 * i - 1) * (2 * i - 1) / ((2 * i + 1) * 2 * i);
      result += term;
    }
  }
  return result;
}

long double s21_atan(double x) {
  long double atan;
  if (x != INF && x != -INF) {
    atan = s21_asin((x) / (s21_sqrt(1 + x * x)));
  } else {
    if (x == INF)
      atan = PI / 2;
    else
      atan = -PI / 2;
  }
  return atan;
}

long double s21_ceil(double x) {
  long double result;
  if (x == x) {
    result = (int)x < x ? (int)x + 1 : (int)x;
    result = (result > MAX_DOUBLE || result < -MAX_DOUBLE) ? NAN : result;
    if (x == INF) {
      result = INF;
    }
    if (x == MINUS_INF) {
      result = MINUS_INF;
    }
  } else {
    result = x;
  }
  return result;
}

long double s21_cos(double x) { return s21_sin(x + PI / 2.0); }

long double s21_exp(double x) {
  long double add_value = 1, res = 1, i = 1;
  int flag = 0, exitFlag = 0;
  if (x < 0) {
    x *= -1;
    flag = 1;
  }
  while (s21_fabs(add_value) > EPS && exitFlag == 0) {
    add_value *= x / i;
    i += 1;
    res += add_value;
    if (res > MAX_DOUBLE) {
      res = INF;
      exitFlag = 1;
    }
  }
  if (flag == 1) {
    if (res > MAX_DOUBLE)
      res = 0;
    else
      res = 1. / res;
  }
  return res > MAX_DOUBLE ? INF : res;
}

long double s21_fabs(double x) {
  long double result;
  if (x != x)
    result = NAN;
  else
    result = x < 0.0 ? -x : x;
  return result;
}

long double s21_floor(double x) {
  long double result;
  if (x == x) {
    result = (int)x > x ? (int)x - 1 : (int)x;
    result = (result > MAX_DOUBLE || result < -MAX_DOUBLE) ? NAN : result;
    if (x == INF) result = INF;
    if (x == MINUS_INF) result = MINUS_INF;
  } else
    result = x;
  return result;
}

long double s21_fmod(double x, double y) {
  long double res;
  if (x != x)
    res = x;
  else if ((x == INF || x == MINUS_INF) && (y == INF || y == MINUS_INF)) {
    res = MINUS_NAN;
  } else {
    long long int mod = x / y;
    res = (long double)x - mod * (long double)y;
    if (y == INF) res = (long double)1.0 * x;
  }
  return res;
}

long double s21_log(double x) {
  long double result = 0;
  if (x == INF)
    result = INF;
  else if (x == -INF)
    result = -NAN;
  else if (x != x)
    result = x;
  else if (x > 0) {
    long double term = (x - 1) / (x + 1);
    long double term_squared = term * term;
    long double numerator = term;
    long double denominator = 1.;

    for (int n = 1; n <= 200; n += 2) {
      result += numerator / denominator;
      numerator *= term_squared;
      denominator += 2;
    }

    result *= 2;
  } else
    result = MINUS_NAN;
  return result;
}

long double s21_pow(double base, double exp) {
  long double res;
  if (base != base)
    res = base;
  else if (exp != exp)
    res = exp;
  else if (!exp)
    res = 1;
  else if (base < EPS && base >= 0 && exp < EPS)
    res = INF;
  else if (base < EPS && base >= 0 && exp > EPS)
    res = 0;
  else if (base == MINUS_INF && exp == MINUS_INF)
    res = 0;
  else if (base == MINUS_INF && exp == INF)
    res = INF;
  else if (base < 0 && exp != (long long int)exp)
    res = NAN;
  else {
    int sign = base < EPS ? -1 : 1;
    res = s21_exp(exp * s21_log(base * sign));
    if (s21_fmod(exp, 2)) res *= sign;
  }
  return res;
}

long double s21_sin(double x) {
  long double result = 0;
  if (x == INF || x == -INF)
    result = -NAN;
  else {
    while (s21_fabs(x) - 2 * PI > 0) {
      x += 2 * PI * x / s21_fabs(x) * -1;
    }
    int sign = 1;
    double xx = x * x, pw = x, factorial = 1.0;
    for (int i = 1; i < 200; i += 2) {
      factorial *= i;
      result += sign * pw / factorial;
      factorial *= (i + 1);
      sign = -sign;
      pw *= xx;
    }
  }
  return result;
}

long double s21_sqrt(double x) {
  long double result = 4, y = 0;
  int exitFlag = 0;
  if (x == INF)
    result = INF;
  else if (x == -INF)
    result = -NAN;
  else {
    while (s21_fabs(result - y) > EPS && exitFlag == 0) {
      if (x < 0) {
        result = MINUS_NAN;
        exitFlag = 1;
      } else {
        y = result;
        result = (y + x / y) / 2;
      }
    }
  }
  return result;
}

long double s21_tan(double x) {
  long double result;
  if (x == INF || x == -INF)
    result = -NAN;
  else
    result = s21_sin(x) / s21_cos(x);
  return result;
}
