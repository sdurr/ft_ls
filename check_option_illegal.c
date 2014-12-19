/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_option.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 10:39:21 by sdurr             #+#    #+#             */
/*   Updated: 2014/12/19 16:08:57 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdlib.h>
#include "libft.h"

int		check_option_illegal(char *argv)
{
	ft_putstr("ls: illegal option -- ");
	ft_putchar(argv[1]);
	ft_putstr("\nusage: ls [-ABCFGHLOPRSTUWabcdefghijklmnopqrstuwx1]");
	ft_putstr("[file ...]");
	ft_putchar ('\n');
	return (-1);
}
