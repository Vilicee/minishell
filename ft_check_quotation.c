/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_quotation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 16:39:19 by wvaara            #+#    #+#             */
/*   Updated: 2021/10/06 19:36:19 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check_quotation(char *str, int i, int ret, char c)
{
	i = ft_check_start(str);
	if ((ft_strlen(str) == 2) && (ft_is_quote(str[0]) == 1))
		return (-1);
	while (str[i])
	{
		if (ft_is_quote(str[i]) == 1)
		{
			if ((i > 0 && str[i - 1] != '\\') || i == 0)
			{
				c = str[i++];
				while (str[i] != '\0' && str[i] != c)
				{
					i++;
					if (str[i] == c && str[i - 1] == '\\'
						&& ft_isspace(str[i + 1]) == 1)
						i++;
				}
				if (str[i] == '\0')
					return (-1);
			}
		}
		i++;
	}
	return (ret);
}
