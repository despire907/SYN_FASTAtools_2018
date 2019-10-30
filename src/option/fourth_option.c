/*
** EPITECH PROJECT, 2018
** task
** File description:
** task
*/

#include "fastatools.h"

char **k_mers_no_qsort(info_t *info, size_t k, char **tab, int *j)
{
    int i = 0;
    size_t h = 0;

    if (k > strlen(info->adn))
        return tab;
    while (info->adn[i] != '\0' && info->adn[*j + k] != '\0') {
        if (i == 0)
            tab[*j] = malloc(sizeof(char) * k + 1);
        if (h <= k) {
            tab[*j][h] = info->adn[i];
            h++;
        } if (h == k) {
            tab[*j][h] = '\0';
            *j = *j + 1;
            tab[*j] = malloc(sizeof(char) * k + 1);
            i = i - (h - 1);
            h = 0;
        }
        i++;
    }
    return tab;
}

int check_alloc(info_t *info)
{
    info_t *begin = info;
    int i = 0;

    while (info->next != NULL) {
        i = i + strlen(info->adn);
        info = info->next;
    }
    info = begin;
    return i;
}

char **take_k_mers(info_t *info, int k)
{
    info_t *begin = info;
    char **tab = malloc(sizeof(char *) * check_alloc(info));
    int j = 0;

    while (info->next != NULL) {
        tab = k_mers_no_qsort(info, k, tab, &j);
        info = info->next;
    }
    tab[j] = NULL;
    info = begin;
    return tab;
}

int fourth_fonction(int k)
{
    char **tab = NULL;
    info_t *info = NULL;

    if ((tab = get_file()) == NULL)
        return 84;
    info = create_info(tab);
    free_tab(tab);
    tab = take_k_mers(info, k);
    k_mers_with_qsort(tab);
    free_tab(tab);
    free_info(info);

    return 0;
}