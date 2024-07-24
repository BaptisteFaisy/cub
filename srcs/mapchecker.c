/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapchecker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 19:22:23 by bfaisy            #+#    #+#             */
/*   Updated: 2024/07/24 15:47:08 by bfaisy           ###   ########.fr       */
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
					ft_printf("%d %d check_Wall\n ", i, j);
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
	t_i	cond;
	int	j2;

	cond.para = 0;
	cond.para1 = 0;
	j2 = j;
	while (tab[i][j])
	{
		if (tab[i][j] == '1')
		{
			cond.para = 1;
			break ;
		}
		j++;
	}
	if (tab[i][j] == ' ')
	{
		ft_printf("error : check_map_x\n");
		return (0);
	}
	return (check_xv2(j2, tab, i, cond));
}

static int	ft_strlenvertical(char **str, int ligne)
{
	int		i;
	int		nbr;

	i = 0;
	nbr = 0;
	(void)ligne;
	while (str[i])
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
	if (tab[0][j] != '1' && tab[0][j] != ' ' && tab[0][j] != '\0')
		return (ft_printf("error : 1"), 0);
	if (tab[0][j] == ' ')
	{
		while (tab[i2][j] != '1' && i2 != ft_strlenvertical(tab, j))
			i2++;
		if ((tab[i2][j] == '0' && tab[i2 + 1][j] == '\0') || tab[i][j] == '\0')
			return (ft_printf("error : 2"), 0);
	}
	while (tab[i][j] != '1' && i != ft_strlenvertical(tab, j)
		&& tab[i][j] != ' ')
		i++;
	if (tab[i][j] == ' ')
		return (ft_printf("error : 3"), 0);
	if ((tab[i][j] == '0' && tab[i + 1][j] == '\0') || tab[i][j] == '\0')
		return (ft_printf("error : 4"), 0);
	while (tab[i3--][j] != '1' && i3 != -1)
		if (tab[i3][0] == '\0' || tab[i3][j] == ' ' || tab[i3][j] == '\0' )
			return (ft_printf("error : 5"), 0);
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
