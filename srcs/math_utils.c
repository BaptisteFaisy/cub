/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 19:52:17 by lhojoon           #+#    #+#             */
/*   Updated: 2024/05/05 21:12:23 by lhojoon          ###   ########.fr       */
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
	if (tmp == v)
	{
		if (v < 0)
			return (v - 1);
		return (v + 1);
	}
	return (tmp);
}
