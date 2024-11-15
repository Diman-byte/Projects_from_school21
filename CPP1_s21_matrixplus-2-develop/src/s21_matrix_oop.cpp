#include "s21_matrix_oop.h"

#include <iostream>
#include <stdexcept>  // length_error | out_of_range | logic_error
#include <utility>    // std::move | std::swap

S21Matrix::S21Matrix() noexcept {
  this->rows_ = 0;
  this->cols_ = 0;
  this->matrix_ = nullptr;
}

// S21Matrix::S21Matrix(int rows, int cols) : rows_(rows), cols_(cols)

S21Matrix::S21Matrix(int rows, int cols) {
  if (rows < 0 || cols < 0) {
    throw std::length_error("Rows or cols cant be < 0");
  }
  this->rows_ = rows;
  this->cols_ = cols;

  try {
    this->matrix_ = new double* [rows] {};
    for (int i = 0; i < rows; i++) {
      this->matrix_[i] = new double[cols]{};
    }
  } catch (...) {
    for (int i = 0; i < rows; i++) {
      delete[] this->matrix_[i];
    }
    delete[] this->matrix_;
    throw;
  }
}

S21Matrix::S21Matrix(const S21Matrix& other)
    : rows_(other.rows_), cols_(other.cols_) {
  // выделяем память для новой матрицы, но уже без инициализации (без {})
  try {
    this->matrix_ = new double*[rows_];
    for (int i = 0; i < rows_; i++) {
      this->matrix_[i] = new double[cols_];
      // значения новой матрицы задаем
      for (int j = 0; j < cols_; j++) {
        this->matrix_[i][j] = other.matrix_[i][j];
      }
    }
  } catch (...) {
    for (int i = 0; i < rows_; i++) {
      delete[] this->matrix_[i];
    }
    delete[] this->matrix_;
    throw;
  }
}

S21Matrix::S21Matrix(S21Matrix&& other) noexcept
    : rows_(other.rows_), cols_(other.cols_), matrix_(other.matrix_) {
  other.rows_ = 0;
  other.cols_ = 0;
  other.matrix_ = nullptr;
}

S21Matrix::~S21Matrix() noexcept { Free(); }

//Конструктор копирования используется для создания нового объекта как копии
//уже существующего объекта.Он вызывается, когда новый объект создается из уже
//существующего.

//Оператор присвоения используется для копирования данных из одного уже
//существующего объекта в другой уже существующий объект.Он вызывается, когда
//оператор = используется присвоения одного объекта другому.

//Если в программе объявить класс, в котором оператор присваивания не
//перегружается, то для этого класса компилятором будет создан оператор
//присваивания по умолчанию.При вызове оператора присваивания по умолчанию
//происходит побайтовое копирование одного экземпляра класса другому.

//*В нашем случае это недопустимо, т.к.в этом случае 2 экземпляра S21Matrix в
//* поле matrix_ будут указывать на один и тот же участок памяти - при удалении
//* одного из объектов, второй потеряет все данные и станет неконсистентным.

S21Matrix& S21Matrix::operator=(const S21Matrix& other) {
  // можно было так
  // S21Matrix copy{ other };
  //*this = std::move(copy);
  // return *this;

  if (this == &other) {
    return *this;
  }

  // освобождаем старую матрицу (ту в которую будем новые значения записывать)
  Free();

  rows_ = other.rows_;
  cols_ = other.cols_;

  // Выделяем новую память и копируем данные
  try {
    this->matrix_ = new double*[rows_];
    for (int i = 0; i < rows_; i++) {
      this->matrix_[i] = new double[cols_];

      for (int j = 0; j < cols_; j++) {
        this->matrix_[i][j] = other.matrix_[i][j];
      }
    }
  } catch (...) {
    for (int i = 0; i < rows_; i++) {
      delete[] this->matrix_[i];
    }
    delete[] this->matrix_;
    throw;
  }

  return *this;
}

S21Matrix& S21Matrix::operator=(S21Matrix&& other) noexcept {
  if (this != &other) {
    Free();
    // Идиома "copy-and-swap" обеспечивает исключение-безопасное присвоение.
    std::swap(rows_, other.rows_);
    std::swap(cols_, other.cols_);
    std::swap(matrix_, other.matrix_);
  }
  return *this;
}

void S21Matrix::SumMatrix(const S21Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::logic_error("Size matrix incorrect");
  }

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      this->matrix_[i][j] += other.matrix_[i][j];
      // (*this)(i, j) += other(i, j);
    }
  }
}

void S21Matrix::SubMatrix(const S21Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::logic_error("Size matrix incorrect");
  }

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      this->matrix_[i][j] -= other.matrix_[i][j];
      // (*this)(i, j) -= other(i, j);
    }
  }
}

