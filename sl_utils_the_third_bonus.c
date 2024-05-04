/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_utils_the_third_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aproust <aproust@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:05:22 by aproust           #+#    #+#             */
/*   Updated: 2023/02/10 12:34:40 by aproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

void	free_counter_error(t_data *data, int i)
{
	while (--i >= 0)
		mlx_destroy_image(data->mlx, data->c[i]);
	data->p = -1;
}
