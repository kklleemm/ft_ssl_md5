/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rf_ctor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 18:32:11 by cdeniau           #+#    #+#             */
/*   Updated: 2019/03/11 18:34:55 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

void		rf_ctor(t_read_file *this, char *file)
{
	this->head = NULL;
	this->tail = NULL;
	this->error = 0;
	this->size = 0;
	if (NULL != file)
		this->fd = open(file, O_RDONLY);
	else
		this->fd = 0;
	if (-1 == this->fd)
		this->error = 1;
	// @TODO : handle error case
}
