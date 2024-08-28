/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 14:26:57 by lhojoon           #+#    #+#             */
/*   Updated: 2024/08/28 17:14:46 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	str_space_treat(char **s)
{
	while (**s == ' ')
		*s += 1;
}

bool	stock_image(t_mlxvars *vars)
{
	bool	ret;
	int		i;
	char	*s;

	ret = true;
	i = 0;
	while (i <= EAST)
	{
		s = vars->map_data->pref[i] + 3;
		printf("-> %s\n", s);
		str_space_treat(&s);
		ret &= register_image(vars,
				get_new_sprite_image_ptr(vars, s));
		if (!ret)
			return (img_lst_clear(&vars->imgs, vars), false);
		ret &= ((t_mlximage *)ft_lstget_idx(vars->imgs,
					i)->content)->width == DEF_IMG_SIZE;
		ret &= ((t_mlximage *)ft_lstget_idx(vars->imgs,
					i)->content)->height == DEF_IMG_SIZE;
		if (!ret)
			return (img_lst_clear(&vars->imgs, vars), false);
		i++;
	}
	if (!ret)
		return (false);
	return (true);
}
