/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarranz <acarranz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:28:37 by acarranz          #+#    #+#             */
/*   Updated: 2024/12/08 16:37:16 by acarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	move_to_top(t_list *list, t_node *target, char list_name)
{
	int	size;
	int	index;

	size = list->size;
	index = target->index;
	if (index <= size / 2)
	{
		while (list->head->content != target->content)
		{
			if (list_name == 'a')
				ra(list);
			else
				rb(list);
		}
	}
	else
	{
		while (list->head->content != target->content)
		{
			if (list_name == 'a')
				rra(list);
			else
				rrb(list);
		}
	}
}

t_node	*find_t_node_by_value(t_list *list, int value)
{
	t_node	*current;
	int		i;

	current = list->head;
	i = 0;
	while (i < list->size)
	{
		if (current->content == value)
			return (current);
		current = current->next;
		i++;
	}
	return (NULL);
}

void	update_t_node_indexes(t_list *list)
{
	t_node	*current;
	int		i;

	current = list->head;
	i = 0;
	while (i < list->size)
	{
		current->index = i;
		current = current->next;
		i++;
	}
}

void	sort_five_elements(t_list *list_a, t_list *list_b)
{
	int		min;
	int		max;
	t_node	*max_t_node;
	t_node	*min_t_node;

	fin_min(list_a, &min);
	fin_max(list_a, &max);
	update_t_node_indexes(list_a);
	max_t_node = find_t_node_by_value(list_a, max);
	min_t_node = find_t_node_by_value(list_a, min);
	move_to_top(list_a, max_t_node, 'a');
	pb(list_a, list_b);
	update_t_node_indexes(list_a);
	move_to_top(list_a, min_t_node, 'a');
	pb(list_a, list_b);
	sort_three_elements(list_a);
	pa(list_a, list_b);
	pa(list_a, list_b);
	ra(list_a);
}
