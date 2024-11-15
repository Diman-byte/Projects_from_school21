#include "../s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int status = 0;
  if (A->rows < 1 || A->columns < 1) {
    return status = 1;
  }
  if (A == NULL || A->matrix == NULL || result == NULL) {
    return status = 1;
  }
  if (!isfinite(number)) {
    return status = 2;
  }

  s21_create_matrix(A->rows, A->columns, result);

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[i][j] = A->matrix[i][j] * number;
      if (!isfinite(result->matrix[i][j])) {
        return status = 2;
      }
    }
  }

  return status;
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int status = 0;

  if (A == NULL || A->matrix == NULL || B == NULL || B->matrix == NULL ||
      A->rows < 1 || B->rows < 1 || A->columns < 1 || B->columns < 1 ||
      result == NULL) {
    return status = 1;
  }
  if (A->columns != B->rows) {
    return status = 2;
  }

  s21_create_matrix(A->rows, B->columns, result);

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < B->columns; j++) {
      result->matrix[i][j] = 0;

      for (int k = 0; k < A->columns; k++) {
        result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
        if (!isfinite(result->matrix[i][j])) {
          return status = 2;
        }
      }
    }
  }

  return status;
}