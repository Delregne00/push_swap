/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarranz <acarranz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:28:37 by acarranz          #+#    #+#             */
/*   Updated: 2024/12/09 18:12:54 by acarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	verificar_signo(const char *cadena)
{
	int	i;
	int	signos_encontrados;

	i = 0;
	signos_encontrados = 0;
	while (cadena[i])
	{
		if (cadena[i] == '+' || cadena[i] == '-')
		{
			signos_encontrados++;
			if (signos_encontrados > 1 || (i != 0 && cadena[i - 1] != ' '))
				return (0);
		}
		i++;
	}
	return (1);
}

int	verificar_caracteres(const char *cadena)
{
	int	i;

	i = 0;
	while (cadena[i])
	{
		if (!(ft_isdigit(cadena[i]) || cadena[i] == ' '
				|| cadena[i] == '+' || cadena[i] == '-'))
			return (0);
		i++;
	}
	return (1);
}

int	verificar_limites(const char *cadena)
{
	long long	numero;

	numero = ft_atoll(cadena);
	return (numero >= -2147483648 && numero <= 2147483647);
}

int	verificar_duplicados(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_strcmp(argv[i], argv[j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	parsing(int argc, char *argv[])
{
	int	i;

	i = 1;
	if (argc == 1)
		return (1);
	while (i < argc)
	{
		if (!verificar_signo(argv[i]) || !verificar_caracteres(argv[i])
			|| !verificar_limites(argv[i]) || !verificar_duplicados(argc, argv))
		{
			printf("Error\n");
			return (0);
		}
		i++;
	}
	return (1);
}
