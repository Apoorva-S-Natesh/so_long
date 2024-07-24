/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_up_down.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asomanah <asomanah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 11:36:53 by asomanah          #+#    #+#             */
/*   Updated: 2024/07/12 17:46:56 by asomanah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	ft_move_up(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->str[i])
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
					ft_printf("\033[1;93mMOVES : %d\033[0m\n", ++map->move);
					return;
				}
				else
					ft_move_up2(map, i, j);
			}
			j++;
		}
		i++;
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
			ft_printf("\033[1;93mMOVES : %d\033[0m\n", ++map->move);
			ft_win(map);
			return ;
		}
	}
	else if (map->str[i - 1][j] == 'R')
	{
		ft_play_animation(map);
		ft_printf("Oops! The enchanted reindeer turned you into fairy dust!\n");
		ft_lose(map);
	}
	else if (map->str[i - 1][j] == '1')
		return ;
}

void	ft_move_down(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->str[i])
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
					ft_printf("\033[1;93mMOVES : %d\033[0m\n", ++map->move);
					return ;
				}
				else
					ft_move_down2(map, i, j);
			}
			j++;
		}
		i++;
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
			ft_printf("\033[1;93mMOVES : %d\033[0m\n", ++map->move);
			ft_win(map);
		}
	}
	else if (map->str[i + 1][j] == 'R')
	{
		ft_play_animation(map);
		ft_printf("Oops! The enchanted reindeer turned you into fairy dust!\n");
		ft_lose(map);
	}
	else if (map->str[i + 1][j] == '1')
		return ;
}
