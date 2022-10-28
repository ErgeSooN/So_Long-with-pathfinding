/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayaman <ayaman@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 14:44:29 by ayaman            #+#    #+#             */
/*   Updated: 2022/10/26 18:57:51 by ayaman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//alınan x,y değerlerine göre gerekli imageleri windowa basma işlemi yapıyoruz 
int	draw_elements(int x, int y, char **map, t_game *game)
{
	if (map[y][x] == '0' || map[y][x] == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->tile_s, \
				x * SCALE, y * SCALE);
	else if (map[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->wall_s, \
				x * SCALE, y * SCALE);
	else if (map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->coin_s, \
				x * SCALE, y * SCALE);
	else if (map[y][x] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->exit_s, \
				x * SCALE, y * SCALE);
	return (0);
}

//mapteki x,y'yi draw elementse gönderme işlemi yapıyoruz
int	draw_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			draw_elements(x, y, game->map, game);
			x++;
		}
		y++;
	}
	return (0);
}

//basılan tuşlara göre player ilerlemesi veya uygulama çıkış işlemi yapıyoruz
void	key_control(int keycode, t_game *game)
{
	if (keycode == ESC)
		exit(0);
	else if (keycode == W_KEY && game->map[game->py - 1][game->px] != '1')
	{
		game->py--;
		game->moves++;
	}
	else if (keycode == A_KEY && game->map[game->py][game->px - 1] != '1')
	{
		game->px--;
		game->moves++;
	}
	else if (keycode == D_KEY && game->map[game->py][game->px + 1] != '1')
	{
		game->px++;
		game->moves++;
	}
	else if (keycode == S_KEY && game->map[game->py + 1][game->px] != '1')
	{
		game->py++;
		game->moves++;
	}
}

//alınan coinleri zemine dönüştürme işlemi ve exite geldiğinde çıkış işlemi
void	item_control(t_game *game)
{
	if (game->map[game->py][game->px] == 'C')
	{
		game->map[game->py][game->px] = '0';
		game->coins--;
	}
	if (game->map[game->py][game->px] == 'E' && game->coins == 0)
	{
		free(game);
		exit(0);
	}
}

//fonksiyonlara yönlendirme ve key_control sonrası player bastırma işlemi
int	key_game(int keycode, t_game *game)
{
	key_control(keycode, game);
	item_control(game);
	draw_map(game);
	mlx_put_image_to_window(game->mlx, game->win, game->player_s, \
				game->px * SCALE, game->py * SCALE);
	ft_printf("\rMoves : %d", game->moves);
	return (0);
}
