CC= g++
CFLAGS= -Wall -Werror -Wextra
LFLAGS= -lgtest -lstdc++ -ftest-coverage 
SRC= Functions/*.cc 
OBJ= *.o

ifeq ($(shell uname), Linux)
  LFLAGS = -lgtest -lpthread -fprofile-arcs -ftest-coverage
endif

all: test

test: clean s21_matrix_oop.a
	$(CC) $(CFLAGS) -c Functions/test.cc
	$(CC) test.o $(CFLAGS) $(LFLAGS) -L. s21_matrix_oop.a -o test

s21_matrix_oop.a:
	$(CC) $(CFLAGS) -c $(SRC)
	ar rcs s21_matrix_oop.a $(OBJ)
	ranlib s21_matrix_oop.a
	rm -rf *.o

add_coverage:
	$(eval CFLAGS += --coverage)

gcov_report: clean add_coverage test
	-./test
	lcov -t "test" -o test.info -c -d . --no-external
	genhtml -o report test.info
	open report/index.html

clean: 
	rm -rf *.o *.a test *.gcno *.gcda test test.info report