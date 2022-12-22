//header

#include "../../includes/fractol.h"

void print_information_to_user(void)
{
    ft_printf("\n------------------------------");
    ft_printf("------------------------------\n");
    ft_printf("You can use some options to execute this program.\n");
    ft_printf("\n");
    ft_printf("Execute program with name of fractol do you want to see:\n");
    ft_printf("   Ex: bash->./fractol \"modelbrot\"\n");
    ft_printf("   Ex: bash->./fractol \"burning_ship\"\n");
    ft_printf("\n");
    ft_printf("For Julia set is necessary to pass two values zr and zi,\n");
    ft_printf("both values can be: (value <= 2 && value >= -2).\n");
    ft_printf("   Ex: bash->./fractol \"julia\" 1.82 1.0\n");
    ft_printf("------------------------------");
    ft_printf("------------------------------\n\n");
}