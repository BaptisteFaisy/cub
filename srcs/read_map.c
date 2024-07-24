/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:15:22 by lhojoon           #+#    #+#             */
/*   Updated: 2024/07/24 16:16:08 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	*clear_and_close(int fd, t_list **lst)
{
	close(fd);
	ft_lstclear(lst, free);
	return (NULL);
}

/**
 * @brief
 * Import map with get_next_line
 * 
 * @return
 * NULL When error (malloc safe)
 * t_list<char *> when success
*/
static t_list	*get_read_map(char *filename)
{
	t_list	*read_value;
	int		fd;
	char	*s;
	t_list	*tmplst;

	fd = open(filename, O_DIRECTORY);
	if (fd != -1)
		return (close(fd), NULL);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	s = get_next_line(fd);
	read_value = NULL;
	while (s)
	{
		tmplst = ft_lstnew(s);
		if (!tmplst)
			return (clear_and_close(fd, &read_value));
		ft_lstadd_back(&read_value, tmplst);
		s = get_next_line(fd);
	}
	close(fd);
	return (read_value);
}

// static bool	fill_datas(t_map_data *dat, t_list *val)
// {
// 	// int	i;

// 	// dat->pref = (char **)malloc(sizeof(char *) * 8);
// 	// if (!dat->pref)
// 	// 	return (false);
// 	// i = 0;
// 	// while (val && i <= 6)
// 	// {
// 	// 	if (ft_strncmp((const char *)val->content, "\n", 1) == 0)
// 	// 	{
// 	// 		val = val->next;
// 	// 		dat->pref[i] = (char *)malloc(sizeof(char));
// 	// 		if (dat->pref[i] == NULL)
// 	// 			return (free(dat->pref), false);
// 	// 		dat->pref[i++][0] = '\0';
// 	// 		continue ;
// 	// 	}
// 	// 	((char *)val->content)[ft_strlen(val->content) - 1] = '\0';
// 	// 	dat->pref[i++] = ft_strdup(val->content);
// 	// 	val = val->next;
// 	// }
// 	// dat->pref[i] = NULL;
// 	if (!fill_map_data(dat, val))
// 		return (ft_lstclear(&val, free), free(dat->pref), false);
// 	return (true);
// }

static bool	nomralize_map(char **map)
{
	int		len;
	char	*s;
	int		i;

	len = get_longest_line(map);
	i = 0;
	while (map[i])
	{
		s = map[i];
		map[i] = ft_calloc(sizeof(char), len + 1);
		ft_strlcpy(map[i], s, ft_strlen(s));
		free(s);
		i++;
	}
	return (true);
}

t_map_data	*read_map(char *filename)
{
	t_list		*map_value;
	t_map_data	*map_data;

	map_data = (t_map_data *)malloc(sizeof(t_map_data));
	if (!map_data)
		return (NULL);
	map_value = get_read_map(filename);
	if (!map_value)
		return (free(map_data), NULL);
	init_map_data(map_data);
	if (get_map(map_data, map_value) == false)
		return (ft_lstclear(&map_value, free), free(map_data), NULL);
	nomralize_map(map_data->map);
	if (!map_data->pref)
		return (ft_lstclear(&map_value, free), free(map_data), NULL);
	ft_lstclear(&map_value, free);
	return (map_data);
}
