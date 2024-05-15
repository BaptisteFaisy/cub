/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaisy <bfaisy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:57:44 by lhojoon           #+#    #+#             */
/*   Updated: 2024/05/15 17:46:34 by bfaisy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MANAGER_H
# define MANAGER_H

# include "cub.h"

t_mlxvars	*init_mlxvars(t_mlxvars	*vars);
bool		free_mlx(t_mlxvars *p);
bool		mlx_pipeline(t_mlxvars *vars);
int			key_event_manager(int key, t_mlxvars *p);

#endif