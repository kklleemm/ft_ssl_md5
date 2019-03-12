/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 14:55:01 by cdeniau           #+#    #+#             */
/*   Updated: 2019/03/12 16:48:40 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

// @TODO : protect mallocs

/*
 ** t_ssl Constructor method allocate struct memory
 ** or otherwise exit the program
 **
 ** t_ssl	*this		struct
 */
void					ft_ctor(t_ssl *this)
{
	if (!(this->str = (char *)malloc(sizeof (char *))))
		exit (EXIT_FAILURE); // @TODO : is it allowed?
	if (!(this->file = (t_file *)malloc(sizeof (t_file))))
		exit (EXIT_FAILURE);
	if (!(this->error = (char *)malloc(sizeof (char *))))
		exit (EXIT_FAILURE);
	if (!(this->p = (char)malloc(sizeof (char))))
		exit (EXIT_FAILURE);
	if (!(this->q = (char)malloc(sizeof (char))))
		exit (EXIT_FAILURE);
	if (!(this->r = (char)malloc(sizeof (char))))
		exit (EXIT_FAILURE);
	if (!(this->s = (char)malloc(sizeof (char))))
		exit (EXIT_FAILURE);
}
