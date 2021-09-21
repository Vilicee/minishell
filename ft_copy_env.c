/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 17:32:25 by wvaara            #+#    #+#             */
/*   Updated: 2021/09/21 16:31:02 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

char	**ft_copy_env(void)
{
	extern char	**environ;
	char		**copy;
	int			i;
	int			len;

	i = 0;
	len = ft_arrlen(environ);
	copy = (char **)malloc(sizeof(char *) * (len + 1));
	if (copy)
	{
		while (environ[i])
		{
			if (ft_strnequ(environ[i], "SHELL", 5) == 1)
				copy[i] = ft_strdup("SHELL=minishell");
			else
				copy[i] = ft_strdup(environ[i]);
			i++;
		}
		copy[i] = NULL;
	}
	return (copy);
}
