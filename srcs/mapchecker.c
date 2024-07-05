/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapchecker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaisy <bfaisy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 19:22:23 by bfaisy            #+#    #+#             */
/*   Updated: 2024/07/05 17:46:42 by bfaisy           ###   ########.fr       */
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
			if (tab[i][j] == '0' || tab[i][j] == 'N'
				|| tab[i][j] == 'W' || tab[i][j] == 'E' || tab[i][j] == 'S')
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
	bool	para;
	bool	para2;
	int		j2;

	para = 0;
	para2 = 0;
	j2 = j;
	while (tab[i][j])
	{
		if (tab[i][j] == '1')
			para = 1;
		j++;
	}
	while (j2 != -1)
	{
		if (tab[i][j2] == '1')
			para2 = 1;
		j2--;
	}
	if (para2 == 0 || para == 0)
	{
		return (0);
	}
	return (1);
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
	int	i2;
	int	i3;

	i2 = 0;
	i3 = i;
	if (tab[0][j] != '1' && tab[0][j] != ' ')
		return (0);
	if (tab[0][j] == ' ')
	{
		while (tab[i2][j] != '1' && i2 != ft_strlenvertical(tab, j))
			i2++;
		if ((tab[i2][j] == '0' && tab[i2 + 1][j] == '\0') || tab[i][j] == '\0')
			return (0);
	}
	while (tab[i][j] != '1' && i != ft_strlenvertical(tab, j))
		i++;
	if ((tab[i][j] == '0' && tab[i + 1][j] == '\0') || tab[i][j] == '\0')
		return (0);
	while (tab[i3--][j] != '1' && i3 != 0)
		if (tab[i3][j] == ' ' || tab[i3][j] == '\0')
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
