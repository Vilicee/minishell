/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_env_value.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 13:45:13 by wvaara            #+#    #+#             */
/*   Updated: 2021/09/06 20:43:07 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

char	*ft_extract_env_value(char **variables, char *word)
{
	int		i;
	int		ii;
	int		len;
	char	*temp;

	len = 0;
	ii = 0;
	temp = NULL;
	i = ft_search_env(word, 0, variables);
	if (i != -1)
	{
		while (variables[i][len])
			len++;
		temp = (char *)malloc(sizeof(char) * ((len + 1) - (ft_strlen(word))));
		if (temp)
		{
			len = ft_strlen(word) + 1;
			while (variables[i][len])
				temp[ii++] = variables[i][len++];
			temp[ii] = '\0';
		}
	}
	return (temp);
}
