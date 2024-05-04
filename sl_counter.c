/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_counter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aproust <aproust@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:28:39 by aproust           #+#    #+#             */
/*   Updated: 2023/02/10 12:36:36 by aproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	zero_to_height(t_data *data, char nb, int *p, int c)
{
	int	h;
	int	w;

	if (nb == '0')
		data->c[c] = mlx_xpm_file_to_image(data->mlx, "img/nb/0.xpm", &w, &h);
	else if (nb == '1')
		data->c[c] = mlx_xpm_file_to_image(data->mlx, "img/nb/1.xpm", &w, &h);
	else if (nb == '2')
		data->c[c] = mlx_xpm_file_to_image(data->mlx, "img/nb/2.xpm", &w, &h);
	else if (nb == '3')
		data->c[c] = mlx_xpm_file_to_image(data->mlx, "img/nb/3.xpm", &w, &h);
	else if (nb == '4')
		data->c[c] = mlx_xpm_file_to_image(data->mlx, "img/nb/4.xpm", &w, &h);
	else if (nb == '5')
		data->c[c] = mlx_xpm_file_to_image(data->mlx, "img/nb/5.xpm", &w, &h);
	else if (nb == '6')
		data->c[c] = mlx_xpm_file_to_image(data->mlx, "img/nb/6.xpm", &w, &h);
	else if (nb == '7')
		data->c[c] = mlx_xpm_file_to_image(data->mlx, "img/nb/7.xpm", &w, &h);
	else if (nb == '8')
		data->c[c] = mlx_xpm_file_to_image(data->mlx, "img/nb/8.xpm", &w, &h);
	if (!data->c[c])
		return (free_counter_error(data, c), 1);
	mlx_put_image_to_window (data->mlx, data->win, data->c[c], p[0], p[1]);
	return (0);
}

int	nine(t_data *data, char nb, int *p, int c)
{
	int	h;
	int	w;

	if (nb == '9')
		data->c[c] = mlx_xpm_file_to_image(data->mlx, "img/nb/9.xpm", &w, &h);
	if (!data->c[c])
		return (free_counter_error(data, c), 1);
	mlx_put_image_to_window (data->mlx, data->win, data->c[c], p[0], p[1]);
	return (0);
}

void	short_number(t_data *data, int *array, int *p, char *str)
{
	p[2] = zero_to_height(data, '0', p, ++array[1]);
	p[0] += 64;
	if (ft_strlen(str) == 1)
	{
		p[2] = zero_to_height(data, '0', p, ++array[1]);
		p[0] += 64;
	}
}

int	put_nb(t_data *data, char *str, int *p)
{
	int	array[2];

	if (!ft_memset(array, -1, sizeof(array)))
		return (1);
	p[0] -= 64;
	if (ft_strlen(str) <= 2)
	{
		short_number(data, array, p, str);
		if (p[2] == 1)
			return (1);
	}
	while (++array[0] < 3 && str[array[0]])
	{
		if (str[array[0]] >= '0' && str[array[0]] <= '8')
			p[2] = zero_to_height(data, str[array[0]], p, ++array[1]);
		else if (str[array[0]] <= '9')
			p[2] = nine(data, str[array[0]], p, ++array[1]);
		p[0] += 64;
	}
	if (p[2] == 1)
		return (free(str), final_free(data), 1);
	return (0);
}

int	counter(t_data *data, int nb)
{
	int		p[3];
	char	*str;

	p[0] = mapsize (data, 0) / 2 - 48;
	p[1] = mapsize (data, 1) - 64;
	str = ft_itoa(nb);
	if (nb >= 999)
		p[2] = put_nb(data, "999", p);
	else if (nb >= 100)
		p[2] = put_nb(data, str, p);
	else if (nb >= 10)
		p[2] = put_nb(data, str, p);
	else if (nb < 10)
		p[2] = put_nb(data, str, p);
	free(str);
	if (p[2] == 1)
		return (1);
	return (0);
}
