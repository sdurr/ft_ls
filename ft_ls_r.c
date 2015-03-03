/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_r.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 11:40:01 by sdurr             #+#    #+#             */
/*   Updated: 2015/03/03 11:44:51 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

char **ft_ls_r(char **tab)
{
	int i;

	i = 0;
	ft_putchar ('\n');
		ft_putchar ('\n');
			ft_putchar ('\n');
				ft_putchar ('\n');
					ft_putchar ('\n');
	while (tab[i] != NULL)
	{
		ft_putendl(tab[i++]);
	}
	return (tab);
}
