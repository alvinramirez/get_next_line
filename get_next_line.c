/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvinram <alvinram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:03:40 by alvinram          #+#    #+#             */
/*   Updated: 2024/12/13 23:51:34 by alvinram         ###   ########.fr       */
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

	pointer = ft_strchar(depot, '\n');
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

	pointer = ft_strchar(depot, '\n');
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

char	*get_next_line(int fd)
{
	char		*line;
	static char	*depot = NULL;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
}
