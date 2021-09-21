/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 14:56:51 by wvaara            #+#    #+#             */
/*   Updated: 2021/09/16 14:46:47 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

static int	ft_dot_or_dotdot(char **array, t_mini *data, char *current, int ret)
{
	ret = ft_check_dot(array[1]);
	if (ret == 1)
		return (1);
	if (ret == 2)
	{
		if (current)
		{
			if (current[1] != '\0')
			{
				if (data->link_flag > 0)
				{
					data->env = ft_extract_env_value(data->variables, "PWD");
					data->cd_temp = ft_remove_last_word(data->env, '/');
					data->link_flag --;
				}
				else
					data->cd_temp = ft_remove_last_word(current, '/');
				data->new = ft_strjoin("setenv PWD ", data->cd_temp);
				return (chdir(data->cd_temp));
			}
		}
	}
	if (ret == 3)
		return (ft_dotdot_slash(array, data, current));
	return (-1);
}

static int	ft_home(t_mini *data, char *current)
{
	data->old = ft_strjoin("setenv OLDPWD ", current);
	data->check = ft_extract_env_value(data->variables, "HOME");
	if (!data->check)
	{
		data->new = ft_strjoin("setenv PWD ", current);
		return (chdir(current));
	}
	data->new = ft_strjoin("setenv PWD ", data->check);
	return (chdir(data->check));
}

static int	ft_prev_dir(char **array, t_mini *data, char *current)
{
	int	ret;

	ret = ft_dash_check(array[1]);
	if (ret == 1)
	{
		data->check = ft_extract_env_value(data->variables, "OLDPWD");
		if (!data->check)
		{
			ft_printf("cd: OLDPWD has been unset, returning to home\n");
			ft_memdel((void *)&data->old);
			return (ft_home(data, current));
		}
		ft_dollar("$OLDPWD", 0, '\0', data->variables);
		write(1, "\n", 1);
		data->new = ft_strjoin("setenv PWD ", data->check);
		return (chdir(data->check));
	}
	if (ret == 2)
	{
		ft_memdel((void *)&data->old);
		return (ft_home(data, current));
	}
	if (ret == 3)
		return (ft_new_dir(array, data));
	return (-1);
}

void	ft_cd(char *str, t_mini *data, int ret)
{
	char	local_curr[4096];

	data->cd_path = ft_cd_parser(str, data, 0);
	data->cd_array = ft_path_parser(data->cd_path, '/');
	getcwd(local_curr, sizeof(local_curr));
	if (data->cd_path)
		free(data->cd_path);
	if (data->link_flag > 0)
		data->cd_path = ft_extract_env_value(data->variables, "PWD");
	else
		data->cd_path = ft_strdup(local_curr);
	if (data->cd_array[1] != NULL)
	{
		data->old = ft_strjoin("setenv OLDPWD ", data->cd_path);
		if (ft_check_dot(data->cd_array[1]) > 0)
			ret = ft_dot_or_dotdot(data->cd_array, data, data->cd_path, 0);
		else if (ft_dash_check(data->cd_array[1]) == 0)
			ret = ft_new_dir(data->cd_array, data);
		else
			ret = ft_prev_dir(data->cd_array, data, data->cd_path);
	}
	else
		ret = ft_home(data, data->cd_path);
	ft_execute_cd(data, ret);
}
