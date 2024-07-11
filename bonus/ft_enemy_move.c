#include "../so_long_bonus.h"

void	find_player(t_map *map)
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
				map->player_i = i;
				map->player_j = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	ft_enemy_movement(t_map *map, int i, int j)
{
	map->i = i;
	map->j = j;
	if (ft_abs(map->player_i - i) > ft_abs(map->player_j - j))
	{
		if ((map->player_i < i) && (map->str[i - 1][j] != '1') && 
			(map->str[i - 1][j] != 'E') && (map->str[i - 1][j] != 'C') && 
			(map->str[i - 1][j] != 'R') && (map->str[i - 1][j] != 'P'))
			map->i--;
		else if ((map->player_i > i) && (map->str[i + 1][j] != '1') && 
			(map->str[i + 1][j] != 'E') && (map->str[i + 1][j] != 'C') && 
			(map->str[i + 1][j] != 'R') && (map->str[i + 1][j] != 'P'))
			map->i++;
	}
	else
	{
		ft_horizontal_movement(map, i, j);
	}
	if (map->i != i || map->j != j)
	{
		map->str[map->i][map->j] = 'r';
		map->str[i][j] = '0';
	}
}
void	ft_horizontal_movement(t_map *map, int i, int j)
{
	if ((map->player_j < j) && (map->str[i][j - 1] != '1') && 
			(map->str[i][j - 1] != 'E') && (map->str[i][j - 1] != 'C') && 
			(map->str[i][j - 1] != 'R') && (map->str[i][j - 1] != 'P'))
			map->j--;
		else if ((map->player_j > j) && (map->str[i][j + 1] != '1') && 
			(map->str[i][j + 1] != 'E') && (map->str[i][j + 1] != 'C') && 
			(map->str[i][j + 1] != 'R') && (map->str[i][j + 1] != 'P'))
			map->j++;
}

void	ft_enemy_movement_all(t_map *map)
{
	int	i;
	int	j;

	find_player(map);
	i = 0;
	while (map->str[i])
	{
		j = 0;
		while (map->str[i][j])
		{
			if (map->str[i][j] == 'R')
				ft_enemy_movement(map, i, j);
			j++;
		}
		i++;
	}
	ft_update_enemy(map);
}

void	ft_update_enemy(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->str[i])
	{
		j = 0;
		while (map->str[i][j])
		{
			if (map->str[i][j] == 'r')
				map->str[i][j] = 'R';
			j++;
		}
		i++;
	}
}
