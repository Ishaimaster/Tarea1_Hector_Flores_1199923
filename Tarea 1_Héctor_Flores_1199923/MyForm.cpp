#include "MyForm.h"
#include "StopWatch.h"



using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Tarea1HéctorFlores1199923::MyForm form;
	Application::Run(% form);
	return 0;
}