/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rm_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 15:10:49 by sdurr             #+#    #+#             */
/*   Updated: 2014/12/17 15:16:50 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

char	**ft_rm_argv(char **argv, int i)
{
	int c;
	char **new_argv;
	int j;

	j = 0;
	c = 0;
	while (argv[c])
		c++;
	if (!(new_argv = (char **)malloc(sizeof(char *) * c)))
		return (NULL);
	c = 0;
	while (argv[c] && c > i)
	{
		new_argv[j] = ft_strdup(argv[c]);
		c++;
		j++;
	}
	c++;
	while (argv[c])
	{
		new_argv[j] = ft_strdup(argv[c]);
		j++;
		c++;
	}
	new_argv[j] = NULL;
	return (new_argv);
}
