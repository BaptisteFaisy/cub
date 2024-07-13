/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 20:12:38 by lhojoon           #+#    #+#             */
/*   Updated: 2024/07/13 19:46:30 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	get_longest_line(char **map)
{
	int		max;
	int		len;
	int		i;

	max = 0;
	i = 0;
	while (map[i])
	{
		len = ft_strlen(map[i]);
		if (len > max)
			max = len;
		i++;
	}
	return (max);
}

static void	fill_map_data_ext(int i, char **map, int len)
{
	map[i] = ft_calloc(sizeof(char), len + 1);
	map[i + 1] = NULL;
}

// bool	fill_map_data(t_map_data *dat, t_list *val)
// {
// 	int		len;
// 	int		i;

// 	if (ft_strncmp(val->content, "\0", 1) == 0)
// 		return (false);
// 	else
// 		val = val->next;
// 	dat->map = (char **)malloc(sizeof(char *) * (ft_lstsize(val) + 2));
// 	if (!dat->map)
// 		return (false);
// 	i = 0;
// 	len = get_longest_line(val);
// 	while (val)
// 	{
// 		dat->map[i] = ft_calloc(sizeof(char), len + 1);
// 		if (!dat->map[i])
// 			return (ft_freesplit(dat->map), false);
// 		((char *)val->content)[ft_strlen((char *)val->content) - 1] = '\0';
// 		ft_strlcpy(dat->map[i], (char *)val->content,
// 			ft_strlen((char *)val->content) + 1);
// 		val = val->next;
// 		i++;
// 	}
// 	return (fill_map_data_ext(i, dat->map, len), true);
// }

void	init_map_data(t_map_data *dat)
{
	dat->map = NULL;
	dat->pref = NULL;
}
