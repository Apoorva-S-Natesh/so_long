/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_move_window.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asomanah <asomanah@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 13:00:05 by asomanah          #+#    #+#             */
/*   Updated: 2024/07/12 13:00:07 by asomanah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	ft_place_image(t_map *map)
{
	map->i = 0;
	map->y = 0;
	mlx_clear_window(map->mlx, map->win);
	while (map->str[map->i])
	{
		map->j = 0;
		map->x = 0;
		while (map->str[map->i][map->j])
		{
			ft_draw_image(map);
			map->j++;
			map->x += 32;
		}
		map->i++;
		map->y += 32;
	}
	ft_drawmove(map);
}

void	ft_drawmove(t_map *map)
{
	char	*move_str;
	char	*display_str;

	move_str = ft_itoa(map->move);
	if (!move_str)
	{
		ft_printf("Error converting move count to string\n");
		return ;
	}
	display_str = (char *)malloc(sizeof(char) * (ft_strlen("MOVES: ") + 
				ft_strlen(move_str) + 1));
	if (!display_str)
	{
		free(move_str);
		ft_printf("Error allocating memory for display string\n");
		ft_closemap(map);
		return ;
	}
	ft_drawmove2(map, display_str, move_str);
	free(move_str);
	free(display_str);
}

void	ft_drawmove2(t_map *map, char *display_str, char *move_str)
{
	int		dx;
	int		dy;

	ft_strcpy(display_str, "MOVES: ");
	ft_strcat(display_str, move_str);
	if (!display_str)
	{
		ft_closemap(map);
		return ;
	}
	dx = -1;
	while (dx <= 0)
	{
		dy = -1;
		while (dy <= 0)
		{
			mlx_string_put(map->mlx, map->win, (20 + dx), (20 + dy), 
				0x800000, display_str);
			dy++;
		}
		dx++;
	}
}
