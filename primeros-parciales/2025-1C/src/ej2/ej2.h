#pragma once

#define EJ2
#include "../ej1/ej1.h"

typedef struct
{
	directory_t __dir;		// mide 8 -> 0
	uint16_t __dir_entries; // mide 2 --> 8
	void *__archetype;		// mide 8 --> 16
} card_t;					// size of 24

typedef struct
{
	directory_t __dir;			// 0
	uint16_t __dir_entries;		// 8
	fantastruco_t *__archetype; // 16
	uint32_t materials;			// 24
} alucard_t;					// 32

typedef void ability_function_t(void *card);

void invocar_habilidad(void *carta, char *habilidad);
