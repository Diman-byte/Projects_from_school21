#include "s21_sprintf.h"

int s21_sprintf(char* str, const char* format, ...) {
  va_list args;
  void* adr_ptr;
  size_t index_str = 0;
  size_t str_index = 0;
  size_t width = 0;
  size_t precision = 0;
  char long_short_f = 0;
  bool flag_not_spec = 0;
  bool flag_plus = 0;
  bool flag_minus = 0;
  bool flag_nul = 0;
  bool flag_space = 0;
  bool flag_precision = 0;
  bool flag_sharp = 0;

  int int_num = 0;
  long int l_int_num = 0;
  long long int ll_int_num = 0;
  short int h_int_num = 0;
  unsigned int u_int_num = 0;
  unsigned long int u_l_int_num = 0;
  unsigned long long int u_ll_int_num = 0;
  unsigned short int u_h_int_num = 0;
  float float_num = 0;
  double l_float = 0;
  long double ll_float = 0;
  char* string = 0;

  // read args
  va_start(args, format);

  // format processing
  while (*format) {
    if (*format == '%') {
      format++;
      if (*format == '%') {
        flag_not_spec = 1;
        format++;
      }
      // flags processing
      for (int i = 0; i < 5; i++) {
        if (*format == '#') {
          flag_sharp = 1;
          format++;
        }
        if (*format == '+') {
          flag_plus = 1;
          format++;
        }
        if (*format == '-') {
          flag_minus = 1;
          format++;
        }
        while (*format == ' ') {
          flag_space = 1;
          format++;
        }
        if (*format == '0') {
          flag_nul = 1;
          format++;
        }
      }
      if (*format == '*') {
        width = va_arg(args, int);
        format++;
      } else
        while (*format >= '0' && *format <= '9') {
          width = width * 10 + *format - '0';
          format++;
        }
      if (*format == '.') {
        flag_precision = 1;
        format++;
        if (*format == '*') {
          precision = va_arg(args, int);
          format++;
        } else
          while (*format >= '0' && *format <= '9') {
            precision = precision * 10 + *format - '0';
            format++;
          }
      }
      // read formats - long, short, long long
      if (*format == 'l' || *format == 'L' || *format == 'h') {
        if (*format == 'l') {
          format++;
          if (*format == 'l') {
            long_short_f = 'L';
            format++;
          } else
            long_short_f = 'l';
        } else {
          long_short_f = *format;
          format++;
        }
      } else
        long_short_f = 0;

      // run algs
      switch (*format) {
        case 'c':
          if (!flag_not_spec) {
            if (long_short_f == 'l') {
              string = malloc(sizeof(wchar_t) * 2);
              *(wchar_t*)string = va_arg(args, wchar_t);
              string++;
              *(wchar_t*)string = '\0';
              string--;
            } else {
              string = malloc(sizeof(char) * 2);
              *string = va_arg(args, int);
              string++;
              *string = '\0';
              string--;
            }
          }
          break;
        case 'd':
          if (!flag_not_spec) {
            if (long_short_f == 'h') {
              h_int_num = va_arg(args, int);
              string = int_arg(&h_int_num, long_short_f, flag_plus, precision,
                               flag_precision, flag_sharp, *format);
            } else if (long_short_f == 'l') {
              l_int_num = va_arg(args, long int);
              string = int_arg(&l_int_num, long_short_f, flag_plus, precision,
                               flag_precision, flag_sharp, *format);
            } else if (long_short_f == 'L') {
              ll_int_num = va_arg(args, long long int);
              string = int_arg(&ll_int_num, long_short_f, flag_plus, precision,
                               flag_precision, flag_sharp, *format);
            } else {
              int_num = va_arg(args, int);
              string = int_arg(&int_num, long_short_f, flag_plus, precision,
                               flag_precision, flag_sharp, *format);
            }
          }
          break;
        case 'i':
          if (!flag_not_spec) {
            if (long_short_f == 'h') {
              h_int_num = va_arg(args, int);
              string = int_arg(&h_int_num, long_short_f, flag_plus, precision,
                               flag_precision, flag_sharp, *format);
            } else if (long_short_f == 'l') {
              l_int_num = va_arg(args, long int);
              string = int_arg(&l_int_num, long_short_f, flag_plus, precision,
                               flag_precision, flag_sharp, *format);
            } else if (long_short_f == 'L') {
              ll_int_num = va_arg(args, long long int);
              string = int_arg(&ll_int_num, long_short_f, flag_plus, precision,
                               flag_precision, flag_sharp, *format);
            } else {
              int_num = va_arg(args, int);
              string = int_arg(&int_num, long_short_f, flag_plus, precision,
                               flag_precision, flag_sharp, *format);
            }
          }
          break;
        case 'e':
          if (!flag_not_spec) {
            if (!flag_precision) precision = 6;

            if (long_short_f == 'l') {
              l_float = va_arg(args, double);
              string = float_e_arg(&l_float, long_short_f, flag_plus, precision,
                                   flag_sharp, *format);
            } else if (long_short_f == 'L') {
              ll_float = va_arg(args, long double);
              string = float_e_arg(&ll_float, long_short_f, flag_plus,
                                   precision, flag_sharp, *format);
            } else {
              float_num = va_arg(args, double);
              string = float_e_arg(&float_num, long_short_f, flag_plus,
                                   precision, flag_sharp, *format);
            }
          }
          break;
        case 'E':
          if (!flag_not_spec) {
            if (!flag_precision) precision = 6;

            if (long_short_f == 'l') {
              l_float = va_arg(args, double);
              string = float_e_arg(&l_float, long_short_f, flag_plus, precision,
                                   flag_sharp, *format);
            } else if (long_short_f == 'L') {
              ll_float = va_arg(args, long double);
              string = float_e_arg(&ll_float, long_short_f, flag_plus,
                                   precision, flag_sharp, *format);
            } else {
              float_num = va_arg(args, double);
              string = float_e_arg(&float_num, long_short_f, flag_plus,
                                   precision, flag_sharp, *format);
            }
          }
          break;
        case 'f':
          if (!flag_not_spec) {
            if (!flag_precision) precision = 6;

            if (long_short_f == 'l') {
              l_float = va_arg(args, double);
              string = float_f_arg(&l_float, long_short_f, flag_plus, precision,
                                   flag_sharp, *format);
            } else if (long_short_f == 'L') {
              ll_float = va_arg(args, long double);
              string = float_f_arg(&ll_float, long_short_f, flag_plus,
                                   precision, flag_sharp, *format);
            } else {
              float_num = va_arg(args, double);
              string = float_f_arg(&float_num, long_short_f, flag_plus,
                                   precision, flag_sharp, *format);
            }
          }
          break;
        case 'g':
          if (!flag_not_spec) {
            if (!flag_precision) precision = 6;

            if (long_short_f == 'l') {
              l_float = va_arg(args, double);
              string = float_g_arg(&l_float, long_short_f, flag_plus, precision,
                                   flag_precision, flag_sharp, *format);
            } else if (long_short_f == 'L') {
              ll_float = va_arg(args, long double);
              string =
                  float_g_arg(&ll_float, long_short_f, flag_plus, precision,
                              flag_precision, flag_sharp, *format);
            } else {
              float_num = va_arg(args, double);
              string =
                  float_g_arg(&float_num, long_short_f, flag_plus, precision,
                              flag_precision, flag_sharp, *format);
            }
          }
          break;
        case 'G':
          if (!flag_not_spec) {
            if (!flag_precision) precision = 6;

            if (long_short_f == 'l') {
              l_float = va_arg(args, double);
              string = float_g_arg(&l_float, long_short_f, flag_plus, precision,
                                   flag_precision, flag_sharp, *format);
            } else if (long_short_f == 'L') {
              ll_float = va_arg(args, long double);
              string =
                  float_g_arg(&ll_float, long_short_f, flag_plus, precision,
                              flag_precision, flag_sharp, *format);
            } else {
              float_num = va_arg(args, double);
              string =
                  float_g_arg(&float_num, long_short_f, flag_plus, precision,
                              flag_precision, flag_sharp, *format);
            }
          }
          break;
        case 'o':
          if (!flag_not_spec) {
            if (long_short_f == 'h') {
              u_h_int_num = va_arg(args, unsigned int);
              string = int_arg(&u_h_int_num, long_short_f, flag_plus, precision,
                               flag_precision, flag_sharp, *format);
            } else if (long_short_f == 'l') {
              u_l_int_num = va_arg(args, unsigned long int);
              string = int_arg(&u_l_int_num, long_short_f, flag_plus, precision,
                               flag_precision, flag_sharp, *format);
            } else if (long_short_f == 'L') {
              u_ll_int_num = va_arg(args, unsigned long long int);
              string = int_arg(&u_ll_int_num, long_short_f, flag_plus,
                               precision, flag_precision, flag_sharp, *format);
            } else {
              u_int_num = va_arg(args, unsigned int);
              string = int_arg(&u_int_num, long_short_f, flag_plus, precision,
                               flag_precision, flag_sharp, *format);
            }
          }
          break;
        case 's':
          if (!flag_not_spec) {
            char* str_tmp = va_arg(args, char*);
            size_t tmp_len = (flag_precision) ? precision : s21_strlen(str_tmp);

            if (precision > s21_strlen(str_tmp)) {
              tmp_len = s21_strlen(str_tmp);
              precision = tmp_len;
            }

            string = malloc(sizeof(char) * (tmp_len + 1));

            for (size_t i = 0;
                 i < tmp_len || (flag_precision && precision != 0); i++) {
              string[i] = str_tmp[tmp_len - 1 - i];
              precision--;
            }

            string[tmp_len] = '\0';
          }
          break;
        case 'u':
          if (!flag_not_spec) {
            if (long_short_f == 'h') {
              u_h_int_num = va_arg(args, unsigned int);
              string = int_arg(&u_h_int_num, long_short_f, flag_plus, precision,
                               flag_precision, flag_sharp, *format);
            } else if (long_short_f == 'l') {
              u_l_int_num = va_arg(args, unsigned long int);
              string = int_arg(&u_l_int_num, long_short_f, flag_plus, precision,
                               flag_precision, flag_sharp, *format);
            } else if (long_short_f == 'L') {
              u_ll_int_num = va_arg(args, unsigned long long int);
              string = int_arg(&u_ll_int_num, long_short_f, flag_plus,
                               precision, flag_precision, flag_sharp, *format);
            } else {
              u_int_num = va_arg(args, unsigned int);
              string = int_arg(&u_int_num, long_short_f, flag_plus, precision,
                               flag_precision, flag_sharp, *format);
            }
          }
          break;
        case 'x':
          if (!flag_not_spec) {
            if (long_short_f == 'h') {
              u_h_int_num = va_arg(args, unsigned int);
              string = int_arg(&u_h_int_num, long_short_f, flag_plus, precision,
                               flag_precision, flag_sharp, *format);
            } else if (long_short_f == 'l') {
              u_l_int_num = va_arg(args, unsigned long int);
              string = int_arg(&u_l_int_num, long_short_f, flag_plus, precision,
                               flag_precision, flag_sharp, *format);
            } else if (long_short_f == 'L') {
              u_ll_int_num = va_arg(args, unsigned long long int);
              string = int_arg(&u_ll_int_num, long_short_f, flag_plus,
                               precision, flag_precision, flag_sharp, *format);
            } else {
              u_int_num = va_arg(args, unsigned int);
              string = int_arg(&u_int_num, long_short_f, flag_plus, precision,
                               flag_precision, flag_sharp, *format);
            }
          }
          break;
        case 'X':
          if (!flag_not_spec) {
            if (long_short_f == 'h') {
              u_h_int_num = va_arg(args, unsigned int);
              string = int_arg(&u_h_int_num, long_short_f, flag_plus, precision,
                               flag_precision, flag_sharp, *format);
            } else if (long_short_f == 'l') {
              u_l_int_num = va_arg(args, unsigned long int);
              string = int_arg(&u_l_int_num, long_short_f, flag_plus, precision,
                               flag_precision, flag_sharp, *format);
            } else if (long_short_f == 'L') {
              u_ll_int_num = va_arg(args, unsigned long long int);
              string = int_arg(&u_ll_int_num, long_short_f, flag_plus,
                               precision, flag_precision, flag_sharp, *format);
            } else {
              u_int_num = va_arg(args, unsigned int);
              string = int_arg(&u_int_num, long_short_f, flag_plus, precision,
                               flag_precision, flag_sharp, *format);
            }
          }
          break;
        case 'p':
          if (!flag_not_spec) {
            flag_sharp = 1;

            u_int_num = va_arg(args, unsigned int);
            string = int_arg(&u_int_num, long_short_f, flag_plus, precision,
                             flag_precision, flag_sharp, *format);
          }
          break;
        case 'n':
          if (!flag_not_spec) {
            flag_space = 0;
            long_short_f = 0;
            flag_plus = 0;
            flag_minus = 0;
            flag_nul = 0;
            width = 0;
            precision = 0;
            flag_precision = 0;
            flag_not_spec = 0;
            flag_sharp = 0;

            adr_ptr = va_arg(args, void*);
            *(int*)adr_ptr = index_str;
            string = malloc(1);
            *string = '\0';
          }
          break;
        default:
          flag_not_spec = 1;
      }

      if (!flag_not_spec) {
        // Начало вывода
        str_index = s21_strlen(string);
        // printf("%ld\n", str_index);
        if (width < str_index) width = str_index;

        // Обработка флага пробела
        if (flag_space && str_index >= width && !flag_plus && *format != 'c' &&
            *format != 'u' && *format != 'o' && *format != 'x' &&
            *format != 'X' &&
            *format != 's') {  // UPD: убрал условие  "&& *format != 'p'" -- >
                               // теперь флаг (пробел) учитывается и в случае %p
          str_index--;
          if (string[str_index] != '-') {
            str[index_str] = ' ';
            index_str++;
          }
        }

        if ((isinf(float_num) || isinf(l_float) || isinf(ll_float)) && flag_nul)
          flag_nul = 0;

        // sign processing
        if (flag_nul && !flag_minus && *format != 'c' && *format != 's' &&
            *format != 'n') {
          str_index--;
          if (string[str_index] == '-' || string[str_index] == '+') {
            str[index_str] = string[str_index];
            index_str++;
            str_index--;
            width--;
          }
        }
        // output
        bool b = 0;
        if ((!string[str_index] && str_index) && !flag_minus) str_index--;
        while (str_index || width) {
          if (str_index && (width == str_index || flag_minus || !width ||
                            (flag_nul && ((*format == 'x' || *format == 'X' ||
                                           *format == 'p') &&
                                          ((string[str_index] == 'x' ||
                                            string[str_index - 1] == 'X'))))))
            str_index--;
          if (width) width--;

          if ((width == str_index || flag_minus ||
               (str_index > 1 && flag_nul &&
                ((*format == 'x' || *format == 'X' || *format == 'p') &&
                 (string[str_index] == '0' &&
                  (string[str_index - 1] == 'x' ||
                   string[str_index - 1] == 'X'))))) &&
              !b && string[str_index]) {
            if (str_index > 1 &&
                (*format == 'x' || *format == 'X' || *format == 'p') &&
                (string[str_index] == '0' && (string[str_index - 1] == 'x' ||
                                              string[str_index - 1] == 'X'))) {
              width -= 1;
              str[index_str] = string[str_index];
              index_str++;
              str_index--;
              str[index_str] = string[str_index];
            } else
              str[index_str] = string[str_index];
          } else {
            if (flag_nul && !flag_minus && *format != 's' && *format != 'c' &&
                *format != 'n')
              str[index_str] = '0';
            else
              str[index_str] = ' ';
          }
          index_str++;
          if (!str_index && flag_minus) b = 1;
        }

        format++;
        free(string);
      } else {
        // specificator output
        if (*format == '%') format--;
        while (*format != '%') format--;

        str[index_str] = *format;
        index_str++;
        format++;
      }
    } else {
      // output format
      str[index_str] = *format;
      index_str++;
      format++;
    }
    // flags reinitializing
    flag_space = 0;
    long_short_f = 0;
    flag_plus = 0;
    flag_minus = 0;
    flag_nul = 0;
    width = 0;
    precision = 0;
    flag_precision = 0;
    flag_not_spec = 0;
    flag_sharp = 0;
  }

  // free memory and return
  str[index_str] = '\0';
  va_end(args);
  return s21_strlen(str);
}

