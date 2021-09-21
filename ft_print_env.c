/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 15:57:47 by wvaara            #+#    #+#             */
/*   Updated: 2021/08/24 17:47:24 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	ft_print_env(int i, char **variables)
{
	int	len;

	len = ft_wordlength(variables[i], '=');
	len++;
	while (variables[i][len])
		write(1, &variables[i][len++], 1);
}
