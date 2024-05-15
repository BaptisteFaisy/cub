/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_math.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:35:16 by lhojoon           #+#    #+#             */
/*   Updated: 2024/05/15 21:40:52 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

double	wall_get_ray_pos_y(double v, double angle)
{
	if (get_is_negative(angle, false))
	{
		return (floorexp_exceed(fabs(v)));
	}
	return (ceilexp_exceed(fabs(v)));
}

double	wall_get_ray_pos_x(double v, double angle)
{
	if (get_is_negative(angle, true))
	{
		return (floorexp_exceed(fabs(v)));
	}
	return (ceilexp_exceed(fabs(v)));
}

double	wall_get_correspondant_pos_x(double v, double angle)
{
	if (get_is_negative(angle, true))
	{
		return (-fabs((v / tan(angle))));
	}
	return (fabs(v / tan(angle)));
}

double	wall_get_correspondant_pos_y(double v, double angle)
{
	if (get_is_negative(angle, false))
	{
		return (-fabs(tan(angle) * v));
	}
	return (fabs(tan(angle) * v));
}
