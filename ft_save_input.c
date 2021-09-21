/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 11:55:59 by wvaara            #+#    #+#             */
/*   Updated: 2021/09/07 10:35:06 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

static char	*ft_read_input(int ret, char *buf, char *str)
{
	char	*temp;

	temp = NULL;
	while (ret)
	{
		if (!temp)
			temp = ft_strdup(buf);
		else
		{
			free(temp);
			temp = ft_strdup(str);
		}
		ret = read(0, buf, BUFF_SIZE);
		buf[ret] = '\0';
		if (str)
			free(str);
		str = ft_strjoin(temp, buf);
		if (buf[ret - 1] == '\n')
			break ;
	}
	if (temp)
		free(temp);
	return (str);
}

char	*ft_save_input(void)
{
	int		ret;
	char	buf[BUFF_SIZE + 1];
	char	*str;

	str = NULL;
	ret = read(0, buf, BUFF_SIZE);
	if (buf[0] == '\0')
		return (NULL);
	buf[ret] = '\0';
	if (buf[ret - 1] == '\n')
	{
		str = ft_strdup(buf);
		return (str);
	}
	return (ft_read_input(ret, buf, str));
}
