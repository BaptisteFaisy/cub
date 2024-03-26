/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chechlignep1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaisy <bfaisy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:15:22 by bfaisy            #+#    #+#             */
/*   Updated: 2024/03/26 20:23:24 by bfaisy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

static int	checker_nbr(char **tab, int i, int ligne, bool cond);

int	checkligne(char **tab, int ligne)
{
	int		i;
	char	*str;
	int		j;

	i = 0;
	j = 0;
	str = malloc(sizeof(char) * ft_strlen(tab[ligne]) + 1);
	if (!str)
		return (0);
	if ((tab[ligne][0] != 'N' || tab[ligne][1] != 'O') && ligne == 0)
		return (free(str), 0);
	else if ((tab[ligne][0] != 'S' || tab[ligne][1] != 'O') && ligne == 1)
		return (free(str), 0);
	else if ((tab[ligne][0] != 'W' || tab[ligne][1] != 'E') && ligne == 2)
		return (free(str), 0);
	else if ((tab[ligne][0] != 'E' || tab[ligne][1] != 'A') && ligne == 3)
		return (free(str), 0);
	while (tab[ligne][i] && tab[ligne][i] != '.')
		i++;
	if (!tab[ligne][i])
	{
		free(str);
		return (0);
	}
	return (checklignev2(tab, ligne, str, i));
}

int	checklignev2(char **tab, int ligne, char *str, int i)
{
	int	j;

	j = 0;
	while (tab[ligne][i])
	{
		str[j] = tab[ligne][i];
		i++;
		j++;
	}
	str[j] = '\0';
	i = open(str, O_RDONLY);
	if (i == -1)
	{
		ft_putstr_fd("Error : I can't open texture\n", 1);
		return (0);
	}
	close(i);
	i = open(str, O_DIRECTORY);
	if (i == -1)
		return (1);
	close(i);
	ft_putstr_fd("Error : Directory found, file expected \n", 1);
	free(str);
	return (0);
}

int	checklignefc(char **tab)
{
	int	i;

	i = 2;
	if (tab[5][0] != 'F' || tab[6][0] != 'C')
		return (0);
	i = checker_nbr(tab, i, 5, false);
	if (i == 0)
		return (0);
	i = checker_nbr(tab, i, 5, false);
	if (i == 0)
		return (0);
	i = checker_nbr(tab, i, 5, true);
	if (i == 0)
		return (0);
	i = 2;
	i = checker_nbr(tab, i, 6, false);
	if (i == 0)
		return (0);
	i = checker_nbr(tab, i, 6, false);
	if (i == 0)
		return (0);
	i = checker_nbr(tab, i, 6, true);
	if (i == 0)
		return (0);
	return (1);
}

static int	checker_nbr(char **tab, int i, int ligne, bool cond)
{
	int	nbr;

	nbr = 0;
	while (tab[ligne][i] != ',' && tab[ligne][i])
	{
		nbr = nbr * 10 + tab[ligne][i] - '0';
		i++;
	}
	if (tab[ligne][i] == 0 && cond == false)
		return (0);
	if (nbr < 0 || nbr > 256)
		return (0);
	i++;
	return (i);
}
