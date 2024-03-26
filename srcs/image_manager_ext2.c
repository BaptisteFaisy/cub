/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_manager_ext2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:31:10 by lhojoon           #+#    #+#             */
/*   Updated: 2024/03/26 15:36:01 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	draw_square(t_mlxvars *vars, t_mlximage *img, int x, int y)
{
	unsigned int	color;
	int				xi;
	int				yi;

	yi = 0;
	while (yi < DEF_IMG_SIZE)
	{
		xi = 0;
		while (xi < DEF_IMG_SIZE)
		{
			color = mlx_get_pixel(img, xi, yi);
			if (color != 4278190080)
				mlx_draw_pixel(vars->canvas, x + xi, y + yi, color);
			xi++;
		}
		yi++;
	}
}
