/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_math2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:47:43 by lhojoon           #+#    #+#             */
/*   Updated: 2024/05/06 16:22:12 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static double	diff_abs_floor(double v)
{
	if (v < 0)
	{
		return (-(fabs(v) - floor(fabs(v))));
	}
	return (v - floor(v));
}

static double	diff_abs_ceil(double v)
{
	if (v < 0)
	{
		return (-(ceil(fabs(v)) - fabs(v)));
	}
	return (ceil(v) - v);
}

double	diff_abs_exceed_angle(double v, bool is_x, double angle)
{
	if (fabs(v) == v)
		return (1.0);
	if (is_x)
	{
		if (angle >= 0 && angle < M_PI)
			return (diff_abs_floor(v));
		else
			return (diff_abs_ceil(v));
	}
	else
	{
		if (angle >= M_PI / 2 && angle < M_PI * 3 / 2)
			return (diff_abs_floor(v));
		else
			return (diff_abs_ceil(v));
	}
}
