/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_toupper_hex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafade-o <rafade-o@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 09:25:02 by rafade-o          #+#    #+#             */
/*   Updated: 2022/07/19 12:34:39 by rafade-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_put_toupper_hex(unsigned long nbr)
{
	char	*swap;
	char	*str;
	int		j;
	int		i;

	swap = ft_ul_parse_to_hexa((unsigned long)nbr);
	str = ft_calloc(1, (ft_strlen(swap) + 1));
	i = -1;
	while (swap[++i] != '\0')
		str[i] = ft_toupper(swap[i]);
	j = ft_print_str(str);
	free(swap);
	free(str);
	return (j);
}
