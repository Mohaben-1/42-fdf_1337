NAME = fdf

CC = cc
CFLAGS = -Wall -Werror -Wextra

SRC = fdf.c get_next_line_utils.c get_next_line.c utils.c ft_split.c ft_atoi.c bresenham.c draw.c get_map.c handle_keyboard_bonus.c initialize.c color_bonus.c rotation_bonus.c

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -Lminilibx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c fdf.h
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

all: $(NAME)

bonus: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -Lminilibx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@touch bonus

clean:
	rm -f $(OBJ) bonus

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean