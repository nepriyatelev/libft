/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modysseu <modysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 16:23:19 by modysseu          #+#    #+#             */
/*   Updated: 2021/10/16 15:36:13 by modysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*f_element;

	f_element = (t_list *)malloc(1 * sizeof(t_list));
	if (!f_element)
		return (NULL);
	f_element->content = content;
	f_element->next = NULL;
	return (f_element);
}
