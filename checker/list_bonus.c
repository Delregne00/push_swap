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

void	ini_list(t_list *list)
{
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
	list->max = 0;
}

void	del_list(t_list *list)
{
	t_node	*current;
	t_node	*start;
	t_node	*next_node;

	if (list == NULL || list->head == NULL)
		return ;
	current = list->head;
	start = current;
	while (current != NULL)
	{
		next_node = current->next;
		free(current);
		current = next_node;
		if (current == start)
			break ;
	}
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
}

void	add_node_empty_list(t_list *list, t_node *new_t_node)
{
	new_t_node->next = new_t_node;
	new_t_node->prev = new_t_node;
	list->head = new_t_node;
	list->tail = new_t_node;
}

void	add_node_non_empty_list(t_list *list, t_node *new_t_node)
{
	new_t_node->next = list->head;
	new_t_node->prev = list->tail;
	list->tail->next = new_t_node;
	list->head->prev = new_t_node;
	list->tail = new_t_node;
}

void	add_node(t_list *list, int value)
{
	t_node	*new_t_node;

	new_t_node = malloc(sizeof(t_node));
	if (!new_t_node)
		return ;
	new_t_node->content = value;
	new_t_node->cost = 0;
	if (list->size == 0)
		add_node_empty_list(list, new_t_node);
	else
		add_node_non_empty_list(list, new_t_node);
	list->size++;
}
