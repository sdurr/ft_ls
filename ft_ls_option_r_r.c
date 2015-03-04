/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_option_r_r.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/29 11:06:50 by sdurr             #+#    #+#             */
/*   Updated: 2015/03/04 10:24:37 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

char **ft_ls_option_r_r(char **tab_argv, char **tab)
{
	char **path;
	int i;
	int j;

	i = 0;
	path = ft_ls_path(tab_argv, tab);
	while (path[i] != NULL)
	{
		if (open_file(path[i]) == 0)
			path[i] += 2;
		i++;
	}
	j = 0;
	i = 0;
	while (path[i] != NULL)
	{
		tab[i] = ft_strdup(path[i]);
		if (ft_strncmp(path[i], "./", 2) == 0)
		{
			tab_argv[j++] = ft_strdup(path[i]);

		}
		i++;
	}
	tab_argv[j] = NULL;
	i = 0;
	while (tab_argv[i])
	{
		ft_putchar ('\n');
		ft_putstr(tab_argv[i]);
		ft_putendl(" :");
		path = recursive(tab_argv[i++]);
		j = 0;
		while (path[j])
			ft_putendl(path[j++]);
	}
		return (tab);
}
