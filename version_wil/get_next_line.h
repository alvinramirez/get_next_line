#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

// Prototipo de la función principal
char *get_next_line(int fd);

// Prototipos de funciones auxiliares
size_t ft_strlen(const char *s);
char   *ft_strchr(const char *s, int c);
char   *ft_strjoin(char *s1, char *s2);
char   *ft_strdup(const char *s);
char   *extract_line(char **remainder);

#endif
