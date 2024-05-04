/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aproust <aproust@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:24:50 by aproust           #+#    #+#             */
/*   Updated: 2022/12/01 11:54:15 by aproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define B10 "0123456789"
# define L16 "0123456789abcdef"
# define B16 "0123456789ABCDEF"

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdint.h>

int		ft_printf(const char *format, ...);
size_t	ft_strlen(const char *str);
int		ft_putchar(char c, int fd);
int		putnb(int n, int fd);
int		ps(char *s);
int		pu(unsigned long int n, unsigned long int sb, const char *base);
int		ft_printf_sequel(char c, va_list args);

#endif
