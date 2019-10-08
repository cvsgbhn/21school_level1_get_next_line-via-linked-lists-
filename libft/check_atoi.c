/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_atoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdanilo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 15:07:52 by vdanilo           #+#    #+#             */
/*   Updated: 2019/09/30 12:23:30 by vdanilo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		check_atoi(int result, int next, int flag)
{
	if (result * 10 == 2147483640 && next > 7 && flag == 1)
		return (1);
	if (result * 10 == 2147483640 && next > 8 && flag == -1)
		return (1);
	return (0);
}
