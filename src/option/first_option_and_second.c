/*
** EPITECH PROJECT, 2018
** task
** File description:
** task
*/

#include "fastatools.h"

int first_fonction(void)
{
    char **tab = NULL;
    info_t *info = NULL;
    info_t *begin = NULL;

    if ((tab = get_file()) == NULL)
        return 84;
    info = create_info(tab);
    begin = info;

    while (info->next != NULL) {
        printf("%s\n%s\n", info->name, info->adn);
        info = info->next;
    }
    info = begin;
    free_tab(tab);
    free_info(info);
    return 0;
}

info_t *chang_adn_for_second(info_t *info)
{
    int i = 0;

    while (info->adn[i] != '\0') {
        if (info->adn[i] == 'T')
            info->adn[i] = 'U';
        i++;
    }
    return info;
}

int second_fonction(void)
{
    char **tab = NULL;
    info_t *info = NULL;
    info_t *begin = NULL;

    if ((tab = get_file()) == NULL)
        return 84;
    info = create_info(tab);
    begin = info;

    while (info->next != NULL) {
        info = chang_adn_for_second(info);
        printf("%s\n%s\n", info->name, info->adn);
        info = info->next;
    }
    info = begin;
    free_tab(tab);
    free_info(info);
    return 0;
}