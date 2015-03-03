/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_option_r_r.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/29 11:06:50 by sdurr             #+#    #+#             */
/*   Updated: 2015/03/03 14:21:15 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

char **ft_ls_option_r_r(char **tab)
{
	char **path;
	int i;

	i = 0;
	path = ft_ls_path(tab);
	while (tab[i] != NULL)
		ft_putendl(tab[i++]);
}
