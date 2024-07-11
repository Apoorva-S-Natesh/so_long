/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asomanah <asomanah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:49:41 by asomanah          #+#    #+#             */
/*   Updated: 2024/07/08 13:56:34 by asomanah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
	{
		ft_printf("ERROR <Invalid arguments> \n");
		exit (1);
	}
	if (ft_strncmp(argv[1] + (ft_strlen(argv[1]) - 4), ".ber", 4))
	{
		ft_printf("ERROR <Invalid entry (.ber!!)>\n");
		exit (1);
	}
	read_map(argv, &map);
	check_mapcontent(&map);
	check_mapwall_tb(&map);
	check_sidewall(&map);
	check_map_rectgl(&map);
	ft_backtracking(&map);
	map.move = 0;
	ft_drawmap(&map);
	mlx_hook(map.win, 17, 0, on_destroy, &map);
	mlx_key_hook(map.win, move_loop, &map);
	mlx_loop(map.mlx);
	return (0);
}

void	read_map(char **argv, t_map *map)
{
	map->j = 0;
	map->i = check_lines(argv, map);
	map->str = (char **)malloc(sizeof(char *) * (map->i + 1));
	if (!map->str)
	{
		free(map->str);
		exit(1);
	}
	map->fd = open(argv[1], O_RDONLY);
	if (map->fd < 0)
	{
		ft_printf("ERROR <Map doesnt open> \n");
		exit(1);
	}
	while (map->j < map->i)
	{
		map->str[map->j] = get_next_line(map->fd);
		map->j++;
	}
	map->str[map->j] = NULL;
	close(map->fd);
}

int	check_lines(char **argv, t_map *map)
{
	int	lines;

	lines = 0;
	map->fd = open(argv[1], O_RDONLY);
	if (map->fd < 0)
	{
		ft_printf("ERROR <Map doesnt open> \n");
		exit(1);
	}
	map->buff = get_next_line(map->fd);
	while (map->buff)
	{
		free(map->buff);
		map->buff = get_next_line(map->fd);
		lines++;
	}
	free(map->buff);
	close(map->fd);
	return (lines);
}
