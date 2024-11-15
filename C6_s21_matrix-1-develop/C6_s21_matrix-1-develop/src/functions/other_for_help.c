#include "../s21_matrix.h"

void print_dynamic_matrix(matrix_t *A) {
  if (A == NULL || A->matrix == NULL) {
    printf("Matrix not exist\n");
  }

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      if (j == A->columns - 1) {
        printf("%lf", A->matrix[i][j]);
      } else {
        printf("%lf ", A->matrix[i][j]);
      }
    }
    if (i != A->rows - 1) {
      printf("\n");
    }
  }
}

void s21_initialize_matrix(matrix_t *A, double start_value,
                           double iteration_step) {
  if (A != NULL && A->matrix != NULL) {
    double value = start_value;
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        A->matrix[i][j] = value;
        value += iteration_step;
      }
    }
  }
}