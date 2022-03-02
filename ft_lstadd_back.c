/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modysseu <modysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 16:25:36 by modysseu          #+#    #+#             */
/*   Updated: 2021/10/16 17:43:48 by modysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*f_element;

	if (*lst != NULL)
	{
		f_element = *lst;
		while (f_element->next != NULL)
			f_element = f_element->next;
		f_element->next = new;
	}
	else
		*lst = new;
}
