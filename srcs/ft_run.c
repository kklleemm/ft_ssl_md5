/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 14:55:42 by cdeniau           #+#    #+#             */
/*   Updated: 2019/03/12 16:58:17 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>
#define PRINT_STDIN		"p"
#define QUIET_MODE		"q"
#define REVERSE_OUTPUT	"r"
#define PRINT_SUM		"s"
// @TODO : remove this
#include <stdio.h>

/*
 ** See .h struct documentation
 **
 ** t_ssl	*this
 ** char	*av		first program parameter
 */
static void	parse_algo(t_ssl *this, char *av)
{
	int i = 0;
	const t_hash_fns fns[] = {
		{ "md5", ft_md5 },
		{ "sha256", ft_sha256 }
	};

	while (fns[i].name) {
	    if (0 == ft_strcmp(fns[i].name, av)) {
	        fns[i].fntoapply(this->str);
	        break ;
	    }
		i += 1;
		if (!(fns[i].name))
			this->error = "Unknown parameter";
	}
}

/*
 ** Create t_ssl ssl->error when necessary
 **
 ** t_ssl	*this
 **	char	*opt	flags
 */
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

/*
 ** Read file descriptor 0 until EOF or <Ctrl>+<D>
 ** Allocate as many t_ssl ssl->file->line as necessary
 **
 ** t_read_file	*rf		read file
 ** t_ssl		*this
 */
static void	parse_stdin(t_read_file *rf, t_ssl *this)
{
	char	*buf;
	int		check;

	while ((check = get_next_line(rf->fd, &buf)) > 0)
	{
		this->file = push_line(this->file, buf);
	}
}

/*
 ** Save parameter, options and file descriptor contained in argv into
 ** proper structures. Create and display t_ssl ssl->error when necessary,
 ** otherwise execute hash treatments
 **
 ** t_read_file	*rf		read file
 ** t_ssl		*this
 ** char		**av	input parameters
 */
void		ft_run(t_read_file *rf, t_ssl *this, char **av)
{
	int			i;

	i = 2;
	parse_stdin(rf, this);
	ft_putendl(av[i]);
	while (av[i] && NULL == this->error)
	{
		parse_option(this, av[i]);
		i += 1;
	}
	return ;
	parse_algo(this, av[1]);
	if (this->error)
		ft_putendl(this->error);
	// @TODO : it is possible to free av at this point
}
