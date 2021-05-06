/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_numtype.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalerio <avalerio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 16:07:42 by avalerio          #+#    #+#             */
/*   Updated: 2021/04/11 16:22:38 by avalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_numtype(char conv, unsigned int nbr)
{
	if (conv == 'u')
		ft_putnbr_u(nbr);
	if (conv == 'x')
		ft_putnbr_base(nbr, HEXA_LOW);
	if (conv == 'X')
		ft_putnbr_base(nbr, HEXA_UP);
}

void	ft_print_int(va_list param, t_flags sfl, int *print)
{
	int nbr;
	int	width;

	width = 0;
	sfl = read_w(param, sfl);
	if (sfl.width_num > 0)
		width = sfl.width_num;
	if (sfl.precision2 == '*')
		sfl.precis_num = va_arg(param, int);
	nbr = va_arg(param, int);
	if (sfl.precis_num < 0)
		sfl.precis_num = -1;
	if (nbr == 0 && sfl.precision == '.' && sfl.precis_num == 0)
		ft_print_zero(width, print);
	else if (nbr >= 0)
		ft_print_nump(nbr, sfl, width, print);
	else
		ft_print_intn(nbr, sfl, width, print);
}

void	ft_print_uint(va_list param, t_flags sfl, int *print)
{
	unsigned int	u_nbr;
	int				width;

	width = 0;
	sfl = read_w(param, sfl);
	if (sfl.width_num > 0)
		width = sfl.width_num;
	if (sfl.precision2 == '*')
	{
		sfl.precis_num = va_arg(param, int);
		if (sfl.precis_num < 0)
			sfl.precis_num = -1;
	}
	u_nbr = va_arg(param, unsigned int);
	if (u_nbr == 0 && sfl.precision == '.' && sfl.precis_num == 0)
		ft_print_zero(width, print);
	else
		ft_print_ux(u_nbr, sfl, width, print);
}

void	ft_print_hexa(va_list param, t_flags sfl, int *print)
{
	unsigned int	u_nbr;
	int				width;

	width = 0;
	sfl = read_w(param, sfl);
	if (sfl.width_num > 0)
		width = sfl.width_num;
	if (sfl.precision2 == '*')
	{
		sfl.precis_num = va_arg(param, int);
		if (sfl.precis_num < 0)
			sfl.precis_num = -1;
	}
	u_nbr = va_arg(param, unsigned int);
	if (u_nbr == 0 && sfl.precision == '.' && sfl.precis_num == 0)
		ft_print_zero(width, print);
	else
		ft_print_ux(u_nbr, sfl, width, print);
}

void	ft_print_ptr(va_list param, t_flags sfl, int *print)
{
	unsigned long int	u_nbr;
	int					width;

	width = 0;
	sfl = read_w(param, sfl);
	if (sfl.width_num > 0)
		width = sfl.width_num;
	if (sfl.precision2 == '*')
	{
		sfl.precis_num = va_arg(param, int);
		if (sfl.precis_num < 0)
			sfl.precis_num = 0;
	}
	u_nbr = va_arg(param, unsigned long int);
	ft_print_pa(u_nbr, sfl, width, print);
}
