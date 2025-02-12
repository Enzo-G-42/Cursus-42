/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiacom <engiacom@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:31:45 by engiacom          #+#    #+#             */
/*   Updated: 2025/02/12 07:09:38 by engiacom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_sorted(t_stack *a)
{
	while (a && a->next)
	{
		if (a->nbr < a->next->nbr)
			a = a->next;
		else
			return (0);
	}
	return (1);
}

void	ft_lstclear(t_stack **lst)
{
	t_stack	*tmp;

	while (*lst != NULL)
	{
		tmp = (*lst)->next;
		free ((*lst));
		*lst = tmp;
	}
	*lst = NULL;
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc < 2 || (argc == 2 && argv[1][0] == 0))
		return (1);
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	if (check_args(argv))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	init(&a, argv);
	if (!stack_sorted(a))
		sort(&a, &b);
	if (a)
		ft_lstclear(&a);
	if (b)
		ft_lstclear(&b);
}
