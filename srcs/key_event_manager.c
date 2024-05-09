/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 20:23:51 by lhojoon           #+#    #+#             */
/*   Updated: 2024/05/08 18:45:00 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

double	radian_value_normalize(double var)
{
	if (var > 2 * M_PI)
		var -= 2 * M_PI;
	else if (var < 0)
		var += 2 * M_PI;
	return (var);
}

static void	move_character(t_mlxvars *vars, int key)
{
	if (key == DEF_KEY_W)
	{
		vars->player->pos.y -= sin(vars->player->angle) * DEF_PLAYER_MOVE_SPD;
		vars->player->pos.x -= cos(vars->player->angle) * DEF_PLAYER_MOVE_SPD;
	}
	else if (key == DEF_KEY_S)
	{
		vars->player->pos.y += sin(vars->player->angle) * DEF_PLAYER_MOVE_SPD;
		vars->player->pos.x += cos(vars->player->angle) * DEF_PLAYER_MOVE_SPD;
	}
	else if (key == DEF_KEY_A) // TODO : faut changer la direction qui est inverse
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
	vars->player->angle = radian_value_normalize(vars->player->angle);
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
	printf("Player pos : %f %f , angle : %f\n", p->player->pos.x, p->player->pos.y, p->player->angle * (180 / M_PI));
	return (0);
}
