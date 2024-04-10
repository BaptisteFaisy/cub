/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_one_vertical_line.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 18:16:23 by lhojoon           #+#    #+#             */
/*   Updated: 2024/04/10 14:56:41 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

bool	print_one_vertical_line(t_mlxvars *var,
			double distance, int vertical_count, t_direction dir,
			double percentage);

// angle : angle du rayon lance
// dir_fov : angle du premier rayon
// nbr_angle : numero du rayon
// pos : position du player x,y
// angle_base : dir du player
// distance_mur_positif : retourne une struct contenant tout

t_data	fov_main(t_mlxvars *var)
{
	double	angle;
	double	dir_fov;
	int		nbr_angle;
	t_data	dat;

	nbr_angle = 0;
	dir_fov = 45 * M_PI / 180 ;
	while (nbr_angle != DEF_WINDOW_SIZE_W)
	{
		angle = dir_fov - (nbr_angle * (0.046875 * M_PI / 180)) + var->player->angle;
		dat = distance_mur_positif(angle, var->player->pos, var->map_data->map,
				var->player->angle);
		// printf("x.fi = %d, y.fin = %d", dat.final.x);
		// printf("RESULTAT : %fs %c %f --- angle %f\n", dat.degre, dat.dir, dat.distance, angle);
		if (print_one_vertical_line(var, dat.distance, nbr_angle,
				transform_direction_from_char(dat.dir), 0.5) == false)
			printf("Error print one vertical line\n");
		// mlx_put_image_to_window(var->mlx, var->mlx_win, var->canvas, 0, 0);
		nbr_angle++;
	}
	return (dat);
}

// TODO : Test this function by modifying math equation
static int	get_height_by_distance(double distance, int img_height)
{
	// return ((DEF_DISTANCE_COEFF - distance) * img_height * DEF_WINDOW_SIZE_H);
	return ((int)(((distance) / (double)img_height * (double)DEF_WINDOW_SIZE_H) * DEF_DISTANCE_COEFF));
}

// /**
//  * @brief Get the x by angle object
//  * 
//  * @param angle radian, depending on the screen's direction
//  * @return int 
//  */
// static int	get_x_by_angle(double angle)
// {
// 	int	dangle;

// 	dangle = (int)ceil(angle * (M_PI / 180));
// 	return (dangle / DEF_POV_ANGLE * DEF_WINDOW_SIZE_W);
// }

/**
 * @brief print one vertical line on the canvas while
 * shrinking vertical size of a line of image
 * 
 * @param var mlxvars
 * @param distance distance from characher to wall
 * @param angle angle of ray from character to wall, radian,
 * depending on map's absolute direction
 * @param dir direction of the wall
 * @param percentage horizontal percentage of the vertical line on the image
 * 
 * @return bool - true if success, false if failed
 * 
 * @todo Do I have to calculate the average color ? 
 */
bool	print_one_vertical_line(t_mlxvars *var,
			double distance, int vertical_count, t_direction dir,
			double percentage)
{
	t_mlximage	*img;
	int			h;
	int			starth;
	int			i;
	int			pixel;

	(void)starth;
	img = get_image_by_direction(var, dir);
	if (!img)
		return (false);
	h = get_height_by_distance(distance, img->height) * DEF_DISTANCE_COEFF;
	i = 0;
	starth = (DEF_WINDOW_SIZE_H - h) / 2;
	// printf("starth: %d h  %d distance %f imgh %d \n", starth, h, distance, img->height);
	while (i < h)
	{
		pixel = mlx_get_pixel(img, percentage * img->width,
				ceil(((double)i / (double)h) * img->height));
		// printf("pixel : %d ceil : %f x : %d\n", pixel, ceil(((double)i / (double)DEF_WINDOW_SIZE_H) * h + starth), vertical_count);
		mlx_draw_pixel(var->canvas, vertical_count,
			ceil(((double)i / (double)DEF_WINDOW_SIZE_H) * h + starth), pixel);
		i++;
	}
	return (true);
}
