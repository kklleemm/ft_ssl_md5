/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 16:44:25 by cdeniau           #+#    #+#             */
/*   Updated: 2019/03/11 18:34:53 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# include "../libft/libft.h"
# include <stdlib.h>

typedef struct		s_ssl
{
	char			*str;
	struct s_file	*file;
	char			*error;
	char			p;
	char			q;
	char			r;
	char			s;
}					t_ssl;

typedef struct		s_hash_fns {
	char			*name;
	void			(*fntoapply)(char *str);
}					t_hash_fns;

typedef struct		s_file {
	char			*line;
	struct s_file	*next;
}					t_file;

typedef struct		s_lst
{
	struct s_lst	*next;
	char			*line
}					t_lst;

typedef struct		s_read_file {
	int				fd;
	int				size;
	t_lst			*head;
	t_lst			*tail;
	int				error;
}					t_read_file;

void				ft_ctor(t_ssl *this);
void				rf_ctor(t_read_file *this, char *file);
void				ft_run(t_ssl *this, char **av);
void				ft_dtor(t_ssl *this);
void				ft_md5(char *str);
void				ft_sha256(char *str);
	
#endif
