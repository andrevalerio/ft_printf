/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalerio <avalerio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 23:22:47 by avalerio          #+#    #+#             */
/*   Updated: 2021/04/11 20:56:58 by avalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_uintlen(unsigned int n)
{
	unsigned int	length;
	unsigned int	temp_n;

	if (n == 0)
		return (1);
	length = 0;
	if (n < 0)
	{
		length++;
		n = -n;
	}
	temp_n = n;
	while (temp_n != 0)
	{
		length++;
		temp_n = temp_n / 10;
	}
	return (length);
}

void	ft_print_zero(int width, int *print)
{
	if (width > 0)
	{
		ft_print_0_or_spc(width, ' ');
		*print = *print + width;
	}
	else
		write(1, "", 0);
}

void	ft_print_0_or_spc(int nbr, char zero)
{
	int i;

	i = 0;
	while (i < nbr)
	{
		if (zero == '0')
			write(1, "0", 1);
		else
			write(1, " ", 1);
		i++;
	}
}
