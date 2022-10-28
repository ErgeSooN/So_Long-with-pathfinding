/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayaman <ayaman@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:01:45 by ayaman            #+#    #+#             */
/*   Updated: 2022/10/24 16:01:47 by ayaman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "printf.h"
# include "../bin/minilibx_opengl_20191021/mlx.h"

# define TITLE "so_long"
# define SCALE 64

# define COIN "res/coin.xpm"
# define EXIT "res/exit.xpm"
# define PLAYER "res/player.xpm"
# define TILE "res/tile.xpm"
# define WALL "res/wall.xpm"

# define ESC 53
# define W_KEY 13
# define A_KEY 0
# define S_KEY 1
# define D_KEY 2

typedef struct l_int_map
{
	int		l;
	int		r;
	int		t;
	int		b;
	int		read_count;
}			t_int_map;

typedef struct s_game
{
	void		*mlx;
	void		*win;

	int			map_height;
	int			map_width;
	char		**map;

	int			moves;
	int			coins;

	int			exit;
	int			ply;

	int			px;
	int			py;
	int			ex;
	int			ey;

	void		*player_s;
	void		*coin_s;
	void		*exit_s;
	void		*tile_s;
	void		*wall_s;
	t_int_map	i_map;
}	t_game;

void	start_game(char *path);
void	ft_reset(char *buffer);
void	item_control(t_game *game);

int		map_validation(t_game *sl);
int		ft_strlen(char *str);
int		key_game(int keycode, t_game *game);
int		draw_map(t_game *game);

char	**map_constractor(t_game *sl, int fd);
void	placeholder(t_game *list, int x, int y);
void	exit_game(int mousecode, t_game *game);
#endif