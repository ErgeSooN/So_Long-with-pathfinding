/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_constraction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayaman <ayaman@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:01:22 by ayaman            #+#    #+#             */
/*   Updated: 2022/10/26 18:55:53 by ayaman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//mapteki satırın uzunluğunu bulup bize satırı döndürüyor
static char	*put_line(char *buffer, int *bf)
{
	char	*line;
	int		buffer_index;
	int		line_length;
	int		temp_index;

	buffer_index = (*bf);
	line_length = 0;
	temp_index = buffer_index;
	while (buffer[buffer_index] != '\n' && buffer[buffer_index] != '\0')
	{
		line_length++;
		buffer_index++;
	}
	(*bf) += line_length + 1;
	buffer_index = temp_index;
	temp_index = 0;
	line = (char *) malloc(sizeof(char) * (line_length + 1));
	while (temp_index < line_length)
		line[temp_index++] = buffer[buffer_index++];
	line[temp_index] = '\0';
	return (line);
}

//oluşturulan mapteki map_height uzunluğunu bulmamıza yarıyor
static int	count_nl(char *buffer, int size)
{
	int	enter;
	int	i;

	i = 0;
	enter = 0;
	while (i < size)
	{
		if (buffer[i] == '\n')
			enter++;
		i++;
	}
	return (enter + 1);
}

//bulmuş olduğumuz mapin uzunluğunu ve genişliğini değişkenlere aktarım
static char	**map_builder(char *buffer, int size, t_game *sl)
{
	int		enter;
	int		index;
	int		bf;
	char	**map;

	index = 0;
	bf = 0;
	enter = count_nl(buffer, size);
	sl->map_height = enter;
	map = (char **) malloc(sizeof(char *) * enter);
	while (index < enter)
	{
		map[index] = put_line(buffer, &bf);
		index++;
	}
	sl->map_width = ft_strlen(map[0]);
	return (map);
}

//map'e yer ayırdıp okuma işlemini gerçekleştirdik
char	**map_constractor(t_game *sl, int fd)
{
	char	buffer[10000];
	int		size;
	int		bytes;

	bytes = 1;
	size = 0;
	ft_reset(buffer);
	while (bytes)
	{
		bytes = read(fd, &buffer[size], 1);
		if (bytes == -1)
		{
			free(sl);
			exit(1);
		}
		size++;
	}
	return (map_builder(buffer, size, sl));
}
