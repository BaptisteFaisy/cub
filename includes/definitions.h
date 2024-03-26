/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   definitions.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:50:23 by lhojoon           #+#    #+#             */
/*   Updated: 2024/03/26 16:03:10 by bfaisy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINITIONS_H
# define DEFINITIONS_H
# include "struct.h"
# define DEF_WINDOW_SIZE_W 800
# define DEF_WINDOW_SIZE_H 600

# define DEF_MAX_WINDOW_SIZE_W 1920
# define DEF_MAX_WINDOW_SIZE_H 900

# define DEF_IMG_SIZE 32

# define DEF_PROGRAM_NAME "Cub3D"

# define DEF_MAP_BLANK '0'

# define DEF_KEY_ESC 0xFF1B
# define DEF_KEY_W 0x77
# define DEF_KEY_A 0x61
# define DEF_KEY_S 0x73
# define DEF_KEY_D 0x64
# define DEF_X11_EVENT_DESTROY_NOTIFY 17

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

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

#endif