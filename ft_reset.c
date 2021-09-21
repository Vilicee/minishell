/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 18:33:16 by wvaara            #+#    #+#             */
/*   Updated: 2021/08/05 18:34:39 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	ft_reset(t_mini *data)
{
	data->i = 0;
	while (data->words[data->i] != NULL)
		free(data->words[data->i++]);
	free(data->words);
	data->i = 0;
}
