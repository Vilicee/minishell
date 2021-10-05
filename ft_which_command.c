/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_which_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 15:48:48 by wvaara            #+#    #+#             */
/*   Updated: 2021/10/05 15:31:57 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_free(char *word, char *temp)
{
	ft_memdel((void *)&word);
	ft_memdel((void *)&temp);
}

int	ft_which_command(char *str, t_mini *data, char *word, char *temp)
{
	temp = ft_strtrim(str);
	if (ft_is_quote(temp[0]) == 1)
		data->quote = temp[0];
	if (temp)
		word = ft_get_next_command(temp, 0, data->quote, data);
	if (ft_strcmp(word, "exit") == 0)
		exit (1);
	if (ft_strcmp(word, "echo") == 0)
		ft_echo(temp, data);
	else if (ft_strcmp(word, "env") == 0)
		ft_print_array(data->variables);
	else if (ft_strcmp(word, "setenv") == 0)
		ft_setenv(temp, data, 1);
	else if (ft_strcmp(word, "unsetenv") == 0)
		ft_unsetenv(temp, data, 0);
	else if (ft_strcmp(word, "cd") == 0)
		ft_cd(temp, data, 0);
	else
		if (ft_execve(temp, data, word) == -1)
			ft_command_not_found(word, data);
	ft_free(word, temp);
	return (0);
}
