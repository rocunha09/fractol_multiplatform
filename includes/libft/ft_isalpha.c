/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafade-o <rafade-o@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 11:47:28 by rafade-o          #+#    #+#             */
/*   Updated: 2022/05/05 16:54:26 by rafade-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	int	low_case_letters;
	int	up_case_letters;

	up_case_letters = (c > 64 && c < 91);
	low_case_letters = (c > 96 && c < 123);
	if (low_case_letters || up_case_letters)
		return (1);
	return (0);
}
