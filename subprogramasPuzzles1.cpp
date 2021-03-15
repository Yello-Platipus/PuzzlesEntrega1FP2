#include "ModuloMatriz.h"
#include "ModuloCoordenada.h"
#include "ModuloJuegoPM.h"

//=========================================================================
// ModuloCoordenada

bool operator == (tCoor c1, tCoor c2) {
	bool iguales = false;
	if (c1.fila == c2.fila && c1.columna == c2.columna) {
		iguales = true;
	}
	return iguales;
}

bool operator != (tCoor c1, tCoor c2) {
	bool diferentes = false;
	if (c1.fila != c2.fila || c1.columna != c2.columna) {
		diferentes = true;
	}
	return diferentes;
}

tCoor operator + (tCoor c1, tCoor c2) {
	tCoor coord;
	coord.fila = c1.fila + c2.fila;
	coord.columna = c1.columna + c2.columna;
	return coord;
}

//=========================================================================

// ModuloMatriz

bool cargar(tMatrizChar& mat, ifstream ent) {
	ent >> mat.nFilas >> mat.nColumnas;
	for (int i = 0; i < mat.nFilas; i++) {
		for (int j = 0; j < mat.nColumnas; j++) {
			ent >> mat.imagen[i][j].color;
			mat.imagen[i][j].coord.fila = i;
			mat.imagen[i][j].coord.columna = j;
		}
	}
	return true;
}
bool operator == (tMatrizChar const& mat1, tMatrizChar const& mat2) {
	bool iguales = true;
	if (mat1.nFilas == mat2.nFilas && mat1.nColumnas == mat2.nColumnas) {
		int i = 0, j = 0;
		while (iguales && i < mat1.nFilas) {
			while (iguales && j < mat1.nColumnas) {
				if (mat1.imagen[i][j].color != mat2.imagen[i][j].color) {
					iguales = false;
				}
				j++;
			}
			i++;
		}
	}
	else {
		iguales = false;
	}
	return iguales;
}
bool swap(tMatrizChar& mat, tCoor pos1, tCoor pos2) {
	unsigned char aux;
	bool cambiado = false;
	if (pos1.fila < mat.nFilas && pos1.columna < mat.nColumnas && pos2.fila < mat.nFilas && pos2.columna < mat.nColumnas) {
		aux = mat.imagen[pos1.fila][pos1.columna].color;
		mat.imagen[pos1.fila][pos1.columna].color = mat.imagen[pos2.fila][pos2.columna].color;
		mat.imagen[pos2.fila][pos2.columna].color = aux;
		cambiado = true;
	}
	return cambiado;
}
bool swapF(tMatrizChar& mat, int f1, int f2) {
	unsigned char aux;
	bool cambiado = false;
	if (f1 < mat.nFilas && f2 < mat.nFilas) {
		for (int i = 0; i < mat.nColumnas; i++) {
			aux = mat.imagen[f1][i].color;
			mat.imagen[f1][i].color = mat.imagen[f2][i].color;
			mat.imagen[f2][i].color = aux;
		}
		cambiado = true;
	}
	return cambiado;
}
bool swapC(tMatrizChar& mat, int c1, int c2) {
	unsigned char aux;
	bool cambiado = false;
	if (c1 < mat.nColumnas && c2 < mat.nColumnas) {
		for (int i = 0; i < mat.nFilas; i++) {
			aux = mat.imagen[c1][i].color;
			mat.imagen[c1][i].color = mat.imagen[c2][i].color;
			mat.imagen[c2][i].color = aux;
		}
		cambiado = true;
	}
	return cambiado;
}
bool swapD(tMatrizChar& mat, int d) {
	bool cambiadas = false;
	unsigned char aux;
	if (mat.nFilas == mat.nColumnas && d < mat.nColumnas) {
		for (int i = 0; i < mat.nFilas; i++) {
			for (int j = 0; j < mat.nColumnas; j++) {
				if (j == i + d) {
					aux = mat.imagen[i][j].color;
					mat.imagen[i][j].color = mat.imagen[j][i].color;
					mat.imagen[j][i].color = aux;
				}
			}
		}
		cambiadas = true;
	}
	return cambiadas;
}
bool voltearF(tMatrizChar& mat, int f) {
	bool volteada = false;
	unsigned char aux;
	if (f < mat.nFilas) {
		for (int i = 0; i < mat.nColumnas; i++) {
			aux = mat.imagen[f][i].color;
			mat.imagen[f][i].color = mat.imagen[f][mat.nColumnas - 1 - i].color;
			mat.imagen[f][mat.nColumnas - 1 - i].color = aux;
		}
		volteada = true;
	}
	return volteada;
}
bool voltearC(tMatrizChar& mat, int c) {
	bool volteada = false;
	unsigned char aux;
	if (c < mat.nColumnas){
		for (int i = 0; i < mat.nFilas; i++){
			aux = mat.imagen[i][c].color;
			mat.imagen[i][c].color = mat.imagen[mat.nFilas - 1 - i][c].color;
			mat.imagen[mat.nFilas - 1 - i][c].color = aux;
		}
		volteada = true;
	}
	return volteada;
}
bool voltearD(tMatrizChar& mat, int d) {
	bool volteada = false;
	unsigned char aux;
	if (d < mat.nColumnas) {
		for (int i = 0; i < mat.nFilas; i++) {
			for (int j = 0; j < mat.nColumnas; j++) {
				if (j == i + d) {
					aux = mat.imagen[i][j].color;
					mat.imagen[i][j].color = mat.imagen[mat.nFilas - i - 1][mat.nColumnas - i - 1].color;
					mat.imagen[mat.nFilas - i - 1][mat.nColumnas - i - 1].color = aux;
				}
			}
		}
		volteada = true;
	}
	return volteada;
}
void voltearV(tMatrizChar& mat) {
	for (int i = 0; i < mat.nFilas - 1; i++) {
		voltearF(mat, i);
	}
}
void voltearH(tMatrizChar& mat) {
	for (int i = 0; i < mat.nColumnas - 1; i++){
		voltearC(mat, i);
	}
}
void rotarD(tMatrizChar& mat) { // oye, igual está al reevees(keanu), o igual esta totalmente mal
	unsigned char aux;
	for (int i = 0; i < mat.nFilas; i++) {
		for (int j = 0; j < mat.nColumnas; j++) {
			aux = mat.imagen[i][j].color;
			mat.imagen[i][j].color = mat.imagen[j][mat.nFilas - i].color;
			mat.imagen[j][mat.nFilas - i].color = aux;
		}
	}
}
bool swapAdy(tMatrizChar& mat, tCoor pos1, tCoor pos2) {
	bool cambiado = false;
	unsigned char aux;
	if ((pos1.columna > 0 && pos1.columna < mat.nColumnas - 1) && (pos1.fila > 0 && pos1.fila < mat.nFilas - 1) && (pos2.columna > 0 && pos2.columna < mat.nColumnas - 1) && (pos2.fila > 0 && pos2.fila < mat.nFilas - 1)) {
		for (int i = -1; i < 2; i++) {
			for (int j = -1; j < 2; j++) {
				aux = mat.imagen[pos1.fila + i][pos1.columna + j].color;
				mat.imagen[pos1.fila + i][pos1.columna + j].color = mat.imagen[pos2.fila + i][pos2.columna + j].color;
				mat.imagen[pos2.fila + i][pos2.columna + j].color = aux;
			}
		}
		cambiado = true;
	}
	return cambiado;
}
bool VoltearID(tMatrizChar& mat) {
	bool volteada = false;
	if (mat.nFilas == mat.nColumnas) {
		for (int i = 1; i < mat.nFilas; i++) {
			swapD(mat, i);
		}
		volteada = true;
	}
	return volteada;
}

//=========================================================================