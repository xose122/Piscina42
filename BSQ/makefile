HEADERS = header/ft_lib.h
OBJECTS = src/main.o src/parse_file.o src/split.o
NAME = BSQ

$(NAME): program cleano rename

%.o: %.c $(HEADERS)
	gcc -Wall -Wextra -Werror -c $< -o $@

program: $(OBJECTS)
	gcc $(OBJECTS) -o $@

clean:
	-rm -f $(OBJECTS)
	-rm -f program

cleano:
	-rm -f $(OBJECTS)

rename:
	mv program $(NAME)