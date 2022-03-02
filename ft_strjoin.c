/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modysseu <modysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 16:49:28 by modysseu          #+#    #+#             */
/*   Updated: 2021/10/13 14:12:58 by modysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t			s1_size;
	size_t			s2_size;
	unsigned int	i;
	char			*tmp_str;

	if (!s1 || !s2)
		return (0);
	s1_size = ft_strlen(s1);
	s2_size = ft_strlen(s2);
	i = 0;
	tmp_str = malloc(sizeof(char) * s1_size + s2_size + 1);
	if (!tmp_str)
		return (NULL);
	while (s1[i] != '\0')
	{
		tmp_str[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i] != '\0')
		tmp_str[s1_size++] = s2[i++];
	tmp_str[s1_size] = '\0';
	return (tmp_str);
}
