/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checklignemain.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaisy <bfaisy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:14:37 by bfaisy            #+#    #+#             */
/*   Updated: 2024/07/13 19:01:04 by bfaisy           ###   ########.fr       */
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
		if (!checkligne(mer, i++, para, liste))
			return (free(para), 0);
	i = 0;
	while (mer[i])
		if (!checklignefc(mer, para, i++, liste))
			return (free(para), 0);
	i = 0;
	while (i != 6)
		if (para[i++] == 0)
			return (ft_printf("error 0 found\n"), 0);
	return (free(para), 1);
}
