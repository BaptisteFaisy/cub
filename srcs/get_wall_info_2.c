/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_wall_info_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:28:58 by lhojoon           #+#    #+#             */
/*   Updated: 2024/05/20 18:30:57 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	y_calculate_coordination(t_ray *ray)
{
	double	diff;

	diff = ray->pos.y;
	ray->pos.y = wall_get_ray_pos_y(ray->pos.y, ray->angle);
	diff -= ray->pos.y;
	ray->pos.x += wall_get_correspondant_pos_x(diff, ray->angle);
}
