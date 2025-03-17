TARGET = exemple
OBJ = exemple.o
CFLAGS = -Wall -Wextra -Werror
SRC = exemple.c


 all : $(TARGET)

 $(TARGET) : $(OBJ)
	gcc $(CFLAGS) -o $(TARGET) $(OBJ)

 $(OBJ) : $(SRC)
	gcc $(CFLAGS) -c $(SRC)

 clean:
	rm -f *.o

 fclean: clean
	rm -f $(TARGET)

 re: fclean all