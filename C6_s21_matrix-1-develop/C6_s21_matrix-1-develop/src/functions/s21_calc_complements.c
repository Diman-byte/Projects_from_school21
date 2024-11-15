#include "../s21_matrix.h"

// D * A(-1); и это все дело транспонируем
int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int status = 0;
  if (A == NULL || A->rows < 1 || A->columns < 1 || A == NULL ||
      A->matrix == NULL || result == NULL) {
    return status = 1;
  }
  if (A->rows != A->columns) {
    return status = 2;
  }

  double det;
  s21_determinant(A, &det);

  matrix_t tmp;
  // s21_create_matrix(A->rows, A->columns, &tmp);
  s21_inverse_matrix(A, &tmp);

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      tmp.matrix[i][j] = tmp.matrix[i][j] * det;
    }
  }

  // s21_create_matrix(A->rows, A->columns, result);

  s21_transpose(&tmp, result);
  s21_remove_matrix(&tmp);

  return status;
}