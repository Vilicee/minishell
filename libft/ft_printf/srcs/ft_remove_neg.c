/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_neg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 15:55:43 by wvaara            #+#    #+#             */
/*   Updated: 2021/04/19 14:37:04 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_remove_neg(t_data *data)
{
	if (data->hn < 0 || data->hn > 32767)
		data->hn = data->hn * -1;
	if (data->hhn < 0 || data->hhn > 127)
		data->hhn = data->hhn * -1;
	if (data->ln < 0)
		data->ln = data->ln * -1;
	if (data->lln < 0)
		data->lln = data->lln * -1;
	if (data->n < 0)
		data->n = data->n * -1;
}
