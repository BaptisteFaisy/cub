/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checklignemain.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaisy <bfaisy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:14:37 by bfaisy            #+#    #+#             */
/*   Updated: 2024/07/13 16:03:51 by bfaisy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	checklignemain(char **mer, t_tab *head)
{
	int		*para;
	int		i;
	t_tab	*liste;

	i = 0;
	liste = head;
	para = malloc(sizeof(int) * 6);
	if (!para || !liste)
		exit (1);
	while (i != 6)
		para[i++] = 0;
	i = 0;
	while (i != 7) // ligne jusqu a check
	{
		if (!checkligne(mer, i, para, liste) || !checklignefc(mer, para, i, liste)) // checkligne marche
		{
			printf("ok\n");
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
	return (free(para), 1);
}
