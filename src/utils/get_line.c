/*
** EPITECH PROJECT, 2018
** task
** File description:
** task
*/

#include "fastatools.h"

char *get_line(void)
{
    __ssize_t check = 0;
    char *buf = NULL;
    size_t buf_size = 0;

    if ((check = getline(&buf, &buf_size, stdin)) == 0)
        return NULL;
    if (check == -1) {
        free(buf);
        return NULL;
    }
    return buf;
}

char **get_file(void)
{
    char *str = NULL;
    char **tab = NULL;
    char *res = strdup("");
    size_t i = 0;

    while ((str = get_line()) != NULL) {
        res = realloc(res, (i + strlen(str) + 1));
        res[i + strlen(str)] = '\0';
        i = i + strlen(str);
        strcat(res, str);
        free(str);
    }
    if ((tab = my_str_to_word_array_synthesis(res)) == NULL)
        return NULL;
    free(res);
    return tab;
}