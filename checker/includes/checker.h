/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 checker.h										:+:		 :+:	:+:   */
/*	i												  +:+ +:+		  +:+	  */
/*	 By: acarranz <marvin@42.fr>					+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2024/12/04 19:32:47 by acarranz		   #+#	  #+#			  */
/*	 Updated: 2024/12/04 19:32:47 by acarranz		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include "ft_printf.h"
# include "libft.h"

typedef struct t_node
{
	int				content;
	int				index;
	int				cost;
	int				total_cost;
	int				r_or_rr;
	int				target;
	struct t_node	*next;
	struct t_node	*prev;
}				t_node;

typedef struct list
{
	t_node	*head;
	t_node	*tail;
	int		max;
	int		min;
	int		size;
}			t_list;

//functions

void	ini_list(t_list *list);
void	add_node(t_list *list, int value);
void	del_list(t_list *list);

//instruction

void	sa(t_list *list_a);
void	sb(t_list *list_b);
void	ss(t_list *list_a, t_list *list_b);
void	sa(t_list *list_a);
void	sb(t_list *list_b);
void	ss(t_list *list_a, t_list *list_b);
void	pa(t_list *list_a, t_list *list_b);
void	pb(t_list *list_a, t_list *list_b);
void	ra(t_list *list_a);
void	rb(t_list *list_b);
void	rr(t_list *list_a, t_list *list_b);
void	rra(t_list *list_a);
void	rrb(t_list *list_b);
void	rrr(t_list *list_a, t_list *list_b);

#endif
