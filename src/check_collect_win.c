/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_collect_win.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asomanah <asomanah@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 11:14:59 by asomanah          #+#    #+#             */
/*   Updated: 2024/07/08 11:15:08 by asomanah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_check_collect(t_map *map)
{
	int	i;
	int	j;

	map->collectible = 0;
	i = 0;
	while (map->str[i])
	{
		j = 0;
		while (map->str[i][j])
		{
			if (map->str[i][j] == 'C')
				map->collectible++;
			j++;
		}
		i++;
	}
	return (map->collectible);
}

int	ft_win(t_map *map)
{
	ft_printf("           (       )  \n");
	ft_printf(" (  (      )\\ ) ( /(  \n");
	ft_printf(" )\\))(   '(()/( )\\()) \n");
	ft_printf("((_)()\\ )  /(_)|(_)\\  \n");
	ft_printf("_(())\\_)()(_))  _((_) \n");
	ft_printf("\\ \\((_)/ /|_ _|| \\| | \n");
	ft_printf(" \\ \\/\\/ /  | | | .` | \n");
	ft_printf("  \\_/\\_/  |___||_|\\_| \n");
	ft_printf("                      \n");
	on_destroy(map);
	exit (1);
	return (0);
}
