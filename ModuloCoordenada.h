#pragma once

struct tCoor {
	int fila, columna;
};

bool operator == (tCoor c1, tCoor c2);
bool operator != (tCoor c1, tCoor c2);
tCoor operator + (tCoor c1, tCoor c2);