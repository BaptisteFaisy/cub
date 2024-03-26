/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_pipeline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaisy <bfaisy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:02:57 by lhojoon           #+#    #+#             */
/*   Updated: 2024/03/26 15:49:02 by bfaisy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static bool	maps_pipeline(t_mlxvars *vars)
{
	if (!verifie_cub(vars->map_filename))
		return (false);
	vars->map_data = read_map(vars->map_filename);
	if (!vars->map_data)
		return (false);
	if (!mapcheck_main(vars->map_data))
		return (false);
	return (true);
}

static bool	hook_pipeline(t_mlxvars *vars)
{
	mlx_key_hook(vars->mlx_win, key_event_manager, vars);
	mlx_hook(vars->mlx_win, DEF_X11_EVENT_DESTROY_NOTIFY,
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

static bool	mlx_win_pipeline(t_mlxvars *vars)
{
	vars->mlx_win = mlx_new_window(vars->mlx, DEF_WINDOW_SIZE_W,
			DEF_WINDOW_SIZE_H, DEF_PROGRAM_NAME);
	if (!vars->mlx_win)
		return (false);
	return (true);
}

// static void	init_draw(t_mlxvars *vars)
// {
// 	// draw_map(vars);
// 	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->canvas, 0, 0);
// }

bool	mlx_pipeline(t_mlxvars *vars)
{
	if (maps_pipeline(vars) == false)
		return (ft_printf("Interrupt : maps_pipeline\n"), false);
	if (mlx_win_pipeline(vars) == false)
		return (ft_printf("Interrupt : mlx_win_pipeline\n"), false);
	if (hook_pipeline(vars) == false)
		return (ft_printf("Interrupt : hook_pipeline\n"), false);
	if (img_pipeline(vars) == false)
		return (ft_printf("Interrupt : img_pipeline\n"), false);
	// init_draw(vars);
	mlx_loop(vars->mlx);
	return (true);
}
