//header

#include "../../includes/fractol.h"

/*
	[ ]valiar impressão de helper caso haja algum erro de input
	[ ]validar a quantidade correta de argumentos
	[ ]validar se o nome dos fractais estão corretos
	[ ]validar os parâmetros para o julia set (para isso será necessário um atod ou atof)
	[ ]validar caminho ideal (quando todos os parâmetros estão corretos)
*/
void validate_and_filter_args(t_vars *v, int argc, char **argv)
{
	char *fractol;		
	char *parameter_x;
	char *parameter_y;

	fractol = argv[1];
	parameter_x = argv[2];
	parameter_y = argv[3];

    printf("%s\n", fractol);
	printf("%s\n", parameter_x);
	printf("%s\n", parameter_y);

}