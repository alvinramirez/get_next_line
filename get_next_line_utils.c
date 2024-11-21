/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvinram <alvinram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 23:14:25 by alvinram          #+#    #+#             */
/*   Updated: 2024/11/21 23:17:02 by alvinram         ###   ########.fr       */
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
