/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapchecker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 19:22:23 by bfaisy            #+#    #+#             */
/*   Updated: 2024/05/17 00:52:01 by lhojoon          ###   ########.fr       */
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
			if (tab[i][j] == '0' || tab[i][j] == 'N')
			{
				if (!(checkmap_x(tab, i, j) == 1 && checkmap_y(tab, j, i) == 1))
				{
					return (0);
				}
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
		if (tab[i][j] == '1')
			return (1);
		j++;
	}
	return (0);
}

static int	ft_strlenvertical(char **str, int ligne)
{
	int		i;
	int		nbr;

	i = 0;
	nbr = 0;
	while (str[i][ligne])
	{
		nbr++;
		i++;
	}
	return (nbr);
}

int	checkmap_y(char **tab, int j, int i)
{
	if (tab[0][j] != '1')
		return (0);
	while (tab[i][j] != '1' && i != ft_strlenvertical(tab, j))
		i++;
	if ((tab[i][j] == '0' && tab[i + 1][j] == '\0') || tab[i][j] == '\0')
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
			return (1);
	}
	return (0);
}
