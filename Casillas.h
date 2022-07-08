#ifndef CASILLAS_H
#define CASILLAS_H

class Casillas {
	// Atributos
	public:
		int normales, serpientes, escaleras, total, posS[30], posE[30], contS[30], contE[30];
	
	// Métodos	
	public:
		Casillas();
		Casillas(int n, int s, int e);
		~Casillas();
		void generarPos();
		void ordenar();
		void generarConteo();
};

#endif
