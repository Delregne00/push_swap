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

t_node	*max_node(t_list *list_b)
{
	t_node	*current;
	int		max;
	int		i;

	i = 0;
	max = list_b->max;
	current = list_b->head;
	while (i < list_b->size)
	{
		if (current->content == max)
			break ;
		current = current->next;
		i++;
	}
	return (current);
}

void	calculate_cost_for_max_node(t_node *current_a, t_node *max)
{
	current_a->target = max->index;
	if (current_a->r_or_rr == max->r_or_rr)
	{
		if (current_a->cost > max->cost)
			current_a->total_cost = current_a->cost;
		else if (current_a->cost < max->cost)
			current_a->total_cost = max->cost;
		else
			current_a->total_cost = current_a->cost;
	}
	else
		current_a->total_cost = current_a->cost + max->cost;
}

void	calculate_cost_for_middle_node(t_node *current_a, t_node *current_b)
{
	current_a->target = current_b->next->index;
	if (current_a->r_or_rr == current_b->next->r_or_rr)
	{
		if (current_a->cost > current_b->next->cost)
			current_a->total_cost = current_a->cost;
		else if (current_a->cost < current_b->next->cost)
			current_a->total_cost = current_b->next->cost;
		else
			current_a->total_cost = current_a->cost;
	}
	else
		current_a->total_cost = current_a->cost + current_b->next->cost;
}

void	cost_node(t_node *node, t_list *list_b, t_node *max)
{
	t_node	*current_b;
	int		j;

	current_b = list_b->head;
	j = 0;
	while (j < list_b->size)
	{
		if (node->content > list_b->max
			|| node->content < list_b->min)
		{
			calculate_cost_for_max_node(node, max);
			break ;
		}
		else if (node->content < current_b->content
			&& node->content > current_b->next->content)
		{
			calculate_cost_for_middle_node(node, current_b);
			break ;
		}
		current_b = current_b->next;
		j++;
	}
}

void	calculate_cost(t_list *list_a, t_list *list_b)
{
	t_node	*current_a;
	t_node	*max;
	int		i;

	max = max_node(list_b);
	current_a = list_a->head;
	i = 0;
	while (i < list_a->size)
	{
		cost_node(current_a, list_b, max);
		current_a = current_a->next;
		i++;
	}
}
