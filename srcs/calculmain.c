/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculmain.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaisy <bfaisy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 11:51:20 by bfaisy            #+#    #+#             */
/*   Updated: 2024/03/28 13:54:29 by bfaisy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	get_pos(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N')
				return (90);
			else if (map[i][j] == 'W')
				return (180);
			else if (map[i][j] == 'S')
				return (270);
			else if (map[i][j] == 'E')
				return (0);
			j++;
		}
		i++;
	}
	return (-2);
}

int	fov_main(int direction_player)
{
	double	angle;
	double	dir_fov;
	int		nbr_angle;

	nbr_angle = 0;
	dir_fov = -45;
	while (nbr_angle != 960)
	{
		angle = dir_fov + (nbr_angle * 0.046875);
		nbr_angle++;
	}
}
