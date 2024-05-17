/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_one_vertical_line.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 18:16:23 by lhojoon           #+#    #+#             */
/*   Updated: 2024/05/17 21:20:50 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

bool	print_one_vertical_line(t_mlxvars *var,
			int vertical_count, t_wall_info wall);

#ifndef DEF_CAMERA_PLANE

static t_ray	get_ray(int i, t_mlxvars *var)
{
	t_ray	ray;

	if (i < DEF_WINDOW_SIZE_W / 2)
		i = -(DEF_WINDOW_SIZE_W / 2) + i;
	else
		i = i - DEF_WINDOW_SIZE_W / 2;
	ray.pos.x = var->player->pos.x;
	ray.pos.y = var->player->pos.y;
	ray.angle = radian_value_normalize(var->player->angle - (i * 0.001));
	return (ray);
}

#else

static t_ray	get_ray(int i, t_mlxvars *var)
{
	t_ray	ray;

	if (i < DEF_WINDOW_SIZE_W / 2)
		i = -(DEF_WINDOW_SIZE_W / 2) + i;
	else
		i = i - DEF_WINDOW_SIZE_W / 2;
	ray.angle = var->player->angle;
	ray.pos.x = var->player->pos.x + sin(ray.angle) * DEF_FOV_COEFF * i;
	ray.pos.y = var->player->pos.y + cos(ray.angle) * DEF_FOV_COEFF * i;
	return (ray);
}

#endif

void	fov_main(t_mlxvars *var)
{
	unsigned int	iter_count;
	t_ray			ray;
	t_wall_info		wall;

	iter_count = 0;
	while (iter_count < DEF_WINDOW_SIZE_W)
	{
		ray = get_ray((int)iter_count, var);
		wall = get_wall_info(ray, var);
		print_one_vertical_line(var, iter_count, wall);
		iter_count++;
	}
}

// TODO : Test this function by modifying math equation
static double	get_height_by_distance(double distance, int img_height)
{
	return (((double)img_height
			* (double)DEF_WINDOW_SIZE_H)
		- (distance * DEF_HEIGHT_COEFF));
}

/**
 * @brief print one vertical line on the canvas while
 * shrinking vertical size of a line of image
 * 
 * @param var mlxvars
 * @param wall_distance distance from characher to wall
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
			int x_count, t_wall_info wall)
{
	t_mlximage	*img;
	int			h;
	int			starth;
	int			i;
	int			pixel;

	img = get_image_by_direction(var, wall.direction);
	if (!img)
		return (false);
	h = (int)ceil(get_height_by_distance(wall.distance, img->height)
			* DEF_DISTANCE_COEFF);
	i = 0;
	if (h > DEF_WINDOW_SIZE_H)
		h = DEF_WINDOW_SIZE_H;
	starth = (DEF_WINDOW_SIZE_H - h) / 2;
	while (i < h && (starth + i) < DEF_WINDOW_SIZE_H)
	{
		pixel = mlx_get_pixel(img, wall.percentage * img->width,
				ceil(((double)i / (double)h) * img->height));
		mlx_draw_pixel(var->canvas, x_count,
			(starth + i), pixel);
		i++;
	}
	return (true);
}
