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

void	swap(t_list *list)
{
	int	temp;

	temp = list->head->content;
	list->head->content = list->head->next->content;
	list->head->next->content = temp;
}

void	sa(t_list *list_a)
{
	swap(list_a);
	ft_printf("sa\n");
}

void	sb(t_list *list_b)
{
	swap(list_b);
	ft_printf("sb\n");
}

void	ss(t_list *list_a, t_list *list_b)
{
	swap(list_a);
	swap(list_b);
	ft_printf("sa\n");
}
