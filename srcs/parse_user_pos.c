/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_user_pos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaisy <bfaisy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 14:38:52 by lhojoon           #+#    #+#             */
/*   Updated: 2024/05/17 02:42:45 by bfaisy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static bool	search_player_pos(int x, int y, char **map)
{
	if (map[y][x] == 'N' || map[y][x] == 'S'
		|| map[y][x] == 'E' || map[y][x] == 'W')
		return (true);
	return (false);
}

static double	get_user_angle(char c)
{
	if (c == 'N')
		return (M_PI / 2);
	if (c == 'S')
		return ((M_PI * 3) / 2);
	if (c == 'E')
		return (0);
	if (c == 'W')
		return (M_PI);
	return (M_PI / 2);
}

bool	parse_user_pos(t_mlxvars *vars)
{
	int			x;
	int			y;
	bool		found;

	x = 0;
	y = 0;
	found = false;
	while (found == false && vars->map_data->map[y] != NULL)
	{
		x = 0;
		while (found == false && vars->map_data->map[y][x] != '\0')
		{
			found = search_player_pos(x, y, vars->map_data->map);
			x++;
		}
		y++;
	}
	if (found == false)
		return (false);
	x--;
	y--;
	vars->player->pos.x = x + 0.5;
	vars->player->pos.y = y + 0.5;
	vars->player->angle = get_user_angle(vars->map_data->map[y][x]);
	return (true);
}
