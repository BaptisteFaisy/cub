/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checklignemain.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaisy <bfaisy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:14:37 by bfaisy            #+#    #+#             */
/*   Updated: 2024/07/08 19:05:07 by bfaisy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	checklignemain(char **tab) // ici ca check
{
	int	*para;
	int	i;

	i = 0;
	para = malloc(sizeof(int) * 6);
	if (!para)
		exit (1);
	while (i != 6)
	{
		para[i] = 0;
		i++;
	}
	while (tab[i])
	{
		printf("a\n");
		if (!checkligne(tab, i, para) || !checklignefc(tab, para, i)) // checkligne marche pas
		{
			printf("a\n");
			return (0);
		}
		i++;
	}
	i = 0;
	while (i != 6)
	{
		if (para[i] == 0)
		{
			printf("error 0 found\n");
			return (0);
		}
		i++;
	}
	free(para);
	return (1);
}
