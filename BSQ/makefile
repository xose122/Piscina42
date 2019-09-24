HEADERS = ft_lib.h
OBJECTS = main.o parse_file.o split.o

default: program cleano

%.o: %.c $(HEADERS)
	gcc -c $< -o $@

program: $(OBJECTS)
	gcc $(OBJECTS) -o $@

clean:
	-rm -f $(OBJECTS)
	-rm -f program

cleano:
	-rm -f $(OBJECTS)