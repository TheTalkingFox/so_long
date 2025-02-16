NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = so_long.c create_map.c check_map.c check_objects.c bfs_algo.c add_textures.c events.c

FT_PRINTF_FILES = ft_printf/libftprintf.c ft_printf/handle_str.c ft_printf/handle_char.c ft_printf/handle_dec.c ft_printf/handle_unsigned.c ft_printf/handle_hex.c ft_printf/handle_pointer.c

GNL_FILES = gnl/get_next_line.c gnl/get_next_line_utils.c

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_MAKEFILE = $(LIBFT_DIR)/Makefile

OBJ = $(SRC:.c=.o)

FT_PRINTF_OFILES = $(FT_PRINTF_FILES:.c=.o)
GNL_OFILES = $(GNL_FILES:.c=.o)

MLX = -lmlx -lXext -lX11
FT_PRINTF = -I./ft_printf
GNL = -I./gnl

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ 

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(FT_PRINTF_OFILES) $(GNL_OFILES) $(LIBFT)
	$(CC) $(OBJ) $(FT_PRINTF_OFILES) $(GNL_OFILES) $(LIBFT) $(MLX) -o $(NAME)

clean:
	rm -f $(OBJ) $(FT_PRINTF_OFILES) $(GNL_OFILES)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
