/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_info_ext.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 21:20:09 by lhojoon           #+#    #+#             */
/*   Updated: 2024/05/17 00:57:13 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_direction	get_direction_of_wall(float angle, bool is_x)
{
	if (is_x)
	{
		if (angle > 0 && angle <= M_PI)
		{
			return (NORTH);
		}
		return (SOUTH);
	}
	else
	{
		if (angle > M_PI / 2 && angle < M_PI * 3 / 2)
		{
			return (WEST);
		}
		return (EAST);
	}
}

double	get_distance_of_wall(t_ray ray, t_posd origin)
{
	return ((sqrt(pow(ray.pos.x - origin.x, 2)
				+ pow(ray.pos.y - origin.y, 2))));
}

double	get_percentage_of_wall(double v)
{
	return (v - floor(v));
}
