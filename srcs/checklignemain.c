/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checklignemain.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaisy <bfaisy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:14:37 by bfaisy            #+#    #+#             */
/*   Updated: 2024/07/13 17:26:37 by bfaisy           ###   ########.fr       */
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
	while (mer[i])
	{
		if (!checkligne(mer, i, para, liste)
			|| !checklignefc(mer, para, i, liste))
			return (printf("ok\n"), 0);
		i++;
	}
	i = 0;
	while (i != 6)
	{
		if (para[i] == 0)
			return (printf("error 0 found\n"), 0);
		i++;
	}
	return (free(para), 1);
}
