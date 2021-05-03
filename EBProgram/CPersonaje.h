#pragma once
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;
class CJugador {
private:
	int posX, posY;
	int dX, dY;
	int indX, indY;
	int anchoI, largoI;
	int longitudX, longitudY;
public:
	CJugador() {}
	~CJugador() {}
	CJugador(int posX,int posY,int dX,int dY,int longX, int longY, int anchoSprite, int largoSprite) {
		this->posX = posX;
		this->posY = posY;
		this->dX = dX;
		this->dY = dY;
		this->anchoI = longX;
		this->largoI = longY;
		this->longitudX = anchoSprite / 9;
		this->longitudY = largoSprite / 4;
		this->indX = 0;
		this->indY = 0;
	}
	void Mover(Keys e, int anchoF, int largoF) {
		if (e == Keys::Right && posX + dX + anchoI < anchoF) {
			indY = 3;
			posX += dX;
		}
		else if (e == Keys::Left && posX - dX > 0) {
			indY = 1;
			posX -= dX;
		}
		else if (e == Keys::Up && posY - dY > 0) {
			indY = 0;
			posY -= dY;
		}
		else if (e == Keys::Down && posY + dY + largoI < largoF) {
			indY = 2;
			posY += dY;
		}
		
		if (indX >= 8) {
			indX = 0;
		}
		indX++;
	}
	void Gravedad(float speedY) {
		posY -= speedY;
	}
	void Dibujar(Graphics^ g, Bitmap^ bmp) {
		Rectangle origen = Rectangle(indX*longitudX, indY*longitudY, longitudX, longitudY);
		Rectangle destino = Rectangle(posX, posY, anchoI, largoI);
		g->DrawImage(bmp, destino, origen, GraphicsUnit::Pixel);
	}
	void setPosY(int n) { this->posY = n; }
	int getX() { return this->posX; }
	int getY() { return this->posY; }
};