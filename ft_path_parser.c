/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 14:55:50 by wvaara            #+#    #+#             */
/*   Updated: 2021/09/06 15:47:16 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

char	*ft_parse_str(char *str, char c, char quote, int i)
{
	int		ii;
	char	*temp;

	ii = 0;
	temp = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (temp)
	{
		if (ft_is_quote(str[i]) == 1)
			quote = str[i];
		while (str[i])
		{
			if ((str[i] == c && str[i + 1] == c) || str[i] == quote)
				i++;
			else
			{
				temp[ii] = str[i];
				ii++;
				i++;
			}
		}
		temp[ii] = '\0';
	}
	else
		temp = NULL;
	return (temp);
}

char	**ft_path_parser(char *str, char c)
{
	char	**array;
	char	*temp;
	char	*temp2;

	array = NULL;
	temp = NULL;
	temp2 = NULL;
	if (str)
	{
		temp = ft_command_parser(str, 0, 0);
		array = ft_strsplit(temp, ' ');
		temp2 = ft_strdup(array[1]);
		if (array[1])
		{
			free(array[1]);
			array[1] = ft_parse_str(temp2, c, '\0', 0);
		}
	}
	if (temp)
		free(temp);
	if (temp2)
		free(temp2);
	return (array);
}
