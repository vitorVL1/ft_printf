/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima <vlima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:23:08 by vlima             #+#    #+#             */
/*   Updated: 2022/11/21 14:56:30 by vlima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_print_uns(unsigned int n);
int		ft_print_ptr(unsigned long long ptr);
int		ft_print_hex(unsigned int numero, const char variavel);
int		ft_hex_len(unsigned	int numero);
int		ft_print_str(char *str);
int		ft_formats(va_list args, const char format);
int		ft_print_char(int c);
int		ft_print_nbr(int nbr);

#endif