bool S21Matrix::EqMatrix(const S21Matrix& other) const {
  if (rows_ == other.rows_ || cols_ == other.cols_) {
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        if (std::abs((*this).matrix_[i][j] - other.matrix_[i][j]) > Eps) {
          return false;
        }
      }
    }
    return true;
  } else {
    return false;
  }
}

void S21Matrix::MulNumber(const double num) noexcept {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      this->matrix_[i][j] *= num;
    }
  }
}

void S21Matrix::MulMatrix(const S21Matrix& other) {
  if (cols_ != other.rows_) {
    throw std::logic_error("Incorrect size matrix for Multiplication");
  }

  // называется списочной инициализацией или uniform initialization
  S21Matrix tmp{rows_, other.cols_};

  // инициализация через конструктор
  // S21Matrix tmp(rows_, other.cols_);

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < other.cols_; j++) {
      tmp.matrix_[i][j] = 0;
      for (int k = 0; k < cols_; k++) {
        tmp.matrix_[i][j] += this->matrix_[i][k] * other.matrix_[k][j];
      }
    }
  }
  // Копировать дорого, а матрица tmp нам больше не нужна, поэтому используем
  // перемещение вместо копирования (что бесплатно)
  *this = std::move(tmp);
}

S21Matrix S21Matrix::Transpose() {
  // S21Matrix tmp(rows_, cols_);
  S21Matrix tmp{cols_, rows_};

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      tmp.matrix_[j][i] = this->matrix_[i][j];
    }
  }

  return tmp;
}

//в качестве опорного элемента следует брать
//наибольший по модулю элемент, причём производить поиск опорного элемента и
//обмен с ним надо всегда, а не только когда это необходимо(т.е.не только
//тогда, когда элемент(i, i) == 0).Поиск опорного элемента на каждом шаге
//улучшает численную устойчивость алгоритма Гаусса, что очень важно.

// Метод Гаусса
double S21Matrix::Determinant() const {
  if (rows_ != cols_) {
    throw std::logic_error(
        "Matrix is not kvadrat, incorrect matrix for Determinant");
  }

  double det = 1.0;
  S21Matrix tmp{*this};
  int size = rows_;

  for (int i = 0; i < size; i++) {
    //  ищем опорник
    int pivot = i;
    for (int j = i + 1; j < size; j++) {
      if (std::abs(tmp(j, i)) > std::abs(tmp(pivot, i))) {
        pivot = j;
      }
    }

    // все элементы в столбце нулевые
    if (std::abs(tmp(pivot, i)) < Eps) {
      return 0.0;
    }

    // Меняем местами текущую строку и строку с опорным элементом.
    if (i != pivot) {
      tmp.SwapRows(pivot, i);
      // при перестановке меняем знак определителя
      det = -det;
    }

    // Осуществляем вычитание текущей строки из всех следующих
    for (int j = i + 1; j < size; j++) {
      double koef = tmp(j, i) / tmp(i, i);
      for (int k = i; k < size; k++) {
        tmp(j, k) = tmp(j, k) - tmp(i, k) * koef;
      }
    }
    det *= tmp(i, i);
  }

  return det;
}

S21Matrix S21Matrix::CalcComplements() const {
  if (rows_ != cols_) {
    throw std::logic_error(
        "Matrix is not kvadrat, incorrect matrix for CalcComplements");
  }

  S21Matrix res{rows_, cols_};
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      res(i, j) = GetMinorMatrix(i, j).Determinant();

      if ((i + j) % 2 != 0) {
        res(i, j) = -res(i, j);
      }
    }
  }

  return res;
}

//Алгоритм нахождения обратной матрицы для матрицы A :
//*1) Определяем, существует ли обратная матрица для заданной.
//* 2) Находим транспонированную матрицу A^ T.
//* 3) Составляем матрицу алгебраических дополнений для A^ T
//* 4) Составляем обратную матрицу из матрицы алгебраических дополнений : каждый
//* элемент матрицы алгебраических дополнений для A^ T делят на определитель
//* исходной матрицы.Результирующая матрица является обратной для исходной
//* матрицы.

S21Matrix S21Matrix::InverseMatrix() const {
  if (rows_ != cols_) {
    throw std::logic_error(
        "Matrix is not kvadrat, incorrect matrix for Inverse");
  }

  double det = (*this).Determinant();

  if (std::abs(det) < Eps) {
    throw std::logic_error("Det must be non-zero for Inverse");
  }

  S21Matrix tmp{*this};

  tmp = tmp.Transpose();
  S21Matrix res = {tmp.CalcComplements()};

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      res(i, j) = res(i, j) / det;
    }
  }

  return res;

  // return Transpose().CalcComplements() * (1.0 / det);
}

int S21Matrix::getCols() const noexcept { return cols_; }

int S21Matrix::getRows() const noexcept { return rows_; }

