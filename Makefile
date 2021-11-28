# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Jraye <jraye@student.21-school.ru>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/26 15:45:37 by Jraye             #+#    #+#              #
#    Updated: 2021/02/07 17:56:19 by Jraye            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRC = cub3d.c make_map.c write_bmp.c errors.c checks.c map_check.c \
	setters.c setters_2.c parse_utils.c key_hook.c key_hook_2.c \
	main_utils.c ft_print.c sprite_print.c \
	sprite_health_print.c print_lines.c \
	gnl/get_next_line.c gnl/get_next_line_utils.c

BNS = bonus/cub3d_bonus.c bonus/make_map_bonus.c bonus/write_bmp_bonus.c \
	bonus/errors_bonus.c bonus/checks_bonus.c bonus/map_check_bonus.c \
	bonus/setters_bonus.c bonus/setters_2_bonus.c \
	bonus/parse_utils_bonus.c bonus/key_hook_bonus.c bonus/key_hook_2_bonus.c \
	bonus/main_utils_bonus.c bonus/motion_event_bonus.c bonus/trap_set_bonus.c \
	bonus/ft_print_bonus.c bonus/sprite_print_bonus.c \
	bonus/sprite_health_print_bonus.c bonus/print_lines_bonus.c \
	gnl/get_next_line.c gnl/get_next_line_utils.c

LIBFT = ./libft

INCLUDE = -I./gnl -I./libft -I./minilibx_opengl_20191021 \
	-I./SDL2/sdl2/2.0.14_1/include/SDL2 -I./SDL2/sdl2_mixer/2.0.4/include/SDL2 \
	-I./bonus

HEADER = libft/libft.h bonus/cub3d_bonus.h ./cub3d.h

OBJ = $(SRC:.c=.o)

OBJBNS = $(BNS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=32 $(INCLUDE) -O2

LIBS = libft/libft.a minilibx_opengl_20191021/libmlx.a

all: $(LIBFT) $(NAME)

$(LIBFT): RULE
	@ $(MAKE) all -C ./libft
	@ $(MAKE) bonus -C ./libft

RULE:

$(OBJ): ./cub3d.h

$(OBJBNS): bonus/cub3d_bonus.h

$(NAME): $(OBJ)
	@ $(CC) $(CFLAGS) -o $(NAME) $(LIBS) $^ -framework OpenGL -framework Appkit \
	-L./SDL2/sdl2/2.0.14_1/lib -L./SDL2/sdl2_mixer/2.0.4/lib -lSDL2 -lSDL2_mixer

bonus: $(LIBFT) $(NAME) $(OBJBNS)

	@ $(CC) $(CFLAGS) -o $(NAME) $(LIBS) $(OBJBNS) -framework OpenGL -framework Appkit \
	-L./SDL2/sdl2/2.0.14_1/lib -L./SDL2/sdl2_mixer/2.0.4/lib -lSDL2 -lSDL2_mixer

clean:
	$(MAKE) clean -C ./libft
	rm -rf $(OBJ)
	rm -rf $(OBJBNS)

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus

