/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_raw_color.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafade-o <rafade-o@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 18:03:47 by rafade-o          #+#    #+#             */
/*   Updated: 2023/01/08 18:04:03 by rafade-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/fractol.h"

int	calculate_raw_color(double t)
{
	int	raw_color;

	raw_color = color_get_trgb(0,
			(int)(9 * (1 - t) * t * t * t * 255),
			(int)(15 * (1 - t) * t * t * 255),
			(int)(8.5 * (1 - t) * t * 255)
			);
	return (raw_color % 0xFFFFFF);
}
