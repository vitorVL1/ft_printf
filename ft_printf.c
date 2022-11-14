/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitorvl <vitorvl@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 20:17:52 by vitorvl           #+#    #+#             */
/*   Updated: 2022/11/14 21:22:07 by vitorvl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
int ft_printchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_formats(va_list args, const char format)
{
	int	lent_print;

	lent_print = 0;
	if (format == 'c')
		lent_print += ft_printchar(va_arg(args, int));
	else if (format == 's')
		lent_print += ft_printstr(va_arg(args, char *));
	else if (format == 'p')
		lent_print += ft_print_ptr(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
		lent_print += ft_printnbr(va_arg(args, int));
	else if (format == 'u')
		lent_print += ft_print_unsigned(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		lent_print += ft_print_hex(va_arg(args, unsigned int), format);
	else if (format == '%')
		lent_print += ft_printpercent();
	return (lent_print);
}

int	ft_printf(const char *str, ...)
{
	int lent_print;
	int i;
	i = 0;
	va_list args;
	va_start(args, str);
	while(str[i])
	{
		if(str[i] == %)
		{
			
		}
		else 
			lent_print += ft_printchar(str[i]);
		i++;
	}
	va_end(args);
}d