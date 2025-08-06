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

#include "checker.h"

t_list	*rotate(t_list *list)
{
	if (list->size <= 1)
		return (list);
	list->tail = list->head;
	list->head = list->head->next;
	return (list);
}

void	ra(t_list *list_a)
{
	rotate(list_a);
}

void	rb(t_list *list_b)
{
	rotate(list_b);
}

void	rr(t_list *list_a, t_list *list_b)
{
	rotate(list_a);
	rotate(list_b);
}
