#ifndef TABLERO_H
#define TABLERO_H
#include "Casillas.h"
#include "PosicionJugador.h"

class Tablero {
	// Atributos
	public:
		Casillas casilla;
		int tab, cantJugador, dado;
		PosicionJugador posJugador[5];
		
	public:
		Tablero();
		Tablero(int t, Casillas cas, int jugador);
		~Tablero();
		void imprimir();
		void movimiento(int jugador);
		void jugar();
		void instrucciones();
};

#endif
