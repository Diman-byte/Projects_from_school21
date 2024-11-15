#include "../s21_matrix.h"

void swap_rows(matrix_t *mat, int row1, int row2) {
  for (int i = 0; i < mat->rows; i++) {
    double temp = mat->matrix[row1][i];
    mat->matrix[row1][i] = mat->matrix[row2][i];
    mat->matrix[row2][i] = temp;
  }
}

void copy_matrix(matrix_t *src, matrix_t *dest) {
  for (int i = 0; i < src->rows; i++) {
    for (int j = 0; j < src->columns; j++) {
      dest->matrix[i][j] = src->matrix[i][j];
    }
  }
}

// по методу Гаусса
int s21_determinant(matrix_t *B, double *result) {
  int status = 0;
  if (B->rows < 1 || B->columns < 1 || B == NULL || B->matrix == NULL) {
    return status = 1;
  }
  if (B->rows != B->columns) {
    return status = 2;
  }

  // делаю матрицу А для того, чтобы не менять исходную матрицу В при приведении
  // к верхнеугольной
  matrix_t A;
  s21_create_matrix(B->rows, B->columns, &A);
  copy_matrix(B, &A);

  double det = 1;  // Инициализация определителя

  // Приведение матрицы к верхнетреугольному виду
  for (int i = 0; i < A.rows; i++) {
    // Если на главной диагонали элемент равен нулю, меняем строки местами
    if (A.matrix[i][i] == 0) {
      int j;
      for (j = i + 1; j < A.rows; j++) {
        if (A.matrix[j][i] != 0) {
          swap_rows(&A, i, j);
          det *= -1;  // Меняем знак определителя при обмене строк
          break;
        }
      }
      // Если все элементы нулевые, определитель равен 0
      if (j == A.rows) {
        s21_remove_matrix(&A);
        *result = 0;
        return status = 0;
      }
    }

    // Приведение матрицы к верхнетреугольному виду
    for (int j = i + 1; j < A.rows; j++) {
      double ratio = A.matrix[j][i] / A.matrix[i][i];
      for (int k = 0; k < A.rows; k++) {
        A.matrix[j][k] -= ratio * A.matrix[i][k];
      }
    }

    det *= A.matrix[i][i];  // Обновляем определитель
  }

  s21_remove_matrix(&A);

  *result = det;

  return status;
}