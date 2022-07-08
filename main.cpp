#include<iostream>
#include <time.h>
#include "Tablero.h"
#include "Casillas.h"
using namespace std;

int main() {
	
	system("color f0");
	srand(time(NULL));
	
	int tam, s, e, jug;
	bool resp = false;
	
	do {
		cout << "De que tamanio sera el tablero (30, 40, 50, 60): ";
		cin >> tam;
		
		if ((tam == 30) or (tam == 40) or (tam == 50) or (tam == 60)) {
			resp = true;
		}
		
	} while (resp == false);
	
	do {
		cout << "\nTeclea la cantidad de serpientes en el tablero: ";
		cin >> s;
		cout << "Teclea la cantidad de escaleras en el tablero: ";
		cin >> e;
	} while (s+e > tam/2);
	
	resp = false;
	do {
		cout << "\nTeclea la cantidad de jugadores (2-5): ";
		cin >> jug;
	} while (jug < 2 or jug > 5);
	
	cout << endl;
	
	Casillas cas(tam-(s+e),s,e);
	Tablero tab(tam,cas,jug);
	
	tab.instrucciones();
	
	tab.imprimir();
	
	system("PAUSE");
	
	tab.jugar();
	
	return 0;
}
