/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asomanah <asomanah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 11:42:15 by asomanah          #+#    #+#             */
/*   Updated: 2024/07/12 13:59:28 by asomanah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <mlx.h>
# include <stdlib.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "../printf/ft_printf.h"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_animation
{
	void	*frames[17];
	int		f_height;
	int		f_width;
}			t_animation;

typedef struct b_map
{
	int			i;
	int			j;
	int			fd;
	int			len;
	char		**str;
	char		*buff;
	int			collectible;
	int			player;
	int			escape;
	int			enemy;
	char		**copy_str;
	void		*mlx;
	void		*win;
	void		*pl;
	void		*background;
	void		*esc;
	void		*collect;
	void		*wall;
	void		*reindeer;
	int			width;
	int			height;
	int			x;
	int			y	;
	int			move;
	int			player_i;
	int			player_j;
	t_animation	anim;
}			t_map;

//----- UTIL FUNCTIONS -----//
char	*get_next_line(int fd);
char	*ft_read_file(int fd, char *result);
char	*ft_get_line(char *buff);
char	*ft_nextline(char *buff);
char	*ft_str_join(char *result, char *buff);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
char	*allocate(char *buff, char *result);
int		ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s1);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_itoa(int n);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strcat(char *dest, char *src);

//----- SOURCE FUNCTIONS -----//
int		check_lines(char **argv, t_map *map);
void	read_map(char **argv, t_map *map);
void	ft_maplen(t_map *map);
int		ft_closemap(t_map *map);
void	check_mapcontent2(t_map *map);
void	check_mapcontent(t_map *map);
void	check_mapwall_tb(t_map *map);
size_t	strlen_won(char *str);
void	check_sidewall(t_map *map);
int		check_map_rectgl(t_map *map);
void	ft_copymap(t_map *map);
int		check_reach(char **strbckp, char c, int i, int j);
void	ft_close_cpy(t_map *map);
void	ft_backtracking(t_map *map);
void	ft_freemap(t_map *map);
void	ft_drawmap(t_map *map);
void	ft_load_img(t_map *map);
void	ft_check_img(t_map *map, void *ptr);
void	ft_place_image(t_map *map);
void	ft_drawmove(t_map *map);
void	ft_drawmove2(t_map *map, char *display_str, char *move_str);
void	ft_draw_image(t_map *map);
void	ft_draw_image2(t_map *map);
int		on_destroy(t_map *map);
int		move_loop(int keycode, t_map *map);
void	ft_move_up(t_map *map);
void	ft_move_up2(t_map *map, int i, int j);
int		ft_check_collect(t_map *map);
int		ft_win(t_map *map);
int		ft_lose(t_map *map);
void	ft_move_down(t_map *map);
void	ft_move_down2(t_map *map, int i, int j);
void	ft_move_right(t_map *map);
void	ft_move_right2(t_map *map, int i, int j);
void	ft_move_right3(t_map *map, int i, int j);
void	ft_move_left2(t_map *map, int i, int j);
void	ft_move_left(t_map *map);
void	ft_enemy_movement(t_map *map, int i, int j);
void	ft_enemy_movement_all(t_map *map);
void	ft_horizontal_movement(t_map *map, int i, int j);
void	find_player(t_map *map);
int		ft_abs(int value);
void	ft_update_enemy(t_map *map);
void	ft_load_animation(t_map *map);
void	ft_load_frames1(t_map *map);
void	ft_load_frames2(t_map *map);
void	ft_free_frames(t_map *map);
void	ft_play_animation(t_map *map);

#endif
