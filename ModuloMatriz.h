#pragma once
#include "ModuloCoordenada.h"
#include <iostream>
#include <fstream>

const int DIM_MAX = 64;

struct tPosicion {
	tCoor coord;
	unsigned char color;
};

struct tMatrizChar {
	tPosicion imagen[DIM_MAX][DIM_MAX];
	int nFilas, nColumnas;
};

using namespace std;

bool cargar(tMatrizChar& mat, ifstream ent);
bool operator == (tMatrizChar const& mat1, tMatrizChar const& mat2);
bool swap(tMatrizChar& mat, tCoor pos1, tCoor pos2);
bool swapF(tMatrizChar& mat, int f1, int f2);
bool swapC(tMatrizChar& mat, int c1, int c2);
bool swapD(tMatrizChar& mat, int d);
bool voltearF(tMatrizChar& mat, int f);
bool voltearC(tMatrizChar& mat, int c);
bool voltearD(tMatrizChar& mat, int d);
void voltearV(tMatrizChar& mat);
void voltearH(tMatrizChar& mat);
void rotarD(tMatrizChar& mat);
bool swapAdy(tMatrizChar& mat, tCoor pos1, tCoor pos2);
bool VoltearID(tMatrizChar& mat);
