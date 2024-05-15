/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_math2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:47:43 by lhojoon           #+#    #+#             */
/*   Updated: 2024/05/16 01:14:23 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

// static double	diff_abs_floor(double v)
// {
// 	if (v < 0)
// 	{
// 		return (-(fabs(v) - floor(fabs(v))));
// 	}
// 	return (v - floor(v));
// }

// static double	diff_abs_ceil(double v)
// {
// 	if (v < 0)
// 	{
// 		return (-(ceil(fabs(v)) - fabs(v)));
// 	}
// 	return (ceil(v) - v);
// }

// double	diff_abs_exceed_angle(double v, bool is_x, double angle)
// {
// 	if (!is_x)
// 	{
// 		if (angle >= 0  && angle < M_PI)
// 			return (1 - v - floor(v));
// 		return (v - floor(v));
// 	}
// 	else
// 	{
// 		if (angle >= M_PI / 2 && angle < 3 * M_PI / 2)
// 			return (1 - v - floor(v));
// 		return (v - floor(v));
// 	}
// }

double	positive_dist(double v)
{
	if (ceil(v) == v)
		return (1.0);
	return (ceil(v) - v);
}

double	negative_dist(double v)
{
	if (floor(v) == v)
		return (1.0);
	return (v - floor(v));
}

double	diff_abs_exceed_angle(double v, bool is_x, double angle)
{
	t_posd	dest;

	if (is_x)
	{
		if (get_is_negative(angle, true))
			dest.x = negative_dist(v);
		else
			dest.x = positive_dist(v);
		dest.y = fabs(tan(angle)) * dest.x;
	}
	else
	{
		if (get_is_negative(angle, false))
			dest.y = negative_dist(v);
		else
			dest.y = positive_dist(v);
		dest.x = dest.y / fabs(tan(angle));
	}
	printf("diff_abs : x %f y %f is : %s | dist : %f\n", dest.x, dest.y, is_x ? "x" : "y", sqrt(pow(dest.y, 2) + pow(dest.x , 2)));
	return (pow(dest.y, 2) + pow(dest.x, 2));
}
