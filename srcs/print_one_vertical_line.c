/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_one_vertical_line.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 18:16:23 by lhojoon           #+#    #+#             */
/*   Updated: 2024/05/06 17:46:39 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

bool	print_one_vertical_line(t_mlxvars *var,
			int vertical_count, t_wall_info wall);

// angle : angle du rayon lance
// dir_fov : angle du premier rayon
// nbr_angle : numero du rayon
// pos : position du player x,y
// angle_base : dir du player
// distance_mur_positif : retourne une struct contenant tout

// TODO : check if it exceeds map limit
// c'est la merde ici
static t_wall_info	get_wall_info(t_ray ray, t_mlxvars *var)
{
	t_wall_info	info;
	double		diff;
	t_posd		origin_pos;

	origin_pos = ray.pos;
	while (true)
	{
		printf("diff value : x %f y %f\n", diff_abs_exceed_angle(fabs(ray.pos.x), true, ray.angle), diff_abs_exceed_angle(fabs(ray.pos.y), false, ray.angle));
		if (diff_abs_exceed_angle(fabs(ray.pos.x), true, ray.angle)
			> diff_abs_exceed_angle(fabs(ray.pos.y), false, ray.angle))
		{
			printf("IN Y : ");
			printf("__ RAY X : %f RAY Y %f\n", ray.pos.x, ray.pos.y);
			diff = ray.pos.x;
			ray.pos.x = wall_get_ray_pos_y(ray.pos.x, ray.angle);
			diff = ray.pos.x - diff;
			ray.pos.y += wall_get_correspondant_pos_x(diff, ray.angle);// ca marche pas du coup
			printf("ray x : %f ray y : %f angle : %f diff_abs_exceed : %f tan : %f\n", ray.pos.x, ray.pos.y, ray.angle, diff_abs_exceed(fabs(ray.pos.x)), tan(ray.angle));
			if (var->map_data->map[(int)floorexp(ray.pos.y)][(int)ray.pos.x] == '1')
			{
				info.direction = get_direction_of_wall(ray.angle, false);
				info.distance = get_distance_of_wall(ray, origin_pos);
				info.percentage = get_percentage_of_wall(ray.pos.y);
				return (info);
			}
		}
		else
		{
			printf("IN X : ");
			printf("__ RAY X : %f RAY Y %f\n", ray.pos.x, ray.pos.y);
			diff = ray.pos.y;
			ray.pos.y = wall_get_ray_pos_x(ray.pos.y, ray.angle);
			diff = ray.pos.y - diff;
			ray.pos.x += wall_get_correspondant_pos_y(diff, ray.angle); // ca marche po
			printf("ray x : %f ray y : %f angle : %f diff_abs_exceed: %f tan : %f\n", ray.pos.x, ray.pos.y, ray.angle, diff_abs_exceed(fabs(ray.pos.y)), tan(ray.angle));
			if (var->map_data->map[(int)ray.pos.y][(int)floorexp(ray.pos.x)] == '1')
			{
				info.direction = get_direction_of_wall(ray.angle, true);
				info.distance = get_distance_of_wall(ray, origin_pos);
				info.percentage = get_percentage_of_wall(ray.pos.x);
				return (info);
			}
		}
	}
	exit(1); // TODO : Watch free
}

static t_ray	get_ray(int i, t_mlxvars *var)
{
	t_ray	ray;

	ray.angle = var->player->angle;
	if (i < DEF_WINDOW_SIZE_W / 2)
		i = -(DEF_WINDOW_SIZE_W / 2) + i;
	else
		i = i - DEF_WINDOW_SIZE_W / 2;
	ray.pos.x = var->player->pos.x + sin(ray.angle) * DEF_FOV_COEFF * i;
	ray.pos.y = var->player->pos.y + cos(ray.angle) * DEF_FOV_COEFF * i;
	printf("Ray X : %f  Y: %f sin : %f cos : %f angle:  %f coeff: %f\n", ray.pos.x, ray.pos.y, sin(ray.angle), cos(ray.angle), ray.angle, DEF_FOV_COEFF);
	return (ray);
}

void	fov_main(t_mlxvars *var)
{
	unsigned int	iter_count;
	t_ray			ray;
	t_wall_info		wall;

	iter_count = 0;
	printf("player angle deg : %f rad : %f\n", var->player->angle * 180 / M_PI, var->player->angle);
	while (iter_count < DEF_WINDOW_SIZE_W)
	{
		ray = get_ray((int)iter_count, var);
		printf("> ray x : %f ray y : %f angle : %f\n", ray.pos.x, ray.pos.y, ray.angle);
		wall = get_wall_info(ray, var);
		printf("wall distance: %f percentage : %f direction : %d\n", wall.distance, wall.percentage, (int)wall.direction);
		// getchar();
		print_one_vertical_line(var, iter_count, wall);
		iter_count++;
	}
}


// t_data	fov_main(t_mlxvars *var)
// {
// 	double	angle;
// 	double	dir_fov;
// 	int		nbr_angle;
// 	t_data	dat;

// 	nbr_angle = 0;
// 	dir_fov = 45 * M_PI / 180;
// 	while (nbr_angle != DEF_WINDOW_SIZE_W)
// 	{
// 		angle = dir_fov - (nbr_angle * (0.046875 * M_PI / 180)) + var->player->angle;
// 		dat = distance_mur_positif(angle, var->player->pos, var->map_data->map,
// 				var->player->angle);
// 		// printf("x.fi = %f, y.fin = %f", dat.final.x, dat.final.y);
// 		printf("RESULTAT : %fs %c %f --- angle %f\n", dat.degre, dat.dir, dat.distance, angle);
// 		if (dat.distance <= 0)
// 		{
// 			printf("Out of map\n");
// 			exit (1);
// 		}
// 		if (print_one_vertical_line(var, dat.distance, nbr_angle,
// 				transform_direction_from_char(dat.dir), 0.5) == false)
// 			printf("Error print one vertical line\n");
// 		// mlx_put_image_to_window(var->mlx, var->mlx_win, var->canvas, 0, 0);
// 		nbr_angle++;
// 	}
// 	return (dat);
// }

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
			int vertical_count, t_wall_info wall)
{
	t_mlximage	*img;
	int			h;
	int			starth;
	int			i;
	int			pixel;

	(void)starth;
	img = get_image_by_direction(var, wall.direction);
	if (!img)
		return (false);
	h = get_height_by_distance(wall.distance, img->height) * DEF_DISTANCE_COEFF;
	i = 0;
	starth = (DEF_WINDOW_SIZE_H - h) / 2;
	// printf("starth: %d h  %d distance %f imgh %d \n", starth, h, distance, img->height);
	while (i < h)
	{
		pixel = mlx_get_pixel(img, wall.percentage * img->width,
				ceil(((double)i / (double)h) * img->height));
		// printf("pixel : %d ceil : %f x : %d\n", pixel, ceil(((double)i / (double)DEF_WINDOW_SIZE_H) * h + starth), vertical_count);
		mlx_draw_pixel(var->canvas, vertical_count,
			ceil(((double)i / (double)DEF_WINDOW_SIZE_H) * h + starth), pixel);
		i++;
	}
	return (true);
}
