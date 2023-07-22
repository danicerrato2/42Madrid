/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <dcerrato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 19:34:51 by dcerrato          #+#    #+#             */
/*   Updated: 2023/07/22 20:29:26 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	error(char *msg)
{
	ft_putstr_fd(msg, 2);
	return (-1);
}

int	main(int argc, char *argv[], char *envp[])
{
	if (argc < 5 && argv)
		return (error("Número de argumentos incorrecto\n"));
	return (0);
}

/*
Estudio:

infile command1 | ... | commandN outfile

access (const char *pathname, int mode)
	pathname	->	Ruta al comando a ejecutar
	mode		->	Accesos a comprobar (mirar en manual - F_OK, R_OK, W_OK...)

	Retornos:
		Success	->	Retorna 0
		Failure	->	Retorna -1 (en errno se indica el error)

	Cosas a tener en cuenta:
		No se si es mejor comprobar primero y luego execve o directamente execve y mirar si errores
		( mirar errores en lista de manual )


execve (const char *pathname, char *argv[], char *envp[])
	pathname	->	Ruta al comando
	argv		->	Argumentos para el comando. argv[0] debe ser el comando. Debe terminar en null pointer
		( Para argv podria usar ft_split al argv[i] del main )
	envp		->	enviroment del comando, suele tener formato key=value. Debe terminar en null pointer

	Retornos:
		Success	->	No retorna nada
		Failure	->	Retorna -1 (en errno se indica el error)

	Cosas a tener en cuenta:
		Problemas por numero de argumentos, comando existente, argumentos correctos para comando, permisos de ejecucion...
			( mirar errores en lista del manual )


fork ()
	No tiene argumentos

	Retornos:
		Success	->	PID del hijo en el proceso padre, 0 en el proceso hijo
			( Si quiero que siga el padre: if pid != 0 ...; si quiero que siga el hijo: if pid == 0 )
		Failure	->	Retorna -1 (en errno se indica el error)

	Cosas a tener en cuenta:
		Numero de procesos maximo...
			( mirar errores en lista del manual )


perror (const char *str)
	str	-> Mensaje de error que se escribira en sdterr

	Cosas a tener en cuenta:
		Escribe "str: err_msg"
		Podria usarlo para que los procesos hijos escriban los errores


strerror (int errnum)
	errnum	->	Codigo de error

	Retornos:
		Success	->	Retorna una string donde describe el error
		Failure	->	Retorna una frase de error desconocido

	Cosas a tener en cuenta:
		Podria usarlo para escribir los errores en vez de usar perror


dup (int oldfd) - dup2 (int olfd, newfd)
	oldfd	->	Descriptor de un fichero
	newfd	->	Nuevo numero de descriptor de fichero

	Cosas a tener en cuenta:
		dup abre el fichero en el descriptor de fichero con numero mas bajo y lo devuelve
		dup2 abre el fichero en el descriptor de fichero que se le indique en newfd

*/
