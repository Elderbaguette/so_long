/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_check_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aproust <aproust@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:05:12 by aproust           #+#    #+#             */
/*   Updated: 2023/02/08 15:00:46 by aproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_ll(char **str, int i, int j)
{
	while (str[++j])
		;
	j--;
	i = -1;
	while (str[j][++i])
	{
		if (str[j][i] != '1' && str[j][i])
			return (1);
	}
	return (0);
}

int	check_map(char **str, int i, int j)
{
	int	epc[3];

	if (!ft_memset(epc, 0, sizeof(epc)))
		return (1);
	while (str[++j])
	{
		i = -1;
		while (str[j][++i])
		{
			if (str[j][0] != '1' || str[j][ft_strlen(str[j]) - 1] != '1')
				return (1);
			if ((str[j][i] != '1' && str[j][i] != '0' && str[j][i] != 'E' &&
				str[j][i] != 'P' && str[j][i] != 'C' && str[j][i]))
				return (1);
			if (str[j][i] == 'E')
				epc[0] += 1;
			if (str[j][i] == 'P')
				epc[1] += 1;
			if (str[j][i] == 'C')
				epc[2] += 1;
		}
	}
	if (epc[0] != 1 || epc[1] != 1 || epc[2] < 1)
		return (1);
	return (0);
}

int	sl_check_error(t_data *data)
{
	int		i;
	int		j;
	char	**str;

	str = data->cap;
	j = 0;
	i = -1;
	while (str[++j])
	{
		if (ft_strlen(str[0]) != ft_strlen(str[j]))
			return (1);
	}
	j = 0;
	while (str[0][++i])
	{
		if (str[0][i] != '1' && str[0][i])
			return (1);
	}
	if (check_map(str, i, j) == 1)
		return (1);
	if (check_ll(str, i, j) == 1)
		return (1);
	if (check_path(data) == 1)
		return (1);
	return (0);
}
