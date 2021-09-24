/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 10:57:37 by wvaara            #+#    #+#             */
/*   Updated: 2021/09/24 21:07:52 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

static int	ft_else(char **array, t_mini *data, char tilde, int ret)
{
	data->env = ft_extract_env_value(data->variables, "PWD");
	if (data->env)
	{
		if (data->env[0] == '/' && data->env[1] == '\0')
			data->check = ft_strjoin(data->env, array[1]);
		else
			data->check = ft_strcjoin(data->env, '/', array[1]);
	}
	if (array[1][0] == '/')
	{
		ret = chdir(array[1]);
		if (data->stats.st_mode & S_IFLNK)
			data->new = ft_is_link(data, array, tilde);
		else
			data->new = ft_strjoin("setenv PWD ", array[1]);
	}
	else
	{
		ret = chdir(data->check);
		if (data->stats.st_mode & S_IFLNK)
			data->new = ft_is_link(data, array, tilde);
		else
			data->new = ft_strjoin("setenv PWD ", data->check);
	}
	return (ret);
}

int	ft_new_dir(char **array, t_mini *data)
{
	if (array[1])
	{
		lstat(array[1], &data->stats);
		if (array[1][0] == '~')
		{
			data->tilde = '1';
			data->env = ft_extract_env_value(data->variables, "HOME");
			data->check = ft_strjoin(data->env, ++array[1]);
			if (data->stats.st_mode & S_IFLNK)
			{
				data->new = ft_is_link(data, array, data->tilde);
				data->tilde = '0';
			}
//			else
//				data->new = ft_strjoin("setenv PWD ", data->check);
			array[1]--;
			return (chdir(data->check));
		}
		else
			return (ft_else(array, data, data->tilde, 0));
	}
	return (-1);
}
