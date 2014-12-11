/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_option.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 10:39:21 by sdurr             #+#    #+#             */
/*   Updated: 2014/12/11 11:19:54 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdlib.h>
#include "libft.h"

char		**check_option(char *argv)
{
	char **tab;
	char tmp[2];

	tmp[0] = argv[1];
	tmp[1] = '\0';
	if (!(tab = (char **)malloc(sizeof(char *) * 2)))
		return (NULL);
	tab[0] = ft_strdup("ls: illegal option -- ");
	tab[0] = ft_strjoin(tab[0], tmp);
	tab[0] = ft_strjoin(tab[0], "\nusage: ls [-ABCFGHLOPRSTUWabcdefghijklmnopqrstuwx1] [file ...]");
	tab[1] = NULL;
	return (tab);
}
