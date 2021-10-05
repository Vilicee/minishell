/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_which_quote.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 13:24:50 by wvaara            #+#    #+#             */
/*   Updated: 2021/10/05 15:31:57 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_verify_quote(char *str, int i)
{
	char	quote;

	quote = str[i];
	i++;
	while (str[i])
	{
		if (str[i] == quote && str[i - 1] != '\\')
			return (0);
		i++;
	}
	return (-1);
}

int	ft_which_quote(char *str)
{
	int	i;

	i = ft_check_start(str);
	while (str[i])
	{
		if (str[i] == DQUOTE && str[i - 1] != '\\')
			if (ft_verify_quote(str, i) == -1)
				return (2);
		if (str[i] == SQU0TE && str[i - 1] != '\\')
			if (ft_verify_quote(str, i) == -1)
				return (1);
		if (str[i] == BQUOTE && str[i - 1] != '\\')
			if (ft_verify_quote(str, i) == -1)
				return (3);
		i++;
	}
	return (0);
}
