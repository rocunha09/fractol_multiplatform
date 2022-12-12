/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: big <rafade-o@student.42.rio>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 23:03:01 by big               #+#    #+#             */
/*   Updated: 2022/11/05 23:03:28 by big              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	size_of_list;

	size_of_list = 0;
	while (lst)
	{
		lst = lst->next;
		size_of_list++;
	}
	return (size_of_list);
}
