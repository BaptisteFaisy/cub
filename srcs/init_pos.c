/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:25:26 by lhojoon           #+#    #+#             */
/*   Updated: 2024/03/26 15:36:01 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_pos	get_init_pos(void)
{
	t_pos	vars;

	vars.x = 0;
	vars.y = 0;
	return (vars);
}

t_pos	*get_init_pos_ptr(void)
{
	t_pos	*vars;

	vars = (t_pos *)malloc(sizeof(t_pos));
	if (!vars)
		return (NULL);
	vars->x = 0;
	vars->y = 0;
	return (vars);
}

t_pos	get_init_pos_value(int x, int y)
{
	t_pos	vars;

	vars.x = x;
	vars.y = y;
	return (vars);
}

t_pos	*get_init_pos_ptr_value(int x, int y)
{
	t_pos	*vars;

	vars = (t_pos *)malloc(sizeof(t_pos));
	if (!vars)
		return (NULL);
	vars->x = x;
	vars->y = y;
	return (vars);
}
