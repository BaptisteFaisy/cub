/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_one_vertical_line.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaisy <bfaisy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 18:16:23 by lhojoon           #+#    #+#             */
/*   Updated: 2024/03/29 17:49:27 by bfaisy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

// angle : angle du rayon lance
// dir_fov : angle du premier rayon
// nbr_angle : numero du rayon
// pos : position du player x,y
// angle_base : dir du player
// distance_mur_positif : retourne une struct contenant tout

t_data	fov_main(double direction_player, t_mlxvars *var)
{
	double	angle;
	double	dir_fov;
	int		nbr_angle;

	nbr_angle = 0;
	dir_fov = -45;
	while (nbr_angle != DEF_WINDOW_SIZE_W)
	{
		distance_mur_positif(angle, pos, map, angle_base);
		angle = dir_fov + (nbr_angle * 0.046875);
		nbr_angle++;
	}
}

// TODO : Test this function by modifying math equation
static int	get_height_by_distance(double distance, int img_height)
{
	return ((DEF_DISTANCE_COEFF - distance) * img_height * DEF_WINDOW_SIZE_H);
}

/**
 * @brief Get the x by angle object
 * 
 * @param angle radian, depending on the screen's direction
 * @return int 
 */
static int	get_x_by_angle(double angle)
{
	int	dangle;

	dangle = (int)ceil(angle * (M_PI / 180));
	return (dangle / DEF_POV_ANGLE * DEF_WINDOW_SIZE_W);
}

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
			double distance, double angle, t_direction dir,
			double percentage)
{
	t_mlximage	*img;
	int			h;
	int			starth;
	int			i;
	int			pixel;

	img = get_image_by_direction(var, dir);
	if (!img)
		return (false);
	h = get_height_by_distance(distance, img->height);
	i = 0;
	starth = (DEF_WINDOW_SIZE_H - h) / 2;
	while (i < h)
	{
		pixel = mlx_get_pixel(img, percentage * img->width,
				ceil(((double)i / (double)h) * img->height));
		mlx_draw_pixel(var->canvas, get_x_by_angle(angle),
			ceil(((double)i / (double)h) * DEF_WINDOW_SIZE_H), pixel);
		i++;
	}
	return (true);
}
