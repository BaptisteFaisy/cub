/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 13:54:34 by bfaisy            #+#    #+#             */
/*   Updated: 2024/03/27 19:50:16 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// https://www.assistancescolaire.com/eleve/3e/maths/reviser-une-notion/calculer-la-longueur-d-un-cote-dans-un-triangle-rectangle-3mtr06

// calculer avec pythagore la distance en prenant l'angle en compte
// https://youtu.be/xZe0ZYPzxkg?t=264
// https://medium.com/@afatir.ahmedfatir/cub3d-tutorial-af5dd31d2fcf

#include "../includes/cub.h"

static t_data	calcul_distance(t_pos pos_initial, double x_final,
					double y_final, double angle);
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

t_data	distance_mur_positif(int nbr_angle, t_pos pos, char **map,
	int double_angle)
{
	t_pos	inter;
	t_pos	arrondie;
	int		y;
	int		x;
	double	angle;

	arrondie.y = ceil(pos.y) - pos.y;
	arrondie.x = ceil(pos.x) - pos.x;
	angle = double_angle + (nbr_angle * 0.046875);
	angle = tan(angle);
	inter.x = pos.x + arrondie.x;
	inter.y = pos.y + arrondie.y;
	while (true)
	{
		y = inter.x * angle;
		x = inter.y / angle;
		if (x < inter.x)
			if (check_wall(y, inter.x, map) == true)
				return (calcul_distance(pos, y, inter.x, angle));
		else
			if (check_wall(inter.y, x, map) == true)
				return (calcul_distance(pos, inter.y, x, angle));
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

static t_data	calcul_distance(t_pos pos_initial, double x_final,
		double y_final, double angle)
{	
	t_data	data;

	data.degre = angle;
	data.final.x = x_final;
	data.final.y = y_final;
	data.distance = sqrt(pow((x_final - pos_initial.x), 2)
			+ pow((y_final - pos_initial.y), 2));
	return (data);
}
