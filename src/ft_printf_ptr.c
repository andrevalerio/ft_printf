/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalerio <avalerio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 09:19:51 by avalerio          #+#    #+#             */
/*   Updated: 2021/04/11 20:04:03 by avalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_pa(unsigned long int nbr, t_flags sfl, int width, int *print)
{
	int length;

	length = 0;
	if (nbr > 0 || sfl.precision != '.')
		ft_intlen_base(nbr, HEXA_LOW, &length);
	if ((sfl.minus == '-' || sfl.zero == '0') && width == 0)
	{
		write(1, "0x", 2);
		if (nbr == 0 && sfl.precision == '.' && sfl.precis_num == 0)
			*print = *print + 2;
		else
		{
			ft_putnbr_base(nbr, HEXA_LOW);
			*print = *print + length + 2;
		}
	}
	else if (sfl.minus == '-' && width != 0)
		ft_print_pa1(nbr, sfl, width, print);
	else
		ft_print_pa2(nbr, sfl, width, print);
}

void	ft_print_pa1(unsigned long int nbr, t_flags sfl, int width, int *print)
{
	int length;

	length = 0;
	if (nbr > 0 || sfl.precision != '.')
		ft_intlen_base(nbr, HEXA_LOW, &length);
	if ((length + 2) < width)
	{
		write(1, "0x", 2);
		ft_print_pa3(nbr, sfl, width, print);
		ft_print_0_or_spc(width - length - 2, ' ');
	}
	else
	{
		write(1, "0x", 2);
		if (nbr == 0 && sfl.precision == '.' && sfl.precis_num == 0)
			*print = *print + 2;
		else
		{
			ft_putnbr_base(nbr, HEXA_LOW);
			*print = *print + length + 2;
		}
	}
}

void	ft_print_pa2(unsigned long int nbr, t_flags sfl, int width, int *print)
{
	int length;

	length = 0;
	if (nbr > 0 || sfl.precision != '.')
		ft_intlen_base(nbr, HEXA_LOW, &length);
	if ((length + 2) < width)
	{
		ft_print_0_or_spc(width - length - 2, ' ');
		write(1, "0x", 2);
		ft_print_pa3(nbr, sfl, width, print);
	}
	else
		ft_print_pa4(nbr, sfl, print);
}

void	ft_print_pa3(unsigned long int nbr, t_flags sfl, int width, int *print)
{
	if (nbr == 0 && sfl.precision == '.' && sfl.precis_num == 0)
		*print = *print + width;
	else
	{
		ft_putnbr_base(nbr, HEXA_LOW);
		*print = *print + width;
	}
}

void	ft_print_pa4(unsigned long int nbr, t_flags sfl, int *print)
{
	int length;

	length = 0;
	if (nbr > 0 || sfl.precision != '.')
		ft_intlen_base(nbr, HEXA_LOW, &length);
	write(1, "0x", 2);
	if (nbr == 0 && sfl.precision == '.' && sfl.precis_num == 0)
		*print = *print + 2;
	else if (sfl.precision == '.' && sfl.precis_num > 0)
	{
		ft_print_0_or_spc(sfl.precis_num - length, '0');
		if (nbr > 0)
			ft_putnbr_base(nbr, HEXA_LOW);
		*print = *print + sfl.precis_num + 2;
	}
	else
	{
		ft_putnbr_base(nbr, HEXA_LOW);
		*print = *print + length + 2;
	}
}
