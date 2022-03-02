/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modysseu <modysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:07:37 by modysseu          #+#    #+#             */
/*   Updated: 2021/10/10 15:33:09 by modysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char	*tmp_src;
	size_t	src_size;
	size_t	tmp_dst_size;
	size_t	result;
	int		i;

	i = 0;
	src_size = 0;
	tmp_dst_size = 0;
	tmp_src = (char *)src;
	while (src[src_size])
		src_size++;
	while (dst[tmp_dst_size])
		tmp_dst_size++;
	if (dstsize > tmp_dst_size)
		result = tmp_dst_size + src_size;
	else
		result = src_size + dstsize;
	while (tmp_src[i] && ((tmp_dst_size + 1) < dstsize))
		dst[tmp_dst_size++] = tmp_src[i++];
	dst[tmp_dst_size] = '\0';
	return (result);
}