void* int_arg(void* number, const char LS, const bool flag_plus, size_t prec,
              const bool pf, const bool flag_sharp, const char format) {
  char* head_int_to_char = malloc(sizeof(char));
  char* int_to_char = head_int_to_char;
  char temp_num = 0;
  int sign = 0;
  size_t mas_size = 1;
  bool zero = 0;
  bool is_nil = 0;

  // if zero
  if (!*(int*)number) {
    if (format != 'p') zero = 1;
    if ((prec || !pf)) {
      mas_size++;
      *int_to_char = '0';
      head_int_to_char = realloc(head_int_to_char, mas_size + 1);
      int_to_char = head_int_to_char + mas_size - 1;
    }
  }

  // specificators
  if (format == 'o') {
    if (LS == 'h') {
      while (*(unsigned short int*)number) {
        mas_size++;
        temp_num = *(unsigned short int*)number % 8 + '0';
        *int_to_char = temp_num;
        head_int_to_char = realloc(head_int_to_char, mas_size + 1);
        int_to_char = head_int_to_char + mas_size - 1;
        *(unsigned short int*)number /= 8;
      }
    } else if (LS == 'l') {
      while (*(unsigned long int*)number) {
        mas_size++;
        temp_num = *(unsigned long int*)number % 8 + '0';
        *int_to_char = temp_num;
        head_int_to_char = realloc(head_int_to_char, mas_size + 1);
        int_to_char = head_int_to_char + mas_size - 1;
        *(unsigned long int*)number /= 8;
      }
    } else if (LS == 'L') {
      while (*(unsigned long long int*)number) {
        mas_size++;
        temp_num = *(unsigned long long int*)number % 8 + '0';
        *int_to_char = temp_num;
        head_int_to_char = realloc(head_int_to_char, mas_size + 1);
        int_to_char = head_int_to_char + mas_size - 1;
        *(unsigned long long int*)number /= 8;
      }
    } else {
      // output in mas
      while (*(unsigned int*)number) {
        mas_size++;
        temp_num = *(unsigned int*)number % 8 + '0';
        *int_to_char = temp_num;
        head_int_to_char = realloc(head_int_to_char, mas_size + 1);
        int_to_char = head_int_to_char + mas_size - 1;
        *(unsigned int*)number /= 8;
      }
    }
  }
  if (format == 'u') {
    if (LS == 'h') {
      while (*(unsigned short int*)number) {
        mas_size++;
        temp_num = *(unsigned short int*)number % 10 + '0';
        *int_to_char = temp_num;
        head_int_to_char = realloc(head_int_to_char, mas_size + 1);
        int_to_char = head_int_to_char + mas_size - 1;
        *(unsigned short int*)number /= 10;
      }
    } else if (LS == 'l') {
      while (*(unsigned long int*)number) {
        mas_size++;
        temp_num = *(unsigned long int*)number % 10 + '0';
        *int_to_char = temp_num;
        head_int_to_char = realloc(head_int_to_char, mas_size + 1);
        int_to_char = head_int_to_char + mas_size - 1;
        *(unsigned long int*)number /= 10;
      }
    } else if (LS == 'L') {
      while (*(unsigned long long int*)number) {
        mas_size++;
        temp_num = *(unsigned long long int*)number % 10 + '0';
        *int_to_char = temp_num;
        head_int_to_char = realloc(head_int_to_char, mas_size + 1);
        int_to_char = head_int_to_char + mas_size - 1;
        *(unsigned long long int*)number /= 10;
      }
    } else {
      // output in mas
      while (*(unsigned int*)number) {
        mas_size++;
        temp_num = *(unsigned int*)number % 10 + '0';
        *int_to_char = temp_num;
        head_int_to_char = realloc(head_int_to_char, mas_size + 1);
        int_to_char = head_int_to_char + mas_size - 1;
        *(unsigned int*)number /= 10;
      }
    }
  }
  if (format == 'x' || format == 'X' || format == 'p') {
    if (!*((int*)number) && format == 'p') {
      is_nil = 1;
      for (int i = 0; i < 5; i++) {
        mas_size++;
        switch (i) {
          case 0:
            *int_to_char = ')';
            break;
          case 1:
            *int_to_char = 'l';
            break;
          case 2:
            *int_to_char = 'i';
            break;
          case 3:
            *int_to_char = 'n';
            break;
          case 4:
            *int_to_char = '(';
            break;
        }
        head_int_to_char = realloc(head_int_to_char, mas_size + 1);
        int_to_char = head_int_to_char + mas_size - 1;
      }
    } else if (LS == 'h') {
      while (*(unsigned short int*)number) {
        mas_size++;
        if (*(unsigned short int*)number % 16 < 10)
          temp_num = *(unsigned short int*)number % 16 + '0';
        else if (format == 'x' || format == 'p')
          temp_num = *(unsigned short int*)number % 16 + 'a' - 10;
        else if (format == 'X')
          temp_num = *(unsigned short int*)number % 16 + 'A' - 10;
        *int_to_char = temp_num;
        head_int_to_char = realloc(head_int_to_char, mas_size + 1);
        int_to_char = head_int_to_char + mas_size - 1;
        *(unsigned short int*)number /= 16;
      }
    } else if (LS == 'l') {
      while (*(unsigned long int*)number) {
        mas_size++;
        if (*(unsigned long int*)number % 16 < 10)
          temp_num = *(unsigned long int*)number % 16 + '0';
        else if (format == 'x' || format == 'p')
          temp_num = *(unsigned long int*)number % 16 + 'a' - 10;
        else if (format == 'X')
          temp_num = *(unsigned long int*)number % 16 + 'A' - 10;
        *int_to_char = temp_num;
        head_int_to_char = realloc(head_int_to_char, mas_size + 1);
        int_to_char = head_int_to_char + mas_size - 1;
        *(unsigned long int*)number /= 16;
      }
    } else if (LS == 'L') {
      while (*(unsigned long long int*)number) {
        mas_size++;
        if (*(unsigned long long int*)number % 16 < 10)
          temp_num = *(unsigned long long int*)number % 16 + '0';
        else if (format == 'x' || format == 'p')
          temp_num = *(unsigned long long int*)number % 16 + 'a' - 10;
        else if (format == 'X')
          temp_num = *(unsigned long long int*)number % 16 + 'A' - 10;
        *int_to_char = temp_num;
        head_int_to_char = realloc(head_int_to_char, mas_size + 1);
        int_to_char = head_int_to_char + mas_size - 1;
        *(unsigned long long int*)number /= 16;
      }
    } else {
      // output in mas
      while (*(unsigned int*)number) {
        mas_size++;
        if (*(unsigned int*)number % 16 < 10)
          temp_num = *(unsigned int*)number % 16 + '0';
        else if (format == 'x' || format == 'p')
          temp_num = *(unsigned int*)number % 16 + 'a' -
                     10;  // 'a' + (('a', ..., 'f') - 10)
        else if (format == 'X')
          temp_num = *(unsigned int*)number % 16 + 'A' - 10;
        *int_to_char = temp_num;
        head_int_to_char = realloc(head_int_to_char, mas_size + 1);
        int_to_char = head_int_to_char + mas_size - 1;
        *(unsigned int*)number /= 16;
      }
    }
  }
  if (format == 'd' || format == 'i') {
    if (LS == 'h') {
      if (*(short int*)number < 0) {
        *(short int*)number *= -1;
        sign++;
      }

      while (*(short int*)number) {
        mas_size++;
        temp_num = *(short int*)number % 10 + '0';
        *int_to_char = temp_num;
        head_int_to_char = realloc(head_int_to_char, mas_size + 1);
        int_to_char = head_int_to_char + mas_size - 1;
        *(short int*)number /= 10;
      }
    } else if (LS == 'l') {
      if (*(long int*)number < 0) {
        *(long int*)number *= -1;
        sign++;
      }

      while (*(long int*)number) {
        mas_size++;
        temp_num = *(long int*)number % 10 + '0';
        *int_to_char = temp_num;
        head_int_to_char = realloc(head_int_to_char, mas_size + 1);
        int_to_char = head_int_to_char + mas_size - 1;
        *(long int*)number /= 10;
      }
    } else if (LS == 'L') {
      if (*(long long int*)number < 0) {
        *(long long int*)number *= -1;
        sign++;
      }

      while (*(long long int*)number) {
        mas_size++;
        temp_num = *(long long int*)number % 10 + '0';
        *int_to_char = temp_num;
        head_int_to_char = realloc(head_int_to_char, mas_size + 1);
        int_to_char = head_int_to_char + mas_size - 1;
        *(long long int*)number /= 10;
      }
    } else {
      // sign
      if (*(int*)number < 0) {
        *(int*)number *= -1;
        sign++;
      }

      // output in mas
      while (*(int*)number) {
        mas_size++;
        temp_num = *(int*)number % 10 + '0';
        *int_to_char = temp_num;
        head_int_to_char = realloc(head_int_to_char, mas_size + 1);
        int_to_char = head_int_to_char + mas_size - 1;
        *(int*)number /= 10;
      }
    }
  }

  // precission
  if (prec > mas_size - 1 && pf) {
    prec++;
    while (prec != mas_size) {
      mas_size++;
      *int_to_char = '0';
      head_int_to_char = realloc(head_int_to_char, mas_size + 1);
      int_to_char = head_int_to_char + mas_size - 1;
    }
  }

  // sharp #
  if (flag_sharp && !zero) {
    int_to_char--;
    if (format == 'o' && *int_to_char != '0') {
      int_to_char++;
      mas_size++;
      *int_to_char = '0';
      head_int_to_char = realloc(head_int_to_char, mas_size + 1);
      int_to_char = head_int_to_char + mas_size - 1;
    } else
      int_to_char++;

    if (format == 'x' || format == 'X' || (format == 'p' && !is_nil)) {
      mas_size++;
      if (format == 'x' || format == 'p')
        *int_to_char = 'x';
      else
        *int_to_char = 'X';
      head_int_to_char = realloc(head_int_to_char, mas_size + 1);
      int_to_char = head_int_to_char + mas_size - 1;
      mas_size++;
      *int_to_char = '0';
      head_int_to_char = realloc(head_int_to_char, mas_size + 1);
      int_to_char = head_int_to_char + mas_size - 1;
    }
  }

  // output sign in mas
  if ((sign || flag_plus) && format != 'o' && format != 'u' && format != 'x' &&
      format != 'X' && !is_nil) {
    mas_size++;
    if (sign)
      *int_to_char = '-';
    else
      *int_to_char = '+';
    head_int_to_char = realloc(head_int_to_char, mas_size + 1);
    int_to_char = head_int_to_char + mas_size - 1;
  }

  // endline and output
  *int_to_char = '\0';
  return head_int_to_char;
}

