/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ignore.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 12:22:54 by wvaara            #+#    #+#             */
/*   Updated: 2021/09/08 12:23:12 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	ft_ignore(int signo)
{
	if (signo == SIGINT)
		ft_putstr("\nminishell> ");
}
