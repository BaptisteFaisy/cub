/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkermapmain.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 11:20:09 by bfaisy            #+#    #+#             */
/*   Updated: 2024/05/17 00:58:39 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

static int	check_double(char **tab);

int	mapcheck_main(t_map_data *data)
{
	if (!check_double(data->map) || !check_input(data->map)
		|| !checkmap_check_wall(data->map) || !checklignemain(data->pref)
		|| !checklignefc(data->pref))
		return (0);
	return (1);
}

static int	check_double(char **tab)
{
	int		i;
	int		j;
	bool	cond;

	cond = false;
	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if ((tab[i][j] == 'N' || tab[i][j] == 'S' || tab[i][j] == 'E'
				|| tab[i][j] == 'W') && cond == false)
				cond = true;
			else if ((tab[i][j] == 'N' || tab[i][j] == 'S' || tab[i][j] == 'E'
				|| tab[i][j] == 'W'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
