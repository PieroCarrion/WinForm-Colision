#include "frmJuego.h"
using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]
void main() {
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	Application::Run(gcnew EBProgram::frmJuego);
}
