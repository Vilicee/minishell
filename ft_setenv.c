/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 18:06:59 by wvaara            #+#    #+#             */
/*   Updated: 2021/09/15 15:09:39 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

static int	ft_verify_data(char **array, int i)
{
	if (!array)
		return (-1);
	i = ft_arrlen(array);
	if (i < 3 || i > 4)
	{	
		if (i < 3)
			ft_putstr("setenv: too few arguments\n");
		if (i > 4)
			ft_putstr("setenv: too many arguments\n");
		ft_free_array(array);
		return (-1);
	}
	while (array[1][i])
	{
		if (array[1][i] == '=')
		{
			ft_printf("setenv: '=' not allowed in env name\n");
			ft_free_array(array);
			return (-1);
		}
		i++;
	}
	return (0);
}

static void	ft_add_variables(t_mini *data, char *new_var, char *value)
{
	char	**temp;
	char	*word;
	int		len;

	len = ft_arrlen(data->variables);
	word = ft_get_next_word(value, 0);
	temp = ft_arrdup(data->variables);
	ft_free_array(data->variables);
	data->variables = ft_realloc_array(temp, 1);
	data->variables[len] = ft_strcjoin(new_var, '=', word);
	free(word);
	ft_free_array(temp);
}

static void	ft_mod_variable(int ret, char *type, char *value, t_mini *data)
{
	char	*word;

	free(data->variables[ret]);
	word = ft_get_next_word(value, 0);
	data->variables[ret] = ft_strcjoin(type, '=', word);
	free(word);
}

static char	*ft_remove_quotes(char *str)
{
	char	quote;
	char	*temp;
	char	*temp2;

	quote = str[0];
	temp = ft_strdup(str);
	free(str);
	if (temp)
	{
		temp2 = ft_str_char_trim(temp, quote);
		free(temp);
		return (temp2);
	}
	return (NULL);
}

void	ft_setenv(char *str, t_mini *data, int overwrite)
{
	data->ret = 0;
	data->temp = ft_command_parser(str, 0, 0);
	if (!data->temp)
		return ;
	data->array = ft_strsplit(data->temp, ' ');
	free(data->temp);
	if (ft_verify_data(data->array, 0) == -1)
		return ;
	if (ft_is_quote(data->array[2][0]) == 1)
		data->array[2] = ft_remove_quotes(data->array[2]);
	while (data->array[1][data->ret])
	{
		data->array[1][data->ret] = ft_toupper(data->array[1][data->ret]);
		data->ret++;
	}
	if (data->array[3] != NULL)
		overwrite = ft_atoi(data->array[3]);
	data->ret = ft_search_env(data->array[1], 0, data->variables);
	if (data->ret == -1 && data->array[2])
		ft_add_variables(data, data->array[1], data->array[2]);
	else
		if (overwrite == 1 && data->array[2])
			ft_mod_variable(data->ret, data->array[1], data->array[2], data);
	ft_free_array(data->array);
}
