/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaisy <bfaisy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 13:54:34 by bfaisy            #+#    #+#             */
/*   Updated: 2024/04/26 17:24:30 by bfaisy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// calculer avec pythagore la distance en prenant l'angle en compte
// https://youtu.be/xZe0ZYPzxkg?t=264
// https://medium.com/@afatir.ahmedfatir/cub3d-tutorial-af5dd31d2fcf

#include "../includes/cub.h"

bool			check_wall(int y, int x, char **map);
static t_data	calcul_distance(t_posd pos_initial, t_data data, double x_final,
					double y_final);
int				transform_int_with_dir(t_data data, int cond, int pos, int nbr_angle);
// int	distance_mur_positif(int nbr_angle, t_posd pos, char **map)
// {
// 	int xarrondir, yarrondir;
// 	yarrondir = ceil(pos.y) - pos.y;
// 	xarrondir = ceil(pos.x) - pos.x;

// 	int i = 0;
// 	t_posd x, y;
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
	return ('\0');
}

// double	add_base_angle(double angle_add, double angle_base)
// {
// 	angle_base += angle_add;
// 	if (angle_base >= 360)
// 		angle_base -= 360;
// 	else if (angle_add < 0)
// 		angle_base += 360;
// 	return (angle_base);
// }
t_data	distance_mur_positif(double angle, t_posd pos, char **map,
	double angle_base, int nbr_angle)
{
	t_posd	inter;
	t_posd	base;
	t_data	data;

	data.dir = find_direction(angle_base / M_PI * 180, angle);
	inter.x = transform_int_with_dir(data, 1, pos.x, nbr_angle);
	inter.y = transform_int_with_dir(data, 0, pos.y, nbr_angle);
	data.degre = angle;
	if (angle == 0.0000)
		return (data);
	base.x = inter.y / angle;
	base.y = inter.x * angle;
	printf("%f\n", angle);
	while (1)
	{
		if (angle == 0)
			break ;
		base.x = inter.y * angle;
		if (base.x >= inter.x)
		{
			printf("%f %f fd\n", base.y , inter.x);
			if (check_wall((int)base.y, (int)inter.x, map) == true)
				return (calcul_distance(pos, data, inter.x, base.y));
		}
		else if (base.x < inter.x && inter.y != 0)
		{
			if (angle == 0)
				break ;
			base.y = inter.x * angle;
			printf("%f %f fdgdfgdfgd\n", base.y , inter.x);
			if (check_wall((int)inter.y, (int)base.x, map) == true)
				return (calcul_distance(pos, data, base.x, inter.y));
			if (nbr_angle >= 960 && data.dir != 'W' && data.dir != 'S')
				inter.y++;
			else if (data.dir != 'W' && data.dir != 'S')
				inter.y--;
			else if (nbr_angle >= 960)
				inter.y--;
			else
				inter.y++;
			continue ;
		}
		if (nbr_angle >= 960 && data.dir != 'N' && data.dir != 'W')
			inter.x++;
		else if (data.dir != 'W' && data.dir != 'N')
			inter.x--;
		else if (nbr_angle >= 960)
			inter.x--;
		else
			inter.x++;
	}
	return (data);
}

bool	check_wall(int y, int x, char **map)
{
	printf("%d %d fd\n", y , x);
	if (map[y][x] == '1')
		return (true);
	return (false);
}

static t_data	calcul_distance(t_posd pos_initial, t_data data, double x_final,
	double y_final)
{

	//mapX - posX + (1 - stepX) / 2) / rayDirX
	data.distance = sqrt(pow((x_final - pos_initial.x), 2)
			+ pow((y_final - pos_initial.y), 2));
			// printf("l9\n");
	return (data);
}

int	transform_int_with_dir(t_data data, int cond, int pos, int nbr_angle)
{
	printf("%d, %c\n", pos, data.dir);
	if (cond == 0)
	{
		if (nbr_angle >= 960 && data.dir != 'W' && data.dir != 'S')
			pos++;
		else if (data.dir != 'W' && data.dir != 'S')
			pos--;
		else if (nbr_angle >= 960)
			pos--;
		else
			pos++;
	}
	else
	{
		if (nbr_angle >= 960 && data.dir != 'N' && data.dir != 'W')
			pos++;
		else if (data.dir != 'W' && data.dir != 'N')
			pos--;
		else if (nbr_angle >= 960)
			pos--;
		else
			pos++;
	}
	return (pos);
}
