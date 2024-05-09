/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_math2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaisy <bfaisy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:47:43 by lhojoon           #+#    #+#             */
/*   Updated: 2024/05/09 19:32:17 by bfaisy           ###   ########.fr       */
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

double	diff_abs_exceed_angle(double v, bool is_x, double angle)
{
	if (!is_x)
	{
		if (angle >= 0  && angle < M_PI)
			return (1 - v - floor(v));
		return (v - floor(v));
	}
	else
	{
		if (angle >= M_PI / 2 && angle < 3 * M_PI / 2)
			return (1 - v - floor(v));
		return (v - floor(v));
	}
}
