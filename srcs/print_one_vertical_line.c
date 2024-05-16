/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_one_vertical_line.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaisy <bfaisy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 18:16:23 by lhojoon           #+#    #+#             */
/*   Updated: 2024/05/16 02:08:47 by bfaisy           ###   ########.fr       */
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
			return ((int)ceil(v));
		else
			return ((int)floor(v));
	}
	else
	{
		if (angle >= 0 && angle < M_PI)
			return ((int)ceil(v));
		else
			return ((int)floor(v));
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
	if (ch == '1' || ch == 0)
		return (false);
	return (true);
}

static bool	check_crash_wall(t_mlxvars *var, t_ray ray, double th, bool is_x)
{
	double	i;
	double	v;

	if (is_x)
	{
		i = ray.pos.x + th;
		v = ray.pos.y + th * fabs(tan(ray.angle));
		printf("X ray x: %f ray y : %f |||  i and v : %f %f th : %f is : %s\n", ray.pos.x, ray.pos.y, i, v, th, get_is_negative(ray.angle, true) ? "true" : "false");
		if (v < 0 || i < 0)
			return (false);
		if (get_is_negative(ray.angle, true))
		{
			while (i > ray.pos.x)
			{
				if (v < 0 || i < 0)
					return (false);
				if (is_inside_map(var->map_data->map[(int)floor(v)][(int)floor(i)]) == false)
					return (false);
				i -= 1.0;
				v -= fabs(tan(ray.angle));
			}
		}
		else
		{
			while (i < ray.pos.x)
			{
				if (v < 0 || i < 0)
					return (false);
				if (is_inside_map(var->map_data->map[(int)floor(v)][(int)floor(i)]) == false)
					return (false);
				i += 1.0;
				v += fabs(tan(ray.angle));
			}
		}
	}
	else
	{
		i = ray.pos.y + th;
		v = ray.pos.x + th / tan(ray.angle);
		printf("X ray x: %f ray y : %f |||  i and v : %f %f th : %f is : %s\n", ray.pos.x, ray.pos.y, i, v, th, get_is_negative(ray.angle, false) ? "true" : "false");
		if (v < 0 || i < 0)
			return (false);
		if (get_is_negative(ray.angle, false))
		{
			while (i > ray.pos.y)
			{
				if (v < 0 || i < 0)
					return (false);
				if (is_inside_map(var->map_data->map[(int)floor(i)][(int)floor(v)]) == false)
					return (false);
				i -= 1.0;
				v -= fabs(tan(ray.angle));
			}
		}
		else
		{
			while (i < ray.pos.y)
			{
				if (v < 0 || i < 0)
					return (false);
				if (is_inside_map(var->map_data->map[(int)floor(i)][(int)floor(v)]) == false)
					return (false);
				i += 1.0;
				v += fabs(tan(ray.angle));
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
		(void)check_crash_wall;
		if (!false && (false || diff_abs_exceed_angle(ray.pos.x, true, ray.angle)
				<= diff_abs_exceed_angle(ray.pos.y, false, ray.angle)))
		{
			is_x_force = false;
			printf("IN X : __ RAY X : %f RAY Y %f\n", ray.pos.x, ray.pos.y);
			diff = ray.pos.x;
			origin_value = ray.pos.x;
			ray.pos.x = wall_get_ray_pos_x(ray.pos.x, ray.angle);
			diff -= ray.pos.x;
			th = wall_get_correspondant_pos_y(diff, ray.angle);
			printf("th ::: %f ray y : %f diff : %f\n", th, ray.pos.y, diff);
			ray.pos.y += th;
			printf("dd -> ray x : %f ray y : %f || y : %d x : %d || angle : %f diff %f\n", ray.pos.x, ray.pos.y, foc(false, ray.angle, ray.pos.y), foc(true, ray.angle, ray.pos.x), ray.angle, diff);
			printf("RESULT %c\n\n", var->map_data->map[foc(false, ray.angle, ray.pos.y)][foc(true, ray.angle, ray.pos.x)]);
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
			origin_value = ray.pos.y;
			ray.pos.y = wall_get_ray_pos_y(ray.pos.y, ray.angle); // ca marche po
			diff -= ray.pos.y;
			th = wall_get_correspondant_pos_x(diff, ray.angle);
			printf("th ::: %f ray x : %f diff : %f\n", th, ray.pos.x, diff);
			ray.pos.x += th;
			printf("dd -> ray x : %f ray y : %f || y : %d x : %d || angle : %f diff %f\n", ray.pos.x, ray.pos.y, foc(false, ray.angle, ray.pos.y), foc(true, ray.angle, ray.pos.x), ray.angle, diff);
			printf("RESULT %c\n\n", var->map_data->map[foc(false, ray.angle, ray.pos.y)][foc(true, ray.angle, ray.pos.x)]);
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
		print_one_vertical_line(var, iter_count, wall);
		iter_count++;
	}
}

// TODO : Test this function by modifying math equation
static double	get_height_by_distance(double distance, int img_height)
{
	return ((((double)img_height * (double)DEF_WINDOW_SIZE_H) / distance));
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
	h = (int)ceil(get_height_by_distance(wall.distance, img->height) * DEF_DISTANCE_COEFF);
	i = 0;
	if (h > DEF_WINDOW_SIZE_H)
		h = DEF_WINDOW_SIZE_H;
	starth = (DEF_WINDOW_SIZE_H - h) / 2;
	// printf("starth: %d h  %d distance %f imgh %d \n", starth, h, distance, img->height);
	while (i < h && (starth + i) < DEF_WINDOW_SIZE_H)
	{
		pixel = mlx_get_pixel(img, wall.percentage * img->width,
				ceil(((double)i / (double)h) * img->height));
		// printf("pixel : %d ceil : %f x : %d\n", pixel, ceil(((double)i / (double)DEF_WINDOW_SIZE_H) * h + starth), vertical_count);
		mlx_draw_pixel(var->canvas, x_count,
			// ceil(((double)i / (double)DEF_WINDOW_SIZE_H) * h) + starth, pixel);
			(starth + i), pixel);
		i++;
	}
	return (true);
}
