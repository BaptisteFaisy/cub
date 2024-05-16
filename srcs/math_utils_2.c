/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 00:46:14 by lhojoon           #+#    #+#             */
/*   Updated: 2024/05/17 00:54:27 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

double	diff_abs_exceed(double v)
{
	double	tmp;

	tmp = diff_abs(v);
	if (tmp == 0.0)
	{
		if (v < 0)
			return (-1.0);
		return (1.0);
	}
	return (tmp);
}

bool	fcmp(double a, double b)
{
	return (fabs(a - b) < (0.000001 * fabs(a + b)));
}

int	foc(bool is_x, double angle, double v)
{
	if (is_x)
	{
		if (angle >= M_PI / 2 && angle < 3 * M_PI / 2)
			return ((int)ceil(v));
		else
			return ((int)floor(v) + 1);
	}
	else
	{
		if (angle >= 0 && angle < M_PI)
			return ((int)ceil(v));
		else
			return ((int)floor(v) + 1);
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
