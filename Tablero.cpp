#include "Tablero.h"
#include "Casillas.h"
#include "PosicionJugador.h"
#include <windows.h>
#include <iostream>
using namespace std;

Tablero::Tablero() {
	Casillas cas;
	PosicionJugador pos[5];
	
	tab = 0;
	casilla = cas;
	cantJugador = 0;
	dado = 0;
	
	for (int i = 0; i < 5; i++) {
		posJugador[i] = pos[i];
	}
}

Tablero::Tablero(int t, Casillas cas, int jugador) {
	PosicionJugador pos[5];
	
	tab = t;
	casilla = cas;
	cantJugador = jugador;
	dado = 0;
	
	for (int i = 0; i < cantJugador; i++) {
		posJugador[i] = pos[i];
	}
}

Tablero::~Tablero() {}

void Tablero::imprimir() {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	int vueltas, s = 0, e = 0, numJug;
	
	if (tab == 30){
		cout << "\n.~.~.~.~.~.~.~.~. Tablero .~.~.~.~.~.~.~.~." << endl;
		vueltas = 6;
	}
	if (tab == 40){
		cout << "\n.~.~.~.~.~.~.~.~.~.~.~.~. Tablero .~.~.~.~.~.~.~.~.~.~.~.~." << endl;
		vueltas = 8;
	}
	if (tab == 50 or tab == 60){
		cout << "\n.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~. Tablero .~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~." << endl;
		vueltas = 10;
	}
	
	for (int i = 1; i < tab+1; i++) {
		if (i == casilla.posS[s]) {
			SetConsoleTextAttribute(h,244);
			cout << "S" << i << "\t";
			s++;
		}
		else {
			if (i == casilla.posE[e]) {
				SetConsoleTextAttribute(h,242);
				cout << "E" << i << "\t";
				e++;
			}
			else {
				numJug = -1;
				for (int j = 0; j < cantJugador; j++) {
					if (posJugador[j].pos == i) {
						numJug = j;
					}
				}
				if (numJug != -1) {
					SetConsoleTextAttribute(h,241);
					cout << "J" << numJug+1 << "\t";
				}
				else {
					SetConsoleTextAttribute(h,240);
					cout << i << "\t";
				}
			}
		}
		SetConsoleTextAttribute(h,240);
		if (i%vueltas == 0) {
			cout << endl << endl;
		}
	}
}

void Tablero::movimiento(int jugador) {
	///////////////////////
	PosicionJugador posAux;
	bool chequeo;
	
	dado = rand()%6 + 1;
	cout << "\nJugador " << jugador+1 << ", el dado cayo con un valor de " << dado << "!" << endl;
	system("PAUSE");
	
	//////////// Sobrecarga de operadores ////////////////////////
	posAux = posJugador[jugador] + dado;
	
	do {
		chequeo = false;
		for (int i = 0; i < casilla.serpientes; i ++) {
			if (posAux.pos == casilla.posS[i]) {
				cout << "\nCaiste en una serpiente en la casilla " << casilla.posS[i] << ". Bajas hasta la casilla " << casilla.contS[i] << "."  << endl;
				posAux = casilla.contS[i];
				chequeo = true;
				system("PAUSE");
			}
		}
		
		for (int i = 0; i < casilla.escaleras; i ++) {
			if (posAux.pos == casilla.posE[i]) {
				cout << "\nCaiste en una escalera en la casilla " << casilla.posE[i] << ". Subes hasta la casilla " << casilla.contE[i] << "." << endl;
				posAux = casilla.contE[i];
				chequeo = true;
				system("PAUSE");
			}
		}
	} while (chequeo == true);
	
	for (int i = 0; i < cantJugador; i++) {
		if (jugador != i) {
			if (posAux.pos == posJugador[i].pos) {
				cout << "\nEl jugador " << i+1 << " se encontraba en la misma casilla destino. Intercambio de posicion!" << endl;
				posJugador[i] = posJugador[jugador];
				system("PAUSE");
			}
		}
	}
	
	if (posAux.pos > tab) {
		posAux.pos = tab;
	}
	
	posJugador[jugador] = posAux;
	
	imprimir();
}


void Tablero::jugar() {
	bool fin = false;
	int partida = 1, numJugador = 0;
	
	cout << "\n\n------------------ Partida " << partida << " ------------------" << endl;
	system("PAUSE");
	do {
		if (numJugador == cantJugador) {
			numJugador = 0;
			partida++;
			
			if (fin == false) {
				cout << "\n\n------------------ Partida " << partida << " ------------------" << endl;
				system("PAUSE");
			}
		}
		
		movimiento(numJugador);
		system("PAUSE");
		
		if (posJugador[numJugador].pos == tab) {
			fin = true;
			cout << "\n ------------------ GAME OVER -----------------" << endl;
			cout << "|           El jugador J" << numJugador+1 << " ha ganado!          |" << endl;
			cout << " ----------------------------------------------" << endl;
		}
		if ((partida == tab/2) and (numJugador+1 == cantJugador)) {
			fin = true;
			cout << "\n ------------------ GAME OVER -----------------" << endl;
			cout << "|     Ningun jugador pudo alcanzar la meta     |" << endl;
			cout << " ----------------------------------------------" << endl;
		}
		
		numJugador++;
	} while (fin == false);
}

void Tablero::instrucciones() {
	cout << "-- Instrucciones --" << endl;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << "- Serpientes: ";
	SetConsoleTextAttribute(h,244);
	cout << "S#" << endl;
	SetConsoleTextAttribute(h,240);
	cout << "- Escaleras: ";
	SetConsoleTextAttribute(h,242);
	cout << "E#" << endl;
	SetConsoleTextAttribute(h,240);
	cout << "- Jugadores: ";
	SetConsoleTextAttribute(h,241);
	cout << "J#" << endl;
	SetConsoleTextAttribute(h,240);
}
