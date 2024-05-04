/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aproust <aproust@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:09:13 by aproust           #+#    #+#             */
/*   Updated: 2023/02/10 13:05:07 by aproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	mapsize(t_data *data, int i)
{
	int	j;

	j = 0;
	while (data->cap[j])
		j++;
	if (i == 1)
		return (j * 64);
	return (ft_strlen(data->cap[0]) * 64);
}

int	alloc_img(t_data *data)
{
	data->img = malloc(sizeof(void *) * ((mapsize(data, 1) / 64)
				* ft_strlen(data->cap[0])));
	if (!data->img)
		return (1);
	data->c = malloc(sizeof(void *) * 3);
	if (!data->c)
		return (1);
	return (0);
}

void	so_exit(t_data *data, char c)
{
	int	i;
	int	j;

	j = 0;
	if (c == 'X')
		final_free(data);
	while (data->map[++j])
	{
		i = 0;
		while (data->map[j][++i])
		{
			if (data->map[j][i] == 'C')
				return ;
		}
	}
	final_free(data);
}

void	free_img(t_data *data)
{
	int	i;

	i = ((mapsize(data, 1) / 64) * ft_strlen(data->cap[0]));
	while (i > 0)
		mlx_destroy_image(data->mlx, data->img[--i]);
	i = 3;
	while (i > 0 && data->p != -1)
		mlx_destroy_image(data->mlx, data->c[--i]);
}

int	key_event(int keycode, t_data *data)
{
	static int	i = 0;

	if (keycode == 65307)
	{
		final_free(data);
		return (1);
	}
	if (keycode == 100 || keycode == 97 || keycode == 119 || keycode == 115)
	{
		if (keycode == 100 || keycode == 97)
			data->key = keycode;
		if (playermove(data, keycode) == 0)
		{
			i++;
			free_img(data);
			if (so_long(data) == 1 || counter(data, i) == 1)
				return (final_free(data), 1);
		}
	}
	(void)data;
	return (0);
}
