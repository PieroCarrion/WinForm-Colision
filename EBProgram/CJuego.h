#pragma once
#include "CVectEnemigo.h"
class CJuego {
	CJugador* objJugador;
	CArrEnemigo* objVector;
	CEnemigo* objEnemigo;
	int nEnemigos;
	int dX, dY;
	int anchoF, largoF;
public:
	CJuego() {}
	~CJuego() {}
	CJuego(int anchoF,int largoF, Bitmap^ bmpJugador, Bitmap^ bmpE) {
		this->anchoF = anchoF;
		this->largoF = largoF;
		Random^ r = gcnew Random(DateTime::Now.Ticks);
		objVector = new CArrEnemigo();
		objJugador = new CJugador(10, 10, 3, 3, 40, 40, bmpJugador->Width, bmpJugador->Height);
		nEnemigos = r->Next(10,20);
		for (int i = 0; i < nEnemigos; i++){
			this->dX = r->Next(-3,3);
			this->dY = r->Next(-3, 3);
			objEnemigo = new ERunner(40, 40, dX, dY, 30, 30, bmpE->Width, bmpE->Height);
			objVector->Agregar(objEnemigo);
		}
	}
	void Mover(Keys e) {
		objJugador->Mover(e, anchoF, largoF);
	}
	void Mover() {
		objVector->Mover(anchoF, largoF, objJugador->getX(), objJugador->getY());
	}
	void Dibujar(Graphics^ g, Bitmap^ bmp,Bitmap^ bmpE) {
		objJugador->Dibujar(g,bmp);
		objVector->Dibujar(g,bmpE);
	}

};