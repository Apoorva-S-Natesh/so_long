/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_right_left.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asomanah <asomanah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 11:35:17 by asomanah          #+#    #+#             */
/*   Updated: 2024/07/12 17:46:36 by asomanah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

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
				ft_printf("\033[1;93mMOVES : %d\033[0m\n", ++map->move);
				break ;
			}
			else if (map->str[i][j + 1] == 'C')
			{
				map->str[i][j + 1] = 'P';
				map->str[i][j] = '0';
				ft_printf("\033[1;93mMOVES : %d\033[0m\n", ++map->move);
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
			ft_printf("\033[1;93mMOVES : %d\033[0m\n", ++map->move);
			ft_win(map);
		}
	}
	else if (map->str[i][j + 1] == 'R')
	{
		ft_play_animation(map);
		ft_printf("Oops! The enchanted reindeer turned you into fairy dust!\n");
		ft_lose(map);
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
					ft_printf("\033[1;93mMOVES : %d\033[0m\n", ++map->move);
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
		ft_printf("\033[1;93mMOVES : %d\033[0m\n", ++map->move);
	}
	else if (map->str[i][j - 1] == 'E')
	{
		if ((ft_check_collect(map)) == 0)
		{
			map->str[i][j - 1] = 'P';
			map->str[i][j] = '0';
			ft_printf("\033[1;93mMOVES : %d\033[0m\n", ++map->move);
			ft_win(map);
		}
	}
	else if (map->str[i][j - 1] == 'R')
	{
		ft_play_animation(map);
		ft_printf("Oops! The enchanted reindeer turned you into fairy dust!\n");
		ft_lose(map);
	}
	else if (map->str[i][j - 1] == '1')
		return ;
}