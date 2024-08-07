/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_manager_ext1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaisy <bfaisy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:01:31 by lhojoon           #+#    #+#             */
/*   Updated: 2024/07/13 19:16:50 by bfaisy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_mlximage	*get_new_sprite_image_ptr(t_mlxvars *vars, char *path)
{
	t_mlximage	*img;
	int			x;
	int			y;

	img = mlx_xpm_file_to_image(vars->mlx,
			path, &x, &y);
	if (!img)
		return (NULL);
	img->width = x;
	img->height = y;
	return (img);
}

/**
 * Register image
*/
bool	register_image(t_mlxvars *vars, t_mlximage *img)
{
	if (!img)
		return (false);
	ft_lstadd_back(&vars->imgs, ft_lstnew(img));
	return (true);
}

t_mlximage	*get_image_by_direction(t_mlxvars *vars, t_direction idx)
{
	t_list	*item;

	item = ft_lstget_idx(vars->imgs, (size_t)idx);
	if (item == NULL)
		return (NULL);
	return (item->content);
}
