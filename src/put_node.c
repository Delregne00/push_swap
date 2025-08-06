/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 put_node.c											:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: acarranz <marvin@42.fr>					+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2024/12/04 19:32:51 by acarranz		   #+#	  #+#			  */
/*	 Updated: 2024/12/04 19:32:51 by acarranz		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ini_mov(t_moviments *mov)
{
	mov->sa = 0;
	mov->sb = 0;
	mov->ss = 0;
	mov->pa = 0;
	mov->pb = 0;
	mov->ra = 0;
	mov->rb = 0;
	mov->rr = 0;
	mov->rra = 0;
	mov->rrb = 0;
	mov->rrr = 0;
}

t_node	*cheapest_node(t_list *list_a)
{
	t_node	*current;
	t_node	*cheap_t_node;
	int		i;

	if (!list_a || list_a->size == 0)
		return (NULL);
	cheap_t_node = list_a->head;
	current = list_a->head;
	i = 0;
	while (i < list_a->size)
	{
		if (current->total_cost < cheap_t_node->total_cost)
			cheap_t_node = current;
		current = current->next;
		i++;
	}
	return (cheap_t_node);
}

t_node	*find_target(t_node *cheap, t_list *list_b)
{
	t_node	*current;

	current = list_b->head;
	while (current)
	{
		if (cheap->target == current->index)
			break ;
		current = current->next;
	}
	return (current);
}

void	put_node(t_node *cheap, t_node *target, t_list *list_a, t_list *list_b)
{
	t_moviments	*mov;

	mov = malloc(sizeof(t_moviments));
	if (!mov)
		return ;
	ini_mov(mov);
	update_movements(mov, cheap, target);
	execute_comands(mov, list_a, list_b);
	pb(list_a, list_b);
	free(mov);
}
