CC = g++
CFLAGS = -std=c++17 -Wall -Werror -Wextra
SRC = ./model/*.cc ./modules/*.cc
TEST_SRC = ./tests/maze_tests.cc
OBJ = *.o
LFLAGS = -lgtest
TARGET = maze
GCOV_FLAGS = --no-external

ifeq ($(shell uname), Linux) 
	LFLAGS += -lpthread
endif

ifeq ($(shell uname), Darwin)
	TARGET = maze.app
	GCOV_FLAGS += --ignore-errors mismatch 
endif

all: install

install:
	@echo "Installation of Maze:"
	@mkdir -p ../build
	@cd view && qmake && make && make clean && rm -rf Makefile && mv $(TARGET) ../../build/$(TARGET)
	@echo "Installation completed! You can find the app in the ../build/ folder!"
	
uninstall:
	@rm -rf ../build
	@echo "Uninstall completed!"
	
dvi:
	open doc.md
	
dist: 
	@mkdir -p ../dist
	@cp -R ../build/$(TARGET) ../dist
	@cp doc.md ../dist 
	@cp ../misc/images/start.png ../dist
	@cp ../misc/images/generated.png ../dist
	@cp ../misc/images/path.png ../dist
	@cd ../dist && tar cvzf $(TARGET).tgz *
	@cd ../dist && rm -rf $(TARGET) doc.md *.png
	@echo "Archive creation completed successfully!"

tests: maze.a
	@$(CC) $(CFLAGS) -c $(TEST_SRC)
	@$(CC) maze_tests.o $(CFLAGS) $(LFLAGS) -L. maze.a -o test
	./test

maze.a:
	$(CC) $(CFLAGS) -c $(SRC)
	ar rcs maze.a $(OBJ)
	ranlib maze.a
	rm -rf *.o

add_coverage:
	$(eval CFLAGS += --coverage)

gcov_report: clean add_coverage tests
	-./test
	lcov -t "test" -o test.info -c -d . $(GCOV_FLAGS)
	genhtml -o report test.info
	open report/index.html

check_format:
	clang-format -n -style=Google -verbose model/*.cc model/*.h 
	clang-format -n -style=Google -verbose controller/*.cc controller/*.h
	clang-format -n -style=Google -verbose view/*.cc view/*.h
	clang-format -n -style=Google -verbose modules/*.cc modules/*.h
	clang-format -n -style=Google -verbose tests/*.cc 

formatting:
	clang-format -i -style=Google -verbose model/*.cc model/*.h 
	clang-format -i -style=Google -verbose controller/*.cc controller/*.h
	clang-format -i -style=Google -verbose view/*.cc view/*.h
	clang-format -i -style=Google -verbose modules/*.cc modules/*.h
	clang-format -i -style=Google -verbose tests/*.cc

valgrind: clean tests
	valgrind --tool=memcheck --leak-check=full --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all -s ./test

clean:
	rm -rf *.o *.a *.gcno *.gcda test test.info report

PHONY: all tests clean valgrind
