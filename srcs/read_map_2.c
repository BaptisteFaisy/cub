/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 20:12:38 by lhojoon           #+#    #+#             */
/*   Updated: 2024/03/25 20:14:56 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	get_longest_line(t_list *map)
{
	int		max;
	int		len;
	t_list	*tmp;

	max = 0;
	tmp = map;
	while (tmp)
	{
		len = ft_strlen(tmp->content);
		if (len > max)
			max = len;
		tmp = tmp->next;
	}
	return (max);
}
