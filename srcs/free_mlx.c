/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 10:58:49 by lhojoon           #+#    #+#             */
/*   Updated: 2024/03/28 15:11:48 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	img_lst_clear(t_list **lst, t_mlxvars *vars)
{
	t_list	*lp;
	t_list	*lp2;

	if (!lst || !vars)
		return ;
	lp = *lst;
	while (lp)
	{
		mlx_destroy_image(vars->mlx, lp->content);
		lp2 = lp->next;
		free(lp);
		lp = lp2;
	}
	*lst = NULL;
}

static void	free_mlx_part2(t_mlxvars *p)
{
	if (p->player)
	{
		free(p->player);
		p->player = NULL;
	}
}

bool	free_mlx(t_mlxvars *p)
{
	if (p == NULL)
		return (false);
	if (p->canvas)
		mlx_destroy_image(p->mlx, p->canvas);
	if (p->imgs)
		img_lst_clear(&(p->imgs), p);
	if (p->mlx == NULL)
		return (false);
	if (p->mlx_win != NULL)
	{
		mlx_destroy_window(p->mlx, p->mlx_win);
		p->mlx_win = NULL;
	}
	mlx_destroy_display(p->mlx);
	free(p->mlx);
	p->mlx = NULL;
	if (p->map_data)
	{
		ft_freesplit(p->map_data->map);
		ft_freesplit(p->map_data->pref);
		free(p->map_data);
		p->map_data = NULL;
	}
	free_mlx_part2(p);
	return (true);
}
