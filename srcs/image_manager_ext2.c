/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_manager_ext2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:31:10 by lhojoon           #+#    #+#             */
/*   Updated: 2023/11/25 17:36:18 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_square(t_mlxvars *vars, t_mlximage *img, int x, int y)
{
	unsigned int	color;
	int				xi;
	int				yi;

	yi = 0;
	while (yi < SL_IMG_SIZE)
	{
		xi = 0;
		while (xi < SL_IMG_SIZE)
		{
			color = mlx_get_pixel(img, xi, yi);
			if (color != 4278190080)
				mlx_draw_pixel(vars->canvas, x + xi, y + yi, color);
			xi++;
		}
		yi++;
	}
}
