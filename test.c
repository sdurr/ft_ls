/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 11:01:30 by sdurr             #+#    #+#             */
/*   Updated: 2015/02/04 11:21:44 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_list
{
	int	a;
	struct s_list	*next;
}	t_list;


t_list		*ft_create(void)
{
	t_list	*elem;

	elem = malloc(sizeof(t_list));
	elem->a = 0;
	elem->next = NULL;
}

void		ft_push_elem(t_list	**begin, t_list *elem)
{
	t_list	*tmp;

	tmp = *begin;
	if (tmp == NULL)
		*begin = elem;
	while (tmp && tmp->next)
		tmp = tmp->next;
	tmp->next = elem;
}

int		count_elem(t_list **begin)
{
	int cpt;
	t_list *tmp;

	cpt = 0;
	tmp = *begin;
	while (tmp)
	{
		cpt++;
		tmp = tmp -> next;
	}
	return (cpt);
}

int		main(void)
{
t_list	*l1 = ft_create()
	t_list	*begin = NULL;



	return (0);
}
