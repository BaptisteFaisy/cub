/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaisy <bfaisy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 20:23:51 by lhojoon           #+#    #+#             */
/*   Updated: 2024/05/14 19:29:54 by bfaisy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

double	radian_value_normalize(double var)
{
	if (var >= 2 * M_PI)
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
		vars->player->pos.x += cos(vars->player->angle) * DEF_PLAYER_MOVE_SPD;
	}
	else if (key == DEF_KEY_S)
	{
		vars->player->pos.y += sin(vars->player->angle) * DEF_PLAYER_MOVE_SPD;
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
	{
		vars->ray.old_dir_x = vars->ray.dir_x;
		vars->ray.dir_x = vars->ray.dir_x * cos(ROT)
			- vars->ray.dir_y * sin(ROT);
		vars->ray.dir_y = vars->ray.old_dir_x * sin(ROT)
			+ vars->ray.dir_y * cos(ROT);
		vars->ray.old_plane_x = vars->ray.plane_x;
		vars->ray.plane_x = vars->ray.plane_x * cos(ROT)
			- vars->ray.plane_y * sin(ROT);
		vars->ray.plane_y = vars->ray.old_plane_x * sin(ROT)
			+ vars->ray.plane_y * cos(ROT);
	}
	else if (key == DEF_KEY_RIGHT)
	{
		vars->ray.old_dir_x = vars->ray.dir_x;
		vars->ray.dir_x = vars->ray.dir_x * cos(-ROT)
			- vars->ray.dir_y * sin(-ROT);
		vars->ray.dir_y = vars->ray.old_dir_x * sin(-ROT)
			+ vars->ray.dir_y * cos(-ROT);
		vars->ray.old_plane_x = vars->ray.plane_x;
		vars->ray.plane_x = vars->ray.plane_x * cos(-ROT)
			- vars->ray.plane_y * sin(-ROT);
		vars->ray.plane_y = vars->ray.old_plane_x * sin(-ROT)
			+ vars->ray.plane_y * cos(-ROT);
	}
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
