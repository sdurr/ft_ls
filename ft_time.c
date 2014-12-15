/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 11:19:23 by sdurr             #+#    #+#             */
/*   Updated: 2014/12/15 11:53:10 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <sys/stat.h>
#include "ft_ls.h"
#include "libft.h"

void	ft_time(char *av)
{
	struct	stat sb;
	time_t time;
	char *ret;
	int i;

	i = 4;
	stat(av, &sb);
	time = sb.st_mtime;
	ret =ctime(&time);
	while (i < 16)
		ft_putchar (ret[i++]);
	ft_putstr(" ");
}
