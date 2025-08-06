/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 push_swap.h										:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: acarranz <marvin@42.fr>					+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2024/12/04 19:32:47 by acarranz		   #+#	  #+#			  */
/*	 Updated: 2024/12/04 19:32:47 by acarranz		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <libft.h>

typedef struct s_node
{
	int				content;
	int				index;
	int				cost;
	int				total_cost;
	int				r_or_rr;
	int				target;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_list
{
	t_node	*head;
	t_node	*tail;
	int		max;
	int		min;
	int		size;
}			t_list;

typedef struct s_moviment
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}		t_moviments;

void	sort_three_elements(t_list *list);
void	sort_four_elements(t_list *list_a, t_list *list_b);
void	sort_five_elements(t_list *list_a, t_list *list_b);

void	control(t_list *list_a, t_list *list_b);
void	execute_comands(t_moviments *mov, t_list *list_a, t_list *list_b);
void	ini_list(t_list *list);
void	update_list(t_list *list);
void	del_list(t_list *list);

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

void	calculate_cost(t_list *list_a, t_list *list_b);
void	add_t_node(t_list *list, int value);
void	put_node(t_node *node, t_node *tar, t_list *list_a, t_list *list_b);
void	move_to_a(t_list *list_a, t_list *list_b);
int		parsing(char **argv);

#endif
