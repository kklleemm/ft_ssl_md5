/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 14:55:42 by cdeniau           #+#    #+#             */
/*   Updated: 2019/03/11 18:38:47 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>
#define PRINT_STDIN		"p"
#define QUIET_MODE		"q"
#define REVERSE_OUTPUT	"r"
#define PRINT_SUM		"s"
// @TODO : remove this
#include <stdio.h>

static void	parse_algo(t_ssl *this, char *av)
{
	const t_hash_fns fns[] = {
		{ "md5", ft_md5 },
		{ "sha256", ft_sha256 }
	};
	int i = 0;

	while (fns[i].name) {
	    if (0 == ft_strcmp(fns[i].name, av)) {
	        fns[i].fntoapply(this->fd);
	        break ;
	    }
		i += 1;
	}
}

static void	parse_option(t_ssl *this, char *opt)
{
	if ('-' != opt[0])
	{
		this->error = "Unknown option";
		return;
	}
	opt += 1;
	if (!this->p && 0 == ft_strcmp(opt, PRINT_STDIN))
		this->p = (0 == ft_strcmp(opt, PRINT_STDIN));
	else if (!this->q && 0 == ft_strcmp(opt, QUIET_MODE))
		this->q = (0 == ft_strcmp(opt, QUIET_MODE));
	else if (!this->r && 0 == ft_strcmp(opt, REVERSE_OUTPUT))
		this->r = (0 == ft_strcmp(opt, REVERSE_OUTPUT));
	else if (!this->s && 0 == ft_strcmp(opt, PRINT_SUM))
		this->s = (0 == ft_strcmp(opt, PRINT_SUM));
	else
		this->error = "Unknown option";
}

static void	parse_stdin(t_read_file *rf, t_ssl *this)
{
	char	*buf;
	int		check;
	t_
}

void		ft_run(t_read_file *rf, t_ssl *this, char **av)
{
	int			i;

	i = 2;
	parse_stdin(&rf, this);
	parse_algo(this, av[1]);
	while (av[i] && NULL == this->error)
	{
		parse_option(this, av[i]);
		i += 1;
	}	
}
