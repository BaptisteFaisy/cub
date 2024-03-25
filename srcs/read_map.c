/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:15:22 by lhojoon           #+#    #+#             */
/*   Updated: 2024/03/25 20:11:48 by lhojoon          ###   ########.fr       */
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

static void	fill_datas(t_map_data *dat, t_list *val)
{
	int	i;

	dat->pref = (char **)malloc(sizeof(char *) * 6);
	if (!dat->pref)
		return ;
	i = 0;
	while (val)
	{
		if (ft_strncmp(*(const char *)val->content, "\n", 1))
		{
			val = val->next;
			continue ;
		}
		dat->pref[i] = ft_strdup(val->content);
		i++;
		val = val->next;
	}
	dat->map = (char **)malloc(sizeof(char *) * ft_lstsize(val) + 1);
	if (!dat->map)
		return ;
	i = 0;
	while (val)
	{
		dat->map[i] = 
		val = val->next;
	}
}

t_map_data	read_map(char *filename)
{
	t_list		*map_value;
	t_map_data	map_data;

	map_value = get_read_map(filename);
	if (!map_value)
		return ((t_map_data){.map = NULL, .pref = NULL});
}
