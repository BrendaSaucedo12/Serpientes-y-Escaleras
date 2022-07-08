#include "Serpientes.h"

Serpientes::Serpientes() {
	casillas = 0;
	
}

Serpientes::Serpientes(int tam) {
	int tamSerp = rand()%(tam/2);
	casillas = tamSerp;
	for (int i = 0; i < tamSerp; i++) {
		posicion[i] = rand()%tam;
	}
}

Serpientes::~Serpientes() {}
