/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_utils_final_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aproust <aproust@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:06:43 by aproust           #+#    #+#             */
/*   Updated: 2023/02/10 11:49:02 by aproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	put_rsk(t_data *data, int x, int y, int i)
{
	int		h;
	int		w;

	data->img[i] = mlx_xpm_file_to_image(data->mlx, "img/rskelly.xpm", &w, &h);
	if (!data->img[i])
		return (free_img_error(data, i), 1);
	mlx_put_image_to_window (data->mlx, data->win, data->img[i], x, y);
	return (0);
}

void	free_img_error(t_data *data, int i)
{
	while (i > 0)
		mlx_destroy_image(data->mlx, data->img[--i]);
	data->p = 0;
	free(data->c);
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
