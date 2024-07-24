/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_up_down.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asomanah <asomanah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 11:36:53 by asomanah          #+#    #+#             */
/*   Updated: 2024/07/08 13:03:59 by asomanah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_move_up(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (map->str[++i])
	{
		j = 0;
		while (map->str[i][j])
		{
			if (map->str[i][j] == 'P')
			{
				if (map->str[i - 1][j] == '0' || map->str[i - 1][j] == 'C')
				{
					map->str[i - 1][j] = 'P';
					map->str[i][j] = '0';
					ft_printf("MOVES : %d \n", ++map->move);
					return ;
				}
				else
					ft_move_up2(map, i, j);
			}
			j++;
		}
	}
}

void	ft_move_up2(t_map *map, int i, int j)
{
	if (map->str[i - 1][j] == 'E')
	{
		if ((ft_check_collect(map)) == 0)
		{
			map->str[i - 1][j] = 'P';
			map->str[i][j] = '0';
			ft_printf("MOVES : %d \n", ++map->move);
			ft_win(map);
		}
	}
	else if (map->str[i - 1][j] == '1')
		return ;
}

void	ft_move_down(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (map->str[++i])
	{
		j = 0;
		while (map->str[i][j])
		{
			if (map->str[i][j] == 'P')
			{
				if (map->str[i + 1][j] == '0' || map->str[i + 1][j] == 'C')
				{
					map->str[i + 1][j] = 'P';
					map->str[i][j] = '0';
					ft_printf("MOVES : %d \n", ++map->move);
					return ;
				}
				else
					ft_move_down2(map, i, j);
			}
			j++;
		}
	}
}

void	ft_move_down2(t_map *map, int i, int j)
{
	if (map->str[i + 1][j] == 'E')
	{
		if ((ft_check_collect(map)) == 0)
		{
			map->str[i + 1][j] = 'P';
			map->str[i][j] = '0';
			ft_printf("MOVES : %d \n", ++map->move);
			ft_win(map);
		}
	}
	else if (map->str[i + 1][j] == '1')
	{
		ft_printf("cannot move , wall ahead \n");
		return ;
	}
}
