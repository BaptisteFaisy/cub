/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 20:23:51 by lhojoon           #+#    #+#             */
/*   Updated: 2024/05/16 23:35:24 by lhojoon          ###   ########.fr       */
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

static bool	is_in_map(t_mlxvars *var, t_posd pos)
{
	t_posd	p1;
	t_posd	p2;
	int		x;

	x = DEF_WINDOW_SIZE_W / 2;
	p1.x = pos.x + sin(var->player->angle) * DEF_FOV_COEFF * -x;
	p1.y = pos.y + cos(var->player->angle) * DEF_FOV_COEFF * -x;
	p2.x = pos.x + sin(var->player->angle) * DEF_FOV_COEFF * x;
	p2.y = pos.y + cos(var->player->angle) * DEF_FOV_COEFF * x;
	// printf("p1 : %f %f || %d %d\n", p1.x, p1.y, foc(true, var->player->angle, p1.x), foc(false, var->player->angle, p1.y));
	// printf("p2 : %f %f || %d %d\n", p2.x, p2.y, foc(true, var->player->angle, p2.x), foc(false, var->player->angle, p2.y));
	if (var->map_data->map[foc(false, var->player->angle, p1.y)][foc(true, var->player->angle, p1.x)] == '1'
		|| var->map_data->map[foc(false, var->player->angle, p2.y)][foc(true, var->player->angle, p2.x)] == '1'
		|| var->map_data->map[foc(false, var->player->angle, pos.y)][foc(true, var->player->angle, pos.x)] == '1')
		return (false);
	// if (var->map_data->map[foc(false, var->player->angle, pos.y)][foc(true, var->player->angle, pos.x)] == '1')
	// 	return (false);
	return (true);
}

static void	move_character(t_mlxvars *vars, int key)
{
	t_posd	pos;

	pos.x = vars->player->pos.x;
	pos.y = vars->player->pos.y;
	if (key == DEF_KEY_W)
	{
		pos.y -= sin(vars->player->angle) * DEF_PLAYER_MOVE_SPD;
		pos.x += cos(vars->player->angle) * DEF_PLAYER_MOVE_SPD;
	}
	else if (key == DEF_KEY_S)
	{
		pos.y += sin(vars->player->angle) * DEF_PLAYER_MOVE_SPD;
		pos.x -= cos(vars->player->angle) * DEF_PLAYER_MOVE_SPD;
	}
	else if (key == DEF_KEY_A)
	{
		pos.y -= cos(vars->player->angle) * DEF_PLAYER_MOVE_SPD;
		pos.x -= sin(vars->player->angle) * DEF_PLAYER_MOVE_SPD;
	}
	else if (key == DEF_KEY_D)
	{
		pos.y += cos(vars->player->angle) * DEF_PLAYER_MOVE_SPD;
		pos.x += sin(vars->player->angle) * DEF_PLAYER_MOVE_SPD;
	}
	else if (key == DEF_KEY_LEFT)
		vars->player->angle += DEF_PLAYER_ROTATE_SPD * M_PI;
	else if (key == DEF_KEY_RIGHT)
		vars->player->angle -= DEF_PLAYER_ROTATE_SPD * M_PI;
	if (is_in_map(vars, pos) == true)
	{
		vars->player->pos.x = pos.x;
		vars->player->pos.y = pos.y;
	}
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
