/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_buf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 11:49:48 by wvaara            #+#    #+#             */
/*   Updated: 2021/09/20 14:07:58 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

static int	ft_only_new_line(char *str)
{
	int	len;
	int	ret;
	int	count;

	len = 0;
	count = -1;
	ret = 0;
	while (str[len])
	{
		if ((ft_is_quote(str[len]) == 0) && str[len] != '\n')
			ret++;
		if (str[len] == '\n')
			count++;
		len++;
	}
	if (ret == 0 && count > 0)
	{
		ft_putstr("minishell: command not found: ");
		while (count-- > 0)
			write(1, "\\n", 2);
		write(1, "\n", 1);
		return (-1);
	}
	return (len);
}

static int	ft_empty(char *str, int i, int ret)
{
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != 9 && str[i] != '\n')
		{
			ret = 0;
			break ;
		}
		i++;
	}
	if (ret == 0)
	{
		i = 0;
		ret = -1;
		while (str[i])
		{
			if (str[i] != '/' && str[i] != '\n')
				ret = 0;
			i++;
		}
		if (ret == -1)
			ft_printf("minishell: permission denied: %s", str);
	}
	return (ret);
}

static int	ft_count_chars(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if ((ft_is_quote(str[i]) == 0) && str[i] != ' ' && str[i] != '\n')
			count++;
		i++;
	}
	return (count);
}

static int	ft_only_special_chars(char *str)
{
	int		ret;

	ret = ft_count_chars(str);
	if (ft_strlen(str) == 2)
		if (str[0] == ';' && str[1] == '\n')
			return (-1);
	if (ret > 0)
		return (0);
	else
	{
		ft_putstr("minishell: command not found: ");
		ft_mini_echo(str, '\0');
	}
	return (-1);
}

int	ft_check_buf(char *str, int ret, int len)
{
	if (ft_only_new_line(str) == -1)
		return (-1);
	if (ft_empty(str, 0, -1) == -1)
		return (-1);
	len = ft_strlen(str);
	if (len == 1)
		return (-1);
	if (len == 3)
	{
		if (str[0] == DQUOTE && str[1] == DQUOTE)
			ret = -1;
		if (str[0] == SQU0TE && str[1] == SQU0TE)
			ret = -1;
		if (str[0] == BQUOTE && str[1] == BQUOTE)
			ret = -1;
	}
	if (ret == -1)
	{
		ft_putstr("minishell: permission denied:\n");
		return (ret);
	}
	if (ft_only_special_chars(str) == -1)
		return (-1);
	len = ft_dotdot(str, 0, 0);
	return (len);
}
