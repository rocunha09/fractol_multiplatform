/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafade-o <rafade-o@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 09:21:42 by rafade-o          #+#    #+#             */
/*   Updated: 2022/07/19 10:50:57 by rafade-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_put_hex(unsigned int nbr)
{
	char	*swap;
	int		j;

	swap = ft_ul_parse_to_hexa((unsigned long)nbr);
	j = ft_print_str(swap);
	free(swap);
	return (j);
}
