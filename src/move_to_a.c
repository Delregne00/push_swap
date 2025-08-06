/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 move_to_a.c										:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: acarranz <marvin@42.fr>					+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2024/12/04 19:32:40 by acarranz		   #+#	  #+#			  */
/*	 Updated: 2024/12/04 19:32:40 by acarranz		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	recolocate(t_list *list_b)
{
	t_node	*current;
	int		max;

	current = list_b->head;
	max = list_b->max;
	while (current->content != max)
		current = current->next;
	while (current->cost > 0)
	{
		if (current->r_or_rr == 0)
			rb(list_b);
		else
			rrb(list_b);
		current->cost -= 1;
	}
}

void	move_to_a(t_list *list_a, t_list *list_b)
{
	int	i;
	int	size;

	i = 0;
	size = list_b->size;
	while (i < size)
	{
		pa(list_a, list_b);
		i++;
	}
}
