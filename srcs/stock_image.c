/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaisy <bfaisy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 14:26:57 by lhojoon           #+#    #+#             */
/*   Updated: 2024/05/16 00:43:39 by bfaisy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	get_color(int *colors)
{
	return ((colors[0] << 16) | (colors[1] << 8) | colors[2]);
}

static void	set_color(t_mlxvars *cub, int color, char **buffer, int yx[2])
{
	cub->img.pixel = (yx[0] * cub->img.line_bytes) + (yx[1] * 4);
	if (cub->img.endian == 0)
	{
		(*buffer)[cub->img.pixel + 0] = (color) & 0xFF;
		(*buffer)[cub->img.pixel + 1] = (color >> 8) & 0xFF;
		(*buffer)[cub->img.pixel + 2] = (color >> 16) & 0xFF;
		(*buffer)[cub->img.pixel + 3] = (color >> 24);
	}
}

void	get_imgs(t_mlxvars *cub, void *img, int color, int color2)
{
	int	y;
	int	x;

	cub->img.buffer = mlx_get_data_addr(img, &cub->img.pixel_bits,
			&cub->img.line_bytes, &cub->img.endian);

	y = -1;
	while (++y < DEF_WINDOW_SIZE_H / 2)
	{
		x = -1;
		while (++x < DEF_WINDOW_SIZE_W)
			set_color(cub, color, &cub->img.buffer, (int [2]){y, x});
	}
	y--;
	while (++y < DEF_WINDOW_SIZE_H)
	{
		x = -1;
		while (++x < DEF_WINDOW_SIZE_W)
			set_color(cub, color2, &cub->img.buffer, (int [2]){y, x});
	}
}

bool	stock_image(t_mlxvars *cub)
{
	cub->img.img_floor = mlx_new_image(cub->mlx, DEF_WINDOW_SIZE_W, DEF_WINDOW_SIZE_H);
	get_imgs(cub, cub->img.img_floor, get_color(cub->img.rgb_sky),
		get_color(cub->img.rgb_floor));
	cub->img.north = mlx_xpm_file_to_image(cub->mlx, "./maps/north.xpm",
			&cub->img.width, &cub->img.height); // ceci est hard coder faire des changements
	cub->img.south = mlx_xpm_file_to_image(cub->mlx, "./maps/south.xpm",
			&cub->img.width, &cub->img.height);
	cub->img.east = mlx_xpm_file_to_image(cub->mlx, "./maps/east.xpm",
			&cub->img.width, &cub->img.height);
	cub->img.west = mlx_xpm_file_to_image(cub->mlx,"./maps/west.xpm",
			&cub->img.width, &cub->img.height);
	return (true);
}
