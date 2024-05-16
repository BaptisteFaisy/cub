/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_pipeline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:02:57 by lhojoon           #+#    #+#             */
/*   Updated: 2024/05/17 01:00:30 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static bool	maps_pipeline(t_mlxvars *vars)
{
	if (!verifie_cub(vars->map_filename))
		return (ft_printf("Error: file is not .cub\n"), false);
	vars->map_data = read_map(vars->map_filename);
	if (!vars->map_data)
		return (ft_printf("map_data : "), false);
	if (!mapcheck_main(vars->map_data))
		return (ft_printf(DEF_MAPCHECK_MAIN_ERR), false);
	if (!stock_image(vars))
		return (ft_printf("stock_image : "), false);
	return (true);
}

static bool	hook_pipeline(t_mlxvars *vars)
{
	mlx_hook(vars->mlx_win, KeyPress, KeyPressMask, key_event_manager, vars);
	mlx_hook(vars->mlx_win, DestroyNotify, StructureNotifyMask,
		x11_destroy_event, vars);
	return (true);
}

static bool	mlx_var_init_pipeline(t_mlxvars *vars)
{
	vars->mlx_win = mlx_new_window(vars->mlx, DEF_WINDOW_SIZE_W,
			DEF_WINDOW_SIZE_H, DEF_PROGRAM_NAME);
	vars->canvas = mlx_new_image(vars->mlx,
			DEF_WINDOW_SIZE_W, DEF_WINDOW_SIZE_H);
	if (!vars->mlx_win || !vars->canvas)
		return (ft_printf("mlx_new_* : "), false);
	if (!parse_user_pos(vars))
		return (ft_printf("parse_user_pos : "), false);
	return (true);
}

static void	init_draw(t_mlxvars *vars)
{
	draw_screen(vars);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->canvas, 0, 0);
}

bool	mlx_pipeline(t_mlxvars *vars)
{
	if (maps_pipeline(vars) == false)
		return (ft_printf("Interrupt : maps_pipeline\n"), false);
	if (mlx_var_init_pipeline(vars) == false)
		return (ft_printf("Interrupt : mlx_win_pipeline\n"), false);
	if (hook_pipeline(vars) == false)
		return (ft_printf("Interrupt : hook_pipeline\n"), false);
	init_draw(vars);
	mlx_loop(vars->mlx);
	return (true);
}
