/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_content_wall.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asomanah <asomanah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 11:15:55 by asomanah          #+#    #+#             */
/*   Updated: 2024/07/08 13:57:47 by asomanah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_mapcontent(t_map *map)
{
	map->collectible = 0;
	map->player = 0;
	map->escape = 0;
	ft_maplen(map);
	map->i = 0;
	while (map->i < map->len)
	{
		map->j = 0;
		while ((map->str[map->i][map->j] != '\n') && map->str[map->i][map->j])
		{
			check_mapcontent2(map);
		}
		map->i++;
	}
	if (map->collectible < 1 || map->escape != 1 || map->player != 1)
	{
		ft_printf("ERROR <Map has missing/extra characters> \n");
		ft_closemap(map);
		exit(1);
	}
}

void	check_mapcontent2(t_map *map)
{
	if ((map->str[map->i][map->j] == '1') ||
		(map->str[map->i][map->j] == '0'))
		map->j++;
	else if (map->str[map->i][map->j] == 'P')
	{
		map->player++;
		map->j++;
	}
	else if (map->str[map->i][map->j] == 'C')
	{
		map->collectible++;
		map->j++;
	}
	else if (map->str[map->i][map->j] == 'E')
	{
		map->escape++;
		map->j++;
	}
	else
	{
		ft_printf("ERROR <Map contains some unkonown character> \n");
		ft_closemap(map);
		exit(1);
	}
}

void	check_mapwall_tb(t_map *map)
{
	map->i = map->len - 1;
	map->j = 0;
	if (ft_strlen(map->str[0]) * 32 > 2800)
	{
		ft_printf("ERROR <Map too long>");
		ft_closemap(map);
		exit (1);
	}
	while ((map->str[0][map->j] && map->str[map->i][map->j]) &&
			(map->str[0][map->j] != '\n') && (map->str[map->i][map->j] != '\n'))
	{
		if ((map->str[0][map->j] == '1') && (map->str[map->i][map->j] == '1'))
			map->j++;
		else
		{
			ft_printf("ERROR <Map top/bottom wall needs fix> \n");
			ft_closemap(map);
			exit(1);
		}
	}
}

void	check_sidewall(t_map *map)
{
	map->j = (ft_strlen(map->str[0]) - 2);
	map->i = map->len - 1;
	while (map->i >= 0)
	{
		if ((map->str[map->i][0] != '1') || (map->str[map->i][map->j] != '1'))
		{
			ft_printf("ERROR <Map side wall needs fix> \n");
			ft_closemap(map);
			exit(1);
		}
		map->i--;
	}
}

void	ft_maplen(t_map *map)
{
	int	len;

	len = 0;
	while (map->str[len])
		len++;
	map->len = len;
}
