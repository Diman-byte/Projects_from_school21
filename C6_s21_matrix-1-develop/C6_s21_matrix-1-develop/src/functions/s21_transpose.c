#include "../s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  int status = 0;
  if (A->rows < 1 || A->columns < 1 || A == NULL || A->matrix == NULL ||
      result == NULL) {
    return status = 1;
  }

  s21_create_matrix(A->columns, A->rows, result);

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[j][i] = A->matrix[i][j];
    }
  }

  return status;
}