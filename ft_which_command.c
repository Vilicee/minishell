/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_which_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 15:48:48 by wvaara            #+#    #+#             */
/*   Updated: 2021/09/22 12:17:22 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int	ft_which_command(char *str, t_mini *data, char *word)
{
	if (ft_is_quote(str[0]) == 1)
		data->quote = str[0];
	if (str)
		word = ft_get_next_command(str, 0, data->quote, data);
	if (ft_strcmp(word, "exit") == 0)
		exit (1);
	if (ft_strcmp(word, "echo") == 0)
		ft_echo(str, data);
	else if (ft_strcmp(word, "env") == 0)
		ft_print_array(data->variables);
	else if (ft_strcmp(word, "setenv") == 0)
		ft_setenv(str, data, 1);
	else if (ft_strcmp(word, "unsetenv") == 0)
		ft_unsetenv(str, data, 0);
	else if (ft_strcmp(word, "cd") == 0)
		ft_cd(str, data, 0);
	else
		if (ft_execve(str, data, word) == -1)
			ft_command_not_found(word, data);
	ft_memdel((void *)&word);
	return (0);
}
