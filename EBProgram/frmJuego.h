#pragma once
#include "CJuego.h"
namespace EBProgram {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for frmJuego
	/// </summary>
	public ref class frmJuego : public System::Windows::Forms::Form
	{
	private:
		CJuego* Controlador;
		Bitmap^ bmpJugador;
		Graphics^ g;
		BufferedGraphics^ buffer;
		Bitmap^ bmpE;
	private: System::Windows::Forms::Timer^  timer1;
			 
	public:
		frmJuego(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~frmJuego() {
			if (components) {
				delete components;
			}
		}
	private: System::ComponentModel::IContainer^  components;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &frmJuego::timer1_Tick);
			// 
			// frmJuego
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(576, 489);
			this->Name = L"frmJuego";
			this->Text = L"frmJuego";
			this->Load += gcnew System::EventHandler(this, &frmJuego::frmJuego_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &frmJuego::frmJuego_KeyDown);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void frmJuego_Load(System::Object^  sender, System::EventArgs^  e) {
		g = this->CreateGraphics();
		BufferedGraphicsContext^ Context = BufferedGraphicsManager::Current;
		buffer = Context->Allocate(g, this->ClientRectangle);
		bmpJugador = gcnew Bitmap("bmpEnemigo.png");
		bmpE = gcnew Bitmap("bmpPersonaje.png");
		Controlador = new CJuego(this->ClientRectangle.Width,this->ClientRectangle.Height,bmpJugador,bmpE);
		
	}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		buffer->Graphics->Clear(this->BackColor);
		Controlador->Dibujar(buffer->Graphics, bmpJugador, bmpE);
		Controlador->Mover();
		buffer->Render(g);
	}
	private: System::Void frmJuego_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		Controlador->Mover(e->KeyData);
	}
	};
}
