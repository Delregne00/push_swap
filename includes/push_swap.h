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
# include <ft_printf.h>
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

int		check_list(t_list *list, int size);
int		verificar_limites(const char *cadena);
void	sort_three_elements(t_list *list);
void	sort_four_elements(t_list *list_a, t_list *list_b);
void	update_list(t_list *list);
void	finalize_sort(t_list *list_a);
void	sort_five_elements_initial(t_list *list_a, t_list *list_b);
void	sort_five_elements(t_list *list_a, t_list *list_b);
void	fin_min(t_list *list, int *min);
void	fin_max(t_list *list, int *max);
void	control(t_list *list_a, t_list *list_b);
void	update_movements(t_moviments *mov, t_node *cheap, t_node *target);
void	execute_comands(t_moviments *mov, t_list *list_a, t_list *list_b);
void	ini_mov(t_moviments *mov);
size_t	ft_strlen(const char *str);
int		ft_isdigit(int c);
int		ft_strcmp(const char *s1, const char *s2);
void	ini_list(t_list *list);
int		add_t_node(t_list *list, int value);
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
t_node	*cheapest_node(t_list *list_a);
void	put_node(t_node *node, t_node *tar, t_list *list_a, t_list *list_b);
void	recolocate(t_list *list_b);
void	move_to_a(t_list *list_a, t_list *list_b);
void	find_min(t_list *list);
void	find_max(t_list *list);
t_node	*find_target(t_node *cheap, t_list *list_b);
int		parsing(int argc, char *argv[]);
int		ini_lists(t_list *list_a, t_list *list_b, int argc, char **argv);
int		verificar_caracteres(const char *cadena);

#endif
