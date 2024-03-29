/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculmain.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaisy <bfaisy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 11:51:20 by bfaisy            #+#    #+#             */
/*   Updated: 2024/03/29 17:48:25 by bfaisy           ###   ########.fr       */
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
