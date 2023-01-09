/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_information.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafade-o <rafade-o@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 18:08:55 by rafade-o          #+#    #+#             */
/*   Updated: 2023/01/08 18:11:11 by rafade-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void	print_information_to_user(void)
{
	ft_printf("\n------------------------------");
	ft_printf("------------------------------\n");
	ft_printf("You can use some options to execute this program.\n");
	ft_printf("\n");
	ft_printf("Execute program with name of fractol do you want to see:\n");
	ft_printf("   Ex: bash->./fractol \"mandelbrot\"\n");
	ft_printf("   Ex: bash->./fractol \"burning_ship\"\n");
	ft_printf("\n");
	ft_printf("For Julia set is necessary to pass two values and ");
	ft_printf("both values can be: (value <= 2 && value >= -2).\n");
	ft_printf("c.real and c.imaginary,\n");
	ft_printf("   Ex: bash->./fractol \"julia\" 1.82 1.0\n");
	ft_printf("\n");
	ft_printf("ideas for julia values: -0.4 0.6 or 0.285 0.01 or -0.8 0.156\n");
	ft_printf("------------------------------");
	ft_printf("------------------------------\n\n");
}
