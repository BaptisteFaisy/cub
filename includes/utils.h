/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:23:21 by lhojoon           #+#    #+#             */
/*   Updated: 2023/11/25 16:53:08 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "so_long.h"

t_list			*ft_lstget_idx(t_list *lst, size_t idx);
void			ft_dellast(t_list **lst, void (*del)(void *));
t_list			*ft_lstchr(t_list *lst, bool(*chr)(void *, void *), void *dat);
void			ft_lstadd_sort(t_list **lst,
					t_list *new, bool(*f)(void *, void *));
void			ft_lstsort(t_list *lst, bool(*f)(void *, void *));
unsigned int	mlx_get_pixel(t_mlximage *img, int x, int y);
unsigned int	mlx_rgb_to_int(int o, int r, int g, int b);
void			mlx_draw_pixel(t_mlximage *mlx_img, int x, int y, int color);

#endif