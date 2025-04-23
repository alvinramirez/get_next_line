/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvinram <alvinram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:01:16 by alvinram          #+#    #+#             */
/*   Updated: 2025/04/23 14:06:07 by alvinram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

char				*get_next_line(int fd);

t_list				*ft_lstnew(char *content);
void				ft_lstadd_back(t_list **lst, t_list *new_node);
void				ft_lstclear(t_list **lst);
char				*ft_strjoin_list(t_list *lst);

size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s);
char				*ft_strchr(const char *s, int c);

#endif