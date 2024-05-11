/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   definitions.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:50:23 by lhojoon           #+#    #+#             */
/*   Updated: 2024/05/11 15:30:21 by lhojoon          ###   ########.fr       */
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

# define DEF_DISTANCE_COEFF 0.01
# define DEF_PLAYER_MOVE_SPD 0.06
# define DEF_PLAYER_ROTATE_SPD 0.1
// # define DEF_PLAYER_ROTATE_SPD 0.5
# define DEF_FOV_COEFF 0.001

int				verifie_cub(const char *string);
int				check_input(char **tab);
int				checkmap_y(char **tab, int j, int i);
int				checkmap_x(char **tab, int i, int j);
int				checkmap_check_wall(char **tab);
int				checklignev2(char **tab, int ligne, char *str, int i);
t_rgb			grepccolor(char **tab);
t_rgb			grepfloorcolor(char **tab);
int				checklignefc(char **tab);
int				checkligne(char **tab, int ligne);
int				checklignemain(char **tab);
int				mapcheck_main(t_map_data *data);
char			find_direction(double angle_base, double angle);
void			draw_screen(t_mlxvars *vars);
void			img_lst_clear(t_list **lst, t_mlxvars *vars);
bool			stock_image(t_mlxvars *vars);
bool			parse_user_pos(t_mlxvars *vars);
// t_data			distance_mur_positif(double angle, t_posd pos, char **map,
// 					double angle_base);
void			fov_main(t_mlxvars *var);
t_direction		transform_direction_from_char(char c);
double			ceilexp(double v);
double			ceilexp_exceed(double v);
double			diff_abs(double v);
double			diff_abs_exceed(double v);
t_direction		get_direction_of_wall(float angle, bool is_x);
double			get_distance_of_wall(t_ray ray, t_posd origin);
double			get_percentage_of_wall(double v);
double			floorexp(double v);
double			floorexp_exceed(double v);
double			wall_get_ray_pos_x(double v, double angle);
double			wall_get_ray_pos_y(double v, double angle);
double			diff_abs_exceed_angle(double v, bool is_x, double angle, t_posd pos);
double			wall_get_correspondant_pos_x(double v, double angle);
double			wall_get_correspondant_pos_y(double v, double angle);
bool			fcmp(double v1, double v2);
double			positive_dist(double v);
double			negative_dist(double v);


#endif