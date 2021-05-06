/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalerio <avalerio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 11:54:05 by avalerio          #+#    #+#             */
/*   Updated: 2021/04/11 22:04:13 by avalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	read_w(va_list param, t_flags sfl)
{
	if (sfl.width == '*')
	{
		sfl.width_num = va_arg(param, int);
		if (sfl.width_num < 0)
		{
			sfl.width_num = -sfl.width_num;
			sfl.minus = '-';
		}
	}
	return (sfl);
}

void	ft_print_char(va_list param, t_flags sfl, int *print)
{
	int c;
	int width;

	width = 0;
	sfl = read_w(param, sfl);
	if (sfl.width_num > 0)
		width = sfl.width_num;
	if (sfl.precision2 == '*')
	{
		sfl.precis_num = va_arg(param, int);
		if (sfl.precis_num < 0)
			sfl.precis_num = -sfl.precis_num;
	}
	if (sfl.conv == 'c')
	{
		c = va_arg(param, int);
		ft_print_char1(c, sfl, width, print);
	}
	else
	{
		c = '%';
		ft_print_char1(c, sfl, width, print);
	}
}

void	ft_print_char1(int c, t_flags sfl, int width, int *print)
{
	if (sfl.minus != '-' && sfl.zero != '0' && width == 0)
	{
		(*print)++;
		ft_putchar(c);
	}
	else if (sfl.minus == '-')
	{
		if (width == 0)
			width = 1;
		*print = *print + width;
		ft_putchar(c);
		ft_print_0_or_spc(width - 1, ' ');
	}
	else if (sfl.zero == '0' && width != 0)
	{
		*print = *print + width;
		ft_print_0_or_spc(width - 1, '0');
		ft_putchar(c);
	}
	else
	{
		*print = *print + width;
		ft_print_0_or_spc(width - 1, ' ');
		ft_putchar(c);
	}
}
