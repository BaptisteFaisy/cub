/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:14:53 by lhojoon           #+#    #+#             */
/*   Updated: 2024/03/26 14:37:09 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPS_H
# define MAPS_H

# include "struct.h"
# include <stdbool.h>

t_map_data	*read_map(char *filename);

typedef struct s_elements_map {
	bool	item;
	bool	exit;
	bool	person;
}	t_elements_map;

#endif