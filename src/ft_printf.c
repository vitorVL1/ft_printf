/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima <vlima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 20:17:52 by vitorvl           #+#    #+#             */
/*   Updated: 2022/11/21 14:59:26 by vlima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"
#include	"libft.h"

int	ft_formats(va_list args, const char format)
{
	int	lent_print;

	lent_print = 0;
	if (format == 'c')
		lent_print += ft_print_char(va_arg(args, int));
	else if (format == 's')
		lent_print += ft_print_str(va_arg(args, char *));
	else if (format == 'p')
		lent_print += ft_print_ptr(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i' )
		lent_print += ft_print_nbr(va_arg(args, int));
	else if (format == 'u')
		lent_print += ft_print_uns(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		lent_print += ft_print_hex(va_arg(args, unsigned int), format);
	else if (format == '%')
		lent_print += ft_print_char(37);
	return (lent_print);
}

int	ft_printf(const char *str, ...)
{
	int		lent_print;
	int		i;
	va_list	args;

	i = 0;
	lent_print = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			lent_print += ft_formats(args, str[i + 1]);
			i++;
		}
		else
			lent_print += ft_print_char(str[i]);
		i++;
	}
	va_end(args);
	return (lent_print);
}
