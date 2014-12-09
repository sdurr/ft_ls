/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_option.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 10:39:21 by sdurr             #+#    #+#             */
/*   Updated: 2014/12/09 10:55:09 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdlib.h>
#include "libft.h"

char		**check_option(char **argv, int argc)
{
	char **tab;
	int i;
	int j;

	i = 1;
	j = 1;
	argc = argc -1;
	if (argv[i][j] == 'a')
		tab = ft_ls_option_a(argv, argc);
	return (tab);
}
