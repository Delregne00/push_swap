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

void	ex_reverse_rotate(t_moviments *mov, t_list *list_a, t_list *list_b)
{
	while (mov->rra > 0 && mov->rrb > 0)
	{
		rrr(list_a, list_b);
		mov->rra--;
		mov->rrb--;
	}
	while (mov->rra > 0)
	{
		rra(list_a);
		mov->rra--;
	}
}

void	ex_single_rotate(t_moviments *mov, t_list *list_b)
{
	while (mov->rb > 0)
	{
		rb(list_b);
		mov->rb--;
	}
	while (mov->rrb > 0)
	{
		rrb(list_b);
		mov->rrb--;
	}
}

void	ex_rotate(t_moviments *mov, t_list *list_a, t_list *list_b)
{
	while (mov->ra > 0 && mov->rb > 0)
	{
		rr(list_a, list_b);
		mov->ra--;
		mov->rb--;
	}
	while (mov->ra > 0)
	{
		ra(list_a);
		mov->ra--;
	}
}

void	update_movements(t_moviments *mov, t_node *cheap, t_node *target)
{
	while (cheap->cost > 0)
	{
		if (cheap->cost == 0)
			break ;
		if (cheap->r_or_rr == 0)
			mov->ra += 1;
		else
			mov->rra += 1;
		cheap->cost -= 1;
	}
	while (target->cost > 0)
	{
		if (target->cost == 0)
			break ;
		if (target->r_or_rr == 0)
			mov->rb += 1;
		else
			mov->rrb += 1;
		target->cost -= 1;
	}
}

void	execute_comands(t_moviments *mov, t_list *list_a, t_list *list_b)
{
	ex_rotate(mov, list_a, list_b);
	ex_reverse_rotate(mov, list_a, list_b);
	ex_single_rotate(mov, list_b);
}
