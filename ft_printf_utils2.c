/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalerio <avalerio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 23:01:01 by avalerio          #+#    #+#             */
/*   Updated: 2021/04/07 22:07:03 by avalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_intlen(int n)
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

void	ft_putnbr(long int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr(-n);
	}
	else if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putchar((n % 10) + '0');
	}
	else
		ft_putchar(n + '0');
}

void	ft_putnbr_base(unsigned long int n, char *base)
{
	unsigned int base_len;

	base_len = ft_strlen(base);
	if (n >= base_len)
	{
		ft_putnbr_base(n / base_len, base);
		ft_putnbr_base(n % base_len, base);
	}
	else
	{
		write(1, base + n, 1);
	}
}

void	ft_intlen_base(unsigned long int n, char *base, int *length)
{
	unsigned int base_len;

	base_len = ft_strlen(base);
	if (n >= base_len)
	{
		ft_intlen_base(n / base_len, base, length);
		ft_intlen_base(n % base_len, base, length);
	}
	else
	{
		(*length)++;
	}
}

void	ft_putnbr_u(unsigned int n)
{
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putchar((n % 10) + '0');
	}
	else
		ft_putchar(n + '0');
}
