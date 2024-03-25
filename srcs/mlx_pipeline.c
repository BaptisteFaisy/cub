/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_pipeline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:02:57 by lhojoon           #+#    #+#             */
/*   Updated: 2024/03/25 17:52:26 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	maps_pipeline(t_mlxvars *vars)
{
	return (true);
}

static bool	hook_pipeline(t_mlxvars *vars)
{
	mlx_key_hook(vars->mlx_win, key_event_manager, vars);
	mlx_hook(vars->mlx_win, SL_X11_EVENT_DESTROY_NOTIFY,
		0L, x11_destroy_event, vars);
	return (true);
}

static bool	img_pipeline(t_mlxvars *vars)
{
	if (!register_image(vars,
			get_new_sprite_image_ptr(vars, "./assets/blank.xpm")))
		return (false);
	if (!register_image(vars,
			get_new_sprite_image_ptr(vars, "./assets/wall.xpm")))
		return (false);
	if (!register_image(vars,
			get_new_sprite_image_ptr(vars, "./assets/item.xpm")))
		return (false);
	if (!register_image(vars,
			get_new_sprite_image_ptr(vars, "./assets/exit.xpm")))
		return (false);
	if (!register_image(vars,
			get_new_sprite_image_ptr(vars, "./assets/person.xpm")))
		return (false);
	return (true);
}

static void	init_draw(t_mlxvars *vars)
{
	draw_map(vars);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->canvas, 0, 0);
}

bool	mlx_pipeline(t_mlxvars *vars)
{
	if (maps_pipeline(vars) == false)
		return (false);
	if (hook_pipeline(vars) == false)
		return (false);
	if (img_pipeline(vars) == false)
		return (false);
	init_draw(vars);
	mlx_loop(vars->mlx);
	return (true);
}
