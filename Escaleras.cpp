#include "Escaleras.h"

Escaleras::Escaleras() {}

Escaleras::Serpientes(int tam, Serpientes tamSerp) {
	bool r = false;
	int tamEsc;
	do {
		tamEsc = rand()%(tam/2);
		if (tamEsc+tamSerp <= (tam/2)) {
			casillas = tamEsc;
		}
	} while (r == false);
}

Escaleras::~Escaleras() {}
