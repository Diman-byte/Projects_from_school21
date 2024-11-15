#include "../s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int status = 0;

  if (result == NULL) {
    return status = 1;
  }

  if (rows > 0 && columns > 0) {
    if ((result->matrix = (double **)calloc(rows, sizeof(double *))) != NULL) {
      result->rows = rows;
      result->columns = columns;

      for (int i = 0; i < rows; i++) {
        result->matrix[i] = (double *)calloc(columns, sizeof(double));
        if (result->matrix[i] == NULL) {
          // если произошла ошибка выделения, очищаем то, что выделили до этого
          for (int x = 0; x < i; x++) {
            free(result->matrix[x]);
          }
          free(result->matrix);
          result->matrix = NULL;
          return status = 1;
        }
      }

    } else {
      result->matrix = NULL;
      return status = 1;
    }
  } else {
    result->matrix = NULL;
    return status = 1;
  }

  return status;
}

void s21_remove_matrix(matrix_t *A) {
  if (A != NULL && A->matrix != NULL) {
    for (int i = 0; i < A->rows; i++) {
      free(A->matrix[i]);
    }
    free(A->matrix);
    A->matrix = NULL;
    A->columns = 0;
    A->rows = 0;
  }
}