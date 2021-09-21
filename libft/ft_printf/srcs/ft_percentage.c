/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percentage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 14:44:35 by wvaara            #+#    #+#             */
/*   Updated: 2021/06/22 11:58:04 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_perc(t_data *data)
{
	if (data->minus == 1)
		write(1, "%", 1);
	while (data->xtra > 1)
	{
		if (data->zero == '1' && data->minus == 0)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		data->ret++;
		data->xtra--;
	}
	if (data->minus == 0)
		write(1, "%", 1);
	data->minus = 0;
}

void	ft_percentage(t_data *data)
{
	if (data->save == 1)
		ft_perc(data);
	else
		write(1, "%", 1);
	data->waste++;
	data->ret++;
}
