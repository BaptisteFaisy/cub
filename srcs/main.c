/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:32:47 by lhojoon           #+#    #+#             */
/*   Updated: 2024/03/25 19:28:03 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_mlxvars	vars;

	(void)argc;
	(void)argv;
	vars = init_mlxvars();
	if (mlx_pipeline(&vars) == false)
	{
		ft_printf("Error\n");
		if (free_mlx(&vars) == false)
		{
			ft_printf("Error with free\n");
		}
		exit(EXIT_FAILURE);
	}
	return (0);
}
