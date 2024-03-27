/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:19:50 by lhojoon           #+#    #+#             */
/*   Updated: 2024/03/27 19:36:32 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "libft.h"
# include <stdlib.h>
# include <stdbool.h>
# include <X11/Xlib.h>
# include <X11/extensions/XShm.h>

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_gamedat
{
	t_pos	*userpos;
	t_pos	size;
	size_t	item_count;
	size_t	move_count;
}	t_gamedat;

typedef struct s_mlximage
{
	XImage			*image;
	Pixmap			pix;
	GC				gc;
	int				size_line;
	int				bpp;
	int				width;
	int				height;
	int				type;
	int				format;
	char			*data;
	XShmSegmentInfo	shm;
}	t_mlximage;

typedef struct s_map_data
{
	char		**map;
	char		**pref;
}	t_map_data;

/**
 * @brief master varaible for execution
 * 
 * @param mlx		mlx pointer - must be free'd
 * @param mlx_win	mlx window pointer - must be free'd
 * @param imgs 		list of images - must be free'd
 * @param canvas	canvas image - must be free'd
 * @param map_filename	map file name
 */
typedef struct s_mlxvars
{
	void		*mlx;
	void		*mlx_win;
	t_list		*imgs;
	t_mlximage	*canvas;
	char		*map_filename;
	t_map_data	*map_data;
}	t_mlxvars;

typedef enum e_direction
{
	NORTH = 0,
	SOUTH = 1,
	WEST = 2,
	EAST = 3
}	t_direction;

t_pos		get_init_pos(void);
t_pos		get_init_pos_value(int x, int y);
t_pos		*get_init_pos_ptr(void);
t_pos		*get_init_pos_ptr_value(int x, int y);
t_gamedat	get_init_gamedat(void);
t_mlxvars	get_init_mlxvars(void);

#endif