/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 20:23:51 by lhojoon           #+#    #+#             */
/*   Updated: 2024/03/27 20:24:18 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "manager.h"

int	key_event_manager(int key, t_mlxvars *p)
{
	if (key == DEF_KEY_ESC)
	{
		if (free_mlx(p) == false)
			exit(EXIT_FAILURE);
		else
			exit(EXIT_SUCCESS);
	}
	// TODO : Finish this function
	// else if (key == DEF_KEY_W)
	// else if (key == DEF_KEY_A)
	// else if (key == DEF_KEY_S)
	// else if (key == DEF_KEY_D)
	// move character or rotate camera, and re-render
	return (0);
}
