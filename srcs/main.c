/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaisy <bfaisy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:32:47 by lhojoon           #+#    #+#             */
/*   Updated: 2024/05/14 19:35:15 by bfaisy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"


void	set_dir(t_mlxvars *cub)
{
	if (cub->pos.orientation == 'W')
	{
		cub->ray.dir_x = 0;
		cub->ray.dir_y = -1;
		cub->ray.plane_x = -0.66;
		cub->ray.plane_y = 0;
	}
	if (cub->pos.orientation == 'S')
	{
		cub->ray.dir_x = 1;
		cub->ray.dir_y = 0;
		cub->ray.plane_x = 0;
		cub->ray.plane_y = -0.66;
	}
	if (cub->pos.orientation == 'N')
	{
		cub->ray.dir_x = -1;
		cub->ray.dir_y = 0;
		cub->ray.plane_x = 0;
		cub->ray.plane_y = 0.66;
	}
	if (cub->pos.orientation == 'E')
	{
		cub->ray.dir_x = 0;
		cub->ray.dir_y = 1;
		cub->ray.plane_x = 0.66;
		cub->ray.plane_y = 0;
	}
}

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
