/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvinram <alvinram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:03:40 by alvinram          #+#    #+#             */
/*   Updated: 2024/12/06 23:20:04 by alvinram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_free(char **string)
{
    free(*string);
    *string = NULL;
    return (NULL);
}

char *new_line(char *depot)
{
    char *line;
    char *pointer;
    int length;
    
    pointer = ft_strchar(depot, '\n');
    length = pointer - depot + 1;
    line = ft_substr(depot, 0, length);
    if (!line)
        return (NULL);
    return (line);
}

char    *get_next_line(int fd)
{
    
}