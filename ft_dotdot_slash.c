/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dotdot_slash.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 16:16:27 by wvaara            #+#    #+#             */
/*   Updated: 2021/10/05 15:35:07 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_calculate_path(char *str, t_mini *data)
{
	while (str[data->ii] != '\0')
	{
		if (str[data->ii] == '.')
		{
			while (str[data->ii] == '.')
				data->ii++;
			if (str[data->ii++] == '/')
				return (1);
		}
		else
		{
			if (data->new_word)
				free(data->new_word);
			data->new_word = ft_extract_word(str, data->ii, '/');
			while (str[data->ii] != '\0' && str[data->ii] != '/')
				data->ii++;
			if (str[data->ii] == '/')
				data->ii++;
			return (0);
		}
	}
	return (-1);
}

int	ft_dotdot_slash(char **array, t_mini *data, char *current)
{
	int		ret;
	char	*temp2;

	temp2 = NULL;
	data->cd_temp = ft_strdup(current);
	ret = ft_calculate_path(array[1], data);
	while (ret != -1)
	{
		if (ret == 1)
			temp2 = ft_remove_last_word(data->cd_temp, '/');
		if (ret == 0)
			temp2 = ft_strcjoin(data->cd_temp, '/', data->new_word);
		free(data->cd_temp);
		data->cd_temp = ft_strdup(temp2);
		free(temp2);
		ret = ft_calculate_path(array[1], data);
	}
	data->new_pwd = ft_strjoin("setenv PWD ", data->cd_temp);
	return (chdir(data->cd_temp));
}
