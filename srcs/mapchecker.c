/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapchecker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 19:22:23 by bfaisy            #+#    #+#             */
/*   Updated: 2024/03/26 15:36:01 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	checkmap_check_wall(char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == '0')
			{
				if (checkmap_x(tab, i, j) == 1 && checkmap_y(tab, j) == 1)
					return (1);
				else
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	checkmap_x(char **tab, int i, int j)
{
	while (tab[i][j])
	{
		if (tab[i][j] == '1' && tab[i][j + 1] == '\0')
			return (1);
		j++;
	}
	return (0);
}

int	checkmap_y(char **tab, int j)
{
	int	i;

	i = 0;
	while (tab[i][j] != '1' && tab[i][j] != '\0')
		i++;
	if (tab[i][j] == '\0')
		return (0);
	i++;
	while (tab[i][j] != '1' && tab[i][j] != '\0')
		i++;
	if (tab[i][j] == '\0')
		return (0);
	return (1);
}

int	verifie_cub(const char *string)
{
	int			len;
	const char	*extension;
	int			ext_len;

	len = ft_strlen(string);
	extension = ".cub";
	ext_len = ft_strlen(extension);

    if (len >= ext_len)
	{
        if (ft_strncmp(string + len - ext_len, extension, INTMAX_MAX) == 0)
            return 1;
    }
	return (0);
}

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
				&& tab[i][j] != ' ')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_double(char **tab)
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
				return (1);
			j++;
		}
		i++;
	}
	return (1);
}
