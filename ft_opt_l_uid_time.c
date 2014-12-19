/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opt_l_uid_time.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/19 18:11:31 by sdurr             #+#    #+#             */
/*   Updated: 2014/12/19 18:19:40 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"


void	ft_opt_l_uid_time(char **tab, int count, int c)
{

	ft_putnbr(c);
	ft_putstr(" ");
	ft_noms_proprietaire(tab[count]);
	ft_putstr(" ");
	ft_time(tab[count]);
}
