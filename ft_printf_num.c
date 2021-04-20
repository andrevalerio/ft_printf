/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalerio <avalerio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 21:30:31 by avalerio          #+#    #+#             */
/*   Updated: 2021/04/11 16:20:27 by avalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_nump(int nbr, t_flags sfl, int width, int *print)
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
		ft_print_nump1(nbr, sfl, width, print);
	else
		ft_print_nump2(nbr, sfl, width, print);
}

void	ft_print_nump1(int nbr, t_flags sfl, int width, int *print)
{
	int length;

	length = ft_intlen(nbr);
	if (sfl.precis_num != 0 && sfl.precis_num < length)
		sfl.precis_num = length;
	if (length < width || length < sfl.precis_num)
		ft_print_nump4(nbr, sfl, width, print);
	else
	{
		ft_putnbr(nbr);
		*print = *print + length;
	}
}

void	ft_print_nump4(int nbr, t_flags sfl, int width, int *print)
{
	int length;

	length = ft_intlen(nbr);
	if (sfl.precis_num != 0 && sfl.precis_num < length)
		sfl.precis_num = length;
	if (width > 0 && sfl.precis_num == 0)
	{
		ft_putnbr(nbr);
		ft_print_0_or_spc(width - length, ' ');
	}
	else if (sfl.precis_num != 0)
	{
		ft_print_0_or_spc(sfl.precis_num - length, '0');
		ft_putnbr(nbr);
		ft_print_0_or_spc(width - sfl.precis_num, ' ');
	}
	if (width > length && width > sfl.precis_num)
		*print = *print + width;
	else
		*print = *print + sfl.precis_num;
}

void	ft_print_nump2(int nbr, t_flags sfl, int width, int *print)
{
	int length;

	length = ft_intlen(nbr);
	if (sfl.precis_num > 0 && sfl.precis_num < length)
		sfl.precis_num = length;
	if (length < width || length < sfl.precis_num)
		ft_print_nump3(nbr, sfl, width, print);
	else
	{
		ft_putnbr(nbr);
		*print = *print + length;
	}
}

void	ft_print_nump3(int nbr, t_flags sfl, int width, int *print)
{
	int length;

	length = ft_intlen(nbr);
	if (sfl.precis_num > 0 && sfl.precis_num < length)
		sfl.precis_num = length;
	if (width > 0 && (sfl.precision != '.' || sfl.precis_num == -1))
		ft_print_0_or_spc(width - length, sfl.zero);
	else if (sfl.precision == '.' && sfl.precis_num == 0)
		ft_print_0_or_spc(width - length, ' ');
	else if (sfl.precision == '.')
	{
		ft_print_0_or_spc(width - sfl.precis_num, ' ');
		ft_print_0_or_spc(sfl.precis_num - length, '0');
	}
	ft_putnbr(nbr);
	if (width > length && width > sfl.precis_num)
		*print = *print + width;
	else
		*print = *print + sfl.precis_num;
}
