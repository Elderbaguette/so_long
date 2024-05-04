/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_utils_sequel.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aproust <aproust@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:33:59 by aproust           #+#    #+#             */
/*   Updated: 2023/02/07 10:43:12 by aproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	final_free(t_data *data)
{
	if (data->p != 0)
		free_img(data);
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

void	free_tab(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

char	*make_str(int fd)
{
	char	*buffer;
	char	*str;

	str = ft_calloc(1, 1);
	if (!str)
		return (NULL);
	buffer = get_next_line(fd);
	while (buffer)
	{
		str = ft_strjoin(str, buffer);
		free(buffer);
		buffer = get_next_line(fd);
	}
	free(buffer);
	return (str);
}

int	read_map(t_data *data, int fd)
{
	int		i;
	char	*str;

	i = 0;
	str = make_str(fd);
	while (str[++i])
	{
		if (str[0] == '\n' || (str[i] == '\n' && str[i - 1] == '\n'))
		{
			close(fd);
			return (free(str), 1);
		}
	}
	data->map = ft_split(str, '\n');
	data->cap = ft_split(str, '\n');
	close(fd);
	free(str);
	if (!*data->cap)
		return (free(data->cap), free_tab(data->map), 1);
	if (!*data->map)
		return (1);
	return (0);
}
