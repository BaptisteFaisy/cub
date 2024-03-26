/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:15:22 by lhojoon           #+#    #+#             */
/*   Updated: 2024/03/26 15:00:34 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

static bool	fill_datas(t_map_data *dat, t_list *val)
{
	int	i;

	dat->pref = (char **)malloc(sizeof(char *) * 6);
	if (!dat->pref)
		return (false);
	i = 0;
	while (val)
	{
		if (ft_strncmp((const char *)val->content, "\n", 1))
		{
			val = val->next;
			continue ;
		}
		dat->pref[i] = ft_strdup(val->content);
		i++;
		val = val->next;
	}
	if (!fill_map_data(dat, val))
	{
		// TODO : Verify free data
		ft_lstclear(&val, free);
		free(dat->pref);
		return (false);
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
	if (!fill_datas(map_data, map_value))
		return (free(map_value), free(map_data), NULL);
	return (map_data);
}
