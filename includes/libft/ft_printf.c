/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: big <rafade-o@student.42.rio>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 22:03:07 by big               #+#    #+#             */
/*   Updated: 2022/07/19 10:38:10 by rafade-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_arg(char c, va_list list)
{
	if (c == 'c')
		return (ft_print_char(va_arg(list, int)));
	if (c == 's')
		return (ft_print_str(va_arg(list, char *)));
	if (c == 'p')
		return (ft_put_pointer(va_arg(list, long long unsigned int)));
	if (c == 'd' || c == 'i')
		return (ft_put_number(va_arg(list, int)));
	if (c == 'u')
		return (ft_put_u_number(va_arg(list, unsigned int)));
	if (c == 'x')
		return (ft_put_hex(va_arg(list, unsigned int)));
	if (c == 'X')
		return (ft_put_toupper_hex(va_arg(list, unsigned int)));
	if (c == '%')
		return (ft_print_char('%'));
	return (0);
}

int	ft_printf(const char *str, ...)
{	
	int		i;
	int		j;
	va_list	list;

	i = 0;
	j = 0;
	va_start(list, str);
	while (str[i] != '\0')
	{
		if (str[i] != '%')
		{
			j += ft_print_char(str[i]);
			i++;
		}
		else if (str[i] == '%')
		{
			i++;
			if (ft_strchr("cspdiuxX%", str[i]))
				j += print_arg(str[i], list);
			i++;
		}
	}
	va_end(list);
	return (j);
}
