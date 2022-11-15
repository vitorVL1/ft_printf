/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima <vlima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 20:17:52 by vitorvl           #+#    #+#             */
/*   Updated: 2022/11/15 17:32:59 by vlima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"
#include	"libft.h"

int	ft_print_nbr(int nbr)
{
	char	*str;
	int		len;

	str = ft_itoa(nbr);
	len = ft_putstr(str);
	return (len);
}

int	ft_print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_print_str(char *str)
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
		lent_print += ft_print_char('%');
	return (lent_print);
}

int	ft_printf(const char *str, ...)
{
	int		lent_print;
	int		i;
	va_list	args;

	i = 0;

	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			lent_print += ft_formats(str, args);
		}
		else
			lent_print += ft_printchar(str[i]);
		i++;
	}
	va_end(args);
}