void* float_e_arg(void* number, const char LS, const bool flag_plus,
                  size_t prec, const bool flag_sharp, const char format) {
  char* head_float_to_char = malloc(sizeof(char));
  char* float_to_char = head_float_to_char;
  int index_e = 0;
  float f_mantis;
  double lf_mantis;
  long double llf_mantis;
  char* head_mantis_str = malloc(sizeof(char) * (prec + 1));
  char* mantis_str = head_mantis_str;
  char* end_mantis_str;
  size_t null_num = 0;
  size_t mas_size = 1;
  bool sign_e = 0;
  bool sign_num = 0;
  bool zero = 0;

  if (LS == 'l') {
    if (!*(double*)number) zero = 1;

    if (*(double*)number < 0) {
      *(double*)number *= -1;
      sign_num = 1;
    }

    if (isinf(*(double*)number)) {
      free(head_float_to_char);
      free(head_mantis_str);
      head_float_to_char = infinity(flag_plus, sign_num, format);
      return head_float_to_char;
    }

    if (floor(*(double*)number) == 0 && !zero) {
      sign_e = 1;
      while (floor(*(double*)number) == 0) {
        *(double*)number *= 10;
        index_e++;
      }
    } else if (!zero) {
      while (floor(*(double*)number) != 0) {
        *(double*)number /= 10;
        index_e++;
      }
      *(double*)number *= 10;
      index_e--;
    }

    lf_mantis = *(double*)number - floor(*(double*)number);
    int num = 0;
    for (size_t i = 0; i < prec; i++) {
      lf_mantis *= 10;
      if (i + 1 == prec) lf_mantis = round(lf_mantis);
      num = (int)lf_mantis;
      *mantis_str = num + '0';
      lf_mantis -= num;
      mantis_str++;
    }
    *mantis_str = '\0';
  } else if (LS == 'L') {
    if (!*(long double*)number) zero = 1;

    if (*(long double*)number < 0) {
      *(long double*)number *= -1;
      sign_num = 1;
    }

    if (isinf(*(long double*)number)) {
      free(head_float_to_char);
      free(head_mantis_str);
      head_float_to_char = infinity(flag_plus, sign_num, format);
      return head_float_to_char;
    }

    if (floor(*(long double*)number) == 0 && !zero) {
      sign_e = 1;
      while (floor(*(long double*)number) == 0) {
        *(long double*)number *= 10;
        index_e++;
      }
    } else if (!zero) {
      while (floor(*(long double*)number) != 0) {
        *(long double*)number /= 10;
        index_e++;
      }
      *(long double*)number *= 10;
      index_e--;
    }

    llf_mantis = *(long double*)number - floor(*(long double*)number);
    int num = 0;
    for (size_t i = 0; i < prec; i++) {
      llf_mantis *= 10;
      if (i + 1 == prec) llf_mantis = round(llf_mantis);
      num = (int)llf_mantis;
      *mantis_str = num + '0';
      llf_mantis -= num;
      mantis_str++;
    }
    *mantis_str = '\0';
  } else {
    // if zero
    if (!*(float*)number) zero = 1;

    // sign
    if (*(float*)number < 0) {
      *(float*)number *= -1;
      sign_num = 1;
    }

    // if infinity
    if (isinf(*(float*)number)) {
      free(head_float_to_char);
      free(head_mantis_str);
      head_float_to_char = infinity(flag_plus, sign_num, format);
      return head_float_to_char;
    }

    // converting number to desired form
    if (floor(*(float*)number) == 0 && !zero) {
      sign_e = 1;
      while (floor(*(float*)number) == 0) {
        *(float*)number *= 10;
        index_e++;
      }
    } else if (!zero) {
      while (floor(*(float*)number) != 0) {
        *(float*)number /= 10;
        index_e++;
      }
      *(float*)number *= 10;
      index_e--;
    }

    // read mantissa
    f_mantis = *(float*)number - floor(*(float*)number);
    int num = 0;
    for (size_t i = 0; i < prec; i++) {
      f_mantis *= 10;
      if (i + 1 == prec) f_mantis = round(f_mantis);
      num = (int)f_mantis;
      *mantis_str = num + '0';
      f_mantis -= num;
      mantis_str++;
    }
    *mantis_str = '\0';
  }

  // Overflow protection
  end_mantis_str = mantis_str;
  for (size_t i = prec; i > 1; i--) {
    mantis_str--;
    if (*mantis_str > 9 + '0') {
      *mantis_str = '0';
      mantis_str--;
      *mantis_str = *mantis_str + 1;
      mantis_str++;
    }
  }
  if (*mantis_str) mantis_str--;
  if (*mantis_str && (*mantis_str > 9 + '0')) {
    *mantis_str = '0';
  }
  mantis_str = end_mantis_str;

  // Degree output
  for (int i = 0; i < 2 || index_e; i++) {
    mas_size++;
    *float_to_char = index_e % 10 + '0';
    head_float_to_char = realloc(head_float_to_char, mas_size + 1);
    float_to_char = head_float_to_char + mas_size - 1;
    index_e /= 10;
  }

  // Sign output
  if (sign_e) {
    mas_size++;
    *float_to_char = '-';
    head_float_to_char = realloc(head_float_to_char, mas_size + 1);
    float_to_char = head_float_to_char + mas_size - 1;
  } else {
    mas_size++;
    *float_to_char = '+';
    head_float_to_char = realloc(head_float_to_char, mas_size + 1);
    float_to_char = head_float_to_char + mas_size - 1;
  }

  // Output e
  mas_size++;
  if (format == 'e' || format == 'g')
    *float_to_char = 'e';
  else
    *float_to_char = 'E';
  head_float_to_char = realloc(head_float_to_char, mas_size + 1);
  float_to_char = head_float_to_char + mas_size - 1;

  // output mantissa
  if ((format == 'g' || format == 'G') && !flag_sharp &&
      s21_strlen(head_mantis_str)) {
    mantis_str--;
    for (int i = s21_strlen(head_mantis_str); i > 1 && *mantis_str == '0';
         i--) {
      mantis_str--;
      prec--;
    }
    if (*mantis_str == '0') {
      free(head_mantis_str);
      mantis_str = NULL;
    } else
      mantis_str++;
  }

  while (prec && mantis_str != NULL) {
    prec--;
    mantis_str--;
    mas_size++;
    *float_to_char = *mantis_str;
    head_float_to_char = realloc(head_float_to_char, mas_size + 1);
    float_to_char = head_float_to_char + mas_size - 1;
  }
  if (mantis_str != NULL) free(head_mantis_str);

  // output of zeros
  while (null_num) {
    mas_size++;
    *float_to_char = '0';
    head_float_to_char = realloc(head_float_to_char, mas_size + 1);
    float_to_char = head_float_to_char + mas_size - 1;
    null_num--;
  }

  // output point
  float_to_char--;
  if (*float_to_char != 'e' && *float_to_char != 'E' && *float_to_char != 'g' &&
      *float_to_char != 'G') {
    float_to_char++;
    mas_size++;
    *float_to_char = '.';
    head_float_to_char = realloc(head_float_to_char, mas_size + 1);
    float_to_char = head_float_to_char + mas_size - 1;
  } else
    float_to_char++;

  // output int number
  mas_size++;
  if (LS == 'l')
    *float_to_char = floor(*(double*)number) + '0';
  else if (LS == 'L')
    *float_to_char = floor(*(long double*)number) + '0';
  else
    *float_to_char = floor(*(float*)number) + '0';
  head_float_to_char = realloc(head_float_to_char, mas_size + 1);
  float_to_char = head_float_to_char + mas_size - 1;

  if (sign_num || flag_plus) {
    mas_size++;
    if (sign_num)
      *float_to_char = '-';
    else
      *float_to_char = '+';
    head_float_to_char = realloc(head_float_to_char, mas_size + 1);
    float_to_char = head_float_to_char + mas_size - 1;
  }

  // endline and output
  *float_to_char = '\0';
  return head_float_to_char;
}

