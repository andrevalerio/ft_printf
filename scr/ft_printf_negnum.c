/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_negnum.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalerio <avalerio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 21:45:35 by avalerio          #+#    #+#             */
/*   Updated: 2021/04/11 16:19:26 by avalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_intn(int nbr, t_flags sfl, int width, int *print)
{
	int length;

	length = ft_intlen(nbr);
	if ((sfl.minus == '-' || sfl.zero == '0') && width == 0
	&& sfl.precision != '.')
	{
		ft_putnbr(nbr);
		*print = *print + length;
	}
	else if (sfl.minus == '-' && width != 0)
		ft_print_intn1(nbr, sfl, width, print);
	else
		ft_print_intn2(nbr, sfl, width, print);
}

void	ft_print_intn1(int nbr, t_flags sfl, int width, int *print)
{
	int length;

	if (sfl.precision == '.')
		length = ft_intlen(-nbr);
	else
		length = ft_intlen(nbr);
	if (sfl.precis_num != 0 && sfl.precis_num < length)
		sfl.precis_num = length;
	if (length < width || length < sfl.precis_num)
		ft_print_intn4(nbr, sfl, width, print);
	else
	{
		ft_putnbr(nbr);
		*print = *print + length;
		if (sfl.precision == '.' && nbr != -2147483648)
			(*print)++;
	}
}

void	ft_print_intn4(int nbr, t_flags sfl, int width, int *print)
{
	int length;

	if (sfl.precision == '.')
		length = ft_intlen(-nbr);
	else
		length = ft_intlen(nbr);
	if (sfl.precision == '.' && sfl.precis_num < length)
		sfl.precis_num = length;
	if (width > 0 && sfl.precis_num == 0)
	{
		ft_putnbr(nbr);
		ft_print_0_or_spc(width - length, ' ');
	}
	else if (sfl.precision == '.')
	{
		write(1, "-", 1);
		ft_print_0_or_spc(sfl.precis_num - length, '0');
		ft_putnbr(-nbr);
		ft_print_0_or_spc(width - sfl.precis_num - 1, ' ');
	}
	if (sfl.precis_num > width || width == sfl.precis_num)
		*print = *print + sfl.precis_num + 1;
	else
		*print = *print + width;
}

void	ft_print_intn2(int nbr, t_flags sfl, int width, int *print)
{
	int length;

	if (sfl.precision == '.' && sfl.precis_num != -1)
		length = ft_intlen(-nbr);
	else
		length = ft_intlen(nbr);
	if (sfl.precision == '.' && sfl.precis_num < length && sfl.precis_num != -1)
		sfl.precis_num = length;
	if (length < width || length < sfl.precis_num)
		ft_print_intn3(nbr, sfl, width, print);
	else
	{
		ft_putnbr(nbr);
		*print = *print + length;
		if (sfl.precision == '.' && nbr != -2147483648 && sfl.precis_num != -1)
			(*print)++;
	}
}

void	ft_print_intn3(int nbr, t_flags sfl, int width, int *print)
{
	int length;

	if (sfl.precision == '.' && sfl.precis_num != -1)
		length = ft_intlen(-nbr);
	else
		length = ft_intlen(nbr);
	if (sfl.precision == '.' && sfl.precis_num < length && sfl.precis_num != -1)
		sfl.precis_num = length;
	if (width > 0 && (sfl.precis_num == 0 || sfl.precis_num == -1))
	{
		ft_print_intn5(nbr, sfl, width);
	}
	else if (sfl.precision == '.')
	{
		ft_print_0_or_spc(width - sfl.precis_num - 1, ' ');
		write(1, "-", 1);
		ft_print_0_or_spc(sfl.precis_num - length, '0');
	}
	ft_putnbr(-nbr);
	if (sfl.precis_num > width || width == sfl.precis_num)
		*print = *print + sfl.precis_num + 1;
	else
		*print = *print + width;
}
