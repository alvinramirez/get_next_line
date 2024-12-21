/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvinram <alvinram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:03:40 by alvinram          #+#    #+#             */
/*   Updated: 2024/12/21 23:52:33 by alvinram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char **string)
{
	free(*string);
	*string = NULL;
	return (NULL);
}

char	*new_line(char *depot)
{
	char	*line;
	char	*pointer;
	int		length;

	pointer = ft_strchr(depot, '\n');
	length = pointer - depot + 1;
	line = ft_substr(depot, 0, length);
	if (!line)
		return (NULL);
	return (line);
}

char	*clean_depot(char *depot)
{
	char	*new_depot;
	char	*pointer;
	int		length;

	pointer = ft_strchr(depot, '\n');
	if (!pointer)
	{
		new_depot = NULL;
		return (ft_free(&depot));
	}
	else
		length = (pointer - depot) + 1;
	if (!depot[length])
		return (ft_free(&depot));
	new_depot = ft_substr(depot, length, ft_strlen(depot) - length);
	ft_free(&depot);
	if (!new_depot)
		return (NULL);
	return (new_depot);
}

char	*read_buffer(int fd, char *depot)
{
	int		to_read;
	char	*buffer;

	if (fd < 0)
		return (NULL);
	to_read = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (ft_free(&depot));
	buffer[0] = '\0';
	while (to_read > 0 && !ft_strchr(buffer, '\n'))
	{
		to_read = read(fd, buffer, BUFFER_SIZE);
		if (to_read > 0)
		{
			buffer[to_read] = '\0';
			depot = ft_strjoin(depot, buffer);
		}
	}
	free(buffer);
	if (to_read == -1)
		return (ft_free(&depot));
	return (depot);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*depot = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if ((depot && !ft_strchar(depot, '\n')) || !depot)
		depot = readbuff(fd, depot);
	if (!depot)
		return (NULL);
	line = new_line(depot);
	if (!line)
		return (ft_free(&depot));
	depot = clean_depot(depot);
	return (line);
}
