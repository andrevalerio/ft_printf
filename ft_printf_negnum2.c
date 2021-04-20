/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_negnum2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalerio <avalerio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 22:08:53 by avalerio          #+#    #+#             */
/*   Updated: 2021/04/10 15:05:05 by avalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_intn5(int nbr, t_flags sfl, int width)
{
	int length;

	if (sfl.precision == '.' && sfl.precis_num != -1)
		length = ft_intlen(-nbr);
	else
		length = ft_intlen(nbr);
	if (sfl.zero == '0')
	{
		write(1, "-", 1);
		ft_print_0_or_spc(width - length, sfl.zero);
	}
	else
	{
		ft_print_0_or_spc(width - length, sfl.zero);
		write(1, "-", 1);
	}
}
