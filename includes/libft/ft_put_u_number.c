/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_u_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: big <rafade-o@student.42.rio>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 01:17:29 by big               #+#    #+#             */
/*   Updated: 2022/07/19 11:44:35 by rafade-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_ul_parse_to_str(unsigned long nbr)
{
	int		len;
	int		count;
	int		temp;
	char	*str_temp;
	char	*str;

	len = ft_ul_number_len(nbr);
	str_temp = ft_calloc(1, (len + 1));
	str = ft_calloc(1, (len + 1));
	count = 0;
	while (nbr >= 10)
	{
		temp = nbr % 10;
		nbr /= 10;
		str_temp[count] = temp + '0';
		count++;
	}
	str_temp[count] = nbr + '0';
	len = 0;
	while (count >= 0)
		str[len++] = str_temp[count--];
	free(str_temp);
	return (str);
}

int	ft_put_u_number(unsigned int nbr)
{
	unsigned int		n;
	unsigned int		u_int_max;
	int					j;
	char				*swap;

	u_int_max = 4294967295;
	n = (u_int_max + (nbr) + 1);
	swap = ft_ul_parse_to_str(n);
	j = ft_print_str(swap);
	free(swap);
	return (j);
}
