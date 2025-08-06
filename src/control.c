/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 cost.c												:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: acarranz <marvin@42.fr>					+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2024/12/04 19:15:22 by acarranz		   #+#	  #+#			  */
/*	 Updated: 2024/12/04 19:15:22 by acarranz		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	find_max(t_list *list)
{
	int		i;
	t_node	*current;

	if (!list || !list->head)
		return ;
	current = list->head;
	i = 0;
	list->max = current->content;
	while (i < list->size)
	{
		if (current->content > list->max)
			list->max = current->content;
		current = current->next;
		i++;
	}
}

void	find_min(t_list *list)
{
	int		i;
	t_node	*current;

	if (!list || !list->head)
		return ;
	current = list->head;
	i = 0;
	list->min = current->content;
	while (i < list->size)
	{
		if (current->content < list->min)
			list->min = current->content;
		current = current->next;
		i++;
	}
}

void	initialize_list(t_list *list)
{
	t_node	*current;
	int		middle;
	int		i;

	current = list->head;
	i = 0;
	middle = (list->size + 1) / 2;
	while (i < list->size)
	{
		current->total_cost = 0;
		current->index = i;
		if (i < middle)
		{
			current->cost = i;
			current->r_or_rr = 0;
		}
		else
		{
			current->cost = list->size - i;
			current->r_or_rr = 1;
		}
		current = current->next;
		i++;
	}
}

void	update_list(t_list *list)
{
	initialize_list(list);
	find_min(list);
	find_max(list);
}

void	control(t_list *list_a, t_list *list_b)
{
	t_node	*cheap;
	t_node	*target;

	update_list(list_a);
	update_list(list_b);
	calculate_cost(list_a, list_b);
	cheap = cheapest_node(list_a);
	if (!cheap)
		return ;
	target = find_target(cheap, list_b);
	if (!target)
		return ;
	put_node(cheap, target, list_a, list_b);
}
