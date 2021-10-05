/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_until_matching_quote.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 16:37:10 by wvaara            #+#    #+#             */
/*   Updated: 2021/10/05 11:01:17 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

static void	ft_prompt(int ret)
{
	if (ret == 1)
		ft_putstr("squote> ");
	if (ret == 2)
		ft_putstr("dquote> ");
	if (ret == 3)
		ft_putstr("bquote> ");
}

static char	*ft_loop(char *str, char *temp, char *temp2, int ret)
{
	while (1)
	{
		if (ret == -1)
			ret = ft_which_quote(str);
		ft_prompt(ret);
		if (temp)
			free(temp);
		temp = ft_save_input();
		if (temp2)
			free(temp2);
		temp2 = ft_strdup(str);
		free(str);
		str = ft_strjoin(temp2, temp);
		if (!str)
			exit (-1);
		if (ft_check_quotation(str, 0, 0, 'a') != -1)
		{
			free(temp);
			free(temp2);
			return (str);
		}
	}
	return (str);
}

char	*ft_read_until_matching_quote(char *str)
{
	char	*temp;
	char	*temp2;

	temp = NULL;
	temp2 = NULL;
	return (ft_loop(str, temp, temp2, -1));
}
