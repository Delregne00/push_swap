/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 t_list.c											:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: acarranz <marvin@42.fr>					+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2024/12/04 19:32:28 by acarranz		   #+#	  #+#			  */
/*	 Updated: 2024/12/04 19:32:28 by acarranz		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list	*reverse_rotate(t_list *list)
{
	if (list->size <= 1)
		return (list);
	list->head = list->head->prev;
	list->tail = list->tail->prev;
	return (list);
}

void	rra(t_list *list_a)
{
	reverse_rotate(list_a);
	ft_printf("rra\n");
}

void	rrb(t_list *list_b)
{
	reverse_rotate(list_b);
	ft_printf("rrb\n");
}

void	rrr(t_list *list_a, t_list *list_b)
{
	reverse_rotate(list_a);
	reverse_rotate(list_b);
	ft_printf("rrr\n");
}
