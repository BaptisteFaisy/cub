/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:40:02 by lhojoon           #+#    #+#             */
/*   Updated: 2024/03/26 14:50:50 by lhojoon          ###   ########.fr       */
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
	return (0);
}
