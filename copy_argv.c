/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_argv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 10:20:26 by sdurr             #+#    #+#             */
/*   Updated: 2014/12/29 22:06:58 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdlib.h>
#include "libft.h"

char	**copy_argv(char **av, int nb, int ac)
{
	char	**new_av;
	int		i;

	i = 0;
	if (!(new_av = (char**)malloc(sizeof(char *) * ac - nb)))
		return (NULL);
	while (av[++nb])
	{
		if (av[nb][0] == '-')
		{
			check_option_illegal(av[nb]);
			return (NULL);
		}
		new_av[i] = ft_strdup(av[nb]);
		i++;
	}
	if (i > 0)
		new_av[i] = NULL;
	else
	{
		new_av[i] = ft_strdup(".");
		new_av[i + 1] = NULL;
	}
	return (new_av);
}
