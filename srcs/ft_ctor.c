/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 14:55:01 by cdeniau           #+#    #+#             */
/*   Updated: 2019/03/11 18:25:01 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

// @TODO : protect mallocs

void					ft_ctor(t_ssl *this)
{
	this->str = (char *)malloc(sizeof (char *));
	this->file = (t_file *)malloc(sizeof (t_file *));
	this->p = (char)malloc(sizeof (char));
	this->q = (char)malloc(sizeof (char));
	this->r = (char)malloc(sizeof (char));
	this->s = (char)malloc(sizeof (char));
}
