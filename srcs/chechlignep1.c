/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chechlignep1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaisy <bfaisy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:15:22 by bfaisy            #+#    #+#             */
/*   Updated: 2024/07/11 16:35:02 by bfaisy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

static int	checker_nbr(char **tab, int i, int ligne, bool cond);

int	checkligne(char **tab, int ligne, int *para)
{
	int		i;
	char	*str;
	int		j;

	i = 0;
	j = 0;
	str = malloc(sizeof(char) * ft_strlen(tab[ligne]) + 1);
	if (!str)
		return (0);
	if ((tab[ligne][0] == 'N' && tab[ligne][1] == 'O' && para[0] == 0))
		return (para[0] = 1, checklignev2(tab, ligne, str, i));
	if ((tab[ligne][0] == 'N' && tab[ligne][1] == 'O' && para[0] == 1))
		return (free(str), 0);
	if ((tab[ligne][0] == 'S' || tab[ligne][1] == 'O') && para[1] == 0)
		return (para[1] = 1, checklignev2(tab, ligne, str, i));
	if ((tab[ligne][0] == 'S' && tab[ligne][1] == 'O') && para[1] == 1)
		return (free(str), 0);
	if ((tab[ligne][0] == 'W' || tab[ligne][1] == 'E') && para[2] == 0)
		return (para[2] = 1, checklignev2(tab, ligne, str, i));
	if ((tab[ligne][0] == 'W' && tab[ligne][1] == 'E') && para[2] == 1)
		return (free(str), 0);
	if ((tab[ligne][0] == 'E' || tab[ligne][1] == 'A') && para[3] == 0)
	{
		printf("q\n");
		return (para[3] = 1, checklignev2(tab, ligne, str, i));}
	if ((tab[ligne][0] == 'E' && tab[ligne][1] == 'A') && para[3] == 1)
	{	
		return (free(str), 0);}
	else
		return (1);
}

int	checklignev2(char **tab, int ligne, char *str, int i)
{
	int	j;

	j = 0;
	while (tab[ligne][i] && tab[ligne][i] != '.')
		i++;
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
		return (free(str), 0);
	}
	close(i);
	i = open(str, O_DIRECTORY);
	if (i == -1)
		return (free(str), 1);
	close(i);
	ft_putstr_fd("Error : Directory found, file expected \n", 1);
	return (0);
}

int	checklignefc2(char **tab, int ligne)
{
	int	i;

	i = 2;
	i = checker_nbr(tab, i, ligne, false);
	if (i == 0)
		return (0);
	i = checker_nbr(tab, i, ligne, false);
	if (i == 0)
		return (0);
	i = checker_nbr(tab, i, ligne, true);
	if (i == 0)
		return (0);
	if (tab[ligne][i] != '\0')
		return (0);
	return (1);
}

int	checklignefc(char **tab, int *para, int ligne)
{
	int	i;

	i = 2;
	if (tab[ligne][0] == 'F' && para[4] == 0)
		para[4] = 1;
	else if (tab[ligne][0] == 'F' && para[4] == 1)
		return (0);
	else if (tab[ligne][0] == 'C' && para[5] == 0)
		para[5] = 1;
	else if (tab[ligne][0] == 'C' && para[5] == 1)
		return (0);
	else
		return (1);
	i = checker_nbr(tab, i, ligne, false);
	if (i == 0)
		return (0);
	i = checker_nbr(tab, i, ligne, false);
	if (i == 0)
		return (0);
	i = checker_nbr(tab, i, ligne, true);
	if (i == 0)
		return (0);
	if (tab[ligne][i] != '\0')
		return (0);
	return (checklignefc2(tab, ligne));
}

static int	checker_nbr(char **tab, int i, int ligne, bool cond)
{
	int	nbr;

	nbr = 0;
	while (tab[ligne][i] != ',' && ft_isdigit(tab[ligne][i]))
	{
		nbr = nbr * 10 + tab[ligne][i] - '0';
		i++;
	}
	if (tab[ligne][i] == 0 && cond == false)
		return (0);
	if (nbr < 0 || nbr > 256)
		return (0);
	if (cond == false)
		i++;
	return (i);
}
