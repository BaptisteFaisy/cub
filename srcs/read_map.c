/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:15:22 by lhojoon           #+#    #+#             */
/*   Updated: 2024/03/25 19:20:10 by lhojoon          ###   ########.fr       */
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
 * Function : 
 * Import map with get_next_line
 * Verify equality of line length
 * Verify minimum length, height (3, 3)
 * 
 * 
 * Return:
 * NULL When error (malloc safe)
 * t_list<char *> when success
*/
t_list	*read_map(char *filename)
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
