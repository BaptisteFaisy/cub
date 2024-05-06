/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_math.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:35:16 by lhojoon           #+#    #+#             */
/*   Updated: 2024/05/06 17:45:47 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

double	wall_get_ray_pos_x(double v, double angle)
{
	if (angle >= 0 && angle < M_PI)
	{
		return (floorexp_exceed(fabs(v)));
	}
	return (ceilexp_exceed(fabs(v)));
}

double	wall_get_ray_pos_y(double v, double angle)
{
	if (angle >= M_PI / 2 && angle < M_PI * 3 / 2)
	{
		return (floorexp_exceed(fabs(v)));
	}
	return (ceilexp_exceed(fabs(v)));
}

static double	securized_tan(double v)
{
	if (fcmp(v, M_PI / 2) || fcmp(v, M_PI * 3 / 2))
		return (0.0);
	return (tan(v));
}

// static double	securized_atan(doubles v)
// {
	
// }

double	wall_get_correspondant_pos_x(double v, double angle)
{
	// printf("x diff_abs_exceed_angle : %f\n", diff_abs_exceed_angle(v, true, angle));
	// return (atan(angle) * diff_abs_exceed_angle(v, true, angle));
	printf("wall_get_correspondant_pos_x result : %f - atan : %f v : %f\n", atan(angle) * v, atan(angle), v);
	return (atan(angle) * v);
}

double	wall_get_correspondant_pos_y(double v, double angle)
{
	// printf("y diff_abs_exceed_angle : %f\n", diff_abs_exceed_angle(v, false, angle));
	// return (securized_tan(angle) * diff_abs_exceed_angle(v, false, angle));
	printf("wall_get_correspondant_pos_y result : %f\n", securized_tan(angle) * v);
	return (securized_tan(angle) * v);
}
