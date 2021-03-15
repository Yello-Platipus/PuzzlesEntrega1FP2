#pragma once
#include "ModuloCoordenada.h"
#include "ModuloMatriz.h"

struct tJuegoPM {
	tMatrizChar matObjetivo, matOrigen;
	int maxMovs;
	bool modo;
};