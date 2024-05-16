/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 20:12:38 by lhojoon           #+#    #+#             */
/*   Updated: 2024/05/17 00:57:35 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

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

static void	fill_map_data_ext(int i, char **map, int len)
{
	map[i] = ft_calloc(sizeof(char), len + 1);
	map[i + 1] = NULL;
}

bool	fill_map_data(t_map_data *dat, t_list *val)
{
	int		len;
	int		i;

	if (ft_strncmp(val->content, "\0", 1) == 0)
		return (false);
	else
		val = val->next;
	dat->map = (char **)malloc(sizeof(char *) * (ft_lstsize(val) + 2));
	if (!dat->map)
		return (false);
	i = 0;
	len = get_longest_line(val);
	while (val)
	{
		dat->map[i] = ft_calloc(sizeof(char), len + 1);
		if (!dat->map[i])
			return (false); // TODO : free existing map, dat->map
		((char *)val->content)[ft_strlen((char *)val->content) - 1] = '\0';
		ft_strlcpy(dat->map[i], (char *)val->content,
			ft_strlen((char *)val->content) + 1);
		val = val->next;
		i++;
	}
	return (fill_map_data_ext(i, dat->map, len), true);
}

void	init_map_data(t_map_data *dat)
{
	dat->map = NULL;
	dat->pref = NULL;
}
