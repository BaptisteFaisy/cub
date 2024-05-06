/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_math.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:35:16 by lhojoon           #+#    #+#             */
/*   Updated: 2024/05/06 15:34:34 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

double	wall_get_ray_pos_x(double v, double angle)
{
	if (angle > 0 && angle < M_PI)
	{
		return (ceilexp_exceed(fabs(v)));
	}
	return (floorexp_exceed(fabs(v)));
}

double	wall_get_ray_pos_y(double v, double angle)
{
	if (angle > M_PI / 2 && angle < M_PI * 3 / 2)
	{
		return (floorexp_exceed(fabs(v)));
	}
	return (ceilexp_exceed(fabs(v)));
}

double	wall_get_correspondant_pos_x(double v, double angle)
{

}

double	wall_get_correspondant_pos_y(double v, double angle)
{
	
}
