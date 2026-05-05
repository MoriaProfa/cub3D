NAME = cub3D

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

CFILES = cub3D.c \
	parsing/checks.c \
	parsing/colors.c \
	parsing/map.c \
	parsing/parsing.c \
	parsing/paths.c \
	parsing/player.c \
	utils/array_helpers.c \
	utils/cub3d_atoi.c \
	utils/exit.c \
	graphical/init.c \
	graphical/free.c \
	graphical/events.c \
	graphical/rendering.c \
	graphical/raycasting.c \
	graphical/move_rotate.c

SRCDIR = srcs
OBJDIR = objs
OFILES = $(patsubst %.c, $(OBJDIR)/%.o, $(CFILES))
DFILES = $(patsubst %.c, $(OBJDIR)/%.d, $(CFILES))

LDFLAGS = -lmlx -lX11 -lXext -lm

all: $(NAME)
-include $(DFILES)

bonus: $(NAME)

$(NAME): $(OFILES)
		@cd libft && $(MAKE)
		$(CC) $(CFLAGS) $(OFILES) libft/libft.a $(LDFLAGS) -o $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -MMD -MP -I includes -c $< -o $@

clean:
		@$(MAKE) -sC libft clean
		@$(RM) $(OFILES) $(DFILES) compile_commands.json
		@$(RM) -r $(OBJDIR)

fclean: clean
		@$(MAKE) -sC libft fclean
		@$(RM) $(NAME)

re:		fclean all

compile_commands:
		@bear -- $(MAKE) re

.PHONY: all clean fclean re bonus compile_commands
