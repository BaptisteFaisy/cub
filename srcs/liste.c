/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaisy <bfaisy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 16:23:03 by bfaisy            #+#    #+#             */
/*   Updated: 2024/07/13 17:30:42 by bfaisy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	create_next(t_tab *liste, char *str)
{
	t_tab	*next;

	next = malloc(sizeof(t_tab));
	if (!next)
		exit (1);
	liste->next = next;
	next->next = NULL;
	next->str = str;
}

void	init(t_tab *liste)
{
	liste->next = NULL;
	liste->str = NULL;
}

void	free_liste(t_tab *liste)
{
	t_tab	*tmp;

	printf("a\n");
	while (liste)
	{
		tmp = liste;
		liste = liste->next;
		free(tmp);
	}
	// free(tmp);
}

void	print_liste(t_tab *liste)
{
	while (liste)
	{
		printf("%s\n", liste->str);
		liste = liste->next;
	}
}
