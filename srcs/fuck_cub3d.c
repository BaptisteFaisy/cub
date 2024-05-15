/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fuck_cub3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaisy <bfaisy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 21:15:30 by bfaisy            #+#    #+#             */
/*   Updated: 2024/05/16 01:40:55 by bfaisy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
int set_pixel_color(int face, t_mlxvars *cub, double tex_pos, char *img);


void	find_color(t_mlxvars *cub)
{
	double tex_pos;

	tex_pos = (cub->ray.draw_start - DEF_WINDOW_SIZE_H / 2 + cub->ray.lh / 2) * cub->ray.step;
	if (cub->ray.side == 1)
	{
		if (cub->ray.ray_dir_y > 0)
			cub->ray.color = set_pixel_color(0x0000FF, cub, tex_pos, cub->ray.picked_img);
		else
			cub->ray.color = set_pixel_color(0xFFD700, cub, tex_pos, cub->ray.picked_img);
	}
	else
	{
		// printf("aaa%f\n", cub->ray.ray_dir_x);
		if (cub->ray.ray_dir_x > 0)
			cub->ray.color = set_pixel_color(0x7CFC00, cub, tex_pos, cub->ray.picked_img);
		else
			cub->ray.color = set_pixel_color(0x1ABC9C, cub, tex_pos, cub->ray.picked_img);
	}
}

static double	where_wall_hit(int face, t_mlxvars *cub)
{
	double	hit_x;

	hit_x = 0;
	if (face == 0xFFD700 || face == 0x0000FF)
		hit_x = cub->pos.y + cub->ray.tot_dist * cub->ray.ray_dir_x;
	else
		hit_x = cub->pos.x + cub->ray.tot_dist * cub->ray.ray_dir_y;
	hit_x -= floor(hit_x);
	return (hit_x);
}

static int	where_x_on_texture(int face, t_mlxvars *cub, double wall_x)
{
	int	texture_x;

	texture_x = (int)(wall_x * (double)cub->img.width);
	(void)face;
	return (texture_x);
}

static int	get_pixel(t_mlxvars *cub, char *img, int x, int y)
{
	printf("%d %d %d %d\n", y, cub->img.ray_lb, x, cub->img.ray_bpp);
	return (*(int *)
	(img + 
	(y * cub->img.ray_lb + x * 
	(cub->img.ray_bpp / 8))));
}

int set_pixel_color(int face, t_mlxvars *cub, double tex_pos, char *img)
{
	double	wall_x;
	int	texture_x;
	int	color;

	wall_x = where_wall_hit(face, cub);
	texture_x = where_x_on_texture(face, cub, wall_x);
	color = (get_pixel(cub, img, texture_x, (int) tex_pos & (cub->img.width - 1)));
	printf("aaaa%d\n", color);
	getchar();
	return (color);
}
