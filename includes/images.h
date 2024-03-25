/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:08:02 by lhojoon           #+#    #+#             */
/*   Updated: 2023/11/25 16:54:02 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGES_H
# define IMAGES_H

# include "struct.h"

typedef enum e_sl_img_keys {
	SL_IMG_KEYS_BLANK = 0,
	SL_IMG_KEYS_WALL = 1,
	SL_IMG_KEYS_ITEM = 2,
	SL_IMG_KEYS_EXIT = 3,
	SL_IMG_KEYS_PERSON = 4
}	t_sl_img_keys;

// t_mlximage	*get_init_image_ptr(void);
// t_mlximage	*get_init_image_ptr_value(t_mlxvars *vars, int w, int h);
t_mlximage	*get_new_sprite_image_ptr(t_mlxvars *vars, char *path);
bool		register_image(t_mlxvars *vars, t_mlximage *img);
t_mlximage	*get_image_by_key(t_mlxvars *vars, t_sl_img_keys idx);
void		draw_square(t_mlxvars *vars, t_mlximage *img, int x, int y);

#endif