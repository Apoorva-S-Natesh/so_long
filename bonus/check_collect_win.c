/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_collect_win.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asomanah <asomanah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 11:14:59 by asomanah          #+#    #+#             */
/*   Updated: 2024/07/12 17:49:43 by asomanah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

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
	ft_printf("\033[1;32m           (       )  \033[0m\n");
	ft_printf("\033[1;32m (  (      )\\ ) ( /(  \033[0m\n");
	ft_printf("\033[1;32m )\\))(   '(()/( )\\()) \033[0m\n");
	ft_printf("\033[1;32m((_)()\\ )  /(_)|(_)\\  \033[0m\n");
	ft_printf("\033[1;32m_(())\\_)()(_))  _((_) \033[0m\n");
	ft_printf("\033[1;32m\\ \\((_)/ /|_ _|| \\| | \033[0m\n");
	ft_printf("\033[1;32m \\ \\/\\/ /  | | | .` | \033[0m\n");
	ft_printf("\033[1;32m  \\_/\\_/  |___||_|\\_| \033[0m\n");
	ft_printf("                      \n");
	on_destroy(map);
	exit (1);
	return (0);
}

int	ft_lose(t_map *map)
{
	ft_printf("\033[1;91m __     __           _           _ \n");
	ft_printf("\033[1;91m \\ \\   / /          | |         | |  \n");
	ft_printf("\033[1;91m  \\ \\_/ /__  _   _  | | ___  ___| |_ \n");
	ft_printf("\033[1;91m   \\   / _ \\| | | | | |/ _ \\/ __| __|\n");
	ft_printf("\033[1;91m    | | (_) | |_| | | | (_) \\__ \\ |_ \n");
	ft_printf("\033[1;91m    |_|\\___/ \\__,_| |_|\\___/|___/\\__| \033[0m \n");
	ft_printf("\n");
	on_destroy(map);
	exit (1);
	return (0);
}
