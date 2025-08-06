/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 main.c												:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: acarranz <marvin@42.fr>					+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2024/12/04 19:32:34 by acarranz		   #+#	  #+#			  */
/*	 Updated: 2024/12/04 19:32:34 by acarranz		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "includes/push_swap.h"

static void	sort_more_five(t_list *list_a, t_list *list_b, int argc)
{
	int	i;

	pb(list_a, list_b);
	pb(list_a, list_b);
	i = 0;
	while (i < argc)
	{
		control(list_a, list_b);
		i++;
	}
	recolocate(list_b);
	move_to_a(list_a, list_b);
}

void	sort_lists(t_list *list_a, t_list *list_b, int argc)
{
	if (list_a->size == 2)
	{
		if (list_a->head->content > list_a->tail->content)
			sa(list_a);
	}
	else if (list_a->size == 3)
		sort_three_elements(list_a);
	else if (list_a->size == 4)
		sort_four_elements(list_a, list_b);
	else if (list_a->size == 5)
		sort_five_elements(list_a, list_b);
	else
	{
		sort_more_five(list_a, list_b, argc);
	}
}

int	ini_lists(t_list *list_a, t_list *list_b, int argc, char **argv)
{
	int	i;
	int	nbr;

	i = 1;
	ini_list(list_a);
	ini_list(list_b);
	while (i < argc)
	{
		nbr = ft_atoi(argv[i]);
		if (!add_t_node(list_a, nbr))
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	list_a;
	t_list	list_b;

	if (argc == 1)
		return (0);
	if (argc <= 2)
	{
		if (!(verificar_limites(argv[1])) || !(verificar_caracteres(argv[1])))
		{
			printf("Error\n");
			return (-1);
		}
		return (0);
	}
	if (!parsing(argc, argv) || !ini_lists(&list_a, &list_b, argc, argv))
		return (-1);
	if (!(check_list(&list_a, argc)))
	{
		del_list(&list_a);
		return (-1);
	}
	sort_lists(&list_a, &list_b, argc);
	del_list(&list_a);
	del_list(&list_b);
	return (0);
}
