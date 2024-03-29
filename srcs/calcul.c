/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaisy <bfaisy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 13:54:34 by bfaisy            #+#    #+#             */
/*   Updated: 2024/03/29 17:50:24 by bfaisy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// calculer avec pythagore la distance en prenant l'angle en compte
// https://youtu.be/xZe0ZYPzxkg?t=264
// https://medium.com/@afatir.ahmedfatir/cub3d-tutorial-af5dd31d2fcf

#include "../includes/cub.h"

static t_data	calcul_distance(t_pos pos_initial, t_data data, int x_final,
					int y_final);
// int	distance_mur_positif(int nbr_angle, t_pos pos, char **map)
// {
// 	int xarrondir, yarrondir;
// 	yarrondir = ceil(pos.y) - pos.y;
// 	xarrondir = ceil(pos.x) - pos.x;

// 	int i = 0;
// 	t_pos x, y;
// 	x.x = pos.x;
// 	y.y = pos.y;
// 	while (/* condition */)
// 	{
// 		x.y = angle * (x.x + xarrondir + i);
// 		y.x = (y.y + yarrondir + i) / angle;
// 		if (distance(x) < distance(y))
// 			// utilise x
// 		else
// 			// utilise y
// 	}
// }

char	find_direction(double angle_base, double angle)
{
	angle_base += angle;
	if (angle_base >= 360)
		angle_base -= 360;
	if (angle_base >= 0 && angle_base < 90)
		return ('E');
	else if (angle_base >= 90 && angle_base < 180)
		return ('N');
	else if (angle_base >= 180 && angle_base < 270)
		return ('W');
	else if (angle_base >= 270 && angle_base < 360)
		return ('S');
}

double	add_base_angle(double angle_add, double angle_base)
{
	double	angle;

	angle_base += angle;
	if (angle_base >= 360)
		angle_base -= 360;
	return (angle_base);
}

t_data	distance_mur_positif(int angle, t_pos pos, char **map,
	double angle_base)
{
	t_pos	inter;
	t_pos	arrondie;
	t_pos	base;
	t_data	data;

	arrondie.y = ceil(pos.y) - pos.y;
	arrondie.x = ceil(pos.x) - pos.x;
	data.dir = find_direction(angle_base, angle);
	angle = tan(angle);
	inter.x = pos.x + arrondie.x;
	inter.y = pos.y + arrondie.y;
	data.degre = angle;
	while (true)
	{
		base.y = inter.x * angle;
		base.x = inter.y / angle;
		if (base.x < inter.x)
			if (check_wall(base.y, inter.x, map) == true)
				return (calcul_distance(pos, data, inter.x, base.y));
		else
			if (check_wall(inter.y, base.x, map) == true)
				return (calcul_distance(pos, data, base.x, inter.y));
		inter.x += 1;
		inter.x += 1;
	}
}

bool	check_wall(int y, int x, char **map)
{
	if (map[y][x] == '1')
		return (true);
	return (false);
}

static t_data	calcul_distance(t_pos pos_initial, t_data data, int x_final,
	int y_final)
{	
	data.distance = sqrt(pow((x_final - pos_initial.x), 2)
			+ pow((y_final - pos_initial.y), 2));
	return (data);
}
