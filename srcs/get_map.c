/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:51:37 by lhojoon           #+#    #+#             */
/*   Updated: 2024/07/24 16:06:36 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	put_datas_in_mem(t_map_data *dat, int *i, t_list *head, t_list *lst)
{
	dat->pref = get_map_pref(head, ft_lstsize(head) - ft_lstsize(lst));
	dat->map = (char **)malloc((ft_lstsize(lst) + 1) * sizeof(char *));
	i = 0;
	while (lst)
	{
		dat->map[*i] = ft_strdup((char *)lst->content);
		dat->map[*i][ft_strlen(dat->map[*i])] = 0;
		*i += 1;
		lst = lst->next;
	}
	dat->map[*i] = 0;
}

bool	get_map(t_map_data *dat, t_list *lst)
{
	size_t	i;
	size_t	j;
	t_list	*head;
	bool	is_1;

	is_1 = false;
	head = lst;
	while (lst != NULL)
	{
		j = 0;
		while (lst != NULL
			&& ((char *)lst->content)[j]
			&& ((char *)lst->content)[j] != '\n')
		{
			if (((char *)lst->content)[j] != '1'
				&& ((char *)lst->content)[j] != ' ')
			{
				lst = lst->next;
				j = 0;
				is_1 = false;
				continue ;
			}
			if (((char *)lst->content)[j] == '1')
				is_1 = true;
			j++ ;
		}
		if (is_1 == true)
			break ;
		if (lst)
			lst = lst->next;
	}
	put_datas_in_mem(dat, &i, head, lst);
	return (true);
}
