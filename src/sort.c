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

#include "../includes/push_swap.h"

void	fin_min(t_list *list, int *min)
{
	t_node	*current;
	int		count;

	if (!list || !list->head)
		return ;
	current = list->head;
	*min = current->content;
	count = 0;
	while (count < list->size)
	{
		if (current->content < *min)
			*min = current->content;
		current = current->next;
		count++;
	}
}

void	fin_max(t_list *list, int *max)
{
	t_node	*current;
	int		count;

	if (!list || !list->head)
		return ;
	current = list->head;
	*max = current->content;
	count = 0;
	while (count < list->size)
	{
		if (current->content > *max)
			*max = current->content;
		current = current->next;
		count++;
	}
}

void	sort_three_elements(t_list *list)
{
	int	first;
	int	second;
	int	third;

	first = list->head->content;
	second = list->head->next->content;
	third = list->tail->content;
	if (first > second && second < third && first < third)
		sa(list);
	else if (first > second && second > third && first > third)
	{
		sa(list);
		rra(list);
	}
	else if (first > second && second < third && first > third)
		ra(list);
	else if (first < second && second > third && first < third)
	{
		sa(list);
		ra(list);
	}
	else if (first < second && second > third && first > third)
		rra(list);
}

void	sort_four_elements(t_list *list_a, t_list *list_b)
{
	int		min;
	int		pos;
	t_node	*current;

	fin_min(list_a, &min);
	current = list_a->head;
	pos = 0;
	while (current->content != min)
	{
		current = current->next;
		pos++;
	}
	if (pos == 1)
		sa(list_a);
	else if (pos == 2)
	{
		ra(list_a);
		ra(list_a);
	}
	else if (pos == 3)
		rra(list_a);
	pb(list_a, list_b);
	sort_three_elements(list_a);
	pa(list_a, list_b);
}
