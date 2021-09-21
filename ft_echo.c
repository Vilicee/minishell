/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 11:25:37 by wvaara            #+#    #+#             */
/*   Updated: 2021/09/21 18:21:35 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

static int	ft_no_quote(char *str, int i, char quote, char **variables)
{
	if (ft_dollar_check(str, i, quote) == 1)
		i = ft_dollar(str, i, '\0', variables);
	else
		i = ft_write(str, i, quote);
	return (i);
}

static void	ft_print_echo(char *str, int i, char quote, char **variables)
{
	while (str[i])
	{
		if (ft_is_quote(str[i]) == 1 && str[i + 1] != '\0')
		{
			quote = str[i++];
			while (str[i] != quote)
			{
				if (ft_dollar_check(str, i, quote) == 1)
					i = ft_dollar(str, i, quote, variables);
				else
					i = ft_write(str, i, quote);
				if (str[i] == quote && str[i - 1] == '\\')
					write(1, &str[i++], 1);
			}
			i++;
		}
		else if (str[i] == ' ' && str[i + 1] == ' ')
			i++;
		else
			i = ft_no_quote(str, i, quote, variables);
	}
}

void	ft_echo(char *str, t_mini *data)
{
	char	*temp;
	int		i;

	i = ft_strlen(str);
	if (i == 4 || i == 6)
	{
		if ((i == 6 && ft_is_quote(data->quote) == 1) || i == 4)
		{
			write(1, "\n", 1);
			return ;
		}
	}
	data->flag = ft_check_echo_flag(str, 0);
	if (data->flag == 2)
		return ;
	temp = ft_echo_parser(str, data->e_skip, 0, data);
	if (temp)
	{
		i = ft_check_start(temp);
		ft_print_echo(temp, i, 'a', data->variables);
		free(temp);
	}
	if (data->flag == 0)
		write(1, "\n", 1);
}
