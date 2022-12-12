/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: big <rafade-o@student.42.rio>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 18:24:08 by big               #+#    #+#             */
/*   Updated: 2022/05/25 02:14:35 by big              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*calc;
	size_t	i;

	if (!nmemb && !size)
	{
		nmemb = 1;
		size = 1;
	}
	calc = malloc (nmemb * size);
	if (!calc)
		return (NULL);
	i = 0;
	while (i < (nmemb * size))
	{
		((char *)calc)[i] = '\0';
		i++;
	}
	return (calc);
}
