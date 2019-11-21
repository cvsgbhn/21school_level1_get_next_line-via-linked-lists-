/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdanilo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 18:40:52 by vdanilo           #+#    #+#             */
/*   Updated: 2019/11/21 21:02:49 by vdanilo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char		*string;

	if (size > size + 1)
		return (NULL);
	string = ft_memalloc(size + 1);
	if (!string)
		return (NULL);
	return (string);
}
