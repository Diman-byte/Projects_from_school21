#include "../s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int result;
  if (A->rows == B->rows && A->columns == B->columns) {
    result = 1;
  } else {
    return result = 0;
  }

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      if (fabs(A->matrix[i][j] - B->matrix[i][j]) <= 1e-7) {
        result = 1;
      } else {
        return result = 0;
      }
    }
  }

  return result;
}