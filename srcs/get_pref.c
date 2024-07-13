/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pref.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 15:43:34 by lhojoon           #+#    #+#             */
/*   Updated: 2024/07/13 16:12:05 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

char	**get_pref(t_tab *head)
{
	char	**pref;
	t_tab	*prev;

	prev = head;
	head = head->next;
	free(prev);
	pref = (char **)malloc(sizeof(char **) * 8);
	if (!pref)
		return (NULL);
	while (head)
	{
		if (ft_strncmp(head->str, "NO", 2) == 0)
			pref[0] = head->str;
		else if (ft_strncmp(head->str, "SO", 2) == 0)
			pref[1] = head->str;
		else if (ft_strncmp(head->str, "WE", 2) == 0)
			pref[2] = head->str;
		else if (ft_strncmp(head->str, "EA", 2) == 0)
			pref[3] = head->str;
		else if (ft_strncmp(head->str, "F", 1) == 0)
			pref[4] = head->str;
		else if (ft_strncmp(head->str, "C", 1) == 0)
			pref[5] = head->str;
		prev = head;
		head = head->next;
		free(prev);
	}
	pref[6] = NULL;
	return (pref);
}
