/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_closes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asomanah <asomanah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 11:33:32 by asomanah          #+#    #+#             */
/*   Updated: 2024/07/08 13:02:35 by asomanah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	on_destroy(t_map *map)
{
	mlx_destroy_image(map->mlx, map->pl);
	mlx_destroy_image(map->mlx, map->wall);
	mlx_destroy_image(map->mlx, map->esc);
	mlx_destroy_image(map->mlx, map->background);
	mlx_destroy_image(map->mlx, map->collect);
	mlx_destroy_window(map->mlx, map->win);
	map->win = NULL;
	mlx_destroy_display(map->mlx);
	free(map->mlx);
	map->mlx = NULL;
	ft_closemap(map);
	exit(0);
	return (0);
}

int	move_loop(int keycode, t_map *map)
{
	if (keycode == 65307 || keycode == 113)
		on_destroy(map);
	else if (keycode == 65362 || keycode == 119)
		ft_move_up(map);
	else if (keycode == 65364 || keycode == 115)
		ft_move_down(map);
	else if (keycode == 65363 || keycode == 100)
		ft_move_right(map);
	else if (keycode == 65361 || keycode == 97)
		ft_move_left(map);
	ft_place_image(map);
	return (0);
}

int	ft_closemap(t_map *map)
{
	int	i;

	i = 0;
	if (map->str)
	{
		while (i < map->len)
		{
			if (map->str[i])
			{
				free(map->str[i]);
				map->str[i] = NULL;
			}
			i++;
		}
	}
	free(map->str);
	return (0);
}

void	ft_close_cpy(t_map *map)
{
	int	i;

	i = 0;
	if (map->copy_str)
	{
		while (i < map->len)
		{
			if (map->copy_str[i])
			{
				free(map->copy_str[i]);
				map->copy_str[i] = NULL;
			}
			i++;
		}
	}
	free(map->copy_str);
}
