/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvinram <alvinram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 23:14:25 by alvinram          #+#    #+#             */
/*   Updated: 2024/11/27 17:27:34 by alvinram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *string)
{
	size_t	string_length;

	string_length = 0;
	while (string[string_length] != '\0')
		string_length++;
	return (string_length);
}

void	*ft_memcpy(void *destination, const void *source, size_t byte_number)
{
	size_t				index;
	unsigned char		*tmp_dst;
	const unsigned char	*tmp_src;

	if (destination == NULL && source == NULL)
		return (NULL);
	index = 0;
	tmp_dst = (unsigned char *)destination;
	tmp_src = (const unsigned char *)source;
	while (index < byte_number)
	{
		tmp_dst[index] = tmp_src[index];
		index++;
	}
	return (destination);
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
		{
			return ((char *)string);
		}
		string++;
	}
	if (search_char == '\0')
	{
		return ((char *)string);
	}
	return (NULL);
}
