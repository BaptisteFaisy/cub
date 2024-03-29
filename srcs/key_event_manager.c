/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 20:23:51 by lhojoon           #+#    #+#             */
/*   Updated: 2024/03/29 15:57:17 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	move_character(t_mlxvars *vars, int key)
{
	if (key == DEF_KEY_W)
	{
		vars->player->pos.y += sin(vars->player->angle) * DEF_PLAYER_MOVE_SPD;
		vars->player->pos.x += cos(vars->player->angle) * DEF_PLAYER_MOVE_SPD;
	}
	else if (key == DEF_KEY_S)
	{
		vars->player->pos.y -= sin(vars->player->angle) * DEF_PLAYER_MOVE_SPD;
		vars->player->pos.x -= cos(vars->player->angle) * DEF_PLAYER_MOVE_SPD;
	}
	else if (key == DEF_KEY_A)
	{
		vars->player->pos.y -= cos(vars->player->angle) * DEF_PLAYER_MOVE_SPD;
		vars->player->pos.x -= sin(vars->player->angle) * DEF_PLAYER_MOVE_SPD;
	}
	else if (key == DEF_KEY_D)
	{
		vars->player->pos.y += cos(vars->player->angle) * DEF_PLAYER_MOVE_SPD;
		vars->player->pos.x += sin(vars->player->angle) * DEF_PLAYER_MOVE_SPD;
	}
	else if (key == DEF_KEY_LEFT)
		vars->player->angle += DEF_PLAYER_ROTATE_SPD * M_PI;
	else if (key == DEF_KEY_RIGHT)
		vars->player->angle -= DEF_PLAYER_ROTATE_SPD * M_PI;
}

int	key_event_manager(int key, t_mlxvars *p)
{
	if (key == DEF_KEY_ESC)
	{
		if (free_mlx(p) == false)
			exit(EXIT_FAILURE);
		else
			exit(EXIT_SUCCESS);
	}
	move_character(p, key);
	draw_screen(p);
	return (0);
}
