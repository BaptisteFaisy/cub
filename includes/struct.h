/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaisy <bfaisy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:19:50 by lhojoon           #+#    #+#             */
/*   Updated: 2024/05/15 20:51:50 by bfaisy           ###   ########.fr       */
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

typedef struct s_posd
{
	char			orientation;
	double	x;
	double	y;
}	t_posd;

typedef enum e_direction
{
	NORTH = 0,
	SOUTH = 1,
	WEST = 2,
	EAST = 3
}	t_direction;

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
 * @brief player info struct
 * 
 */
typedef struct s_player
{
	double		angle;
	t_posd		pos;
}	t_player;

/**
 * @brief master varaible for execution
 * 
 * @param mlx		mlx pointer - must be free'd
 * @param mlx_win	mlx window pointer - must be free'd
 * @param imgs 		list of images - must be free'd
 * @param canvas	canvas image - must be free'd
 * @param map_filename	map file name
 * @param map_data map data - must be free'd
 * @param player player info - must be free'd
 */

typedef struct s_ray
{
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			time;
	double			oldtime;
	double			camera_x;
	double			width_screen;
	double			ray_dir_x;
	double			ray_dir_y;
	int				map_x;
	int				map_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			perp_wall_dist;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
	int				line_height;
	int				draw_start;
	int				draw_end;
	double			move_speed;
	double			rot_speed;
	double			old_dir_x;
	double			old_plane_x;
	double			frame_time;
	int				color;
	int				tex_y;
	double			tot_dist;
	int				lh;
	double			step;
	char			*picked_img;
}					t_ray;

typedef struct s_img
{
	void			*north;
	void			*south;
	void			*west;
	void			*east;
	char			**map;
	char			*north_texture;
	char			*south_texture;
	char			*west_texture;
	char			*east_texture;
	char			*floor_color;
	char			*sky_color;
	int				width;
	int				height;
	int				size_map;
	int				rgb_floor[3];
	int				rgb_sky[3];
	int				endian;
	void			*img_floor;
	void			*img_sky;
	int				pixel_bits;
	int				line_bytes;
	char			*buffer;
	int				pixel;
	int				ray_bpp;
	int				ray_lb;
	int				ray_end;
}					t_img;

typedef struct s_mlxvars
{
	void		*mlx;
	void		*mlx_win;
	t_list		*imgs;
	t_mlximage	*canvas;
	char		*map_filename;
	t_map_data	*map_data;
	t_player	player;
	t_ray		ray;
	t_posd		pos;
	t_img		img;
}	t_mlxvars;

typedef struct s_data
{
	double	distance;
	double	degre; // radiant
	t_posd	final;
	char	dir;
}	t_data;

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;



// INITIALISATIONS

t_pos		get_init_pos(void);
t_pos		get_init_pos_value(int x, int y);
t_pos		*get_init_pos_ptr(void);
t_pos		*get_init_pos_ptr_value(int x, int y);
t_gamedat	get_init_gamedat(void);
t_mlxvars	*get_init_mlxvars(t_mlxvars	*cub);
t_player	*get_init_player_ptr(void);

#endif