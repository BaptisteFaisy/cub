/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaisy <bfaisy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:56:00 by lhojoon           #+#    #+#             */
/*   Updated: 2024/05/16 01:23:33 by bfaisy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_mlxvars	*get_init_mlxvars(t_mlxvars	*cub)
{
	cub->img.map = NULL;
	cub->img.north_texture = NULL;
	cub->img.south_texture = NULL;
	cub->img.west_texture = NULL;
	cub->img.east_texture = NULL;
	cub->img.floor_color = NULL;
	cub->img.sky_color = NULL;
	cub->img.north = NULL;
	cub->img.south = NULL;
	cub->img.west = NULL;
	cub->img.east = NULL;
	cub->img.img_floor = NULL;
	cub->img.img_sky = NULL;
	cub->img.width = 32;
	cub->img.height = 32;
	cub->img.size_map = 0;
	cub->img.endian = 0;
	cub->pos.orientation = '\0';
	cub->pos.x = -1;
	cub->pos.y = -1;
	cub->img.ray_bpp = 32;
	cub->img.ray_lb = 0;
	cub->img.ray_end = 0;
	cub->img.line_bytes = 7680;
	return (cub);
}

t_mlxvars	*init_mlxvars(t_mlxvars	*vars)
{
	get_init_mlxvars(vars);
	vars->mlx = mlx_init();
	// vars->player = get_init_player_ptr();
	if (!vars->mlx)
		exit(EXIT_FAILURE);
	return (vars);
}
