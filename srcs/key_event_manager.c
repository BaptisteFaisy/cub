/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 20:23:51 by lhojoon           #+#    #+#             */
/*   Updated: 2024/05/20 16:12:25 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

#ifdef DEF_CAMERA_CHECK_STRICT

static bool	is_in_map(t_mlxvars *var, t_posd pos, double angle)
{
	t_posd	p1;
	t_posd	p2;
	int		x;

	x = DEF_WINDOW_SIZE_W / 2;
	p1.x = pos.x + sin(angle) * DEF_FOV_COEFF * -x;
	p1.y = pos.y + cos(angle) * DEF_FOV_COEFF * -x;
	p2.x = pos.x + sin(angle) * DEF_FOV_COEFF * x;
	p2.y = pos.y + cos(angle) * DEF_FOV_COEFF * x;
	if (var->map_data->map[foc(false, angle, p1.y)]
		[foc(true, angle, p1.x)] == '1'
		|| var->map_data->map[foc(false, angle, p2.y)]
		[foc(true, angle, p2.x)] == '1'
		|| var->map_data->map[foc(false, angle, pos.y)]
		[foc(true, angle, pos.x)] == '1')
		return (false);
	return (true);
}

#else

static bool	is_in_map(t_mlxvars *var, t_posd pos, double angle)
{
	if (var->map_data->map[foc(false, angle, pos.y)]
		[foc(true, angle, pos.x)] == '1')
		return (false);
	return (true);
}

// static bool	is_in_map(t_mlxvars *var, t_posd pos, double angle)
// {
// 	// t_posd	p1;
// 	// t_posd	p2;

// 	if (var->map_data->map[foc(false, angle, pos.y)]
// 		[foc(true, angle, pos.x)] == '1')
// 		return (false);
// 	return (true);
// }

#endif

static void	move_character_add(t_posd *pos, double x, double y)
{
	pos->x += x * DEF_PLAYER_MOVE_SPD;
	pos->y += y * DEF_PLAYER_MOVE_SPD;
}

static void	move_character(t_mlxvars *vars, int key)
{
	t_posd	pos;
	double	angle;

	pos.x = vars->player->pos.x;
	pos.y = vars->player->pos.y;
	angle = vars->player->angle;
	if (key == DEF_KEY_W)
		move_character_add(&pos, cos(angle), -sin(angle));
	else if (key == DEF_KEY_S)
		move_character_add(&pos, -cos(angle), sin(angle));
	else if (key == DEF_KEY_A)
		move_character_add(&pos, -sin(angle), -cos(angle));
	else if (key == DEF_KEY_D)
		move_character_add(&pos, sin(angle), cos(angle));
	else if (key == DEF_KEY_LEFT)
		angle += DEF_PLAYER_ROTATE_SPD * M_PI;
	else if (key == DEF_KEY_RIGHT)
		angle -= DEF_PLAYER_ROTATE_SPD * M_PI;
	if (is_in_map(vars, pos, angle) == true)
	{
		vars->player->pos.x = pos.x;
		vars->player->pos.y = pos.y;
		vars->player->angle = radian_value_normalize(angle);
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
	return (0);
}
