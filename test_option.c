/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_option.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/10 12:48:04 by sdurr             #+#    #+#             */
/*   Updated: 2014/12/16 10:34:02 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdio.h>
#include "libft.h"

int		test_option(char **argv, int *nb)
{
	unsigned int flags;
	int i;
	int j;

	i = 1;
	j = 0;
	flags = 0;
	while (argv[i]) // nb arguments
	{
		if (argv[i][j] == '-')
		{
			j++;
			while (argv[i][j])
			{
				if (argv[i][j] == 'a')
					flags = flags | OPT_A;
				else if (argv[i][j] == 't')
					flags = flags | OPT_T;
				else if (argv[i][j] == 'l')
				{
				flags = flags | OPT_L;
				}
				else if (argv[i][j] == 'r')
					flags = flags | OPT_R;
				else if (argv[i][j] == 'R')
					flags = flags | OPT_R_R;
				else
				{
					check_option_illegal(argv[i]);
					return (-1);
				}
				j++;
			}
		}
		else
			return (flags); // si ce n'est plus des flags return (fonction with flags)
		j = 0;
		i++;
		*nb = *nb + 1;
	}
	return (flags); // pas d'argv a pars les flags
}
