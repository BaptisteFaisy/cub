/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_wall_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 18:32:59 by lhojoon           #+#    #+#             */
/*   Updated: 2024/05/20 18:31:16 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static t_wall_info
	*x_return_info(t_wall_info *info, t_ray ray, t_posd origin_pos)
{
	info->direction = get_direction_of_wall(ray.angle, false);
	info->distance = get_distance_of_wall(ray, origin_pos);
	info->percentage = get_percentage_of_wall(ray.pos.y);
	return (info);
}

static t_wall_info
	*y_return_info(t_wall_info *info, t_ray ray, t_posd origin_pos)
{
	info->direction = get_direction_of_wall(ray.angle, true);
	info->distance = get_distance_of_wall(ray, origin_pos);
	info->percentage = get_percentage_of_wall(ray.pos.x);
	return (info);
}

static void	x_calculate_coordination(t_ray *ray)
{
	double	diff;

	diff = ray->pos.x;
	ray->pos.x = wall_get_ray_pos_x(ray->pos.x, ray->angle);
	diff -= ray->pos.x;
	ray->pos.y += wall_get_correspondant_pos_y(diff, ray->angle);
}

t_wall_info	get_wall_info(t_ray ray, t_mlxvars *var)
{
	t_wall_info	info;
	t_posd		origin_pos;

	origin_pos = ray.pos;
	while (true)
	{
		if (diff_abs_exceed_angle(ray.pos.x, true, ray.angle)
			<= diff_abs_exceed_angle(ray.pos.y, false, ray.angle))
		{
			x_calculate_coordination(&ray);
			if (var->map_data->map[foc(false, ray.angle, ray.pos.y)]
				[foc(true, ray.angle, ray.pos.x)] == '1')
				return (*x_return_info(&info, ray, origin_pos));
		}
		else
		{
			y_calculate_coordination(&ray);
			if (var->map_data->map[foc(false, ray.angle, ray.pos.y)]
				[foc(true, ray.angle, ray.pos.x)] == '1')
				return (*y_return_info(&info, ray, origin_pos));
		}
	}
	return (free_mlx(var), exit(1), info);
}
