/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_screen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:51:49 by lhojoon           #+#    #+#             */
/*   Updated: 2024/04/10 13:28:21 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	clean_window(t_mlxvars *vars)
{
	int		x;
	int		y;

	y = 0;
	while (y < DEF_WINDOW_SIZE_H)
	{
		x = 0;
		while (x < DEF_WINDOW_SIZE_W)
		{
			mlx_draw_pixel(vars->canvas, x, y, mlx_rgb_to_int(0, 0, 0, 0));
			x++;
		}
		y++;
	}
}

void	draw_screen(t_mlxvars *vars)
{
	clean_window(vars);
	fov_main(vars);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->canvas, 0, 0);
}
