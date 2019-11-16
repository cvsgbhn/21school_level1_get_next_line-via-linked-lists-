/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdanilo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 18:40:52 by vdanilo           #+#    #+#             */
/*   Updated: 2019/10/27 18:45:18 by vdanilo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char		*string;

	if (size > size + 1)
		return (NULL);
	/*string = ft_memalloc(size + 1);  */

        string = (char *)malloc(sizeof(char) * size + 1);
	if (!string)
          return (NULL);
	ft_bzero(string, size + 1);
	return (string);
}
