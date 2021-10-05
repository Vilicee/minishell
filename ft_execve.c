/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 13:20:19 by wvaara            #+#    #+#             */
/*   Updated: 2021/10/05 15:31:57 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_execute(char **array, char *command, char **var, pid_t child)
{
	int		process;
	pid_t	pid;

	if (child == 0)
	{
		if (execve(command, array, var) == -1)
		{
			if (array)
				ft_free_array(&array);
			if (command)
				free(command);
			return (-1);
		}
	}
	else
	{
		pid = waitpid(child, &process, 0);
		while (pid > 0)
			pid = waitpid(child, &process, 0);
	}
	ft_free_array(&array);
	if (command)
		free(command);
	return (0);
}

int	ft_execve(char *str, t_mini *data, char *command)
{
	char	**array;
	char	*temp;
	pid_t	child;

	if (command)
		data->temp = ft_extract_command_path(data->variables, "PATH",
				command, data);
	if (ft_strcmp(data->temp, "") == 0 || data->temp == NULL
		|| ft_dotdot(data->temp, 0, 0) == -1)
	{
		ft_memdel((void *)&data->temp);
		return (-1);
	}
	child = fork();
	temp = ft_command_parser(str, 0, 0);
	array = ft_strsplit(temp, ' ');
	free(temp);
	data->arr_temp = ft_arrdup(array);
	ft_free_array(&array);
	array = ft_arr_trim(data->arr_temp);
	ft_free_array(&data->arr_temp);
	free(array[0]);
	array[0] = ft_strdup(data->temp);
	return (ft_execute(array, data->temp, data->variables, child));
}
