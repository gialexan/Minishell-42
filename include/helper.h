/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 17:17:20 by gialexan          #+#    #+#             */
/*   Updated: 2023/04/08 11:25:03 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPER_H
# define HELPER_H

# include "parser.h"
# include "signals.h"
# include <stdio.h>
# include <string.h>

# define SAVE 0
# define CLEAN 1

typedef enum s_action
{
    SAVE_ACTION,
    CLEAN_ACTION
}   t_action;

/***************************************************************************\
 * HELPER/PATH.C
\***************************************************************************/

void	init_arraypath(void);
t_bool	is_abspath(char *path);
char	*find_path(char *cmd, char **paths, int i);

/***************************************************************************\
 * HELPER/INTERFACE.C
\***************************************************************************/

t_list	    **get_envp(void);
char	    ***get_path(void);
t_sigaction *get_signal(void);

/***************************************************************************\
 * HELPER/ERROR.C
\***************************************************************************/

int	    export_error(char *str);
void	msh_error(char *name, char *msg, int error);

/***************************************************************************\
 * HELPER/CLEANER.C
\***************************************************************************/

void	msh_clear(void);
void    clear_envment(void);
void    clear_arraypath(void);
void	clear_cmdlst(t_cmd *lst, void (*del)(void *));
void	save_and_clean(t_list *ref, t_list *ref1, int type);

/***************************************************************************\
 * HELPER/PRINT.C
\***************************************************************************/

void	print_cmd(t_cmd *cmd);
int     declare_x(t_list *envp);
void	print_redir(t_list *token);
void	print_stack(t_list *lst, int type);

/***************************************************************************\
 * HELPER/ENVIRONMENT.C
\***************************************************************************/

void	init_envment(char **envpment, t_list **envp);
t_bool	update_envp(const char *update, t_list *envp);
t_list *search_envp(const char *search, t_list *envp);
t_bool	insert_envp(const char *insert, t_list **envp);
t_bool	delete_envp(const char *dell, t_list **envp, t_list *prev);

/***************************************************************************\
 * EXPANSION/EXPANSION.C
\***************************************************************************/

char	*expand(char *word);
char	*unquote(const char *str);
char	*slice_word(t_scanner *scanner);
char	*slice_quotes(t_scanner *scanner);
char    *concatenate(char *str, const char *append);
char	*pathname_expansion(char *str, size_t i , size_t init);

#endif