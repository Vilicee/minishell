/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnan.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 13:31:15 by wvaara            #+#    #+#             */
/*   Updated: 2021/04/15 13:31:59 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isnan(double nbr)
{
	if (nbr != nbr)
		return (1);
	return (0);
}
