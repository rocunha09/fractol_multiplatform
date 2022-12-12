/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ul_parse_to_hexa.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafade-o <rafade-o@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 09:31:31 by rafade-o          #+#    #+#             */
/*   Updated: 2022/07/19 12:41:08 by rafade-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	sub_ft_ul_parse_to_hexa(unsigned long nbr)
{
	if (nbr < 10)
		return (nbr + '0');
	else if (nbr == 10)
		return ('a');
	else if (nbr == 11)
		return ('b');
	else if (nbr == 12)
		return ('c');
	else if (nbr == 13)
		return ('d');
	else if (nbr == 14)
		return ('e');
	else
		return ('f');
}

char	*ft_ul_parse_to_hexa(unsigned long nbr)
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
	while (nbr >= 16)
	{
		temp = nbr % 16;
		nbr /= 16;
		str_temp[count] = sub_ft_ul_parse_to_hexa(temp);
		count++;
	}
	str_temp[count] = sub_ft_ul_parse_to_hexa(nbr);
	len = 0;
	while (count >= 0)
		str[len++] = str_temp[count--];
	free(str_temp);
	return (str);
}
