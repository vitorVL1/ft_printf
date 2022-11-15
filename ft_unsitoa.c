/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsitoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima <vlima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 16:51:19 by vlima             #+#    #+#             */
/*   Updated: 2022/11/15 14:12:25 by vlima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_lenret(unsigned long n, char *str)
{
	if (n >= 10)
		str = ft_lenret(n / 10, str);
	*str++ = (n % 10) + '0';
	*str = 0;
	return (str);
}

char	*ft_itoa(unsigned long n)
{
	char	str[15];

	ft_lenret(n, str);
	return (ft_substr(str, 0, (ft_strlen(str))));
}
