/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command_parser.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 15:28:03 by wvaara            #+#    #+#             */
/*   Updated: 2021/09/04 13:34:46 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

static int	ft_almost_white_space(char c)
{
	if (c == '\t' || c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

char	*ft_command_parser(char *str, int len, int i)
{
	char	*temp;

	len = ft_strlen(str);
	temp = (char *)malloc(sizeof(char) * (len + 1));
	if (temp)
	{
		len = 0;
		while (str[i])
		{
			if (ft_almost_white_space(str[i]) == 1)
			{
				i++;
				if (temp[len - 1] != ' ')
					temp[len++] = ' ';
			}
			else
			{
				temp[len] = str[i];
				i++;
				len++;
			}
		}
		temp[len] = '\0';
	}
	return (temp);
}
