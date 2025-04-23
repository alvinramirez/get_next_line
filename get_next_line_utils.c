/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvinram <alvinram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 23:14:25 by alvinram          #+#    #+#             */
/*   Updated: 2025/04/23 14:20:47 by alvinram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *string_length)
{
	size_t	count;

	count = 0;
	while (string_length && string_length[count] != '\0')
		count++;
	return (count);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				count;
	unsigned char		*dst_bytes;
	const unsigned char	*src_bytes;

	if (!dst && !src)
		return (NULL);
	dst_bytes = (unsigned char *)dst;
	src_bytes = (const unsigned char *)src;
	count = 0;
	while (count < n)
	{
		dst_bytes[count] = src_bytes[count];
		count++;
	}
	return (dst);
}

char	*ft_strdup(const char *source)
{
	char	*duplicate;

	duplicate = (char *)malloc(ft_strlen(source) + 1);
	if (!duplicate)
		return (NULL);
	ft_memcpy(duplicate, source, ft_strlen(source) + 1);
	return (duplicate);
}

char	*ft_strchr(const char *string, int character)
{
	unsigned char	search_char;

	search_char = (unsigned char)character;
	while (*string)
	{
		if (*string == search_char)
			return ((char *)string);
		string++;
	}
	if (search_char == '\0')
		return ((char *)string);
	return (NULL);
}
