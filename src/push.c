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

void	add_t_node_to_list(t_list *list2, t_node *temp)
{
	if (list2->size == 0)
	{
		list2->head = temp;
		list2->tail = temp;
		temp->next = temp;
		temp->prev = temp;
	}
	else
	{
		temp->next = list2->head;
		temp->prev = list2->tail;
		list2->head->prev = temp;
		list2->tail->next = temp;
		list2->head = temp;
	}
	list2->size++;
}

void	remove_t_node_from_list(t_list *list1)
{
	if (list1->size == 1)
	{
		list1->head = NULL;
		list1->tail = NULL;
	}
	else
	{
		list1->head = list1->head->next;
		list1->head->prev = list1->tail;
		list1->tail->next = list1->head;
	}
	list1->size--;
}

void	push_t_node(t_list *list1, t_list *list2)
{
	t_node	*temp;

	if (list1->size == 0)
		return ;
	temp = list1->head;
	remove_t_node_from_list(list1);
	add_t_node_to_list(list2, temp);
}

void	pa(t_list *list_a, t_list *list_b)
{
	push_t_node(list_b, list_a);
	ft_printf("pa\n");
}

void	pb(t_list *list_a, t_list *list_b)
{
	if (list_a->size == 1)
	{
		push_t_node(list_a, list_b);
		ft_printf("pb\n");
		list_a->head = NULL;
		list_a->tail = NULL;
		list_a->size = 0;
		return ;
	}
	push_t_node(list_a, list_b);
	ft_printf("pb\n");
}
