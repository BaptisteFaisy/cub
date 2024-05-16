# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/16 11:05:03 by lhojoon           #+#    #+#              #
#    Updated: 2024/05/17 00:51:55 by lhojoon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
CC = cc
CFLAGS = -Wall -Wextra -Werror
MINILIBX_FLAGS = -I/usr/include -Imlx_linux
DEBUG = -g

DIR = srcs
SRCS_RAW =	main.c \
			free_mlx.c \
			init_mlx.c \
			read_map.c \
			mlx_pipeline.c \
			x11_events.c \
			key_event_manager.c \
			image_manager_ext1.c \
			image_manager_ext2.c \
			init_pos.c \
			mlx_utils.c \
			read_map_2.c \
			chechlignep1.c \
			checkermapmain.c \
			mapchecker.c \
			structrgb.c \
			checklignemain.c \
			init_t_player.c \
			draw_screen.c \
			print_one_vertical_line.c \
			stock_image.c \
			parse_user_pos.c \
			transform_direction.c \
			math_utils.c \
			wall_info_ext.c \
			wall_math.c \
			wall_math2.c \
			math_utils_2.c \
			mapchecker2.c
SRCS = $(addprefix $(DIR)/,$(SRCS_RAW))
OBJS = $(SRCS:c=o)
INCLUDES = -I./includes -I./libft -I./ft_printf/includes

LIBFT = libft/libft.a
MINILIBX = mlx_linux/libmlx_Linux.a

all: $(NAME)
$(NAME): ${LIBFT} ${MINILIBX} $(OBJS)
	$(CC) $(OBJS) $(DEBUG) -Llibft -l:libft.a -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
clean:
	rm $(OBJS) $(OBJB) -f
fclean: clean libclean
	rm $(NAME) -f
re: fclean all

r: clean all

${LIBFT}:
	$(MAKE) -C libft
${MINILIBX}:
	$(MAKE) -C mlx_linux

libclean: libftclean minilibxclean
libftclean:
	$(MAKE) fclean -C libft
minilibxclean:
	$(MAKE) clean -C mlx_linux

%.o: %.c
	$(CC) -c $< -o $@ $(MINILIBX_FLAGS) $(CFLAGS) $(INCLUDES) $(DEBUG)