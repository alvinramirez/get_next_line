#include "get_next_line.h"

// Calcula la longitud de una cadena
size_t ft_strlen(const char *s)
{
    size_t i = 0;
    while (s && s[i])
        i++;
    return i;
}

// Busca el primer carácter c en la cadena s
char *ft_strchr(const char *s, int c)
{
    if (!s)
        return NULL;
    while (*s)
    {
        if (*s == (char)c)
            return (char *)s;
        s++;
    }
    if (c == '\0')
        return (char *)s;
    return NULL;
}

// Duplica una cadena
char *ft_strdup(const char *s)
{
    size_t len = ft_strlen(s);
    char   *dup = malloc(len + 1);
    size_t i;

    if (!dup)
        return NULL;
    for (i = 0; i < len; i++)
        dup[i] = s[i];
    dup[i] = '\0';
    return dup;
}

// Une dos cadenas, liberando la primera (s1) para evitar fugas de memoria
char *ft_strjoin(char *s1, char *s2)
{
    size_t len1 = ft_strlen(s1);
    size_t len2 = ft_strlen(s2);
    char   *str = malloc(len1 + len2 + 1);
    size_t i = 0, j = 0;

    if (!str)
        return NULL;
    if (s1)
    {
        while (s1[i])
        {
            str[i] = s1[i];
            i++;
        }
    }
    while (s2 && s2[j])
    {
        str[i + j] = s2[j];
        j++;
    }
    str[i + j] = '\0';
    free(s1);
    return str;
}
