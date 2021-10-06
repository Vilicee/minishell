/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_semic.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 14:24:36 by wvaara            #+#    #+#             */
/*   Updated: 2021/10/06 19:18:00 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check_semic(char *str, int i, int ret)
{
	char	check;
	char	c;

	check = '0';
	i = ft_check_start(str);
	while (str[i])
	{
		if (ft_is_quote(str[i]) == 1 && ft_strlen(str) > 3)
		{
			c = str[i];
			i++;
			while (str[i] != c)
			{
				i++;
				if (str[i] == c && str[i - 1] == '\\')
					i++;
			}
		}
		if (str[i] == ';')
			ret = 1;
		if ((ft_isspace(str[i]) == 0) && str[i] != ';' && str[i] != '\n')
			check = '1';
		i++;
	}
	if (ret == 1)
	{
		if (check == '0')
			return (-1);
	}
	return (ret);
}
