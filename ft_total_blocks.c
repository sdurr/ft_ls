/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_total_blocks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 13:21:16 by sdurr             #+#    #+#             */
/*   Updated: 2014/12/17 13:32:39 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include "libft.h"
#include "ft_ls.h"

void	ft_total_blocks(char **tab)
{
	struct stat sb;
	int c;
	int i;

	c = 0;
	i = 0;
	while (tab[i])
	{
		stat(tab[i], &sb);
		c = c + sb.st_blocks;
		i++;
	}
	ft_putstr("total ");
	ft_putnbr(c);
	ft_putchar ('\n');

}
