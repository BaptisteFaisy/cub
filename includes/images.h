/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:08:02 by lhojoon           #+#    #+#             */
/*   Updated: 2024/03/27 18:50:11 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGES_H
# define IMAGES_H

# include "struct.h"

typedef enum e_sl_img_keys {
	SL_IMG_KEYS_BLANK = 0,
	SL_IMG_KEYS_WALL = 1,
}	t_sl_img_keys;

t_mlximage	*get_new_sprite_image_ptr(t_mlxvars *vars, char *path);
bool		register_image(t_mlxvars *vars, t_mlximage *img);
t_mlximage	*get_image_by_direction(t_mlxvars *vars, t_direction idx);

#endif