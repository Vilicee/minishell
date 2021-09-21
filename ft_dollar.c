/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dollar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 14:39:40 by wvaara            #+#    #+#             */
/*   Updated: 2021/09/15 14:21:12 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

static int	ft_which_env(char *variable, char *word)
{
	char	**temp;
	int		ret;

	temp = ft_strsplit(variable, '=');
	ret = ft_strcmp(temp[0], word);
	ft_free_array(temp);
	return (ret);
}

static int	ft_dollar_search_env(char *temp, int i, char **variables)
{
	int		ii;
	char	*word;

	ii = 0;
	word = ft_extract_word_with_char(temp, i, '$');
	while (word[ii])
	{
		word[ii] = ft_toupper(word[ii]);
		ii++;
	}
	ii = 0;
	while (variables[ii])
	{
		if (ft_which_env(variables[ii], word) == 0)
		{
			free(word);
			return (ii);
		}
		ii++;
	}
	free(word);
	return (-1);
}

int	ft_dollar(char *temp, int i, char c, char **variables)
{
	int		ret;

	ret = 0;
	i++;
	ret = ft_dollar_search_env(temp, i, variables);
	if (ret != -1)
		ft_print_env(ret, variables);
	while (temp[i] != ' ' && temp[i] != c && temp[i] != '$')
		i++;
	return (i);
}
