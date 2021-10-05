/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adhoc_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 11:39:21 by wvaara            #+#    #+#             */
/*   Updated: 2021/10/05 15:31:57 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_str_count(const char *str, char c, int i, int count)
{
	char	quote;

	if (!str)
		return (-1);
	while (str[i] != '\0')
	{
		if (ft_is_quote(str[i]) == 1)
		{
			quote = str[i++];
			while (str[i] != quote)
				i++;
		}
		if (str[i] == c)
			count++;
		i++;
	}
	count++;
	return (count);
}

static int	ft_str_c_len(const char *str, char c, int count)
{
	char	quote;

	if (str)
	{
		while (*str)
		{
			if (ft_is_quote(*str) == 1)
			{
				quote = *str;
				str++;
				count++;
				while (*str != quote)
				{
					str++;
					count++;
				}
			}
			if (*str == c)
				return (count);
			str++;
			count++;
		}
	}
	return (count);
}

char	**ft_adhoc_split(char const *str, char c, int len, int i)
{
	char	**fresh;
	int		wlen;

	len = ft_str_count(str, c, 0, 0);
	fresh = (char **)malloc(sizeof(char *) * (len + 1));
	if (!fresh)
		return (NULL);
	while (len > 0)
	{
		wlen = ft_str_c_len(str, c, 0);
		fresh[i] = ft_strsub(str, 0, wlen);
		i++;
		str = str + wlen;
		while (*str != '\0' && *str != c)
			str++;
		str++;
		len--;
	}
	fresh[i] = NULL;
	return (fresh);
}
