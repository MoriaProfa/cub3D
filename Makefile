NAME = cub3D

CC = cc
CFLAGS = -Wall -Wextra -Werror -MMD -MP -g
RM = rm -f

CFILES = cub3D.c \
	parsing/checks.c \
	parsing/colors.c \
	parsing/map.c \
	parsing/parsing.c \
	parsing/paths.c \
	parsing/player.c \
	utils/array_helpers.c \
	utils/exit.c
OFILES = $(CFILES:.c=.o)
DFILES = $(CFILES:.c=.d)

MLX = -lmlx -lX11 -lXext

all: $(NAME)
-include $(DFILES)

$(NAME): $(OFILES)
		@cd libft && $(MAKE)
		$(CC) $(CFLAGS) $(OFILES) libft/libft.a $(MLX) -o $(NAME)

clean:
		@cd libft && $(MAKE) clean
		@$(RM) $(OFILES) $(DFILES)

fclean: clean
		@cd libft && $(MAKE) fclean
		@$(RM) $(NAME)

re:		fclean all

.PHONY: all clean fclean re
