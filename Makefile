# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/16 11:05:03 by lhojoon           #+#    #+#              #
#    Updated: 2024/03/25 17:51:13 by lhojoon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
CC = cc
CFLAGS = -Wall -Wextra -Werror
MINILIBX_FLAGS = -I/usr/include -Imlx_linux

DIR = srcs
SRCS_RAW = main.c \
			get_next_line.c \
			get_next_line_utils.c \
			free_mlx.c \
			init_mlx.c \
			read_map.c \
			mlx_pipeline.c \
			verify_elements_map.c \
			verify_wall_map.c \
			utils_ft_lstget_idx.c \
			verify_path_map.c \
			x11_events.c \
			key_event_manager.c \
			image_manager_ext1.c \
			image_manager_ext2.c \
			utils_get_object_pos_list_map.c \
			heap.c \
			utils_ft_dellast.c \
			init_path_node.c \
			init_pos.c \
			ft_lstchr.c \
			ft_lstadd_sort.c \
			ft_lstsort.c \
			verify_path_map_ext1.c \
			verify_path_map_ext2.c \
			mlx_utils.c \
			draw_manager.c \
			map_move_manager.c
SRCS = $(addprefix $(DIR)/,$(SRCS_RAW))
OBJS = $(SRCS:c=o)
INCLUDES = -I./includes -I./libft -I./ft_printf/includes

LIBFT = libft.a
MINILIBX_A = mlx_linux/libmlx_Linux.a

all: $(NAME)
$(NAME): libcompile $(OBJS)
	$(CC) $(OBJS) $(DEBUG) -Llibft -l:libft.a -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
clean:
	rm $(OBJS) $(OBJB) -f
fclean: clean libclean
	rm $(NAME) -f
re: fclean all

libcompile: libftcompile minilibxcompile
libclean: libftclean minilibxclean

libftcompile:
	$(MAKE) bonus -C libft
libftclean:
	$(MAKE) fclean -C libft
minilibxcompile:
	$(MAKE) -C mlx_linux
minilibxclean:
	$(MAKE) clean -C mlx_linux

%.o: %.c
	$(CC) -c $< -o $@ $(MINILIBX_FLAGS) $(CFLAGS) $(INCLUDES) $(DEBUG)