/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_one_vertical_line.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 18:16:23 by lhojoon           #+#    #+#             */
/*   Updated: 2024/05/12 01:35:14 by lhojoon          ###   ########.fr       */
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

int	foc(bool is_x, double angle, double v)
{
	if (is_x)
	{
		if (angle >= M_PI / 2 && angle < 3 * M_PI / 2)
			return ((int)floor(v));
		else
			return ((int)ceil(v));
	}
	else
	{
		if (angle >= 0 && angle < M_PI)
			return ((int)floor(v));
		else
			return ((int)ceil(v));
	}
}

bool	get_is_negative(double angle, bool is_x)
{
	if (is_x && angle >= M_PI / 2 && angle < 3 * M_PI / 2)
		return (true);
	else if (!is_x && angle >= 0 && angle < M_PI)
		return (true);
	return (false);
}

static bool	is_inside_map(char ch)
{
	printf("--> %c\n", ch);
	// getchar();
	if (ch == '1' || ch == 0)
		return (false);
	return (true);
}

static bool	check_crash_wall(t_mlxvars *var, t_ray ray, double th, bool is_x)
{
	int	i;
	int	v;

	if (is_x)
	{
		i = foc(true, ray.angle, ray.pos.x);
		v = foc(false, ray.angle, ray.pos.y);
		printf("X i and v : %d %d th : %f is : %s\n", i, v, th, get_is_negative(ray.angle, true) ? "true" : "false");
		// getchar();
		if (get_is_negative(ray.angle, true))
		{
			while (i > th)
			{
				if (is_inside_map(var->map_data->map[v][i]) == false)
					return (false);
				i -= 1.0;
			}
		}
		else
		{
			while (i < th)
			{
				if (is_inside_map(var->map_data->map[v][i]) == false)
					return (false);
				i += 1.0;
			}
		}
	}
	else
	{
		i = foc(false, ray.angle, ray.pos.y);
		v = foc(true, ray.angle, ray.pos.x);
		printf("Y i and v : %d %d th : %f is : %s\n", i, v, th, get_is_negative(ray.angle, false) ? "true" : "false");
		// getchar();
		if (get_is_negative(ray.angle, false))
		{
			while (i > th)
			{
				if (is_inside_map(var->map_data->map[i][v]) == false)
					return (false);
				i -= 1.0;
			}
		}
		else
		{
			while (i < th)
			{
				if (is_inside_map(var->map_data->map[i][v]) == false)
					return (false);
				i += 1.0;
			}
		}
	}
	return (true);
}

// TODO : check if it exceeds map limit
// c'est la merde ici
static t_wall_info	get_wall_info(t_ray ray, t_mlxvars *var)
{
	t_wall_info	info;
	double		diff;
	t_posd		origin_pos;
	double		th;
	bool		is_x_force;
	bool		is_y_force;
	double		origin_value;

	origin_pos = ray.pos;
	is_x_force = false;
	is_y_force = false;
	while (true)
	{
		// printf("diff value : x %f y %f\n", diff_abs_exceed_angle(fabs(ray.pos.x), true, ray.angle), diff_abs_exceed_angle(fabs(ray.pos.y), false, ray.angle));
		if (!is_y_force && (is_x_force || diff_abs_exceed_angle(fabs(ray.pos.x), true, ray.angle, var->player->pos)
				< diff_abs_exceed_angle(fabs(ray.pos.y), false, ray.angle, var->player->pos)))
		{
			is_x_force = false;
			printf("IN X : __ RAY X : %f RAY Y %f\n", ray.pos.x, ray.pos.y);
			diff = ray.pos.x;
			origin_value = diff;
			ray.pos.x = wall_get_ray_pos_y(ray.pos.x, ray.angle);
			diff = ray.pos.x - diff;
			th = wall_get_correspondant_pos_y(diff, ray.angle);
			if (!check_crash_wall(var, ray, ray.pos.y + th, false))
			{
				printf("th: %f CRASH WALL !!!!\n", th);
				is_y_force = true;
				ray.pos.x = origin_value;
				continue ;
			}
			ray.pos.y += th;
			printf("dd -> ray x : %f ray y : %f angle : %f diff %f\n", ray.pos.x, ray.pos.y, ray.angle, diff);
			printf("fuck you %c\n", var->map_data->map[foc(false, ray.angle, ray.pos.y)][foc(true, ray.angle, ray.pos.x)]);
			if (var->map_data->map[foc(false, ray.angle, ray.pos.y)][foc(true, ray.angle, ray.pos.x)] == '1')
			{
				info.direction = get_direction_of_wall(ray.angle, false);
				info.distance = get_distance_of_wall(ray, origin_pos);
				info.percentage = get_percentage_of_wall(ray.pos.y);
				return (info);
			}
		}
		else
		{
			is_y_force = false;
			printf("IN Y : __ RAY X : %f RAY Y %f\n", ray.pos.x, ray.pos.y);
			diff = ray.pos.y;
			origin_value = diff;
			ray.pos.y = wall_get_ray_pos_x(ray.pos.y, ray.angle); // ca marche po
			diff = ray.pos.y - diff;
			th = wall_get_correspondant_pos_x(diff, ray.angle);
			if (!check_crash_wall(var, ray, ray.pos.x + th, true))
			{
				printf("th: %f CRASH WALL !!!!\n", th);
				is_x_force = true;
				ray.pos.y = origin_value;
				continue ;
			}
			ray.pos.x += th;
			// if (ray.pos.x > 5)
			// 	getchar();
			// printf("(int)floorexp(ray.pos.x)%d\n", (int)floorexp(ray.pos.x));
			printf("dd -> ray x : %f ray y : %f angle : %f diff %f\n", ray.pos.x, ray.pos.y, ray.angle, diff);
			printf("fuck you %c\n", var->map_data->map[foc(false, ray.angle, ray.pos.y)][foc(true, ray.angle, ray.pos.x)]);
			if (var->map_data->map[foc(false, ray.angle, ray.pos.y)][foc(true, ray.angle, ray.pos.x)] == '1')
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
static double	get_height_by_distance(double distance, int img_height)
{
	return ((((double)img_height * (double)DEF_WINDOW_SIZE_H) / distance));
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
			int x_count, t_wall_info wall)
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
	h = (int)ceil(get_height_by_distance(wall.distance, img->height) * DEF_DISTANCE_COEFF);
	i = 0;
	starth = (DEF_WINDOW_SIZE_H - h) / 2;
	// printf("starth: %d h  %d distance %f imgh %d \n", starth, h, distance, img->height);
	while (i < h)
	{
		pixel = mlx_get_pixel(img, wall.percentage * img->width,
				ceil(((double)i / (double)h) * img->height));
		// printf("pixel : %d ceil : %f x : %d\n", pixel, ceil(((double)i / (double)DEF_WINDOW_SIZE_H) * h + starth), vertical_count);
		mlx_draw_pixel(var->canvas, x_count,
			// ceil(((double)i / (double)DEF_WINDOW_SIZE_H) * h) + starth, pixel);
			ceil(starth + i), pixel);
		i++;
	}
	return (true);
}
