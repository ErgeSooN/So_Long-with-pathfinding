/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayaman <ayaman@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 15:50:17 by ayaman            #+#    #+#             */
/*   Updated: 2022/10/27 12:52:26 by ayaman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//x butonuna tıklandığında çıkış yapmamızı sağlayan fonk.
void	exit_game(int mousecode, t_game *game)
{
	exit(0);
}
