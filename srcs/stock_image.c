/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaisy <bfaisy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 14:26:57 by lhojoon           #+#    #+#             */
/*   Updated: 2024/07/13 17:29:28 by bfaisy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

bool	stock_image(t_mlxvars *vars)
{
	bool	ret;
	int		i;

	ret = true;
	i = 0;
	while (i <= EAST)
	{
		ret &= register_image(vars,
				get_new_sprite_image_ptr(vars, vars->map_data->pref[i] + 4));
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
