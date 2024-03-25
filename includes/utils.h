/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:23:21 by lhojoon           #+#    #+#             */
/*   Updated: 2024/03/25 19:30:14 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "so_long.h"

unsigned int	mlx_get_pixel(t_mlximage *img, int x, int y);
unsigned int	mlx_rgb_to_int(int o, int r, int g, int b);
void			mlx_draw_pixel(t_mlximage *mlx_img, int x, int y, int color);

#endif