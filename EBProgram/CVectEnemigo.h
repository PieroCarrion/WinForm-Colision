#pragma once
#include "CEnemigo.h"
#include "CPersonaje.h"
#include <vector>
using namespace std;
class CArrEnemigo {
private:
	vector<CEnemigo*> arrEnemigo;
public:
	CArrEnemigo() {}
	~CArrEnemigo() {}
	void Agregar(CEnemigo* obj) {
		arrEnemigo.push_back(obj);
	}
	void Mover(int anchoF, int largoF, int pX, int pY) {
		for (int i = 0; i < arrEnemigo.size(); i++)	{
			arrEnemigo.at(i)->Mover(anchoF,largoF,pX,pY);
		}
	}
	void Dibujar(Graphics^ g,Bitmap^ bmp) {
		for (int i = 0; i < arrEnemigo.size(); i++) {
			arrEnemigo.at(i)->Dibujar(g,bmp);
		}
	}
};