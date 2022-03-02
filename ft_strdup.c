/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modysseu <modysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 11:52:39 by modysseu          #+#    #+#             */
/*   Updated: 2021/10/15 14:12:49 by modysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*tmp_s1;
	char	*dst;
	size_t	size;

	size = 0;
	while (s1[size])
		size++;
	tmp_s1 = malloc(size + 1);
	if (!tmp_s1)
		return (NULL);
	dst = tmp_s1;
	while (*s1)
		*dst++ = *s1++;
	*dst = '\0';
	return (tmp_s1);
}
