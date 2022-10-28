/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayaman <ayaman@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:01:35 by ayaman            #+#    #+#             */
/*   Updated: 2022/10/27 12:44:45 by ayaman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//map dörtgen mi kontrolünü yapıyoruz
int	is_ret(t_game *sl)
{
	char	**map;
	int		i;

	map = sl->map;
	i = 1;
	while (i < sl->map_height)
	{
		if (ft_strlen(map[i]) != ft_strlen(map[0]))
			return (1);
		i++;
	}
	sl->map_width = ft_strlen(map[0]);
	return (0);
}

//duvar var mı yok mu kontrolü yapıyoruz
int	is_wall(char **map, int x, int y)
{
	int	i;
	int	j;
	int	len;

	j = 0;
	i = 0;
	while (j < x)
	{
		if (map[0][j] != '1' || map[y - 1][j] != '1')
			return (1);
		j++;
	}
	i = 1;
	len = ft_strlen(map[i]);
	while (i < y)
	{
		if (map[i][0] != '1' || map[i][len - 1] != '1')
			return (1);
		i++;
	}
	return (0);
}

//P,E,C var mı yok mu kontrolü yapıyoruz
int	is_pec(t_game *sl)
{
	int	i;
	int	j;

	i = 0;
	while (i < sl->map_height)
	{
		j = 0;
		while (j < sl->map_width)
		{
			if (sl->map[i][j] == 'P')
				sl->ply++;
			else if (sl->map[i][j] == 'E')
				sl->exit++;
			else if (sl->map[i][j] == 'C')
				sl->coins++;
			j++;
		}
		i++;
	}
	if (sl->ply != 1 || sl->exit == 0 || sl->coins == 0)
		return (1);
	return (0);
}

//mapte P,E,C,1,0 dışında bir karakter var mı kontrolü yapıyoruz
int	is_chr(t_game *sl)
{
	int	i;
	int	j;

	i = 0;
	while (i < sl->map_height)
	{
		j = 0;
		while (j < sl->map_width)
		{
			if (sl->map[i][j] != 'P' && sl->map[i][j] != 'E'
				&& sl->map[i][j] != 'C'
				&& sl->map[i][j] != '0' && sl->map[i][j] != '1')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

//mapteki kontollerin genel dağıtımının yapıldığı yer
int	map_validation(t_game *sl)
{
	if (is_ret(sl))
		return (1);
	if (is_pec(sl))
		return (1);
	if (is_chr(sl))
		return (1);
	if (is_wall(sl->map, sl->map_width, sl->map_height))
		return (1);
	placeholder(sl, sl->ey, sl->ex);
	if (sl->i_map.read_count != sl->coins + 1)
		return (1);
	return (0);
}
