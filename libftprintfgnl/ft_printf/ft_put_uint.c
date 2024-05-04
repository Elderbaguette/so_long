/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_uint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aproust <aproust@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:45:35 by aproust           #+#    #+#             */
/*   Updated: 2022/11/25 17:40:43 by aproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pu(unsigned long int n, unsigned long int sb, const char *base)
{
	if (n < sb)
		return (ft_putchar(base[n % sb], 1));
	if (n >= sb)
		return (pu(n / sb, sb, base) + ft_putchar(base[n % sb], 1));
	return (0);
}
