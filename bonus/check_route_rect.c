/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_route_rect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asomanah <asomanah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 11:17:43 by asomanah          #+#    #+#             */
/*   Updated: 2024/07/08 11:22:07 by asomanah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	check_map_rectgl(t_map *map)
{
	size_t	len;
	size_t	l_len;
	int		i;

	i = 1;
	len = strlen_won(map->str[0]);
	while (map->str[i])
	{
		l_len = strlen_won(map->str[i]);
		if (len != l_len)
		{
			ft_printf("ERROR <Map is not rectangle>\n");
			ft_closemap(map);
			exit (1);
		}
		else
			i++;
	}
	return (len);
}

size_t	strlen_won(char *str)
{
	size_t	l;

	l = 0;
	while (str[l] && str[l] != '\n')
		l++;
	return (l);
}

void	ft_copymap(t_map *map)
{
	int	i;

	map->copy_str = (char **)malloc(sizeof(char *) * (map->len + 1));
	if (!(map->copy_str))
	{
		ft_closemap(map);
		ft_close_cpy(map);
		exit(1);
	}
	i = 0;
	while (map->str[i])
	{
		map->copy_str[i] = ft_strdup(map->str[i]);
		if (!map->copy_str[i])
		{
			ft_close_cpy(map);
			exit (1);
		}
		i++;
	}
	map->copy_str[i] = NULL;
}

void	ft_backtracking(t_map *map)
{
	ft_copymap(map);
	map->i = 1;
	while (map->str[map->i])
	{
		map->j = 0;
		while (map->str[map->i][map->j])
		{
			if (map->str[map->i][map->j] == 'C' || 
				map->str[map->i][map->j] == 'E')
			{
				if (!(check_reach(map->copy_str, map->str[map->i][map->j],
						map->i, map->j)))
				{
					ft_close_cpy(map);
					ft_printf("ERROR <Collectible or exit is stuck>\n");
					exit(1);
				}
				ft_close_cpy(map);
				ft_copymap(map);
			}
			map->j++;
		}
		map->i++;
	}
	ft_close_cpy(map);
}

int	check_reach(char **strbckp, char c, int i, int j)
{
	if (strbckp[i][j] == 'P')
		return (1);
	else if (strbckp[i][j] == '1' || (c != 'E' && strbckp[i][j] == 'E') ||
		strbckp[i][j] == 'R')
		return (0);
	strbckp[i][j] = '1';
	if (check_reach(strbckp, c, i, j + 1))
		return (1);
	if (check_reach(strbckp, c, i + 1, j))
		return (1);
	if (check_reach(strbckp, c, i, j - 1))
		return (1);
	if (check_reach(strbckp, c, i - 1, j))
		return (1);
	return (0);
}
