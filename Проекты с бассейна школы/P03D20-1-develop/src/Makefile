# Makefile для сборки проекта по построению графиков

# Компилятор
CC = gcc

# Флаги компиляции
CFLAGS = -Wall -Wextra -Werror -std=c99

# Файлы исходного кода
SRCS = evaluation.c expression.c rendering.c graph.c

# Заголовочные файлы
HDRS = evaluation.h expression.h rendering.h

# Имя исполняемого файла
OUTPUT = build/graph

all: $(OUTPUT)

$(OUTPUT): $(SRCS) $(HDRS)
	$(CC) $(CFLAGS) -o $(OUTPUT) $(SRCS)

clean:
	rm -f $(OUTPUT)

.PHONY: all clean
