/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: big <rafade-o@student.42.rio>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 18:20:52 by big               #+#    #+#             */
/*   Updated: 2022/06/11 12:42:57 by rafade-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s_temp;
	unsigned char	c_temp;

	s_temp = (unsigned char *)s;
	c_temp = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (*s_temp == c_temp)
			return (s_temp);
		s_temp++;
		i++;
	}
	return (0);
}
