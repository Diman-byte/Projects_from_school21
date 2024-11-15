#ifndef CPP_S21_MATRIX_OOP_
#define CPP_S21_MATRIX_OOP_

class S21Matrix {
 private:
  // Attributes
  int rows_, cols_;  // Rows and columns
  double** matrix_;  // Pointer to the memory where the matrix is allocated

  void Free() noexcept;
  const double Eps = 1e-7;
  const double& GetMatrixElement(int row, int col) const;
  void SwapRows(int row1, int row2);
  S21Matrix GetMinorMatrix(const int skip_row, const int skip_column) const;

 public:
  S21Matrix() noexcept;  // Default constructor, noexcept - показываем, что не
                         // может вызывать исключений
  explicit S21Matrix(int rows,
                     int cols);  // explicit - запрещает неявное приведение
  S21Matrix(const S21Matrix& other);      // конс копирования
  S21Matrix(S21Matrix&& other) noexcept;  // конс переноса
  ~S21Matrix() noexcept;  // Destructor, все деструкторы должны помечаться как
                          // noexcept

  // операторы
  S21Matrix& operator=(
      const S21Matrix& other);  // оператор присваивания копированием
  S21Matrix& operator=(
      S21Matrix&& other) noexcept;  // оператор присваивания перемещением

  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  bool EqMatrix(const S21Matrix& other) const;

  void MulNumber(const double num) noexcept;
  void MulMatrix(const S21Matrix& other);
  S21Matrix Transpose();
  double Determinant() const;
  S21Matrix CalcComplements() const;
  S21Matrix InverseMatrix() const;

  int getCols() const noexcept;
  int getRows() const noexcept;
  void setRows(int new_rows);
  void setCols(int new_cols);

  double& operator()(int row, int col) &;
  double& operator()(int row, int col) && = delete;
  // для const объектов
  const double& operator()(int row, int col) const&;
  const double& operator()(int row, int col) const&& = delete;

  bool operator==(const S21Matrix& other) const;
  S21Matrix operator+(const S21Matrix& other) const;
  S21Matrix& operator+=(const S21Matrix& other);
  S21Matrix operator-(const S21Matrix& other) const;
  S21Matrix& operator-=(const S21Matrix& other);
  S21Matrix operator*(const S21Matrix& other) const;
  S21Matrix& operator*=(const S21Matrix& other);
  S21Matrix operator*(double num) const noexcept;
  friend S21Matrix operator*(double num, const S21Matrix& other) noexcept;
  S21Matrix& operator*=(double num) noexcept;
};

#endif