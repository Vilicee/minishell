/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 16:37:42 by wvaara            #+#    #+#             */
/*   Updated: 2021/09/04 13:40:21 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

static int	ft_no_quotes(char *str, int i)
{
	if (str[i] == '\\' && str[i + 1] != '\0' && str[i + 2] != '\0')
	{
		if (str[i + 2] == 'n' && str[i + 1] == '\\')
		{
			write(1, "\n", 1);
			return (i + 3);
		}
		if (str[i + 2] == 't' && str[i + 1] == '\\')
		{
			write(1, "    ", 4);
			return (i + 3);
		}
	}
	i++;
	write(1, &str[i++], 1);
	return (i);
}

static int	ft_check_special_char(char *str, int i)
{
	int	count;

	count = 0;
	while (str[i])
	{
		if (str[i] != '\\')
			return (count);
		i++;
		count++;
		if (count == 2)
			return (count);
	}
	return (count);
}

static int	ft_ret_two(char *str, int i)
{
	if (str[i + 2] == 'n')
	{
		write(1, "\n", 1);
		i = i + 3;
	}
	else if (str[i + 2] == 't')
	{
		write(1, "\t", 1);
		i = i + 3;
	}
	else
	{
		write(1, &str[i], 1);
		i = i + 2;
	}
	return (i);
}

static int	ft_quotes(char *str, int i, int ret)
{
	ret = ft_check_special_char(str, i);
	if (ret == 1)
	{
		if (str[i + 1] == 'n')
		{
			write(1, "\n", 1);
			i = i + 2;
		}
		else if (str[i + 1] == 't')
		{
			write(1, "\t", 1);
			i = i + 2;
		}
		else if (ft_is_quote(str[i + 1]) == 1)
			i++;
		else
			write(1, &str[i++], 1);
	}
	if (ret == 2)
		i = ft_ret_two(str, i);
	return (i);
}

int	ft_write(char *str, int i, char quote)
{
	if (str[i] == '\\')
	{
		if (quote == 'a')
			return (ft_no_quotes(str, i));
		if (quote != 'a')
			return (ft_quotes(str, i, 0));
	}
	if (str[i] != '\0')
		write(1, &str[i++], 1);
	return (i);
}
