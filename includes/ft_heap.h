/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 01:31:20 by lhojoon           #+#    #+#             */
/*   Updated: 2023/11/23 14:08:13 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEAP_H
# define FT_HEAP_H

# include "so_long.h"

typedef struct s_heap {
	t_list	*lst;
	size_t	count;
}	t_heap;

t_heap	init_heap(void);
void	*pop_heap(t_heap *heap, bool (*eval)(void *, void *));
void	push_heap(t_heap *heap, void *value, bool (*eval)(void *, void *));

#endif