/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 12:20:41 by wvaara            #+#    #+#             */
/*   Updated: 2021/09/10 11:31:56 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

static char	**ft_remove_var(char **array, int position, int len)
{
	char	**temp;
	int		i;

	i = 0;
	temp = (char **)malloc(sizeof(char *) * (len));
	len = 0;
	if (temp)
	{
		while (array[len])
		{
			if (len != position)
			{
				temp[i] = ft_strdup(array[len]);
				i++;
			}
			len++;
		}
		temp[i] = NULL;
	}
	return (temp);
}

static void	ft_remove_env(int i, t_mini *data, char *var)
{
	int		len;
	char	*word;
	char	**temp;

	len = ft_arrlen(data->variables);
	word = ft_get_next_word(var, 0);
	temp = ft_arrdup(data->variables);
	ft_free_array(data->variables);
	data->variables = ft_remove_var(temp, i, len);
	ft_free_array(temp);
	free(word);
}

void	ft_unsetenv(char *str, t_mini *data, int ret)
{
	char	**temp;
	char	*temp2;

	temp2 = ft_command_parser(str, 0, 0);
	if (!temp2)
		return ;
	temp = ft_strsplit(temp2, ' ');
	ft_memdel((void *)&temp2);
	ret = ft_arrlen(temp);
	if (ret > 2)
		ft_putstr("unsetenv: too many arguments\n");
	else if (ret < 2)
		ft_putstr("unsetenv: too few arguments\n");
	else
	{
		ret = ft_search_env(temp[1], 0, data->variables);
		if (ret != -1)
			ft_remove_env(ret, data, temp[1]);
		else
			ft_printf("unsetenv: env: %s does not exist\n", temp[1]);
	}
	ft_free_array(temp);
}
