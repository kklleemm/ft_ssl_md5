/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 16:43:26 by cdeniau           #+#    #+#             */
/*   Updated: 2019/03/12 13:36:21 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>
// @TODO : remove following include
#include <stdio.h>

int			main(int ac, char **av)
{
	t_ssl		ssl;
	t_read_file	rf;

	if (2 <= ac)
	{
		ft_ctor(&ssl);
		rf_ctor(&rf, av[ac - 1]);
		ft_run(&rf, &ssl, av);
		ft_dtor(&ssl);
	}
	else
	{
		ft_putendl("usage: ft_ssl command [command opts] [command args]");
	}
	return (0);
}
