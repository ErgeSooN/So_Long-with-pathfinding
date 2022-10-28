/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfind.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayaman <ayaman@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 20:19:59 by ayaman            #+#    #+#             */
/*   Updated: 2022/10/27 13:00:47 by ayaman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//oluşturulan çift boyutlu mapin recursive bir şekilde taramasını yapıyoruz.
//ardından toplanabilir player ve coin sayımı yapıyoruz
static int	recur_func(int **int_map, t_game *list, int x, int y)
{
	if (list->map[y][x] == 'P' || list->map[y][x] == 'C')
		list->i_map.read_count++;
	if (list->map[y][x + 1] != '1' && int_map[y][x + 1] < 1)
	{
		int_map[y][x + 1] = int_map[y][x] + 1;
		list->i_map.r = recur_func(int_map, list, x + 1, y);
	}
	if (list->map[y + 1][x] != '1' && int_map[y + 1][x] < 1)
	{
		int_map[y + 1][x] = int_map[y][x] + 1;
		list->i_map.b = recur_func(int_map, list, x, y + 1);
	}
	if (list->map[y][x - 1] != '1' && int_map[y][x - 1] < 1)
	{
		int_map[y][x - 1] = int_map[y][x] + 1;
		list->i_map.l = recur_func(int_map, list, x - 1, y);
	}
	if (list->map[y - 1][x] != '1' && int_map[y - 1][x] < 1)
	{
		int_map[y - 1][x] = int_map[y][x] + 1;
		list->i_map.t = recur_func(int_map, list, x, y - 1);
	}
	if ((list->i_map.r || list->i_map.l || list->i_map.b || list->i_map.t))
		return (1);
	return (0);
}

//oluşturduğumuz mapin freeleme işlemini burada yapıyoruz
static void	int_map_free(int **int_map, t_game *list)
{
	int	i;

	i = 0;
	while (i < list->map_height)
	{
		free(int_map[i]);
		i++;
	}
	free(int_map);
}

//verilen mape göre çift boyutlu integer dizisi oluşturup
//gerekli fonksiyolara gönderme işlemi yapıyoruz
void	placeholder(t_game *list, int x, int y)
{
	int	**int_map;
	int	i;
	int	j;

	i = 0;
	j = 0;
	int_map = (int **)malloc(sizeof(int *) * list->map_height);
	while (i < list->map_height)
	{
		int_map[i] = (int *)malloc(sizeof(int) * list->map_width);
		j = 0;
		while (j < list->map_width)
		{
			int_map[i][j] = 0;
			j++;
		}
		i++;
	}	
	int_map[y][x] = 1;
	list->i_map.read_count = 0;
	recur_func(int_map, list, x, y);
	int_map_free(int_map, list);
}
