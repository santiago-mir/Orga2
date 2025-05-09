#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ej1.h"

/**
 * Marca el ejercicio 1A como hecho (`true`) o pendiente (`false`).
 *
 * Funciones a implementar:
 *   - init_fantastruco_dir
 */
bool EJERCICIO_1A_HECHO = true;

// OPCIONAL: implementar en C
// inicializar __dir y __dir-entries
void init_fantastruco_dir(fantastruco_t *card)
{
    directory_t new_dir = malloc(sizeof(directory_t) * 2); // tamaño del dir y espacio para 2 elems
    directory_entry_t *dir_sleep = create_dir_entry("sleep", *sleep);
    directory_entry_t *dir_wakeup = create_dir_entry("wakeup", *wakeup);
    new_dir[0] = dir_sleep;
    new_dir[1] = dir_wakeup;
    card->__dir = new_dir;
    card->__dir_entries = 2;
}

/**
 * Marca el ejercicio 1A como hecho (`true`) o pendiente (`false`).
 *
 * Funciones a implementar:
 *   - summon_fantastruco
 */
bool EJERCICIO_1B_HECHO = true;

// OPCIONAL: implementar en C
fantastruco_t *summon_fantastruco()
{
    fantastruco_t *new_card = malloc(sizeof(fantastruco_t));
    init_fantastruco_dir(new_card);
    new_card->face_up = 1;
    new_card->__archetype = NULL;
    return new_card;
}
