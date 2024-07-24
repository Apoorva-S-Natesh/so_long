/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_animation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asomanah <asomanah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 13:00:19 by asomanah          #+#    #+#             */
/*   Updated: 2024/07/12 13:49:50 by asomanah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	ft_load_frames1(t_map *map)
{
	map->anim.frames[0] = mlx_xpm_file_to_image(map->mlx,
			"./assets/anim/0.xpm", &map->anim.f_width, &map->anim.f_height);
	map->anim.frames[1] = mlx_xpm_file_to_image(map->mlx,
			"./assets/anim/1.xpm", &map->anim.f_width, &map->anim.f_height);
	map->anim.frames[2] = mlx_xpm_file_to_image(map->mlx,
			"./assets/anim/2.xpm", &map->anim.f_width, &map->anim.f_height);
	map->anim.frames[3] = mlx_xpm_file_to_image(map->mlx,
			"./assets/anim/3.xpm", &map->anim.f_width, &map->anim.f_height);
	map->anim.frames[4] = mlx_xpm_file_to_image(map->mlx,
			"./assets/anim/4.xpm", &map->anim.f_width, &map->anim.f_height);
	map->anim.frames[5] = mlx_xpm_file_to_image(map->mlx,
			"./assets/anim/5.xpm", &map->anim.f_width, &map->anim.f_height);
	map->anim.frames[6] = mlx_xpm_file_to_image(map->mlx,
			"./assets/anim/6.xpm", &map->anim.f_width, &map->anim.f_height);
	map->anim.frames[7] = mlx_xpm_file_to_image(map->mlx,
			"./assets/anim/7.xpm", &map->anim.f_width, &map->anim.f_height);
	map->anim.frames[8] = mlx_xpm_file_to_image(map->mlx,
			"./assets/anim/8.xpm", &map->anim.f_width, &map->anim.f_height);
	map->anim.frames[9] = mlx_xpm_file_to_image(map->mlx,
			"./assets/anim/9.xpm", &map->anim.f_width, &map->anim.f_height);
	map->anim.frames[10] = mlx_xpm_file_to_image(map->mlx,
			"./assets/anim/10.xpm", &map->anim.f_width, &map->anim.f_height);
	map->anim.frames[11] = mlx_xpm_file_to_image(map->mlx,
			"./assets/anim/11.xpm", &map->anim.f_width, &map->anim.f_height);
}

void	ft_load_frames2(t_map *map)
{
	map->anim.frames[12] = mlx_xpm_file_to_image(map->mlx,
			"./assets/anim/12.xpm", &map->anim.f_width, &map->anim.f_height);
	map->anim.frames[13] = mlx_xpm_file_to_image(map->mlx,
			"./assets/anim/13.xpm", &map->anim.f_width, &map->anim.f_height);
	map->anim.frames[14] = mlx_xpm_file_to_image(map->mlx,
			"./assets/anim/14.xpm", &map->anim.f_width, &map->anim.f_height);
	map->anim.frames[15] = mlx_xpm_file_to_image(map->mlx,
			"./assets/anim/15.xpm", &map->anim.f_width, &map->anim.f_height);
	map->anim.frames[16] = mlx_xpm_file_to_image(map->mlx,
			"./assets/anim/16.xpm", &map->anim.f_width, &map->anim.f_height);
}

void	ft_load_animation(t_map *map)
{
	int	i;

	ft_load_frames1(map);
	ft_load_frames2(map);
	i = 0;
	while (i < 17)
	{
		if (!map->anim.frames[i])
		{
			ft_printf("failed to load animation frame %d \n", i + 1);
			ft_free_frames(map);
			ft_closemap(map);
			exit(1);
		}
		i++;
	}
}

void	ft_play_animation(t_map *map)
{
	int	i;

	i = 0;
	while (i < 17)
	{
		mlx_put_image_to_window(map->mlx, map->win, map->anim.frames[i], 
			map->player_j * 32, map->player_i * 32);
		mlx_do_sync(map->mlx);
		usleep(200000);
		i++;
	}
}

void	ft_free_frames(t_map *map)
{
	int	i;

	i = 0;
	while (i < 17)
	{
		if (map->anim.frames[i])
		{
			mlx_destroy_image(map->mlx, map->anim.frames[i]);
			map->anim.frames[i] = NULL;
		}
		i++;
	}
}
