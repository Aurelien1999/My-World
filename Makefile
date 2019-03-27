##
## EPITECH PROJECT, 2018
## make
## File description:
## ..
##

CC = gcc

FILES = src/my_world.c \
		src/click_up.c \
		src/project_iso_point.c \
		src/create_map.c \
		src/perlin_noise.c \
		src/shader.c \
		src/create_random.c \
		src/wave.c \
		src/create_water.c \
		src/background.c \
		src/create_line.c \
		src/draw_map.c \
		src/compare.c \
		src/brush.c \
		src/pixel.c \
		src/getisoposmouse.c \
		src/create_board.c \
		src/create_loading.c \
		src/reactFont.c \
		src/copy_tab.c \
		src/my_getnbr.c \
		src/createfile.c \
		src/my_revstr.c \

SRC = $(FILES)

OBJ = $(SRC:.c=.o)

NAME = my_world

RM = rm -rf

CFLAGS = -lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio -lm -I./include

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean:		clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re test

