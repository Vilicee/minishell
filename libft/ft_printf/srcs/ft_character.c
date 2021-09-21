/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_character.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 12:42:07 by wvaara            #+#    #+#             */
/*   Updated: 2021/04/19 16:14:15 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_c(t_data *data)
{
	int	temp;

	temp = va_arg(data->copy, int);
	data->len = ft_intlen(temp);
	if (data->minus == 1)
		ft_putchar((char)temp);
	while (data->xtra > 1)
	{
		write(1, " ", 1);
		data->xtra--;
		data->ret++;
	}
	if (data->minus == 0)
		ft_putchar((char)temp);
	data->minus = 0;
}

void	ft_character(t_data *data)
{
	if (data->save == 1)
		ft_c(data);
	else
		ft_putchar((char)va_arg(data->copy, int));
	data->waste++;
	data->ret++;
}
