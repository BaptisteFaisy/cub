/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checklignemain.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaisy <bfaisy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:14:37 by bfaisy            #+#    #+#             */
/*   Updated: 2024/03/26 16:14:15 by bfaisy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	checklignemain(char **tab)
{
	if (!checkligne(tab, 0) || !checkligne(tab, 1) || !checkligne(tab, 2)
		|| !checkligne(tab, 3))
		return (0);
	return (1);
}
