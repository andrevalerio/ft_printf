/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalerio <avalerio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 19:51:07 by avalerio          #+#    #+#             */
/*   Updated: 2021/04/11 20:54:29 by avalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_string(va_list param, t_flags sfl, int *print)
{
	char	*str;
	int		width;

	width = 0;
	sfl = read_w(param, sfl);
	if (sfl.width_num > 0)
		width = sfl.width_num;
	if (sfl.precision2 == '*')
		sfl.precis_num = va_arg(param, int);
	str = va_arg(param, char *);
	if (str == NULL)
		str = "(null)";
	if (sfl.precis_num < 0)
		sfl.precis_num = ft_strlen(str);
	if (sfl.precision == '.')
		ft_print_strp(str, sfl, width, print);
	else if (width > 0 && sfl.precision != '.')
		ft_print_strw(str, sfl, width, print);
	else
	{
		*print = *print + ft_strlen(str);
		ft_putstr(str);
	}
}

void	ft_print_strw(char *str, t_flags sfl, int width, int *print)
{
	int length;

	length = ft_strlen(str);
	if (sfl.minus == '-' && length < width)
	{
		*print = *print + width;
		ft_putstr(str);
		ft_print_0_or_spc(width - length, sfl.zero);
	}
	else if (length < width)
	{
		*print = *print + width;
		ft_print_0_or_spc(width - length, sfl.zero);
		ft_putstr(str);
	}
	else
	{
		*print = *print + length;
		ft_putstr(str);
	}
}

void	ft_print_strp(char *str, t_flags sfl, int width, int *print)
{
	if ((int)ft_strlen(str) < sfl.precis_num)
		sfl.precis_num = ft_strlen(str);
	if (width == 0)
		ft_print_strp1(str, sfl, print);
	else if (width > 0 && sfl.minus != '-')
	{
		ft_print_0_or_spc(width - sfl.precis_num, sfl.zero);
		if ((width - sfl.precis_num) > 0)
			*print = *print + (width - sfl.precis_num);
		ft_print_strp1(str, sfl, print);
	}
	else
	{
		ft_print_strp1(str, sfl, print);
		ft_print_0_or_spc(width - sfl.precis_num, sfl.zero);
		if ((width - sfl.precis_num) > 0)
			*print = *print + (width - sfl.precis_num);
	}
}

void	ft_print_strp1(char *str, t_flags sfl, int *print)
{
	int j;

	j = 0;
	while (j < sfl.precis_num && str[j] != '\0')
	{
		ft_putchar(str[j]);
		j++;
		(*print)++;
	}
}
