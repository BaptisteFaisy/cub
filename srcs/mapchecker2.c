/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapchecker2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaisy <bfaisy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 00:51:37 by lhojoon           #+#    #+#             */
/*   Updated: 2024/09/03 15:32:27 by bfaisy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	check_input(char **tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] != '0' && tab[i][j] != '1' && tab[i][j] != 'N'
				&& tab[i][j] != 'S' && tab[i][j] != 'E' && tab[i][j] != 'W'
				&& tab[i][j] != ' ' && tab[i][j] != '\n')
			{
				ft_printf("input\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_xv2(int j2, char **tab, int i, t_i cond)
{
	while (j2 != -1 && tab[i][j2] != ' ')
	{
		if (tab[i][j2] == '1')
		{
			cond.para1 = 1;
			break ;
		}
		if (tab[i][j2] == ' ')
			return (0);
		j2--;
	}
	if (j2 < 0)
		return (ft_printf("check_map_x1\n"), 0);
	if (tab[i][j2] == ' ')
		return (ft_printf("check_map_x2\n"), 0);
	if (cond.para1 == 0 || cond.para == 0)
		return (ft_printf("check_map_x3 %d %d \n", cond.para1, cond.para), 0);
	return (1);
}
