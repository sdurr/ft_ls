/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_argv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 10:20:26 by sdurr             #+#    #+#             */
/*   Updated: 2014/12/11 10:28:05 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdlib.h>
#include "libft.h"

char	**copy_argv(char **av, int nb, int ac)
{
	char **new_av;
	int i;

	i = 0;
	if (!(new_av = (char**)malloc(sizeof(char *) * ac - nb)))
		return (NULL);
	nb++;
	while (av[nb])
	{
		new_av[i] = ft_strdup(av[nb]);
		i++;
		nb++;
	}
	new_av[i] = NULL;
	return (new_av);
}
