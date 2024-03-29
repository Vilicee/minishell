/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_cd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 13:51:40 by wvaara            #+#    #+#             */
/*   Updated: 2021/10/05 15:34:42 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_free(t_mini *data)
{
	if (data->cd_temp)
		free(data->cd_temp);
	if (data->check)
		free(data->check);
	if (data->env)
		free(data->env);
	if (data->new_word)
		free(data->new_word);
	if (data->old_pwd)
		free(data->old_pwd);
	if (data->new_pwd)
		free(data->new_pwd);
	if (data->cd_path)
		free(data->cd_path);
	if (data->cd_array)
		ft_free_array(&data->cd_array);
}

static	void	ft_set_env_vars(t_mini *data)
{
	char	current[4096];

	if (data->old_pwd)
		ft_setenv(data->old_pwd, data, 1);
	if (data->tilde == '1')
	{
		getcwd(current, sizeof(current));
		data->new_pwd = (ft_strjoin("setenv PWD ", current));
	}
	if (data->new_pwd)
		ft_setenv(data->new_pwd, data, 1);
}

void	ft_execute_cd(t_mini *data, int ret)
{
	if (ret != -1)
		ft_set_env_vars(data);
	else
	{
		if (data->cd_array[1] != NULL && data->check == NULL)
		{
			if ((ft_strcmp(data->cd_array[1], "..") != 0)
				&& ft_strcmp(data->cd_path, "/") != 0)
				ft_printf("cd: no such file or directory: %s\n",
					data->cd_array[1]);
		}
		else if (lstat(data->check, &data->stats) == 0)
		{
			if (data->stats.st_mode && S_ISDIR(data->stats.st_mode))
				ft_printf("cd: permission denied: %s\n", data->cd_array[1]);
			else
				ft_printf("cd: not a directory: %s\n", data->cd_array[1]);
		}
		else
			ft_printf("cd: no such file or directory: %s\n", data->cd_array[1]);
	}
	ft_free(data);
}
