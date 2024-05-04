/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_check_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aproust <aproust@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:36:18 by aproust           #+#    #+#             */
/*   Updated: 2023/02/08 15:01:01 by aproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_path_sequel(int i, int j, t_data *data)
{
	j = 0;
	while (data->cap[++j])
	{
		i = 0;
		while (data->cap[j][++i])
		{
			if (data->cap[j][i] == 'P')
			{
				if (data->cap[j - 1][i] == '0' || data->cap[j - 1][i] == 'C')
					data->cap[j - 1][i] = 'P';
				if (data->cap[j + 1][i] == '0' || data->cap[j + 1][i] == 'C')
					data->cap[j + 1][i] = 'P';
				if (data->cap[j][i - 1] == '0' || data->cap[j][i - 1] == 'C')
					data->cap[j][i - 1] = 'P';
				if (data->cap[j][i + 1] == '0' || data->cap[j][i + 1] == 'C')
					data->cap[j][i + 1] = 'P';
			}
		}
	}
}

int	check_if_playable_sequel(int i, int j, t_data *data)
{
	while (data->cap[++j])
	{
		i = -1;
		while (data->cap[j][++i])
		{
			if (data->cap[j][i] == 'E')
			{
				if (data->cap[j - 1][i] == 'P')
					return (0);
				if (data->cap[j + 1][i] == 'P')
					return (0);
				if (data->cap[j][i - 1] == 'P')
					return (0);
				if (data->cap[j][i + 1] == 'P')
					return (0);
			}
		}
	}
	return (1);
}

int	check_if_playable(int i, int j, t_data *data)
{
	j = -1;
	while (data->cap[++j])
	{
		i = -1;
		while (data->cap[j][++i])
		{
			if (data->cap[j][i] == 'C')
				return (1);
		}
	}
	j = -1;
	if (check_if_playable_sequel(i, j, data) == 0)
		return (0);
	return (1);
}

int	check_path(t_data *data)
{
	int		i;
	int		j;
	int		l;

	j = 0;
	l = 0;
	i = 0;
	while (data->cap[++j])
	{
		i = 0;
		while (data->cap[j][++i])
		{
			if (data->cap[j][i] == '0' || data->cap[j][i] == 'C')
				l++;
		}
	}
	while (--l)
		check_path_sequel(i, j, data);
	if (check_if_playable(i, j, data) == 0)
		return (0);
	return (1);
}
