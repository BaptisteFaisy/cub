/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x11_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:37:02 by lhojoon           #+#    #+#             */
/*   Updated: 2023/11/21 15:37:51 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"

int	x11_destroy_event(t_mlxvars *vars)
{
	if (free_mlx(vars) == false)
		exit(EXIT_FAILURE);
	else
		exit(EXIT_SUCCESS);
	return (0);
}