void* float_f_arg(void* number, const char LS, const bool flag_plus,
                  size_t prec, const bool flag_sharp, const char format) {
  char* head_float_to_char = malloc(sizeof(char));
  char* float_to_char = head_float_to_char;
  double temp_num;
  float f_mantis;
  double lf_mantis;
  long double llf_mantis;
  char* head_mantis_str = malloc(sizeof(char) * (prec + 1));
  char* end_mantis_str;
  char* mantis_str = head_mantis_str;
  size_t null_num = 0;
  size_t mas_size = 1;
  size_t prec_copy = prec;
  bool sign = 0;
  bool oversize = 0;
  bool round_last_num = 1;

  // mantissa processing
  if (LS == 'l') {
    if (*(double*)number < 0) {
      *(double*)number *= -1;
      sign = 1;
    }

    if (isinf(*(double*)number)) {
      free(head_float_to_char);
      free(head_mantis_str);
      head_float_to_char = infinity(flag_plus, sign, 'e');
      return head_float_to_char;
    }

    lf_mantis = *(double*)number - floor(*(float*)number);
    int num = 0;
    for (size_t i = 0; i < prec; i++) {
      lf_mantis *= 10;
      if (i + 1 == prec) lf_mantis = round(lf_mantis);
      num = (int)lf_mantis;
      *mantis_str = num + '0';
      lf_mantis -= num;
      mantis_str++;
    }
  } else if (LS == 'L') {
    if (*(long double*)number < 0) {
      *(long double*)number *= -1;
      sign = 1;
    }

    if (isinf(*(long double*)number)) {
      free(head_float_to_char);
      free(head_mantis_str);
      head_float_to_char = infinity(flag_plus, sign, 'e');
      return head_float_to_char;
    }

    llf_mantis = *(long double*)number - floor(*(long double*)number);
    int num = 0;
    for (size_t i = 0; i < prec; i++) {
      llf_mantis *= 10;
      if (i + 1 == prec) llf_mantis = round(llf_mantis);
      num = (int)llf_mantis;
      *mantis_str = num + '0';
      llf_mantis -= num;
      mantis_str++;
    }
  } else {
    // sign
    if (*(float*)number < 0) {
      *(float*)number *= -1;
      sign = 1;
    }

    // if infinity
    if (isinf(*(float*)number)) {
      free(head_float_to_char);
      free(head_mantis_str);
      head_float_to_char = infinity(flag_plus, sign, 'e');
      return head_float_to_char;
    }

    // read mantissa
    f_mantis = *(float*)number - floor(*(float*)number);
    int num = 0;
    for (size_t i = 0; i < prec; i++) {
      f_mantis *= 10;
      if (i + 1 == prec) f_mantis = round(f_mantis);
      num = (int)f_mantis;
      *mantis_str = num + '0';
      f_mantis -= num;
      mantis_str++;
    }
  }
  *mantis_str = '\0';

  // Overflow protection
  end_mantis_str = mantis_str;
  for (size_t i = prec; i > 1; i--) {
    mantis_str--;
    if (*mantis_str > 9 + '0') {
      *mantis_str = '0';
      mantis_str--;
      *mantis_str = *mantis_str + 1;
      mantis_str++;
    }
  }
  if (*mantis_str) mantis_str--;
  if (*mantis_str && (*mantis_str > 9 + '0')) {
    *mantis_str = '0';
    oversize = 1;
  }
  mantis_str = end_mantis_str;

  // mantissa output
  if (format == 'g' && !flag_sharp && s21_strlen(head_mantis_str) != 0) {
    mantis_str--;
    for (int i = s21_strlen(head_mantis_str); i > 1 && *mantis_str == '0';
         i--) {
      if (*mantis_str) mantis_str--;
      prec--;
    }
    if (*mantis_str == '0') {
      free(head_mantis_str);
      mantis_str = NULL;
    } else
      mantis_str++;
  }

  while (prec && mantis_str != NULL) {
    prec--;
    mantis_str--;
    mas_size++;
    *float_to_char = *mantis_str;
    head_float_to_char = realloc(head_float_to_char, mas_size + 1);
    float_to_char = head_float_to_char + mas_size - 1;
  }

  // output of zeros
  while (null_num) {
    mas_size++;
    *float_to_char = '0';
    head_float_to_char = realloc(head_float_to_char, mas_size + 1);
    float_to_char = head_float_to_char + mas_size - 1;
    null_num--;
  }

  // output point
  if (format == 'g' && prec_copy && mantis_str == NULL) prec_copy = 0;

  if (prec_copy || flag_sharp) {
    mas_size++;
    *float_to_char = '.';
    head_float_to_char = realloc(head_float_to_char, mas_size + 1);
    float_to_char = head_float_to_char + mas_size - 1;
  }

  // output int number
  int Num = 0;
  if (mantis_str != NULL) Num = *mantis_str;

  if (LS == 'l') {
    if (oversize) *(double*)number = *(double*)number + 1;

    while (floor(*(double*)number)) {
      *(double*)number /= 10;
      temp_num = (*(double*)number - floor(*(double*)number)) * 10;
      if (round_last_num &&
          floor((temp_num - floor(temp_num)) * 10) != (Num - '0'))
        Num = round(temp_num);
      else
        Num = temp_num;
      mas_size++;
      *float_to_char = Num + '0';
      head_float_to_char = realloc(head_float_to_char, mas_size + 1);
      float_to_char = head_float_to_char + mas_size - 1;
      round_last_num = 0;
    }
    if (round_last_num) {
      mas_size++;
      *float_to_char = '0';
      head_float_to_char = realloc(head_float_to_char, mas_size + 1);
      float_to_char = head_float_to_char + mas_size - 1;
      round_last_num = 0;
    }
  } else if (LS == 'L') {
    if (oversize) *(long double*)number = *(long double*)number + 1;

    while (floor(*(long double*)number)) {
      *(long double*)number /= 10;
      temp_num = (*(long double*)number - floor(*(long double*)number)) * 10;
      if (round_last_num &&
          floor((temp_num - floor(temp_num)) * 10) != (Num - '0'))
        Num = round(temp_num);
      else
        Num = temp_num;
      mas_size++;
      *float_to_char = Num + '0';
      head_float_to_char = realloc(head_float_to_char, mas_size + 1);
      float_to_char = head_float_to_char + mas_size - 1;
      round_last_num = 0;
    }
    if (round_last_num) {
      mas_size++;
      *float_to_char = '0';
      head_float_to_char = realloc(head_float_to_char, mas_size + 1);
      float_to_char = head_float_to_char + mas_size - 1;
      round_last_num = 0;
    }
  } else {
    if (oversize) *(float*)number = *(float*)number + 1;

    while (floor(*(float*)number)) {
      *(float*)number /= 10;
      temp_num = (*(float*)number - floor(*(float*)number)) * 10;
      if (round_last_num &&
          floor((temp_num - floor(temp_num)) * 10) != (Num - '0'))
        Num = round(temp_num);
      else
        Num = temp_num;
      mas_size++;
      *float_to_char = Num + '0';
      head_float_to_char = realloc(head_float_to_char, mas_size + 1);
      float_to_char = head_float_to_char + mas_size - 1;
      round_last_num = 0;
    }
    if (round_last_num) {
      mas_size++;
      *float_to_char = '0';
      head_float_to_char = realloc(head_float_to_char, mas_size + 1);
      float_to_char = head_float_to_char + mas_size - 1;
      round_last_num = 0;
    }
  }
  if (mantis_str != NULL) free(head_mantis_str);

  if (sign || flag_plus) {
    mas_size++;
    if (sign)
      *float_to_char = '-';
    else
      *float_to_char = '+';
    head_float_to_char = realloc(head_float_to_char, mas_size + 1);
    float_to_char = head_float_to_char + mas_size - 1;
  }

  // endline and output
  *float_to_char = '\0';
  return head_float_to_char;
}

