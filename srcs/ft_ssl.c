/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 16:43:26 by cdeniau           #+#    #+#             */
/*   Updated: 2019/03/11 10:24:01 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>
# @TODO : remove following include
#include <stdio.h>

int		main(int ac, char **av)
{
	t_ssl	ssl;

	if (2 == ac || 3 == ac)
	{
		fi_ctor(&ssl, av[1]);
		fi_run(&ssl);
		fi_dtor(&ssl);
	}
	else
	{
		ft_putendl("usage: ft_ssl command [command opts] [command args]");
	}
	return (0);
}
