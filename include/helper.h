/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 17:17:20 by gialexan          #+#    #+#             */
/*   Updated: 2023/03/30 20:24:03 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPER_H
# define HELPER_H

#include <parser.h>

/***************************************************************************\
 * CONTROL.C
\***************************************************************************/

t_list	**get_envp(void);

/***************************************************************************\
 * ERROR.C
\***************************************************************************/

void	msh_error(char *name, char *msg, int error);

/***************************************************************************\
 * CLEANER.C
\***************************************************************************/

void	clear_dlst(t_cmd *lst, t_list *token, void (*del)(void *));

/***************************************************************************\
 * PRINT.C
\***************************************************************************/

void	print_cmd(t_cmd *cmd);
void	print_redir(t_list *token);
void	print_stack(t_list *lst, int type);

/***************************************************************************\
 * ENVIRONMENT.C
\***************************************************************************/

t_bool	update_envp(char *new, t_list *envp);
t_list *search_envp(char *search, t_list *envp);
t_bool	insert_envp(char *insert, t_list **envp);
void	init_envment(char **envpment, t_list **envp);
t_bool	delete_envp(char *delete, t_list **envp, t_list *prev);

/***************************************************************************\
 * EXPANSION.C
\***************************************************************************/

void	expand(void);
char	*unquote(char *str);
t_bool	empty_quotes(char *str);
char	*slice_word(t_scanner *scanner);
char	*slice_quotes(t_scanner *scanner);


#endif