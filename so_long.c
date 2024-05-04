/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aproust <aproust@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 16:12:29 by marbaret          #+#    #+#             */
/*   Updated: 2023/02/08 11:27:36 by aproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	so_long(t_data *data)
{
	int	index[3];
	int	player_xy[2];

	if (ft_memset(player_xy, 0, sizeof(player_xy)) == NULL
		|| ft_memset(index, -1, sizeof(index)) == NULL)
		return (1);
	player_xy[0] = -64;
	while (data->map[++index[0]])
	{
		index[1] = -1;
		if (put_img(data, player_xy, index) == 1)
			return (1);
		player_xy[1] += 64;
		player_xy[0] = -64;
	}
	return (0);
}

int	playermove_wd(t_data *data, int i, int j, int event_trigger)
{
	if (event_trigger == 119)
	{
		if (data->map[j - 1][i] == 'E')
			so_exit(data);
		if (data->map[j - 1][i] == '0' || data->map[j - 1][i] == 'C')
		{
			data->map[j - 1][i] = 'P';
			data->map[j][i] = '0';
			return (0);
		}
	}
	else if (event_trigger == 100)
	{
		if (data->map[j][i + 1] == 'E')
			so_exit(data);
		if (data->map[j][i + 1] == '0' || data->map[j][i + 1] == 'C')
		{
			data->map[j][i + 1] = 'P';
			data->map[j][i] = '0';
			return (0);
		}
	}
	return (1);
}

int	playermove_sa(t_data *data, int i, int j, int event_trigger)
{
	if (event_trigger == 115)
	{
		if (data->map[j + 1][i] == 'E')
			so_exit(data);
		if (data->map[j + 1][i] == '0' || data->map[j + 1][i] == 'C')
		{
			data->map[j + 1][i] = 'P';
			data->map[j][i] = '0';
			return (0);
		}
	}
	else if (event_trigger == 97)
	{
		if (data->map[j][i - 1] == 'E')
			so_exit(data);
		if (data->map[j][i - 1] == '0' || data->map[j][i - 1] == 'C')
		{
			data->map[j][i - 1] = 'P';
			data->map[j][i] = '0';
			return (0);
		}
	}
	return (1);
}

int	playermove(t_data *data, int event_trigger)
{
	int		i;
	int		j;

	j = 0;
	while (data->map[++j])
	{
		i = 0;
		while (data->map[j][++i])
		{
			if (data->map[j][i] == 'P')
			{
				if (playermove_wd(data, i, j, event_trigger) == 0)
					return (0);
				if (playermove_sa(data, i, j, event_trigger) == 0)
					return (0);
			}
		}
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_data	data;
	int		fd;

	if (ac != 2 || check_arg(av[1]) == 1)
		return (ft_printf("Error\nWrong arguments\n"), 1);
	data.p = 1;
	fd = open(av[1], O_RDONLY);
	if ((fd == -1) || read_map(&data, fd) == 1)
		return (ft_printf("Error\nFailed attempt to read the map\n"), 1);
	if (sl_check_error(&data) == 1)
	{
		free_tab(data.cap);
		free_tab(data.map);
		ft_printf("Error\nFound an error while looking at the map\n");
		return (1);
	}
	if (init_mlx(&data) == 1)
		return (ft_printf("Error\nFailed attempt to use Minilibx\n"), 1);
	if (alloc_img(&data) == 1 || so_long(&data) == 1)
		return (final_free(&data), ft_printf("Error\nDisplay map fail\n"), 1);
	mlx_hook(data.win, 17, 0, close_window, &data);
	mlx_key_hook(data.win, key_event, &data);
	mlx_loop(data.mlx);
}
