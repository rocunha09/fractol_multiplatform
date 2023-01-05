/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: big <rafade-o@student.42.rio>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 14:39:51 by big               #+#    #+#             */
/*   Updated: 2022/12/30 21:42:35 by big              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

static int  check_valid_dots(char *str)
{
    int i;
    int dot;

    i = 0;
    dot = 0;
    while (str[i] != '\0')
    {
        if (ft_isdot(str[i]))
            dot++;
        if (dot > 1)
            return (dot);
        i++;
    }
    return (dot);
}

static int  check_valid_signals(char *str)
{
    int i;
    int signals;

    i = 0;
    signals = 0;
    while (str[i] != '\0')
    {
        if (ft_is_signal(str[i]))
            signals++;
        if (signals > 1)
            return (0);
        i++;
    }
    return (1);
}

static double  insert_float_point(double nbr, int places)
{
    while (places > 1)
    {
        nbr /= 10;
        places--;
    }
    return (nbr);
}

double ft_atod(char *str)
{
    t_atod_vars v;

    v = new_atod_vars();
    if (check_valid_dots(str) == 0)
        return ((double)ft_atoi(str));
    if (((check_valid_dots(str) == 1) && check_valid_signals(str)) == 0)
        return(0.0);
    while (special_chars(str[v.i]) || str[v.i] == '+')
        v.i++;
    if (str[v.i++] == '-')
        v.signal = -1;
    while (str[v.i])
    {
        if (ft_isdigit(str[v.i]) || ft_isdot(str[v.i]))
        {
            if (ft_isdigit(str[v.i]))
                v.nbr = (v.nbr * 10) + (str[v.i] - '0');
            else if (ft_isdot(str[v.i]))
                v.dot_pos = v.i;
        }
        else
            return (0.0);
        v.i++;
    }
    return (v.signal * insert_float_point(v.nbr, (v.i - v.dot_pos)));
}

