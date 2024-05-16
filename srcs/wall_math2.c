/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_math2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:47:43 by lhojoon           #+#    #+#             */
/*   Updated: 2024/05/16 22:41:02 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

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
	return (pow(dest.y, 2) + pow(dest.x, 2));
}
