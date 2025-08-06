/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 main_bonus.c										:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: acarranz <marvin@42.fr>					+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2024/12/12 21:36:52 by acarranz		   #+#	  #+#			  */
/*	 Updated: 2024/12/12 21:36:52 by acarranz		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "../includes/checker.h"
#include "../includes/libft.h"
#include "../includes/ft_printf.h"

void	check_list(t_list *list, int size)
{
	t_node	*current;
	int		i;

	if (list->size != size - 1)
	{
		ft_printf("KO\n");
		return ;
	}
	current = list->head;
	i = 1;
	while (current->next != list->tail)
	{
		if (current->content > current->next->content)
		{
			ft_printf("KO\n");
			return ;
		}
		current = current->next;
		i++;
	}
	ft_printf("OK\n");
}

void	ini_lists(t_list *list_a, t_list *list_b, int argc, char **argv)
{
	int	i;
	int	nbr;

	i = 1;
	ini_list(list_a);
	ini_list(list_b);
	while (i < argc)
	{
		nbr = ft_atoi(argv[i]);
		add_node(list_a, nbr);
		i++;
	}
}

void	process_line(t_list *list_a, t_list *list_b, char *line)
{
	if (ft_strncmp(line, "sa\n", ft_strlen(line)) == 0)
		sa(list_a);
	else if (ft_strcmp(line, "sb\n") == 0)
		sb(list_b);
	else if (ft_strncmp(line, "ss\n", ft_strlen(line)) == 0)
		ss(list_a, list_b);
	else if (ft_strncmp(line, "pa\n", ft_strlen(line)) == 0)
		pa(list_a, list_b);
	else if (ft_strncmp(line, "pb\n", ft_strlen(line)) == 0)
		pb(list_a, list_b);
	else if (ft_strncmp(line, "ra\n", ft_strlen(line)) == 0)
		ra(list_a);
	else if (ft_strncmp(line, "rb\n", ft_strlen(line)) == 0)
		rb(list_b);
	else if (ft_strncmp(line, "rr\n", ft_strlen(line)) == 0)
		rr(list_a, list_b);
	else if (ft_strncmp(line, "rra\n", ft_strlen(line)) == 0)
		rra(list_a);
	else if (ft_strncmp(line, "rrb\n", ft_strlen(line)) == 0)
		rrb(list_b);
	else if (ft_strncmp(line, "rrr\n", ft_strlen(line)) == 0)
		rrr(list_a, list_b);
}

int	get_output(t_list *list_a, t_list *list_b)
{
	char	*line;

	line = get_next_line(0);
	if (line == NULL)
	{
		ft_printf("OK\n");
		exit(0);
	}
	if (ft_strncmp(line, "Error\n", ft_strlen(line)) == 0)
	{
		free(line);
		return (-1);
	}
	while (line != NULL)
	{
		process_line(list_a, list_b, line);
		free(line);
		line = get_next_line(0);
		if (line == NULL)
			break ;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	*list_a;
	t_list	*list_b;

	if (!argv[1])
		return (0);
	list_a = malloc(sizeof(t_list));
	list_b = malloc(sizeof(t_list));
	if (!list_a || !list_b)
		return (-1);
	ini_lists(list_a, list_b, argc, argv);
	if (get_output(list_a, list_b) == -1)
	{
		ft_printf("Error\n");
		del_list(list_a);
		del_list(list_b);
		return (-1);
	}
	check_list(list_a, argc);
	del_list(list_a);
	del_list(list_b);
	return (0);
}
