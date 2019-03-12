/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 16:44:25 by cdeniau           #+#    #+#             */
/*   Updated: 2019/03/12 17:21:55 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>

/*
 ** @TODO : remove *str
 ** Contains all input-related data :
 ** char			*str		stdin or input file
 ** struct s_file	*file		stdin or input file
 ** char			*file		error message
 ** char			p			displays stdin if true
 ** char			q			quiet mode if true
 ** char			r			reverse output if true
 ** char			s			print sum if true
 */
typedef struct		s_ssl
{
	char			*str;
	struct t_file	*file;
	char			*error;
	char			p;
	char			q;
	char			r;
	char			s;
}					t_ssl;

/*
 ** fns is a list of allowed function and its related methods :
 ** char			*name					allowed function
 ** void			(*fntoapply)(char *str) callback to its related method
 */
typedef struct		s_hash_fns {
	char			*name;
	void			(*fntoapply)(char *str);
}					t_hash_fns;

/*
 ** Contains the whole stdin or input file
 */
typedef struct		s_file {
	char			*line;
	struct s_file	*next;
}					t_file;

/*
 ** Contains the whole stdin or input file
 */
typedef struct		s_lst
{
	struct s_lst	*next;
	char			*line;
}					t_lst;

typedef struct		s_read_file {
	int				fd;
	int				size;
	t_lst			*head;
	t_lst			*tail;
	int				error;
}					t_read_file;

void				ft_ctor(t_ssl *this);
void				ft_run(t_read_file *rf, t_ssl *this, char **av);
void				ft_dtor(t_ssl *this);
void				ft_md5(char *str);
void				ft_sha256(char *str);
	
void				rf_ctor(t_read_file *this, char *file);
t_file				*push_line(t_file *file, char *str);

#endif
