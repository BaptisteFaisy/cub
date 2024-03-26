/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:57:44 by lhojoon           #+#    #+#             */
/*   Updated: 2024/03/26 15:36:00 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MANAGER_H
# define MANAGER_H

# include "cub.h"

t_mlxvars	init_mlxvars(void);
bool		free_mlx(t_mlxvars *p);
bool		mlx_pipeline(t_mlxvars *vars);
int			key_event_manager(int key, t_mlxvars *p);

#endif