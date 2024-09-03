/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkermapmain.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaisy <bfaisy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 11:20:09 by bfaisy            #+#    #+#             */
/*   Updated: 2024/09/03 15:34:55 by bfaisy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

static int	check_double(char **tab);
static int	check_last(char **tab);
int			intrus(char *str);

int	mapcheck_main(t_map_data *data, t_tab *head)
{
	t_tab	*tmp;

	tmp = head;
	if (!check_double(data->map) || !check_input(data->map)
		|| !checkmap_check_wall(data->map) || !checklignemain(data->pref, tmp)
		|| !check_last(data->pref))
	{
		return (0);
	}
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
				return (ft_printf("double\n"), 0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	check_last(char **tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tab[i + 1] != NULL)
		i++;
	while (tab[i][j])
	{
		if (tab[i][j] != '1' && tab[i][j] != ' ' && tab[i][j] != '\n')
		{
			return (0);
		}
		j++;
	}
	i = -1;
	while (tab[++i])
		if (intrus(tab[i]))
			free(tab[i]);
	return (1);
}

int	intrus(char *str)
{
	if (str[0] == 'F' || str[0] == 'C' || (str[0] == 'N' && str[1] == 'O')
		|| (str[0] == 'S' && str[1] == 'O' ) || (str[0] == 'W' && str[1] == 'E')
		|| (str[0] == 'E' && str[1] == 'A'))
		return (0);
	return (1);
}
