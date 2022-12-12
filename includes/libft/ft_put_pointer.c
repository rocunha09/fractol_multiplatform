/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafade-o <rafade-o@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 09:23:49 by rafade-o          #+#    #+#             */
/*   Updated: 2022/07/19 10:41:08 by rafade-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_put_pointer(long long unsigned int p)
{
	int		j;
	char	*swap;

	swap = ft_ul_parse_to_hexa((unsigned long)p);
	j = ft_print_str("0x");
	j += ft_print_str(swap);
	free(swap);
	return (j);
}
