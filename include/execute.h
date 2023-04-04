/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:17:53 by gialexan          #+#    #+#             */
/*   Updated: 2023/04/04 13:10:34 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include "parser.h"
# include <fcntl.h>
# include <stdio.h>
# include <readline/history.h>
# include <readline/readline.h>

typedef struct s_data
{
	int			fd[2];
	int			retcode;
	int			count;
	t_bool		error;
	t_bool		readpipe;
}	t_data;

t_list *exec_redirect(t_list *token, t_data *data, t_list *head);
void	set_redir(t_data *data, int fd, int stdfd, char *filename);
void	set_pipe(t_data *data, t_bool readpipe, int stdfd, int fdclose);
t_list *exec_pipe(t_list *token, t_list *head, t_data *data, t_list *c);
t_list *exec_input(t_list *token, t_list *head, t_data *data, t_list *c);
t_list *exec_output(t_list *token, t_list *head, t_data *data, t_list *c);
t_list *exec_append(t_list *token, t_list *head, t_data *data, t_list *c);
t_list *exec_heredoc(t_list *token, t_list *head, t_data *data, t_list *c);

#endif