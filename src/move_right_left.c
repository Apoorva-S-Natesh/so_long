/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_right_left.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asomanah <asomanah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 11:35:17 by asomanah          #+#    #+#             */
/*   Updated: 2024/07/08 13:03:35 by asomanah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_move_right(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (map->str[++i])
	{
		j = 0;
		ft_move_right2(map, i, j);
	}
}

void	ft_move_right2(t_map *map, int i, int j)
{
	while (map->str[i][j])
	{
		if (map->str[i][j] == 'P')
		{
			if (map->str[i][j + 1] == '0')
			{
				map->str[i][j + 1] = 'P';
				map->str[i][j] = '0';
				ft_printf("MOVES : %d\n", ++map->move);
				break ;
			}
			else if (map->str[i][j + 1] == 'C')
			{
				map->str[i][j + 1] = 'P';
				map->str[i][j] = '0';
				ft_printf("MOVES : %d\n", ++map->move);
				break ;
			}
			else
				ft_move_right3(map, i, j); 
		}
		j++;
	}
}

void	ft_move_right3(t_map *map, int i, int j)
{
	if (map->str[i][j + 1] == 'E')
	{
		if (ft_check_collect(map) == 0)
		{
			map->str[i][j + 1] = 'P';
			map->str[i][j] = '0';
			ft_printf("MOVES : %d\n", ++map->move);
			ft_win(map);
		}
	}
}

void	ft_move_left(t_map *map)
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
				if (map->str[i][j - 1] == '0')
				{
					map->str[i][j - 1] = 'P';
					map->str[i][j] = '0';
					ft_printf("MOVES : %d \n", ++map->move);
					return ;
				}
				else
					ft_move_left2(map, i, j);
			}
			j++;
		}
	}
}

void	ft_move_left2(t_map *map, int i, int j)
{
	if (map->str[i][j - 1] == 'C')
	{
		map->str[i][j - 1] = 'P';
		map->str[i][j] = '0';
		ft_printf("MOVES : %d \n", ++map->move);
	}
	else if (map->str[i][j - 1] == 'E')
	{
		if ((ft_check_collect(map)) == 0)
		{
			map->str[i][j - 1] = 'P';
			map->str[i][j] = '0';
			ft_printf("MOVES : %d \n", ++map->move);
			ft_win(map);
		}
	}
	else if (map->str[i][j - 1] == '1')
	{
		ft_printf("cannot move , wall ahead \n");
		return ;
	}
}
