/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_wall_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 18:32:59 by lhojoon           #+#    #+#             */
/*   Updated: 2024/05/17 18:43:46 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_wall_info	get_wall_info(t_ray ray, t_mlxvars *var)
{
	t_wall_info	info;
	double		diff;
	t_posd		origin_pos;

	origin_pos = ray.pos;
	while (true)
	{
		if (diff_abs_exceed_angle(ray.pos.x, true, ray.angle)
			<= diff_abs_exceed_angle(ray.pos.y, false, ray.angle))
		{
			diff = ray.pos.x;
			ray.pos.x = wall_get_ray_pos_x(ray.pos.x, ray.angle);
			diff -= ray.pos.x;
			ray.pos.y += wall_get_correspondant_pos_y(diff, ray.angle);
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
			diff = ray.pos.y;
			ray.pos.y = wall_get_ray_pos_y(ray.pos.y, ray.angle); // ca marche po
			diff -= ray.pos.y;
			ray.pos.x += wall_get_correspondant_pos_x(diff, ray.angle);
			// printf("%d %d \n", foc(false, ray.angle, ray.pos.y), foc(true, ray.angle, ray.pos.x));
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
