#pragma once
using namespace System::Drawing;
class CEnemigo {
protected:
	int posX, posY;
	int dX, dY;
	int indX, indY;
	int anchoI, largoI;
	int longitudX, longitudY;
public:
	CEnemigo(){}
	~CEnemigo(){}
	CEnemigo(int posX,int posY, int dX,int dY,int longX,int longY, int anchoSprite,int largoSprite) {
		this->posX = posX;
		this->posY = posY;
		this->dX = dX;
		this->dY = dY;
		this->anchoI = longX;
		this->largoI = longY;
		this->longitudX = anchoSprite/8;	// /
		this->longitudY = largoSprite/4;	// /
		this->indX = 0;
		this->indY = 2;
	}
	virtual void Mover(int anchoF,int largoF, int pX, int pY) = 0;
	virtual void Dibujar(Graphics^ g, Bitmap^ bmp) = 0;
	int getX() { return this->posX; }
	int getY() { return this->posY; }
};

class ERunner :public CEnemigo {
public:
	//CRunner(int posX, int posY, int dX, int dY, int longX, int longY, int anchoSprite, int largoSprite) : CEnemigo(posX, posY, dX, dY, longX, longY, anchoSprite, largoSprite){}
	using CEnemigo::CEnemigo;
	//(posX, posY, dX, dY, longX, longY, anchoSprite, largoSprite);
	~ERunner() {}
	void Dibujar(Graphics^ g, Bitmap^ bmp) {
		Rectangle origen = Rectangle(indX*longitudX,indY*longitudY,longitudX,longitudY);
		Rectangle destino = Rectangle(posX, posY, anchoI, largoI);
		bmp->MakeTransparent(bmp->GetPixel(0,0));
		g->DrawImage(bmp, destino, origen, GraphicsUnit::Pixel);
	}
	void Mover(int anchoF,int largoF, int pX, int pY) {
		posX += dX;
		posY += dY;
		indX++;
		if (indX>7) {
			indX = 0;
		}
		if (posX + dX<0 || posX + dX + anchoI>anchoF) {
			dX *= -1;
		}
		if (posY + dY<0 || posY + largoI + dY>largoF) {
			dY *= -1;
		}
	}
};
class EPersecutor : public CEnemigo {


};