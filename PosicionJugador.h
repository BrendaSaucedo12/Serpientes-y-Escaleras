#ifndef POSICIONJUGADOR_H
#define POSICIONJUGADOR_H

class PosicionJugador {
	public:
		int pos;
		
	public:
		PosicionJugador();
		PosicionJugador(int p);
		~PosicionJugador();
		PosicionJugador operator+ (int d) {
			PosicionJugador aux;
			aux.pos = pos + d;
			return aux;
		}
};

#endif
