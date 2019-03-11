/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 16:44:25 by cdeniau           #+#    #+#             */
/*   Updated: 2019/03/10 18:20:20 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# include "../libft/libft.h"
# include <stdlib.h>

typedef struct	s_ssl
{
	char		*str;
}				t_ssl;

void			fi_ctor(t_ssl *this, char *prog_name);
void			fi_run(t_ssl *this);
void			fi_dtor(t_ssl *this);

#endif
