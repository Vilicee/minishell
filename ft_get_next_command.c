/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_command.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 16:15:01 by wvaara            #+#    #+#             */
/*   Updated: 2021/09/06 18:46:57 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

static int	ft_command_len(char *str, char quote)
{
	int	start;

	if (quote != ' ')
	{
		start = 1;
		while (str[start])
		{
			if (str[start] == quote)
				break ;
			start++;
		}
		return (start);
	}
	else
		start = 0;
	while (str[start])
	{
		if (ft_isspace(str[start]) == 1)
			break ;
		start++;
	}
	return (start);
}

static char	*ft_copy_str(char *str, char *ret, char quote, int i)
{
	int	ii;

	ii = 0;
	i = 0;
	if (quote != ' ')
	{
		i++;
		while (str[i] != quote)
			ret[ii++] = str[i++];
	}
	else
	{
		while (str[i])
		{
			if (ft_isspace(str[i]) == 1)
				break ;
			ret[ii++] = str[i++];
		}
	}
	ret[ii] = '\0';
	return (ret);
}

char	*ft_get_next_command(char *str, int i, char quote, t_mini *data)
{
	char	*ret;

	if (quote != ' ')
		data->e_skip = 6;
	i = ft_command_len(str, quote);
	ret = (char *)malloc(sizeof(char) * (i + 1));
	if (ret)
		return (ft_copy_str(str, ret, quote, i));
	return (ret);
}
