CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=c89
OBJS = main.o opcode_functions.o stack_functions.o error_handling.o
TARGET = monty

all: $(TARGET)

$(TARGET): $(OBJS)
    $(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

%.o: %.c
    $(CC) $(CFLAGS) -c $< -o $@

clean:
    rm -f $(OBJS)

fclean: clean
    rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re
