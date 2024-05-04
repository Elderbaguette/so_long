/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_utils_sequel_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aproust <aproust@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:33:59 by aproust           #+#    #+#             */
/*   Updated: 2023/02/10 11:51:16 by aproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_tab(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

void	final_free(t_data *data)
{
	if (data->p != 0)
	{
		free_img(data);
		free(data->c);
	}
	free(data->img);
	free_tab(data->cap);
	free_tab(data->map);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
}

int	close_window(t_data *data)
{
	final_free(data);
	return (0);
}

int	put_ske(t_data *data, int x, int y, int i)
{
	int		h;
	int		w;

	data->img[i] = mlx_xpm_file_to_image(data->mlx, "img/skeleton.xpm", &w, &h);
	if (!data->img[i])
		return (free_img_error(data, i), 1);
	mlx_put_image_to_window (data->mlx, data->win, data->img[i], x, y);
	return (0);
}

int	put_img(t_data *data, int *player_xy, int *index)
{
	int	c;

	while (data->map[index[0]][++index[1]])
	{
		if (data->map[index[0]][index[1]] == '0')
			c = put_road(data, player_xy[0] += 64, player_xy[1], ++index[2]);
		else if (data->map[index[0]][index[1]] == '1')
			c = put_wall(data, player_xy[0] += 64, player_xy[1], ++index[2]);
		else if (data->map[index[0]][index[1]] == 'C')
			c = put_item(data, player_xy[0] += 64, player_xy[1], ++index[2]);
		else if (data->map[index[0]][index[1]] == 'E')
			c = put_exit(data, player_xy[0] += 64, player_xy[1], ++index[2]);
		else if (data->map[index[0]][index[1]] == 'P')
			c = put_player(data, player_xy[0] += 64, player_xy[1], ++index[2]);
		else if (data->map[index[0]][index[1]] == 'X')
		{
			if (player_xy[0] / 64 + 1 <= data->p)
				c = put_ske(data, player_xy[0] += 64, player_xy[1], ++index[2]);
			else
				c = put_rsk(data, player_xy[0] += 64, player_xy[1], ++index[2]);
		}
		if (c == 1)
			return (1);
	}
	return (0);
}
