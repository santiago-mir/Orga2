#include <stdio.h>
#define NAME_LEN 50

typedef struct
{
    char *nombre;
    int vida;
    double ataque;
    double defensa;
} mounstro_t;

int main()
{
    mounstro_t mounstros[3] = {
        {"Dragon Rojo", 100, 5.5, 6.0},
        {"Golem de Piedra", 150, 3.3, 8.2},
        {"Leviatan", 90, 7.4, 4.3},
    };
    printf("Info del mounstro 1 %s %d\n", mounstros[0].nombre, mounstros[0].vida);
    printf("Info del mounstro 2 %s %d\n", mounstros[1].nombre, mounstros[1].vida);
    printf("Info del mounstro 2 %s %d\n", mounstros[2].nombre, mounstros[2].vida);

    return 0;
}