/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** createfile
*/

#include "include.h"

char *my_itoa(int nb)
{
    char *s = malloc(sizeof(int) * 10);
    int i = 0;

    for (int j = 0; j <= 6; j++)
        s[j] = '\0';
    for (; nb >= 9; i++) {
        s[i] = (nb % 10) + 48;
        nb /= 10;
    }
    s[i] = nb + 48;
    s = my_revstr(s);
    return (s);
}
void create_file_and_write_seed(int inc)
{
    FILE *flot;
    char *str = my_itoa(inc);

    flot = fopen("seed.txt", "w");
    fwrite(str, sizeof(int), 1, flot);
    fclose(flot);
}

char *generate_map(int ac, char **av)
{
    (void) ac;
    int fd = open(av[ac-1], O_RDONLY);
    char *buff = malloc(sizeof(char) * (4 + 1));

    if (fd != (- 1))
        read(fd, buff, 10);
    return (buff);
}

int upload(int ac, char **av)
{
    char *str = generate_map(ac, av);
    int seed = my_getnbr(str);

    return (seed);
}