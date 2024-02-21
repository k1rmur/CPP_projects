CC = g++
CFLAGS = -std=c++17 -Wall -Werror -Wextra -g
LFLAGS = -lgtest 
SOURCE = calc_model/*.cc
OBJ = *.o
TESTS_SOURCE = tests/calc_tests.cc
TESTS_EXECUTABLE = test 
TARGET = view
GCOV_FLAGS = --no-external

ifeq ($(shell uname), Linux)
  LFLAGS += -lpthread 
endif

ifeq ($(shell uname), Darwin)
	TARGET = view.app
	GCOV_FLAGS += --ignore-errors mismatch 
endif

all: clean install

install: 
	@echo "Installation of SmartCalc_v2.0:"
	@mkdir -p ../build
	@cd calc_view && qmake && make && make clean && rm -rf Makefile && mv $(TARGET) ../../build/$(TARGET)
	@echo "Installation completed! You can find the app in the ../build/ folder!"

uninstall:
	@rm -rf ../build
	@echo "Uninstall completed!"

dvi:
	@open my_readme.md
	
dist: 
	@mkdir -p ../dist
	@cp -R ../build/$(TARGET) ../dist
	@cp my_readme.md ../dist 
	@cd ../dist && tar cvzf $(TARGET).tgz *
	@cd ../dist && rm -rf $(TARGET) my_readme.md
	@echo "Archive creation completed successfully!"

model.a:
	@$(CC) $(CFLAGS) -c $(SOURCE)
	@ar rcs model.a $(OBJ)
	@ranlib model.a
	@rm -rf *.o

test: model.a
	@$(CC) $(CFLAGS) -c $(TESTS_SOURCE)
	@$(CC) calc_tests.o $(CFLAGS) $(LFLAGS) model.a -o test
	./test

add_coverage:
	$(eval CFLAGS += --coverage)

gcov_report: clean add_coverage test	
	@./test
	@lcov -t "test" -o test.info -c -d . -no-external
	@genhtml -o report test.info
	@open report/index.html

clean:
	@rm -rf $(TESTS_EXECUTABLE) *.gcno *.gcda report test.info *.o model.a ../dist

.PHONY: all clean test gcov_report