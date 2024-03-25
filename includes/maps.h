/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:14:53 by lhojoon           #+#    #+#             */
/*   Updated: 2024/03/25 19:30:26 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPS_H
# define MAPS_H

# include "struct.h"
# include <stdbool.h>

t_list	*read_map(char *filename);

typedef struct s_elements_map {
	bool	item;
	bool	exit;
	bool	person;
}	t_elements_map;

#endif