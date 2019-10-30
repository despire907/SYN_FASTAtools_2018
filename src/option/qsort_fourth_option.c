/*
** EPITECH PROJECT, 2018
** task
** File description:
** task
*/

#include "fastatools.h"

int my_cmp(const void *a, const void *b)
{
    return strcmp(*(char **)a, *(char **)b);
}

int nb_of_line(char **tab)
{
    int i = 0;

    while (tab[i] != NULL)
        i++;

    return i;
}

void k_mers_with_qsort(char **tab)
{
    int nb = nb_of_line(tab);
    int i = 0;
    char *str = NULL;

    qsort(tab, nb, sizeof(char *), my_cmp);
    while (tab[i] != NULL) {
        if (i == 0) {
            str = tab[i];
            printf("%s\n", str);
        } if (strcmp(tab[i], str)) {
            str = tab[i];
            printf("%s\n", str);
        }
        i++;
    }
}