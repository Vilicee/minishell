/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 18:24:06 by wvaara            #+#    #+#             */
/*   Updated: 2021/09/29 11:49:17 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

void	ft_free_array(char ***array)
{
	int	i;

	i = 0;
	if (!*array)
		return ;
	while ((*array)[i] != NULL)
		ft_memdel((void **)&(*array)[i++]);
	ft_memdel((void **)array);
}
