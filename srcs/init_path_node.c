/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_path_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:20:39 by lhojoon           #+#    #+#             */
/*   Updated: 2023/11/26 18:15:18 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_path_node	init_path_node(void)
{
	t_path_node	node;

	node.dist_e = 0;
	node.dist_s = 0.0;
	node.pos = get_init_pos_ptr();
	return (node);
}

t_path_node	*init_path_node_value_ptr(size_t e, double s, t_pos *pos, bool went)
{
	t_path_node	*node;

	node = (t_path_node *)malloc(sizeof(t_path_node));
	node->dist_e = e;
	node->dist_s = s;
	node->pos = get_init_pos_ptr_value(pos->x, pos->y);
	node->went = went;
	return (node);
}
