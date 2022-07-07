CC = gcc
OBJECTS = s21_cat.o
SOURSES = s21_cat.c
CFLAGS = -Werror -Wextra -Wall -std=c11
# SAN = -fsanitize=address


all: clean s21_cat test

s21_cat:
	$(CC) $(CFLAGS) $(SAN) -c $(SOURSES) -o $(OBJECTS)
	$(CC) $(OBJECTS) $(SAN) -o s21_cat
test: s21_cat
	./tests/cat_test.sh
check: s21_cat
	@cppcheck *.h *.c
	@cp ../../materials/linters/CPPLINT.cfg ./
	@python3 ../../materials/linters/cpplint.py --extension=c *.c *.h
	@valgrind --leak-check=full ./s21_cat tests/123.txt
	@rm CPPLINT.cfg
clean:
	rm -rf ./*.o ./a.out ./CPPLINT* s21_cat
rebuild:
	$(MAKE) clean
	$(MAKE) all