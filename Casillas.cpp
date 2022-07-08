#include "Casillas.h"
#include <windows.h>
#include <iostream>
using namespace std;

Casillas::Casillas() {
	normales = 0;
	serpientes = 0;
	escaleras = 0;
	total = 0;
	for (int i = 0; i<30; i++) {
		posS[i] = 0;
		posE[i] = 0;
		contS[i] = 0;
		contE[i] = 0;
	}
}

Casillas::Casillas(int n, int s, int e) {
	normales = n;
	serpientes = s;
	escaleras = e;
	total = n + s + e;
	
	generarPos();
}

Casillas::~Casillas() {}

void Casillas::generarPos() {
	int pos, aux[serpientes+escaleras], j = 0, resp;
	
	for (int i = 0; i<serpientes+escaleras; i++) {
		aux[i] = -1;
	}
	
	for (int i = 0; i<30; i++) {
		posS[i] = 0;
		posE[i] = 0;
	}
	
	while (j < serpientes) {
		resp = 0;
		do {
			pos = rand()%total+1;
		} while(pos==total or pos==1);
		
		for (int i = 0; i<serpientes; i++) {
			if (aux[i] != pos) {
				resp++;
				if (resp == serpientes) {
					aux[j] = pos;
				}
			}
		}
		if (resp == serpientes) {
			posS[j] = pos;
			j++;
		}
	}
	
	j = 0;
	while (j < escaleras) {
		resp = 0;
		do {
			pos = rand()%total+1;
		} while(pos==total or pos==1);
		
		for (int i = 0; i<serpientes+escaleras; i++) {
			if (aux[i] != pos) {
				resp++;
				if (resp == serpientes+escaleras) {
					aux[j+serpientes] = pos;
				}
			}
		}
		if (resp == serpientes+escaleras) {
			posE[j] = pos;
			j++;
		}
	}
	ordenar();
	generarConteo();
}

void Casillas::ordenar() {
	bool orden;
	int aux;
	
	do {
		orden = true;
		
		for (int i = 0; i < serpientes-1; i++) {
			
			if (posS[i] > posS[i+1]) {
				aux = posS[i];
				posS[i] = posS[i+1];
				posS[i+1] = aux;
				orden = false;
			}
		}
	} while (orden == false);
	
	do {
		orden = true;
		
		for (int i = 0; i < escaleras-1; i++) {
			
			if (posE[i] > posE[i+1]) {
				aux = posE[i];
				posE[i] = posE[i+1];
				posE[i+1] = aux;
				orden = false;
			}
		}
	} while (orden == false);
}

void Casillas::generarConteo() {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	
	SetConsoleTextAttribute(h,244);
	cout << "\n---------------------- Serpientes ----------------------" << endl;
	
	SetConsoleTextAttribute(h,240);
	for (int i = 0; i < serpientes; i++) {
		contS[i] = rand()%(posS[i]-1)+1;
		cout << "La serpiente en la casilla " << posS[i] << " baja hasta la casilla " << contS[i] << endl;
	}
	
	SetConsoleTextAttribute(h,242);
	cout << "\n---------------------- Escaleras ----------------------" << endl;
	
	SetConsoleTextAttribute(h,240);
	for (int i = 0; i < escaleras; i++) {
		contE[i] = rand()%(total - posE[i]) + 1 + posE[i];
		cout << "La escalera en la casilla " << posE[i] << " sube hasta la casilla " << contE[i] << endl;
	}
	cout << endl << endl;
}
