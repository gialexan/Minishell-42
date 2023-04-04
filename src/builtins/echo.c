/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 16:24:58 by gialexan          #+#    #+#             */
/*   Updated: 2023/04/04 15:16:45 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

#define LINE_BREAK "-n"

static void	next(t_list **token);
static void	write_output(t_list *token);

int	ft_echo(t_list *token)
{
	if (!token->next)
	{
		ft_putstr_fd("\n", 1);
		return (EXIT_SUCCESS);
	}
    next(&token);
	if (token && !ft_strncmp(token->content, LINE_BREAK, 2))
	{
		if (!token->next)
			return (EXIT_SUCCESS);
        while(token && !ft_strncmp(token->content, LINE_BREAK, 2))
            next(&token);
		write_output(token);
	}
	else
	{
		write_output(token);
		ft_putstr_fd("\n", 1);
	}
	return (EXIT_SUCCESS);
}

static void	write_output(t_list *token)
{
    if (!token)
        return ;
    token->content = expand(token->content);
	ft_putstr_fd(token->content, STDOUT_FILENO);
	return (write_output(token->next));
}

static	void	next(t_list **token)
{
	*token = (*token)->next;
}
