/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_utils_the_third.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aproust <aproust@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 11:27:41 by aproust           #+#    #+#             */
/*   Updated: 2023/02/08 15:02:04 by aproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_arg(char *av)
{
	int	i;

	i = -1;
	while (av[++i])
		;
	if (av[i - 4] == '.' && av[i - 3] == 'b' && av[i - 2] == 'e'
		&& av[i - 1] == 'r')
		return (0);
	return (1);
}

int	init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (free_tab(data->cap), free_tab(data->map), 1);
	data->win = mlx_new_window(data->mlx, mapsize(data, 0),
			mapsize(data, 1), "Hog Rider Quest");
	if (!data->win)
		return (free_tab(data->cap), free_tab(data->map), 1);
	return (0);
}

int	put_img(t_data *data, int *player_p, int *index)
{
	int	chk;

	while (data->map[index[0]][++index[1]])
	{
		if (data->map[index[0]][index[1]] == '0')
			chk = put_road(data, player_p[0] += 64, player_p[1], ++index[2]);
		else if (data->map[index[0]][index[1]] == '1')
			chk = put_wall(data, player_p[0] += 64, player_p[1], ++index[2]);
		else if (data->map[index[0]][index[1]] == 'C')
			chk = put_item(data, player_p[0] += 64, player_p[1], ++index[2]);
		else if (data->map[index[0]][index[1]] == 'E')
			chk = put_exit(data, player_p[0] += 64, player_p[1], ++index[2]);
		else if (data->map[index[0]][index[1]] == 'P')
			chk = put_player(data, player_p[0] += 64, player_p[1], ++index[2]);
		if (chk == 1)
			return (1);
	}
	return (0);
}

void	free_img_error(t_data *data, int i)
{
	while (i > 0)
		mlx_destroy_image(data->mlx, data->img[--i]);
	data->p = 0;
}