void S21Matrix::setRows(int new_rows) {
  if (new_rows < 0) {
    throw std::length_error(
        "The number of rows in a matrix cannot be less than zero");
  }

  if (new_rows != rows_) {
    S21Matrix tmp{new_rows, cols_};

    int min = std::min(new_rows, rows_);

    for (int i = 0; i < min; i++) {
      for (int j = 0; j < cols_; j++) {
        tmp.matrix_[i][j] = this->matrix_[i][j];
      }
    }

    *this = std::move(tmp);
  }
}

void S21Matrix::setCols(int new_cols) {
  if (new_cols < 0) {
    throw std::length_error(
        "The number of cols in a matrix cannot be less than zero");
  }

  if (new_cols != cols_) {
    S21Matrix tmp{rows_, new_cols};

    int min = std::min(new_cols, cols_);

    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < min; j++) {
        tmp.matrix_[i][j] = this->matrix_[i][j];
      }
    }
    // Копировать дорого, а матрица tmp нам больше не нужна, поэтому используем
    // перемещение вместо копирования (что бесплатно)
    *this = std::move(tmp);
  }
}

double& S21Matrix::operator()(int row, int col) & {
  return const_cast<double&>(GetMatrixElement(row, col));
}

const double& S21Matrix::operator()(int row, int col) const& {
  return GetMatrixElement(row, col);
}

bool S21Matrix::operator==(const S21Matrix& other) const {
  return EqMatrix(other);
}

// возвращает новую матрицу, исходную оставляя неизменной
S21Matrix S21Matrix::operator+(const S21Matrix& other) const {
  S21Matrix res{(*this)};
  res.SumMatrix(other);
  return res;
}

// возращает измененную исходную матрицу
S21Matrix& S21Matrix::operator+=(const S21Matrix& other) {
  SumMatrix(other);
  return *this;
}

S21Matrix S21Matrix::operator-(const S21Matrix& other) const {
  S21Matrix res{*this};
  res.SubMatrix(other);
  return res;
}

S21Matrix& S21Matrix::operator-=(const S21Matrix& other) {
  SubMatrix(other);
  return *this;
}

S21Matrix S21Matrix::operator*(const S21Matrix& other) const {
  S21Matrix res{*this};
  res.MulMatrix(other);
  return res;
}

S21Matrix& S21Matrix::operator*=(const S21Matrix& other) {
  MulMatrix(other);
  return *this;
}

//  * Этот метод будет срабатывать только в случае, если матрица умножается на
//  *число(именно в таком порядке).
S21Matrix S21Matrix::operator*(double num) const noexcept {
  S21Matrix res{*this};
  res.MulNumber(num);
  return res;
}

S21Matrix& S21Matrix::operator*=(double num) noexcept {
  MulNumber(num);
  return *this;
}

void S21Matrix::Free() noexcept {
  for (int i = 0; i < rows_; i++) {
    delete[] matrix_[i];
  }
  delete[] matrix_;
  rows_ = 0;
  cols_ = 0;
  matrix_ = nullptr;
}

const double& S21Matrix::GetMatrixElement(int row, int col) const {
  if (row < 0 || col < 0 || row > rows_ || col > cols_) {
    throw std::out_of_range("Incorrect row or col, out of range");
  }
  return matrix_[row][col];
}

void S21Matrix::SwapRows(int row1, int row2) {
  if (row1 != row2) {
    for (int j = 0; j < cols_; j++) {
      double tmp = (*this)(row1, j);
      (*this)(row1, j) = (*this)(row2, j);
      (*this)(row2, j) = tmp;
    }

    /*for (int i = 0; i < cols_; ++i) {
            std::swap((*this)(row1, i), (*this)(row2, i));
    }*/
  }
}

S21Matrix S21Matrix::GetMinorMatrix(const int skip_row,
                                    const int skip_column) const {
  S21Matrix res{rows_ - 1, cols_ - 1};

  int shift_row = 0;
  for (int i = 0; i < res.getRows(); i++) {
    if (i == skip_row) {
      shift_row = 1;
    }
    int shift_col = 0;
    for (int j = 0; j < res.getCols(); j++) {
      if (j == skip_column) {
        shift_col = 1;
      }

      res(i, j) = (*this)(i + shift_row, j + shift_col);
    }
  }
  return res;
}

//*Этот метод будет срабатывать только в случае, если число умножается на
//* матрицу(именно в таком порядке).
//*
//* Переменная с типом double "не знает" о том, как производится умножения на
//* матрицу.Поэтому мы объявляем данную перегрузку за пределами класса и
//* используем оператор с двумя аргументами.
//*
//* Для того, чтобы связать этот метод с классом S21Matrix, в заголовочном файле
//* класса мы определяем данный оператор как дружественный при помощи ключевого
//* слова friend.
S21Matrix operator*(double num, const S21Matrix& other) noexcept {
  S21Matrix res{other};
  res = res * num;
  return res;
}
