/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modysseu <modysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 16:26:59 by modysseu          #+#    #+#             */
/*   Updated: 2021/10/15 17:51:01 by modysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*f_element;
	t_list	*n_element;

	if (lst)
	{
		f_element = *lst;
		while (f_element)
		{
			n_element = f_element->next;
			ft_lstdelone(f_element, (*del));
			f_element = n_element;
		}
	}
	*lst = NULL;
}
