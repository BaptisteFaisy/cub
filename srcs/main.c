/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:32:47 by lhojoon           #+#    #+#             */
/*   Updated: 2024/03/26 15:36:27 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	main(int argc, char *argv[])
{
	t_mlxvars	vars;

	if (argc != 2)
	{
		ft_printf("Error - args invalid\n");
		exit(EXIT_FAILURE);
	}
	vars = init_mlxvars();
	vars.map_filename = argv[1];
	if (mlx_pipeline(&vars) == false)
	{
		ft_printf("Error : mlx_pipeline\n");
		if (free_mlx(&vars) == false)
			ft_printf("Free error : there might be some leaks !\n");
		exit(EXIT_FAILURE);
	}
	return (0);
}
