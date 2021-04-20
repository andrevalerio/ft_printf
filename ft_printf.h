/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalerio <avalerio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 23:25:06 by avalerio          #+#    #+#             */
/*   Updated: 2021/04/11 22:28:22 by avalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

# define HEXA_LOW "0123456789abcdef"
# define HEXA_UP "0123456789ABCDEF"
# define SPECIFIER "cspdiuxX%"
# define FORMATS "-0.*123456789"
# define FLAGS "-0"
# define WIDTH	"*0123456789"
# define PRECISION ".*0123456789"

typedef	struct	s_flags
{
	char		minus;
	char		zero;
	char		width;
	int			width_num;
	char		precision;
	char		precision2;
	int			precis_num;
	char		conv;
	char		set[20];
}				t_flags;

/*
** FILE ft_printf.c
*/
int				ft_printf(const char *format, ...);
void			print_spec(va_list param, t_flags sfl, int *print);
char			star_return(int *j);
t_flags			check_flags(t_flags sfl);
void			read_spec_form(const char *format, va_list param, int *i,
				int *print);
/*
** FILE ft_printf_string.c
*/
void			ft_print_string(va_list param, t_flags sfl, int *print);
void			ft_print_strw(char *str, t_flags sfl, int width,
				int *print);
void			ft_print_strp(char *str, t_flags sfl, int width, int *print);
void			ft_print_strp1(char *str, t_flags sfl, int *print);
/*
** FILE ft_printf_char.c
*/
t_flags			read_w(va_list param, t_flags sfl);
void			ft_print_char(va_list param, t_flags sfl, int *print);
void			ft_print_char1(int c, t_flags sfl, int width, int *print);
/*
** FILE ft_printf_numtype.c
*/
void			ft_print_numtype(char conv, unsigned int nbr);
void			ft_print_int(va_list param, t_flags sfl, int *print);
void			ft_print_uint(va_list param, t_flags sfl, int *print);
void			ft_print_hexa(va_list param, t_flags sfl, int *hexa);
void			ft_print_ptr(va_list param, t_flags sfl, int *print);
/*
** FILE ft_printf_num.c
*/
void			ft_print_nump(int nbr, t_flags sfl, int width, int *print);
void			ft_print_nump1(int nbr, t_flags sfl, int width, int *print);
void			ft_print_nump2(int nbr, t_flags sfl, int width, int *print);
void			ft_print_nump3(int nbr, t_flags sfl, int width, int *print);
void			ft_print_nump4(int nbr, t_flags sfl, int width, int *print);
/*
** FILE ft_printf_negnum.c
*/
void			ft_print_intn(int nbr, t_flags sfl, int width, int *print);
void			ft_print_intn1(int nbr, t_flags sfl, int width, int *print);
void			ft_print_intn4(int nbr, t_flags sfl, int width, int *print);
void			ft_print_intn2(int nbr, t_flags sfl, int width, int *print);
void			ft_print_intn3(int nbr, t_flags sfl, int width, int *print);
/*
** FILE ft_printf_negnum2.c
*/
void			ft_print_intn5(int nbr, t_flags sfl, int width);
/*
** FILE ft_printf_ux.c
*/
void			ft_print_ux(unsigned int nbr, t_flags sfl, int width,
				int *print);
void			ft_print_ux1(unsigned int nbr, t_flags sfl, int width,
				int *print);
void			ft_print_ux4(unsigned int nbr, t_flags sfl, int width,
				int *print);
void			ft_print_ux2(unsigned int nbr, t_flags sfl, int width,
				int *print);
void			ft_print_ux3(unsigned int nbr, t_flags sfl, int width,
				int *print);
/*
** FILE ft_printf_ptr.c
*/
void			ft_print_pa(unsigned long int nbr, t_flags sfl, int width,
				int *print);
void			ft_print_pa1(unsigned long int nbr, t_flags sfl, int width,
				int *print);
void			ft_print_pa2(unsigned long int nbr, t_flags sfl, int width,
				int *print);
void			ft_print_pa3(unsigned long int nbr, t_flags sfl, int width,
				int *print);
void			ft_print_pa4(unsigned long int nbr, t_flags sfl, int *print);
/*
** FILE ft_printf_utils1.c
*/
void			ft_putchar(char c);
void			ft_putstr(char *str);
char			*ft_strchr(const char *s, int c);
char			ft_strchr_c(const char *s, int c);
size_t			ft_strlen(const char *s);
/*
** FILE ft_printf_utils2.c
*/
int				ft_intlen(int n);
void			ft_putnbr(long int n);
void			ft_putnbr_base(unsigned long int n, char *base);
void			ft_intlen_base(unsigned long int n, char *base, int *length);
void			ft_putnbr_u(unsigned int n);
/*
** FILE ft_printf_utils3.c
*/
void			ft_print_0_or_spc(int nbr, char zero);
void			ft_print_zero(int width, int *print);
int				ft_uintlen(unsigned int n);

#endif
