/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_color_trgb.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafade-o <rafade-o@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 17:48:27 by rafade-o          #+#    #+#             */
/*   Updated: 2023/01/08 17:53:12 by rafade-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/fractol.h"

int	color_get_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

/*
 Function retrieves the transparancy channel from the color
*/
int	color_get_t(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

/*
 Function retrieves the red channel from the color
*/
int	color_get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

/*
 Function retrieves the green channel from the color
*/
int	color_get_g(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

/*
 Function retrieves the blue channel from the color
*/
int	color_get_b(int trgb)
{
	return (trgb & 0xFF);
}
