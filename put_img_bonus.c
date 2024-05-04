/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aproust <aproust@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:16:07 by aproust           #+#    #+#             */
/*   Updated: 2023/02/01 12:52:01 by aproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	put_road(t_data *data, int x, int y, int i)
{
	int		h;
	int		w;

	data->img[i] = mlx_xpm_file_to_image(data->mlx, "img/road.xpm", &w, &h);
	if (!data->img[i])
		return (free_img_error(data, i), 1);
	mlx_put_image_to_window (data->mlx, data->win, data->img[i], x, y);
	return (0);
}

int	put_wall(t_data *data, int x, int y, int i)
{
	int		h;
	int		w;

	data->img[i] = mlx_xpm_file_to_image(data->mlx, "img/hay.xpm", &w, &h);
	if (!data->img[i])
		return (free_img_error(data, i), 1);
	mlx_put_image_to_window (data->mlx, data->win, data->img[i], x, y);
	return (0);
}

int	put_item(t_data *data, int x, int y, int i)
{
	int		h;
	int		w;

	data->img[i] = mlx_xpm_file_to_image(data->mlx, "img/carrot.xpm", &w, &h);
	if (!data->img[i])
		return (free_img_error(data, i), 1);
	mlx_put_image_to_window (data->mlx, data->win, data->img[i], x, y);
	return (0);
}

int	put_exit(t_data *data, int x, int y, int i)
{
	int		h;
	int		w;

	data->img[i] = mlx_xpm_file_to_image(data->mlx, "img/baby_pig.xpm", &w, &h);
	if (!data->img[i])
		return (free_img_error(data, i), 1);
	mlx_put_image_to_window (data->mlx, data->win, data->img[i], x, y);
	return (0);
}

int	put_player(t_data *data, int x, int y, int i)
{
	int		h;
	int		w;

	if (data->key == 100 || data->key == 0)
	{
		data->img[i] = mlx_xpm_file_to_image(data->mlx, "img/char.xpm", &w, &h);
		if (!data->img[i])
			return (free_img_error(data, i), 1);
		mlx_put_image_to_window (data->mlx, data->win, data->img[i], x, y);
	}
	if (data->key == 97)
	{
		data->img[i] = mlx_xpm_file_to_image(data->mlx, "img/rc.xpm", &w, &h);
		if (!data->img[i])
			return (free_img_error(data, i), 1);
		mlx_put_image_to_window (data->mlx, data->win, data->img[i], x, y);
	}
	return (0);
}
