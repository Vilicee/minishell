/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dotdot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 14:14:10 by wvaara            #+#    #+#             */
/*   Updated: 2021/10/05 15:31:57 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_check_for_dots(char *str, int i, int count)
{
	while (str[i])
	{
		if ((ft_strlen(str) == 6) && str[1] == '.' && str[2] == '.'
			&& str[3] == '/')
			return (2);
		if ((ft_is_quote(str[i]) == 0) && str[i] != '.' && str[i] != '\n')
			return (0);
		if (str[i] == '.')
			count++;
		i++;
	}
	return (count);
}

static void	ft_print_error(char *str, int count)
{
	if (count == 0)
		ft_putstr("minishell: permission denied/no such file or directory: ");
	if (count == 3)
		ft_putstr("minishell: no such file or directory: ");
	if (count == 1)
		ft_putstr("minishell: permission denied: ");
	ft_mini_echo(str, '\0');
}

static int	ft_check_for_errors(char *str, int i, int count)
{
	if (str[0] == '.' || (str[0] == '/' && str[1] == '.'))
	{
		while (str[i])
		{
			if ((ft_is_quote(str[i]) == 0) && str[i] != '.' && str[i] != '\n'
				&& str[i] != '/')
			{
				ft_print_error(str, 0);
				return (-1);
			}
			if (str[i] == '.')
				count++;
			if (str[i] != '.')
				count = 0;
			if (count == 3)
			{
				ft_print_error(str, count);
				return (-1);
			}
			i++;
		}
		ft_print_error(str, 1);
		return (-1);
	}
	return (0);
}

int	ft_dotdot(char *str, int i, int count)
{
	count = ft_check_for_dots(str, i, 0);
	if (count == 1)
		ft_putstr(".: not enough arguments\n");
	if (count == 2)
		ft_printf("minishell: permission denied: %s", str);
	if (count == 1 || count == 2)
		return (-1);
	count = ft_check_for_errors(str, i, 0);
	return (count);
}
