/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: big <rafade-o@student.42.rio>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 01:16:02 by big               #+#    #+#             */
/*   Updated: 2022/07/19 10:40:36 by rafade-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_put_number(int nbr)
{
	char	*swap;
	int		j;

	swap = ft_itoa(nbr);
	j = ft_print_str(swap);
	free(swap);
	return (j);
}
