/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 check_list.c										:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: acarranz <marvin@42.fr>					+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2024/12/04 19:32:34 by acarranz		   #+#	  #+#			  */
/*	 Updated: 2024/12/04 19:32:34 by acarranz		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_list(t_list *list, int size)
{
	int		i;
	t_node	*current;

	i = 1;
	current = list->head;
	while (i < size)
	{
		if (current->content == list->tail->content)
			break ;
		if (current->content > current->next->content)
		{
			return (1);
		}
		current = current->next;
		i++;
	}
	return (0);
}
