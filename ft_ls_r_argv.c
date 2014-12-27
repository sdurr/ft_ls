/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_r_argv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 11:50:35 by sdurr             #+#    #+#             */
/*   Updated: 2014/12/27 12:03:34 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include "ft_ls.h"

char  **ft_ls_r_argv(char **tab)
{
     char **new_tab;
     int i;
	 int j;
	 int c;
	 j = 0;
	 i = 0;
	 while (tab[i])
		 i++;
	 new_tab = (char **)malloc(sizeof(char *) * i + 1);
	 while (i >= 0)
	 {
		 while ((ft_strchr(tab[i], ':')) == NULL)
			 i--;
		 c = i - 1;
		 new_tab[j] = ft_strdup(tab[i]);
		 i++;
		 j++;
		 ft_putstr(tab[i]);
		 while (tab[i] && (ft_strchr(tab[i], ':')) == NULL)
			 i++;

		 while ((ft_strchr(tab[i], ':')) == NULL)
		 {
			 new_tab[j] = ft_strdup(tab[i]);
			 i++;
			 j++;
		 }
		 i = c;
	 }
	 new_tab[j] = NULL;
	 return (new_tab);
}

