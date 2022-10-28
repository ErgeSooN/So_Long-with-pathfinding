/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayaman <ayaman@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 14:49:39 by ayaman            #+#    #+#             */
/*   Updated: 2022/10/27 12:54:11 by ayaman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//playeri x,y kordinatında bulduğumuz alan
void	find_player(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->map_width)
	{
		y = 0;
		while (y < game->map_height)
		{
			if (game->map[y][x] == 'P')
			{
				game->px = x;
				game->py = y;
				return ;
			}
			y++;
		}
		x++;
	}
}

//exiti x,y kordinatında bulduğumuz alan
void	find_exit(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->map_width)
	{
		y = 0;
		while (y < game->map_height)
		{
			if (game->map[x][y] == 'E')
			{
				game->ex = x;
				game->ey = y;
				return ;
			}
			y++;
		}
		x++;
	}
}

//xpm dosyalarını oyunda resim olarak bastığımız yer
void	image_init(t_game *game)
{
	int	x;
	int	y;

	game->player_s = mlx_xpm_file_to_image(game->mlx, PLAYER, &x, &y);
	game->coin_s = mlx_xpm_file_to_image(game->mlx, COIN, &x, &y);
	game->exit_s = mlx_xpm_file_to_image(game->mlx, EXIT, &x, &y);
	game->tile_s = mlx_xpm_file_to_image(game->mlx, TILE, &x, &y);
	game->wall_s = mlx_xpm_file_to_image(game->mlx, WALL, &x, &y);
}

//oyunumuzun başlangıcının asıl oluştuğu yer
t_game	*game_init(char *path)
{
	t_game	*new;

	new = (t_game *) malloc(sizeof(t_game));
	new->mlx = mlx_init();
	new->map = map_constractor(new, open(path, O_RDONLY));
	find_exit(new);
	new->moves = 0;
	new->coins = 0;
	if (map_validation(new))
	{
		ft_printf("%s\n", "Error loading map!!");
		exit(1);
		free(new);
	}
	new->win = mlx_new_window(new->mlx, new->map_width * SCALE, \
				new->map_height * SCALE, TITLE);
	mlx_hook(new->win, 2, 1L << 2, key_game, new);
	mlx_hook(new->win, 17, 1L << 2, exit_game, new);
	image_init(new);
	find_player(new);
	return (new);
}

//oyunun asıl başlangıcına yönlendirme ve 
//playerin hareket sonrası bastırıldığı yer
void	start_game(char *path)
{
	t_game	*game;

	game = game_init(path);
	draw_map(game);
	mlx_put_image_to_window(game->mlx, game->win, game->player_s, \
				game->px * SCALE, game->py * SCALE);
	mlx_loop(game->mlx);
}
