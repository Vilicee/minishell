/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 15:49:21 by wvaara            #+#    #+#             */
/*   Updated: 2021/10/05 15:31:57 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_cd_len(char *str, int i)
{
	int	len;

	len = 0;
	while (str[i])
	{
		if (str[i] == '-')
		{
			if (str[i + 1] == 'P' || str[i + 1] == 'L')
			{
				i++;
				while (ft_isspace(str[i]) == 0)
					i++;
			}
			else
				len++;
		}
		i++;
		len++;
	}
	return (len);
}

static int	ft_is_flag(char *str, int i, t_mini *data)
{
	int	start;

	start = i;
	i++;
	while (str[i])
	{
		if (str[i] != 'P' && str[i] != 'L')
			break ;
		i++;
	}
	if (str[i] == '\0')
		return (start);
	if (str[i - 1] == 'P')
		data->cd_p = '1';
	if (str[i - 1] == 'L')
		data->cd_l = '1';
	return (i);
}

char	*ft_cd_parser(char *str, t_mini *data, int i)
{
	char	*temp;
	char	*temp2;
	int		len;

	temp2 = ft_command_parser(str, 0, 0);
	len = ft_cd_len(str, 0);
	temp = (char *)malloc(sizeof(char) * (len + 1));
	len = 0;
	if (temp && temp2)
	{
		while (temp2[i])
		{
			if (temp2[i] == '-')
			{
				if (temp2[i + 1] == 'P' || temp2[i + 1] == 'L')
					i = ft_is_flag(temp2, i, data);
			}
			temp[len] = temp2[i];
			i++;
			len++;
		}
		temp[len] = '\0';
	}
	ft_memdel((void *)&temp2);
	return (temp);
}
