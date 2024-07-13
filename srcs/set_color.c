/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 21:59:38 by lhojoon           #+#    #+#             */
/*   Updated: 2024/07/13 18:36:21 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

bool	set_color(t_mlxvars *var)
{
	int		r;
	int		g;
	int		b;
	char	**val;
	int		i;

	i = 0;
	while (i < 2)
	{
		val = ft_split(var->map_data->pref[4 + i], ',');
		if (!val)
			return (false);
		r = ft_atoi(val[0] + 2);
		g = ft_atoi(val[1]);
		b = ft_atoi(val[2]);
		var->colors[i] = mlx_rgb_to_int(0, r, g, b);
		ft_freesplit(val);
		i++;
	}
	return (true);
}
