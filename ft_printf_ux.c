/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ux.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalerio <avalerio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 23:26:26 by avalerio          #+#    #+#             */
/*   Updated: 2021/04/11 16:30:58 by avalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_ux(unsigned int nbr, t_flags sfl, int width, int *print)
{
	int length;

	length = 0;
	if (sfl.conv == 'x' || sfl.conv == 'X')
		ft_intlen_base(nbr, HEXA_LOW, &length);
	else
		length = ft_uintlen(nbr);
	if ((sfl.minus == '-' || sfl.zero == '0') && width == 0
	&& sfl.precision != '.')
	{
		ft_print_numtype(sfl.conv, nbr);
		*print = *print + length;
	}
	else if (sfl.minus == '-' && (width != 0 || sfl.precis_num != 0))
		ft_print_ux1(nbr, sfl, width, print);
	else
		ft_print_ux2(nbr, sfl, width, print);
}

void	ft_print_ux1(unsigned int nbr, t_flags sfl, int width, int *print)
{
	int length;

	length = 0;
	if (sfl.conv == 'x' || sfl.conv == 'X')
		ft_intlen_base(nbr, HEXA_LOW, &length);
	else
		length = ft_uintlen(nbr);
	if (sfl.precis_num != 0 && sfl.precis_num < length)
		sfl.precis_num = length;
	if (length < width || length < sfl.precis_num)
		ft_print_ux4(nbr, sfl, width, print);
	else
	{
		ft_print_numtype(sfl.conv, nbr);
		*print = *print + length;
	}
}

void	ft_print_ux4(unsigned int nbr, t_flags sfl, int width, int *print)
{
	int length;

	length = 0;
	if (sfl.conv == 'x' || sfl.conv == 'X')
		ft_intlen_base(nbr, HEXA_LOW, &length);
	else
		length = ft_uintlen(nbr);
	if (sfl.precis_num != 0 && sfl.precis_num < length)
		sfl.precis_num = length;
	if (width > 0 && sfl.precis_num == 0)
	{
		ft_print_numtype(sfl.conv, nbr);
		ft_print_0_or_spc(width - length, ' ');
	}
	else if (sfl.precis_num != 0)
	{
		ft_print_0_or_spc(sfl.precis_num - length, '0');
		ft_print_numtype(sfl.conv, nbr);
		ft_print_0_or_spc(width - sfl.precis_num, ' ');
	}
	if (width > length && width > sfl.precis_num)
		*print = *print + width;
	else
		*print = *print + sfl.precis_num;
}

void	ft_print_ux2(unsigned int nbr, t_flags sfl, int width, int *print)
{
	int length;

	length = 0;
	if (sfl.conv == 'x' || sfl.conv == 'X')
		ft_intlen_base(nbr, HEXA_LOW, &length);
	else
		length = ft_uintlen(nbr);
	if (sfl.precis_num >= 0 && sfl.precis_num < length)
		sfl.precis_num = length;
	if (length < width || length < sfl.precis_num)
		ft_print_ux3(nbr, sfl, width, print);
	else
	{
		ft_print_numtype(sfl.conv, nbr);
		*print = *print + length;
	}
}

void	ft_print_ux3(unsigned int nbr, t_flags sfl, int width, int *print)
{
	int length;

	length = 0;
	if (sfl.conv == 'x' || sfl.conv == 'X')
		ft_intlen_base(nbr, HEXA_LOW, &length);
	else
		length = ft_uintlen(nbr);
	if (sfl.precis_num >= 0 && sfl.precis_num < length)
		sfl.precis_num = length;
	if (width > 0 && (sfl.precision != '.' || sfl.precis_num == -1))
		ft_print_0_or_spc(width - length, sfl.zero);
	else if (sfl.precision == '.' && sfl.precis_num > 0)
	{
		ft_print_0_or_spc(width - sfl.precis_num, ' ');
		ft_print_0_or_spc(sfl.precis_num - length, '0');
	}
	ft_print_numtype(sfl.conv, nbr);
	if (width > length && width > sfl.precis_num)
		*print = *print + width;
	else
		*print = *print + sfl.precis_num;
}
