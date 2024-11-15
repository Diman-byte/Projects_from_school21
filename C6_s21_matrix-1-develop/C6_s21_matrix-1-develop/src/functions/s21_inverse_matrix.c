#include "../s21_matrix.h"

// Функция для приведения расширенной матрицы к верхнетреугольному виду
void to_upper_triangular(matrix_t *matrix) {
  int rows = matrix->rows;
  int columns = matrix->columns;

  for (int i = 0; i < rows; i++) {
    // Поиск ненулевого элемента в текущем столбце
    int pivot = -1;
    for (int j = i; j < rows; j++) {
      if (matrix->matrix[j][i] != 0) {
        pivot = j;
        break;
      }
    }
    // Если ненулевой элемент найден, меняем строки местами
    if (pivot != -1) {
      swap_rows(matrix, i, pivot);
      // Делаем текущий элемент главным элементом
      double scale = 1.0 / matrix->matrix[i][i];
      for (int j = 0; j < columns; j++) {
        matrix->matrix[i][j] *= scale;
      }
      // Приводим остальные строки к нулю
      for (int j = i + 1; j < rows; j++) {
        double factor = matrix->matrix[j][i];
        for (int k = 0; k < columns; k++) {
          matrix->matrix[j][k] -= factor * matrix->matrix[i][k];
        }
      }
    }
  }
}

// Функция для обратного хода метода Гаусса
void back_substitution(matrix_t *matrix) {
  int rows = matrix->rows;
  int columns = matrix->columns;

  for (int i = rows - 1; i > 0; i--) {
    for (int j = i - 1; j >= 0; j--) {
      double factor = matrix->matrix[j][i];
      for (int k = 0; k < columns; k++) {
        matrix->matrix[j][k] -= factor * matrix->matrix[i][k];
      }
    }
  }
}

// Функция для нахождения обратной матрицы
int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int status = 0;
  if (A->rows < 1 || A->columns < 1 || A == NULL || A->matrix == NULL ||
      result == NULL) {
    return status = 1;
  }
  if (A->rows != A->columns) {
    return status = 2;
  }

  double det_1 = 0;
  s21_determinant(A, &det_1);
  if (det_1 == 0) {
    return status = 2;
  }

  int rows = A->rows;
  int columns = A->columns;

  // Создание единичной матрицы
  matrix_t identity_matrix;
  s21_create_matrix(rows, columns, &identity_matrix);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      if (i == j)
        identity_matrix.matrix[i][j] = 1.0;
      else
        identity_matrix.matrix[i][j] = 0.0;
    }
  }

  // Объединение исходной матрицы и единичной матрицы
  matrix_t augmented_matrix;
  s21_create_matrix(rows, columns * 2, &augmented_matrix);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      augmented_matrix.matrix[i][j] = A->matrix[i][j];
    }
    for (int j = columns; j < columns * 2; j++) {
      augmented_matrix.matrix[i][j] = identity_matrix.matrix[i][j - columns];
    }
  }

  // Приведение расширенной матрицы к верхнетреугольному виду
  to_upper_triangular(&augmented_matrix);

  // Обратный ход метода Гаусса
  back_substitution(&augmented_matrix);

  // Создание матрицы для хранения обратной матрицы
  s21_create_matrix(rows, columns, result);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      result->matrix[i][j] = augmented_matrix.matrix[i][j + columns];
    }
  }

  // Освобождение памяти
  s21_remove_matrix(&identity_matrix);
  s21_remove_matrix(&augmented_matrix);

  return status;
}