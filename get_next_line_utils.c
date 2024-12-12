/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvinram <alvinram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 23:14:25 by alvinram          #+#    #+#             */
/*   Updated: 2024/12/12 21:06:09 by alvinram         ###   ########.fr       */
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

char	*ft_strdup(const char *source)
{
	size_t	length;
	char	*dup;
	size_t	count;

	length = ft_strlen(source) + 1;
	dup = (char *)malloc(length * sizeof(char));
	if (dup == NULL)
		return (NULL);
	count = 0;
	while (count < length)
	{
		dup[count] = source[count];
		count++;
	}
	return (dup);
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

size_t	ft_strlcpy(char *destination, const char *source,
		size_t destination_size)
{
	size_t	count;
	size_t	length_source;

	length_source = ft_strlen(source);
	if (destination_size < 1)
	{
		return (length_source);
	}
	count = 0;
	while (source[count] != '\0' && count < (destination_size - 1))
	{
		destination[count] = source[count];
		count++;
	}
	destination[count] = '\0';
	return (length_source);
}

char	*ft_strjoin(char const *string1, char const *string2)
{
	size_t	string1_length;
	size_t	string2_length;
	char	*join;

	if (!string1 || !string2)
		return (NULL);
	string1_length = ft_strlen(string1);
	string2_length = ft_strlen(string2);
	join = (char *)malloc((string1_length + string2_length + 1) * sizeof(char));
	if (!join)
		return (NULL);
	ft_strlcpy(join, string1, string1_length + 1);
	ft_strlcpy((join + string1_length), string2, string2_length + 1);
	return (join);
}
