/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 19:52:17 by lhojoon           #+#    #+#             */
/*   Updated: 2024/05/06 17:22:39 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

double	ceilexp(double v)
{
	if (v < 0)
	{
		return (-ceil(fabs(v)));
	}
	return (ceil(v));
}

double	ceilexp_exceed(double v)
{
	double	tmp;

	tmp = ceilexp(v);
	if (tmp == v)
	{
		if (v < 0)
		{
			return (v - 1);
		}
		return (v + 1);
	}
	return (tmp);
}

double	floorexp(double v)
{
	if (v < 0)
	{
		return (-floor(fabs(v)));
	}
	return (floor(v));
}

double	floorexp_exceed(double v)
{
	double	tmp;

	tmp = floorexp(v);
	if (tmp == v)
	{
		if (v < 0)
		{
			return (v + 1);
		}
		return (v - 1);
	}
	return (tmp);
}

double	diff_abs(double v)
{
	if (v < 0)
	{
		return (-(fabs(v) - floor(fabs(v))));
	}
	return (v - floor(v));
}

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