void* float_g_arg(void* number, const char LS, const bool flag_plus,
                  size_t prec, const bool pf, const bool flag_sharp,
                  const char format) {
  char* float_to_char;
  size_t index_e = 0;
  bool sign = 0;
  bool zero = 0;

  switch (LS) {
    case 'l':
      if (!*(double*)number) zero = 1;

      if (isinf(*(float*)number)) {
        float_to_char = infinity(flag_plus, sign, 'e');
        return float_to_char;
      }

      if (*(double*)number < 0) {
        sign = 1;
        *(double*)number *= -1;
      }

      double l_copy_number = *(double*)number;
      while (1) {
        if (floor(*(double*)number) != 0) {
          if (floor(l_copy_number) == 0) break;
          l_copy_number /= 10;
        } else {
          if (floor(l_copy_number) != 0) break;
          l_copy_number *= 10;
        }
        index_e++;
      }

      if (sign) *(double*)number *= -1;
      break;
    case 'L':
      if (!*(long double*)number) zero = 1;

      if (isinf(*(float*)number)) {
        float_to_char = infinity(flag_plus, sign, 'e');
        return float_to_char;
      }

      if (*(long double*)number < 0) {
        sign = 1;
        *(long double*)number *= -1;
      }

      long double ll_copy_number = *(long double*)number;
      while (1) {
        if (floor(*(long double*)number) != 0) {
          if (floor(ll_copy_number) == 0) break;
          ll_copy_number /= 10;
        } else {
          if (floor(ll_copy_number) != 0) break;
          ll_copy_number *= 10;
        }
        index_e++;
      }

      if (sign) *(long double*)number *= -1;
      break;
    default:
      // if zero
      if (!*(float*)number) zero = 1;

      // sign
      if (*(float*)number < 0) {
        sign = 1;
        *(float*)number *= -1;
      }

      // if infinity
      if (isinf(*(float*)number)) {
        float_to_char = infinity(flag_plus, sign, 'e');
        return float_to_char;
      }

      // count digit
      float copy_number = *(float*)number;
      while (!zero) {
        if (floor(*(float*)number) != 0) {
          if (floor(copy_number) == 0) break;
          copy_number /= 10;
        } else {
          if (floor(copy_number) != 0) break;
          copy_number *= 10;
        }
        index_e++;
      }

      // sign
      if (sign) *(float*)number *= -1;
      break;
  }

  // alg mod
  if (prec < index_e) {
    if (!pf) prec = 5;
    if (prec) prec--;
    float_to_char =
        float_e_arg(number, LS, flag_plus, prec, flag_sharp, format);
  } else {
    prec = prec - index_e;
    if (floor(*(float*)number) == 0) prec++;
    float_to_char = float_f_arg(number, LS, flag_plus, prec, flag_sharp, 'g');
  }

  return float_to_char;
}

void* infinity(const bool flag_plus, const bool sign, const char format) {
  char* head_float_to_char = malloc(sizeof(char));
  char* float_to_char = head_float_to_char;
  size_t mas_size = 1;

  for (int i = 0; i < 3; i++) {
    mas_size++;
    switch (i) {
      case 0:
        if (format == 'e') *float_to_char = 'f';
        if (format == 'E') *float_to_char = 'F';
        break;
      case 1:
        if (format == 'e') *float_to_char = 'n';
        if (format == 'E') *float_to_char = 'N';
        break;
      case 2:
        if (format == 'e') *float_to_char = 'i';
        if (format == 'E') *float_to_char = 'I';
        break;
    }
    head_float_to_char = realloc(head_float_to_char, mas_size + 1);
    float_to_char = head_float_to_char + mas_size - 1;
  }

  // sign
  if (sign || flag_plus) {
    mas_size++;
    if (sign)
      *float_to_char = '-';
    else
      *float_to_char = '+';
    head_float_to_char = realloc(head_float_to_char, mas_size + 1);
    float_to_char = head_float_to_char + mas_size - 1;
  }

  *float_to_char = '\0';
  return head_float_to_char;
}