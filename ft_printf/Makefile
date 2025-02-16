NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror 

SRC = libftprintf.c handle_str.c handle_char.c handle_dec.c handle_unsigned.c handle_hex.c handle_pointer.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $^

clean:
	rm -f $(OBJ) $(OBJB)

fclean:
	rm -f $(NAME) $(OBJ) $(OBJB)

re: fclean all

.PHONY: all clean fclean re
