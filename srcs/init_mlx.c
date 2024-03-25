/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:56:00 by lhojoon           #+#    #+#             */
/*   Updated: 2024/03/25 19:18:42 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_mlxvars	get_init_mlxvars(void)
{
	t_mlxvars	vars;

	vars.mlx = NULL;
	vars.mlx_win = NULL;
	vars.imgs = NULL;
	vars.canvas = NULL;
	return (vars);
}

t_mlxvars	init_mlxvars(void)
{
	t_mlxvars	vars;

	vars = get_init_mlxvars();
	vars.mlx = mlx_init();
	if (!vars.mlx)
		exit(EXIT_FAILURE);
	return (vars);
}
