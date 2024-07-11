/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asomanah <asomanah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 11:22:59 by asomanah          #+#    #+#             */
/*   Updated: 2024/07/08 11:24:05 by asomanah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	ft_load_img(t_map *map)
{
	map->pl = mlx_xpm_file_to_image(map->mlx, "./assets/player.xpm", 
			&(map->width), &(map->height));
	ft_check_img(map, &map->pl);
	map->wall = mlx_xpm_file_to_image(map->mlx, "./assets/wall.xpm", 
			&(map->width), &(map->height));
	ft_check_img(map, &map->wall);
	map->collect = mlx_xpm_file_to_image(map->mlx, "./assets/gift.xpm", 
			&(map->width), &(map->height));
	ft_check_img(map, &map->collect);
	map->esc = mlx_xpm_file_to_image(map->mlx, "./assets/exit.xpm", 
			&(map->width), &(map->height));
	ft_check_img(map, &map->esc);
	map->background = mlx_xpm_file_to_image(map->mlx, "./assets/snow-tile.xpm", 
			&(map->width), &(map->height));
	ft_check_img(map, &map->background);
	map->reindeer = mlx_xpm_file_to_image(map->mlx, "./assets/reindeer.xpm", 
			&(map->width), &(map->height));
	ft_check_img(map, &map->reindeer);
}

void	ft_check_img(t_map *map, void *ptr)
{
	if (!ptr)
	{
		ft_printf("ERROR <mlx error>");
		free(ptr);
		ft_closemap(map);
		exit(1);
	}
	if (map->width == 0 || map->height == 0)
	{
		ft_printf("ERROR <mlx error>");
		exit(1);
	}
}


void	ft_draw_image(t_map *map)
{
	if (map->str[map->i][map->j] == '0')
	{
		mlx_put_image_to_window(map->mlx, map->win, 
			map->background, map->x, map->y);
	}
	else if (map->str[map->i][map->j] == 'P')
	{
		mlx_put_image_to_window(map->mlx, map->win, 
			map->pl, map->x, map->y);
	}
	else if (map->str[map->i][map->j] == '1')
	{
		mlx_put_image_to_window(map->mlx, map->win, 
			map->wall, map->x, map->y);
	}
	else if (map->str[map->i][map->j] == 'C')
	{
		mlx_put_image_to_window(map->mlx, map->win, 
			map->collect, map->x, map->y);
	}
	else
		ft_draw_image2(map);
	
}
void	ft_draw_image2(t_map *map)
{
	if (map->str[map->i][map->j] == 'E')
	{
		mlx_put_image_to_window(map->mlx, map->win, 
			map->esc, map->x, map->y);
	}
	else if (map->str[map->i][map->j] == 'R')
	{
		mlx_put_image_to_window(map->mlx, map->win, 
			map->reindeer, map->x, map->y);
	}
}

void	ft_drawmap(t_map *map)
{
	map->mlx = mlx_init();
	if (!map->mlx)
	{
		ft_printf("ERROR <mlx error!> \n");
		ft_closemap(map);
	}
	map->win = mlx_new_window(map->mlx, (strlen_won(map->str[0]) * 32),
			map->len * 32, "SO_LONG");
	if (!map->win)
	{
		ft_closemap(map);
		free(map->mlx);
		exit (1);
	}
	ft_load_img(map);
	ft_place_image(map);
}
