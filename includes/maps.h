/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:14:53 by lhojoon           #+#    #+#             */
/*   Updated: 2023/11/26 22:56:29 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPS_H
# define MAPS_H

# include "struct.h"
# include <stdbool.h>

t_list	*read_map(char *filename);
bool	verify_wall_map(t_list *map);
bool	verify_elements_in_map(t_list *map);
bool	verify_path_map(t_mlxvars *vars);
t_pos	*get_object_pos_map(t_list *map, char element);
t_list	*get_object_pos_list_map(t_list *map, char element);
t_pos	get_offset_by_dir(t_direction dir);
void	user_move(t_mlxvars *vars, t_direction dir);

typedef struct s_elements_map {
	bool	item;
	bool	exit;
	bool	person;
}	t_elements_map;

#endif