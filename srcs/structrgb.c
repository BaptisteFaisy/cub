/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structrgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:39:24 by bfaisy            #+#    #+#             */
/*   Updated: 2024/03/26 15:36:01 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

t_rgb	grepfloorcolor(char **tab)
{
	t_rgb	f;
	int		nbr;
	int		i;

	nbr = 0;
	i = 2;
	while (tab[5][i] != ',' && tab[5][i])
		nbr = nbr * 10 + tab[5][i++] - '0';
	f.b = nbr;
	i++;
	nbr = 0;
	while (tab[5][i] != ',' && tab[5][i])
		nbr = nbr * 10 + tab[5][i++] - '0';
	i++;
	f.g = nbr;
	nbr = 0;
	while (tab[5][i] != ',' && tab[5][i])
		nbr = nbr * 10 + tab[5][i++] - '0';
	f.r = nbr;
	return (f);
}

t_rgb	grepccolor(char **tab)
{
	t_rgb	c;
	int		nbr;
	int		i;

	nbr = 0;
	i = 2;
	while (tab[5][i] != ',' && tab[5][i])
		nbr = nbr * 10 + tab[5][i++] - '0';
	c.b = nbr;
	i++;
	nbr = 0;
	while (tab[5][i] != ',' && tab[5][i])
		nbr = nbr * 10 + tab[5][i++] - '0';
	i++;
	c.g = nbr;
	nbr = 0;
	while (tab[5][i] != ',' && tab[5][i])
		nbr = nbr * 10 + tab[5][i++] - '0';
	c.r = nbr;
	return (c);
}
