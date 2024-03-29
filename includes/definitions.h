/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   definitions.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:50:23 by lhojoon           #+#    #+#             */
/*   Updated: 2024/03/29 16:23:55 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINITIONS_H
# define DEFINITIONS_H

# include "struct.h"

# define DEF_WINDOW_SIZE_W 1920
# define DEF_WINDOW_SIZE_H 1000

# define DEF_MAX_WINDOW_SIZE_W 1920
# define DEF_MAX_WINDOW_SIZE_H 900

# define DEF_IMG_SIZE 100

# define DEF_POV_ANGLE 90

# define DEF_PROGRAM_NAME "Cub3D"

# define DEF_MAP_BLANK '0'

# define DEF_KEY_ESC 0xFF1B
# define DEF_KEY_W 0x77
# define DEF_KEY_A 0x61
# define DEF_KEY_S 0x73
# define DEF_KEY_D 0x64
# define DEF_KEY_LEFT 0xFF51
# define DEF_KEY_RIGHT 0xFF53
# define DEF_X11_EVENT_DESTROY_NOTIFY 17

# define DEF_DISTANCE_COEFF 1
# define DEF_PLAYER_MOVE_SPD 0.06
# define DEF_PLAYER_ROTATE_SPD 0.03

int		verifie_cub(const char *string);
int		check_input(char **tab);
int		checkmap_y(char **tab, int j, int i);
int		checkmap_x(char **tab, int i, int j);
int		checkmap_check_wall(char **tab);
int		checklignev2(char **tab, int ligne, char *str, int i);
t_rgb	grepccolor(char **tab);
t_rgb	grepfloorcolor(char **tab);
int		checklignefc(char **tab);
int		checkligne(char **tab, int ligne);
int		checklignemain(char **tab);
int		mapcheck_main(t_map_data *data);
void	draw_screen(t_mlxvars *vars);
void	img_lst_clear(t_list **lst, t_mlxvars *vars);
bool	stock_image(t_mlxvars *vars);
bool	parse_user_pos(t_mlxvars *vars);

#endif