HEADERS = header/ft_lib.h
OBJECTS = src/main.o src/parse_file.o src/split.o src/map_check.o src/stdin_read.o
NAME = BSQ

$(NAME): program cleano

%.o: %.c $(HEADERS)
	gcc -Wall -Wextra -Werror -c $< -o $@

program: $(OBJECTS)
	gcc $(OBJECTS) -o $@

clean:
	-rm -f $(OBJECTS)
	-rm -f program

cleano:
	-rm -f $(OBJECTS)