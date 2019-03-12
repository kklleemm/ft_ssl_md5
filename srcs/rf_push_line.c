/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rf_push_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 13:48:12 by cdeniau           #+#    #+#             */
/*   Updated: 2019/03/12 16:53:19 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>
// @TODO : remove this
#include <stdio.h>

t_file		*push_line(t_file *f, char *str)
{
	t_file	*head;

	head = f;
	if (NULL == f->line)
		f->line = ft_strdup(str);
	else
	{
		while (NULL != f->next)
			f = f->next;
		if (!(f->next = (t_file *)malloc(sizeof(t_file))))
			exit(-1);
		f->next->line = ft_strdup(str);
//		printf("%s\n", f->next->line);
		f->next->next = NULL;
	}
	return (head);
}
