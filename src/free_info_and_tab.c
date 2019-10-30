/*
** EPITECH PROJECT, 2018
** task
** File description:
** task
*/

#include "fastatools.h"

void free_info(info_t *info)
{
    info_t *tmp = info;

    while (info !=  NULL) {
        tmp = info->next;
        free(info->adn);
        free(info);
        info = tmp;
    }
}

void free_tab(char **tab)
{
    int i = 0;

    while(tab[i] != NULL) {
        free(tab[i]);
        i++;
    }
    free(tab);
}