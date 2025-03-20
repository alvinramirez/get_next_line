#include "get_next_line.h"

// Función auxiliar para extraer la línea hasta el salto de línea
char *extract_line(char **remainder)
{
    char    *line;
    char    *tmp;
    char    *newline_ptr;
    size_t  len;

    if (!*remainder)
        return NULL;
    newline_ptr = ft_strchr(*remainder, '\n');
    if (newline_ptr)
    {
        // Calcula la longitud de la línea (incluyendo el '\n')
        len = newline_ptr - *remainder + 1;
        line = malloc(len + 1);
        if (!line)
            return NULL;
        for (size_t i = 0; i < len; i++)
            line[i] = (*remainder)[i];
        line[len] = '\0';
        // Guarda lo que queda después del salto de línea
        tmp = ft_strdup(*remainder + len);
        free(*remainder);
        *remainder = tmp;
    }
    else
    {
        // No se encontró salto de línea, se devuelve lo que queda
        line = ft_strdup(*remainder);
        free(*remainder);
        *remainder = NULL;
    }
    return line;
}

char *get_next_line(int fd)
{
    static char *remainder;
    char        buffer[BUFFER_SIZE + 1];
    ssize_t     bytes_read;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return NULL;
    bytes_read = 1;
    // Lee mientras no encuentre un salto de línea y haya datos para leer
    while (!ft_strchr(remainder, '\n') && bytes_read > 0)
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read < 0)
            return NULL;
        buffer[bytes_read] = '\0';
        remainder = ft_strjoin(remainder, buffer);
    }
    return extract_line(&remainder);
}
