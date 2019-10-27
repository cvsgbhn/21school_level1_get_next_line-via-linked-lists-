/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_toend.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdanilo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 17:01:18 by vdanilo           #+#    #+#             */
/*   Updated: 2019/10/27 17:35:24 by vdanilo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_toend(t_list **alst, t_list *new)
{
	int		length;

	length = ft_lstlength(*alst);
	while (length-- > 0)
		*alst = (*alst)->next;
	(*alst)->next = new;
}
