/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 11:32:17 by gialexan          #+#    #+#             */
/*   Updated: 2023/03/07 19:54:31 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

t_tk_type type(t_token *token)
{
	return (token->tk_type);
}

t_bool match(t_tk_type tk_type, t_tk_type expected)
{
	return (tk_type == expected);
}

t_cmd *addnode(t_cmd *cmd)
{
	t_cmd	*next_cmd;

	next_cmd = cmdnew();
	cmd->next = next_cmd;
	return (next_cmd);
}

t_cmd	*cmdnew()
{
	t_cmd *cmd;

	cmd =  malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->list = NULL;
	cmd->next = NULL;
	return (cmd);
}

t_token *advanced(t_token **token)
{
	t_token *current;

	current = *token;
	*token = (*token)->next;
	current->next = NULL;
	return (current);
}
