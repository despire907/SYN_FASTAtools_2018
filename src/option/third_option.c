/*
** EPITECH PROJECT, 2018
** task
** File description:
** task
*/

#include "fastatools.h"

char *my_revert_str(char *str)
{
    int i = 0;
    int nb = strlen(str) - 1;
    char *ptr = malloc(sizeof(char) * (strlen(str) + 1));

    while (str[i] != '\0') {
        ptr[i] = str[nb];
        i++;
        nb--;
    }
    free(str);
    ptr[i] = '\0';
    return ptr;
}

char check_t_and_a(char c)
{
    if (c == 'T')
        c = 'A';
    else if (c == 'A')
        c = 'T';
    return c;
}

char check_g_and_c(char c)
{
    if (c == 'G')
        c = 'C';
    else if (c == 'C')
        c = 'G';
    return c;
}

info_t *chang_adn_for_third(info_t *info)
{
    int i = 0;

    while (info->adn[i] != '\0') {
        info->adn[i] = check_t_and_a(info->adn[i]);
        info->adn[i] = check_g_and_c(info->adn[i]);
        i++;
    }
    info->adn = my_revert_str(info->adn);
    return info;
}

int third_fonction(void)
{
    char **tab = NULL;
    info_t *info = NULL;
    info_t *begin = NULL;

    if ((tab = get_file()) == NULL)
        return 84;
    info = create_info(tab);
    begin = info;

    while (info->next != NULL) {
        info = chang_adn_for_third(info);
        printf("%s\n%s\n", info->name, info->adn);
        info = info->next;
    }
    info = begin;
    free_tab(tab);
    free_info(info);
    return 0;
}