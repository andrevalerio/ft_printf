/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalerio <avalerio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 21:47:49 by avalerio          #+#    #+#             */
/*   Updated: 2021/04/11 22:08:13 by avalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_spec(va_list param, t_flags sfl, int *print)
{
	if (sfl.conv == 's')
		ft_print_string(param, sfl, print);
	if (sfl.conv == 'c' || sfl.conv == '%')
		ft_print_char(param, sfl, print);
	if (sfl.conv == 'd' || sfl.conv == 'i')
		ft_print_int(param, sfl, print);
	if (sfl.conv == 'u')
		ft_print_uint(param, sfl, print);
	if (sfl.conv == 'x' || sfl.conv == 'X')
		ft_print_hexa(param, sfl, print);
	if (sfl.conv == 'p')
		ft_print_ptr(param, sfl, print);
}

char	star_return(int *j)
{
	(*j)++;
	return ('*');
}

t_flags	check_flags(t_flags sfl)
{
	int j;

	j = 0;
	while (sfl.set[j] != '\0' && ft_strchr(FLAGS, sfl.set[j]) != 0)
		j++;
	while (sfl.set[j] != '\0' && ft_strchr(WIDTH, sfl.set[j]) != 0)
	{
		if (sfl.set[j] != '*')
			while (sfl.set[j] != '\0' && ft_strchr(WIDTH, sfl.set[j]) != 0)
				sfl.width_num = 10 * sfl.width_num + (sfl.set[j++] - '0');
		else
			sfl.width = star_return(&j);
	}
	while (sfl.set[j] != '\0' && ft_strchr(PRECISION, sfl.set[j]) != 0)
	{
		j++;
		if (sfl.set[j] != '*')
			while (sfl.set[j] != '\0' && ft_strchr(PRECISION, sfl.set[j]) != 0)
				sfl.precis_num = 10 * sfl.precis_num + (sfl.set[j++] - '0');
		else
			sfl.precision2 = star_return(&j);
	}
	return (sfl);
}

void	read_spec_form(const char *format, va_list param, int *i, int *print)
{
	t_flags sfl;
	int		j;

	j = 0;
	while (ft_strchr(FORMATS, format[*i]) != 0 && j < 20)
		sfl.set[j++] = format[(*i)++];
	sfl.set[j] = '\0';
	sfl.zero = 'z';
	if (sfl.set[0] == '0')
		sfl.zero = '0';
	if (ft_strchr(SPECIFIER, format[*i]) != 0)
	{
		sfl.minus = ft_strchr_c(sfl.set, '-');
		sfl.width = 'z';
		sfl.precision = ft_strchr_c(sfl.set, '.');
		sfl.precision2 = 'z';
		sfl.width_num = 0;
		sfl.precis_num = 0;
		sfl.conv = format[*i];
		(*i)++;
		sfl = check_flags(sfl);
		print_spec(param, sfl, print);
	}
	else
		*print = -1;
}

int		ft_printf(const char *format, ...)
{
	va_list	param;
	int		i;
	int		print;

	va_start(param, format);
	i = 0;
	print = 0;
	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			ft_putchar(format[i]);
			i++;
			print++;
		}
		else
		{
			i++;
			read_spec_form(format, param, &i, &print);
			if (print == -1)
				return (-1);
		}
	}
	va_end(param);
	return (print);
}
