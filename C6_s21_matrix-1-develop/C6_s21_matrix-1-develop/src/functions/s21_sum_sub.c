#include "../s21_matrix.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int status;

  if (A == NULL || A->matrix == NULL || B == NULL || B->matrix == NULL ||
      A->rows < 1 || B->rows < 1 || A->columns < 1 || B->columns < 1 ||
      result == NULL) {
    return status = 1;
  }
  if (A->rows == B->rows && A->columns == B->columns) {
    status = 0;
  } else {
    return status = 2;
  }

  s21_create_matrix(A->rows, A->columns, result);

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
      if (!isfinite(result->matrix[i][j])) {
        return status = 2;
      }
    }
  }

  return status;
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int status;

  if (A == NULL || A->matrix == NULL || B == NULL || B->matrix == NULL ||
      A->rows < 1 || B->rows < 1 || A->columns < 1 || B->columns < 1 ||
      result == NULL) {
    return status = 1;
  }
  if (A->rows == B->rows && A->columns == B->columns) {
    status = 0;
  } else {
    return status = 2;
  }

  s21_create_matrix(A->rows, A->columns, result);

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
      if (!isfinite(result->matrix[i][j])) {
        return status = 2;
      }
    }
  }

  return status;
}