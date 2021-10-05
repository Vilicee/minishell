/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_echo_start.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 13:43:01 by wvaara            #+#    #+#             */
/*   Updated: 2021/10/05 15:31:57 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_find_echo_start(char *str)
{
	int	i;

	i = 4;
	if (ft_is_quote(str[0]) == 1)
		i = 6;
	while (str[i])
	{
		if (ft_isspace(str[i]) == 0)
			return (i);
		i++;
	}
	return (0);
}
