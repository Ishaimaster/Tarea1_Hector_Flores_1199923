#pragma once
#include "StopWatch.h"
namespace Tarea1HéctorFlores1199923 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}


		int MCD(int num1, int num2) {
			int res;
			do {
				res = num1 % num2;
				num1 = num2;
				num2 = res;
			} while (res != 0);

			return num1;
		}

		int REMCD1(int num1, int num2)
		{
			int res;
			res = num1 % num2;
			if (res == 0) {
				return num2;
			}
			else {
				return REMCD1(num2, res);
			}

		}

		bool Palindromo(String^ p1)
		{
			p1 = p1->Replace(" ", "");
			p1 = p1->ToLower();

			int norm = 0;
			int reves = p1->Length - 1;

			while (norm < reves)
			{
				if (p1[norm] != p1[reves])
				{
					return false;

				}
				norm++;
				reves--;

			}
			return true;
		}

		bool REpalindromo(String^ p1)
		{
			p1 = p1->Replace(" ", "");
			p1 = p1->ToLower();

			return(REpalindromo2(p1, 0, p1->Length - 1));
		}

		bool REpalindromo2(String^ p1, int cont1, int cont2)
		{
			if (p1[cont1] != p1[cont2]) {

				return false;
			}
			else if (cont1 >= cont2)
			{
				return true;
			}
			else
			{
				return REpalindromo2(p1, cont1 + 1, cont2 - 1);
			}
		}

		String^ DecimalBinario(int num)
		{
			String^ bin = " ";

			while (true)
			{
				if ((num % 2) == 0)
				{

					bin = ((num % 2) + bin);


				}
				else if ((num % 2) == 1)
				{
					bin = ((num % 2) + bin);
				}

				num /= 2;

				if (num <= 0) {

					break;
				}
			}
			return bin;
		}

		String^ DecimalHexadecimal(int num)
		{
			String^ hex = " ";

			while (true)
			{

				if ((num % 16) != 0)
				{
					if ((num % 16) > 9)
					{
						switch (num % 16)
						{
						case 10:
							hex = "A" + hex;
							break;
						case 11:
							hex = "B" + hex;
							break;
						case 12:
							hex = "C" + hex;
							break;
						case 13:
							hex = "D" + hex;
							break;
						case 14:
							hex = "E" + hex;
							break;
						case 15:
							hex = "F" + hex;
							break;

						}
					}
					else
					{
						hex = (num % 16) + hex;

					}
				}
				else
				{
					hex = "0" + hex;
				}

				num /= 16;

				if (num <= 0)
				{
					break;
				}
			}
			return hex;
		}

		String^ DecimalOctal(int num)
		{
			String^ oct = " ";
			double residuo;
			do
			{
				residuo = ((double)(num)) / 8;

				num = num / 8;

				residuo = ((residuo - num) * 8);

				oct = residuo + oct;
			} while (num != 0);

			return oct;
		}

		String^ DecimalBinarioRecursivo(int num)
		{	
			if (num == 0) 
			{
				return "";
			}
			
			else if (num % 2 == 0)
			{
				return DecimalBinarioRecursivo(num / 2) + "0";
			}
			else
			{
				return DecimalBinarioRecursivo(num / 2) + "1";
			}
		}
		
		String^ DecimalOctalRecursivo(int num) 
		{
			if(num == 0)
			{
				return "";
			}
			else {
				int residuo = num % 8;
				return DecimalOctalRecursivo(num/8) + Convert::ToString(residuo);
			}
		}

		String^ DecimalHexadecimalRecursivo(int num)
		{
			if (num == 0)
			{
				return "";
			}
			else
			{
				int resto = num % 16;
				String^ hexDigito = "";

				if (resto >= 10)
				{
					switch (resto)
					{
					case 10:
						hexDigito = "A";
						break;
					case 11:
						hexDigito = "B";
						break;
					case 12:
						hexDigito = "C";
						break;
					case 13:
						hexDigito = "D";
						break;
					case 14:
						hexDigito = "E";
						break;
					case 15:
						hexDigito = "F";
						break;
					}
				}
				else
				{
					hexDigito = Convert::ToString(resto);
				}

				return DecimalHexadecimalRecursivo(num / 16) + hexDigito;
			}
		}

		int BinarioDecimalRecursivo(String^ num, int p)
		{
			if (p < 0)
			{
				return 0;
			}
			else
			{
				int digito = num[p] - '0';
				return digito * (1 << (num->Length - 1 - p)) + BinarioDecimalRecursivo(num, p - 1);
			}
		}

		int OctalDecimalRecursivo(String^ num, int p)
		{
			if (p < 0)
			{
				return 0;
			}
			else
			{
				int digito = num[p] - '0';
				return digito * (int)Math::Pow(8, num->Length - 1 - p) + OctalDecimalRecursivo(num, p - 1);
			}
		}

		int HexadecimalDecimalRecursivo(String^ num, int p)
		{
			if (p < 0)
			{
				return 0;
			}
			else
			{
				char hexa = num[p];
				int digito;
				if (hexa >= '0' && hexa <= '9')
				{
					digito = hexa - '0';
				}
				else if (hexa >= 'A' && hexa <= 'F')
				{
					digito = 10 + hexa - 'A';
				}
				else if (hexa >= 'a' && hexa <= 'f')
				{
					digito = 10 + hexa - 'a';
				}
				return digito * (int)Math::Pow(16, num->Length - 1 - p) + HexadecimalDecimalRecursivo(num, p - 1);
			}
		}


		int BinarioDecimal(String^ num)
		{
			int dec = 0;
			int base = 1;

			for (int i = num->Length - 1; i >= 0; i--) {
				if (num[i] == '1') {
					dec += base;
				}
				base *= 2;
			}
			return dec;
		}

		int OctalDecimal(String^ num)
		{
			int dec = 0;
			int base = 1;

			for (int i = num->Length - 1; i >= 0; i--) {
				int digito = num[i] - '0';
				dec += digito * base;
				base *= 8;
			}
			return dec;
		}

		int HexaDecimalDecimal(String^ num)
		{
			int dec = 0;
			int base = 1;

			for (int i = num->Length - 1; i >= 0; i--) {
				char hexa = num[i];
				int digito;
				if (hexa >= '0' && hexa <= '9')
				{
					digito = hexa - '0';
				}
				else if (hexa >= 'A' && hexa <= 'F') {

					digito = 10 + hexa - 'A';
				}
				else if (hexa >= 'a' && hexa <= 'f') {

					digito = 10 + hexa - 'a';
				}
				dec += digito * base;
				base *= 16;
			}
			return dec;
		}

		bool ComprobarBinario(String^ palabra) {
			if (palabra[0] == ' ') {
				return false;
			}
			for (int i = palabra->Length - 1; i >= 0; i--) {

				if (palabra[i] != '0' && palabra[i] != '1')
				{
					return false;
				}
			}
			return true;
		}

		bool ComprobarOctal(String^ n1) {

			if (n1[0] == '0') {
				return false;
			}
			for (size_t i = 1; i < n1->Length; i++) {
				if (n1[i] < '0' || n1[i] > '7') {
					return false;
				}
			}
			return true;
		}
		
		bool ComprobarHexa(String^ n1) 
		{
			if (n1[0] == '0') {
				return false;

			}

			for (size_t i = 0; i < n1->Length; i++) {

				if (n1[i] >= 'A') {
					if (n1[i] < 'A' || n1[i] > 'F') {

						return false;
					}
					
				}
			}
			return true;

		}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TabControl^ tabControl1;
	protected:
	private: System::Windows::Forms::TabPage^ Inicio;
	private: System::Windows::Forms::Label^ lb2;
	private: System::Windows::Forms::Label^ lb1;
	private: System::Windows::Forms::TabPage^ Ejercicio1;
	private: System::Windows::Forms::TabPage^ tabPage3;
	private: System::Windows::Forms::TabPage^ tabPage4;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ res2;
	protected: System::Windows::Forms::Label^ label5;
	private:
	private: System::Windows::Forms::Label^ label4;
	protected:
	private: System::Windows::Forms::Button^ boton1;
	private: System::Windows::Forms::Label^ res1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ txtb2;
	private: System::Windows::Forms::TextBox^ txtb1;
	private: System::Windows::Forms::Label^ mcd2;
	private: System::Windows::Forms::Label^ mcd1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ cont1;
	private: System::Windows::Forms::Button^ Reiniciar;
	private: System::Windows::Forms::Button^ Finalizar;
	private: System::Windows::Forms::ListBox^ lista1;
	private: System::Windows::Forms::Button^ Comprobar;
	private: System::Windows::Forms::TextBox^ txtP1;
	private: System::Windows::Forms::Label^ paro1;
	private: System::Windows::Forms::Label^ Paronimos;
private: System::Windows::Forms::Button^ btOrigen;
private: System::Windows::Forms::Label^ convertido;


private: System::Windows::Forms::Label^ label6;
private: System::Windows::Forms::TextBox^ txtConv;
private: System::Windows::Forms::Label^ numconver;
private: System::Windows::Forms::Label^ destino;
private: System::Windows::Forms::TextBox^ txtDes;
private: System::Windows::Forms::Label^ origen;
private: System::Windows::Forms::TextBox^ baseO;
private: System::Windows::Forms::Label^ conversion;
private: System::Windows::Forms::Label^ tiempo2;

private: System::Windows::Forms::Label^ label9;
private: System::Windows::Forms::Label^ tiempo1;
private: System::Windows::Forms::Label^ label7;
private: System::Windows::Forms::Label^ tiempo4;

private: System::Windows::Forms::Label^ tiempo3;

private: System::Windows::Forms::Label^ label10;
private: System::Windows::Forms::Label^ label8;
private: System::Windows::Forms::Label^ convertidorecurs;


private: System::Windows::Forms::Label^ label11;
private: System::Windows::Forms::Label^ label14;
private: System::Windows::Forms::Label^ tiempo6;
private: System::Windows::Forms::Label^ tiempo5;
private: System::Windows::Forms::Label^ label13;
private: System::Windows::Forms::Label^ label12;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->Inicio = (gcnew System::Windows::Forms::TabPage());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->lb2 = (gcnew System::Windows::Forms::Label());
			this->lb1 = (gcnew System::Windows::Forms::Label());
			this->Ejercicio1 = (gcnew System::Windows::Forms::TabPage());
			this->tiempo2 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->tiempo1 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->res2 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->boton1 = (gcnew System::Windows::Forms::Button());
			this->res1 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->txtb2 = (gcnew System::Windows::Forms::TextBox());
			this->txtb1 = (gcnew System::Windows::Forms::TextBox());
			this->mcd2 = (gcnew System::Windows::Forms::Label());
			this->mcd1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->tiempo4 = (gcnew System::Windows::Forms::Label());
			this->tiempo3 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->cont1 = (gcnew System::Windows::Forms::Label());
			this->Reiniciar = (gcnew System::Windows::Forms::Button());
			this->Finalizar = (gcnew System::Windows::Forms::Button());
			this->lista1 = (gcnew System::Windows::Forms::ListBox());
			this->Comprobar = (gcnew System::Windows::Forms::Button());
			this->txtP1 = (gcnew System::Windows::Forms::TextBox());
			this->paro1 = (gcnew System::Windows::Forms::Label());
			this->Paronimos = (gcnew System::Windows::Forms::Label());
			this->tabPage4 = (gcnew System::Windows::Forms::TabPage());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->tiempo6 = (gcnew System::Windows::Forms::Label());
			this->tiempo5 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->convertidorecurs = (gcnew System::Windows::Forms::Label());
			this->btOrigen = (gcnew System::Windows::Forms::Button());
			this->convertido = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->txtConv = (gcnew System::Windows::Forms::TextBox());
			this->numconver = (gcnew System::Windows::Forms::Label());
			this->destino = (gcnew System::Windows::Forms::Label());
			this->txtDes = (gcnew System::Windows::Forms::TextBox());
			this->origen = (gcnew System::Windows::Forms::Label());
			this->baseO = (gcnew System::Windows::Forms::TextBox());
			this->conversion = (gcnew System::Windows::Forms::Label());
			this->tabControl1->SuspendLayout();
			this->Inicio->SuspendLayout();
			this->Ejercicio1->SuspendLayout();
			this->tabPage3->SuspendLayout();
			this->tabPage4->SuspendLayout();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->Inicio);
			this->tabControl1->Controls->Add(this->Ejercicio1);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Controls->Add(this->tabPage4);
			this->tabControl1->Location = System::Drawing::Point(-1, 0);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(677, 478);
			this->tabControl1->TabIndex = 0;
			// 
			// Inicio
			// 
			this->Inicio->BackColor = System::Drawing::Color::Snow;
			this->Inicio->Controls->Add(this->label1);
			this->Inicio->Controls->Add(this->lb2);
			this->Inicio->Controls->Add(this->lb1);
			this->Inicio->Location = System::Drawing::Point(4, 25);
			this->Inicio->Name = L"Inicio";
			this->Inicio->Padding = System::Windows::Forms::Padding(3);
			this->Inicio->Size = System::Drawing::Size(669, 449);
			this->Inicio->TabIndex = 0;
			this->Inicio->Text = L"Inicio";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(374, 406);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(283, 29);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Hecho por: Héctor Flores";
			// 
			// lb2
			// 
			this->lb2->AutoSize = true;
			this->lb2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lb2->Location = System::Drawing::Point(250, 247);
			this->lb2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lb2->Name = L"lb2";
			this->lb2->Size = System::Drawing::Size(142, 36);
			this->lb2->TabIndex = 2;
			this->lb2->Text = L"TAREA 1";
			// 
			// lb1
			// 
			this->lb1->AutoSize = true;
			this->lb1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lb1->Location = System::Drawing::Point(175, 103);
			this->lb1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lb1->Name = L"lb1";
			this->lb1->Size = System::Drawing::Size(282, 38);
			this->lb1->TabIndex = 1;
			this->lb1->Text = L"LABORATORIO 2";
			// 
			// Ejercicio1
			// 
			this->Ejercicio1->BackColor = System::Drawing::Color::AliceBlue;
			this->Ejercicio1->Controls->Add(this->tiempo2);
			this->Ejercicio1->Controls->Add(this->label9);
			this->Ejercicio1->Controls->Add(this->tiempo1);
			this->Ejercicio1->Controls->Add(this->label7);
			this->Ejercicio1->Controls->Add(this->res2);
			this->Ejercicio1->Controls->Add(this->label5);
			this->Ejercicio1->Controls->Add(this->label4);
			this->Ejercicio1->Controls->Add(this->boton1);
			this->Ejercicio1->Controls->Add(this->res1);
			this->Ejercicio1->Controls->Add(this->label3);
			this->Ejercicio1->Controls->Add(this->txtb2);
			this->Ejercicio1->Controls->Add(this->txtb1);
			this->Ejercicio1->Controls->Add(this->mcd2);
			this->Ejercicio1->Controls->Add(this->mcd1);
			this->Ejercicio1->Controls->Add(this->label2);
			this->Ejercicio1->Location = System::Drawing::Point(4, 25);
			this->Ejercicio1->Name = L"Ejercicio1";
			this->Ejercicio1->Padding = System::Windows::Forms::Padding(3);
			this->Ejercicio1->Size = System::Drawing::Size(669, 449);
			this->Ejercicio1->TabIndex = 1;
			this->Ejercicio1->Text = L"Ejercicio 1";
			// 
			// tiempo2
			// 
			this->tiempo2->AutoSize = true;
			this->tiempo2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tiempo2->Location = System::Drawing::Point(525, 367);
			this->tiempo2->Name = L"tiempo2";
			this->tiempo2->Size = System::Drawing::Size(117, 20);
			this->tiempo2->TabIndex = 25;
			this->tiempo2->Text = L"____________";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->Location = System::Drawing::Point(485, 367);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(34, 20);
			this->label9->TabIndex = 24;
			this->label9->Text = L"En:";
			// 
			// tiempo1
			// 
			this->tiempo1->AutoSize = true;
			this->tiempo1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tiempo1->Location = System::Drawing::Point(525, 309);
			this->tiempo1->Name = L"tiempo1";
			this->tiempo1->Size = System::Drawing::Size(117, 20);
			this->tiempo1->TabIndex = 23;
			this->tiempo1->Text = L"____________";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(485, 309);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(34, 20);
			this->label7->TabIndex = 22;
			this->label7->Text = L"En:";
			// 
			// res2
			// 
			this->res2->AutoSize = true;
			this->res2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->res2->Location = System::Drawing::Point(372, 309);
			this->res2->Name = L"res2";
			this->res2->Size = System::Drawing::Size(84, 20);
			this->res2->TabIndex = 21;
			this->res2->Text = L"Resultado";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::SystemColors::InactiveBorder;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::SystemColors::ControlText;
			this->label5->Location = System::Drawing::Point(197, 368);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(136, 20);
			this->label5->TabIndex = 20;
			this->label5->Text = L"Por recursividad:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(215, 309);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(109, 20);
			this->label4->TabIndex = 19;
			this->label4->Text = L"Por Iteración:";
			// 
			// boton1
			// 
			this->boton1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->boton1->Location = System::Drawing::Point(355, 227);
			this->boton1->Name = L"boton1";
			this->boton1->Size = System::Drawing::Size(86, 29);
			this->boton1->TabIndex = 18;
			this->boton1->Text = L"Calcular";
			this->boton1->UseVisualStyleBackColor = true;
			this->boton1->Click += gcnew System::EventHandler(this, &MyForm::boton1_Click);
			// 
			// res1
			// 
			this->res1->AutoSize = true;
			this->res1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->res1->Location = System::Drawing::Point(372, 368);
			this->res1->Name = L"res1";
			this->res1->Size = System::Drawing::Size(84, 20);
			this->res1->TabIndex = 17;
			this->res1->Text = L"Resultado";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(4, 329);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(192, 25);
			this->label3->TabIndex = 16;
			this->label3->Text = L"Mayor común divisor";
			// 
			// txtb2
			// 
			this->txtb2->Location = System::Drawing::Point(333, 182);
			this->txtb2->Margin = System::Windows::Forms::Padding(4);
			this->txtb2->Name = L"txtb2";
			this->txtb2->Size = System::Drawing::Size(132, 22);
			this->txtb2->TabIndex = 15;
			// 
			// txtb1
			// 
			this->txtb1->Location = System::Drawing::Point(333, 96);
			this->txtb1->Margin = System::Windows::Forms::Padding(4);
			this->txtb1->Name = L"txtb1";
			this->txtb1->Size = System::Drawing::Size(132, 22);
			this->txtb1->TabIndex = 14;
			// 
			// mcd2
			// 
			this->mcd2->AutoSize = true;
			this->mcd2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mcd2->Location = System::Drawing::Point(153, 182);
			this->mcd2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->mcd2->Name = L"mcd2";
			this->mcd2->Size = System::Drawing::Size(150, 22);
			this->mcd2->TabIndex = 13;
			this->mcd2->Text = L"Segundo Número";
			// 
			// mcd1
			// 
			this->mcd1->AutoSize = true;
			this->mcd1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mcd1->Location = System::Drawing::Point(153, 94);
			this->mcd1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->mcd1->Name = L"mcd1";
			this->mcd1->Size = System::Drawing::Size(130, 22);
			this->mcd1->TabIndex = 12;
			this->mcd1->Text = L"Primer Número";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(123, 22);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(396, 36);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Mayor Común Divisor (MCD)";
			// 
			// tabPage3
			// 
			this->tabPage3->BackColor = System::Drawing::Color::Tan;
			this->tabPage3->Controls->Add(this->tiempo4);
			this->tabPage3->Controls->Add(this->tiempo3);
			this->tabPage3->Controls->Add(this->label10);
			this->tabPage3->Controls->Add(this->label8);
			this->tabPage3->Controls->Add(this->cont1);
			this->tabPage3->Controls->Add(this->Reiniciar);
			this->tabPage3->Controls->Add(this->Finalizar);
			this->tabPage3->Controls->Add(this->lista1);
			this->tabPage3->Controls->Add(this->Comprobar);
			this->tabPage3->Controls->Add(this->txtP1);
			this->tabPage3->Controls->Add(this->paro1);
			this->tabPage3->Controls->Add(this->Paronimos);
			this->tabPage3->Location = System::Drawing::Point(4, 25);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Size = System::Drawing::Size(669, 449);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"Ejercicio 2";
			// 
			// tiempo4
			// 
			this->tiempo4->AutoSize = true;
			this->tiempo4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tiempo4->Location = System::Drawing::Point(267, 393);
			this->tiempo4->Name = L"tiempo4";
			this->tiempo4->Size = System::Drawing::Size(99, 20);
			this->tiempo4->TabIndex = 31;
			this->tiempo4->Text = L"__________";
			this->tiempo4->Visible = false;
			// 
			// tiempo3
			// 
			this->tiempo3->AutoSize = true;
			this->tiempo3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tiempo3->Location = System::Drawing::Point(240, 344);
			this->tiempo3->Name = L"tiempo3";
			this->tiempo3->Size = System::Drawing::Size(99, 20);
			this->tiempo3->TabIndex = 30;
			this->tiempo3->Text = L"__________";
			this->tiempo3->Visible = false;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label10->Location = System::Drawing::Point(63, 393);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(185, 20);
			this->label10->TabIndex = 29;
			this->label10->Text = L"Por Recursividad tardó:";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(63, 344);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(157, 20);
			this->label8->TabIndex = 28;
			this->label8->Text = L"Por Iteración tardó :";
			// 
			// cont1
			// 
			this->cont1->AutoSize = true;
			this->cont1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cont1->Location = System::Drawing::Point(161, 269);
			this->cont1->Name = L"cont1";
			this->cont1->Size = System::Drawing::Size(296, 18);
			this->cont1->TabIndex = 27;
			this->cont1->Text = L"____________________________________";
			this->cont1->Visible = false;
			// 
			// Reiniciar
			// 
			this->Reiniciar->Location = System::Drawing::Point(327, 303);
			this->Reiniciar->Name = L"Reiniciar";
			this->Reiniciar->Size = System::Drawing::Size(94, 23);
			this->Reiniciar->TabIndex = 26;
			this->Reiniciar->Text = L"Reiniciar";
			this->Reiniciar->UseVisualStyleBackColor = true;
			this->Reiniciar->Click += gcnew System::EventHandler(this, &MyForm::Reiniciar_Click);
			// 
			// Finalizar
			// 
			this->Finalizar->Location = System::Drawing::Point(175, 303);
			this->Finalizar->Name = L"Finalizar";
			this->Finalizar->Size = System::Drawing::Size(94, 23);
			this->Finalizar->TabIndex = 25;
			this->Finalizar->Text = L"Finalizar";
			this->Finalizar->UseVisualStyleBackColor = true;
			this->Finalizar->Click += gcnew System::EventHandler(this, &MyForm::Finalizar_Click);
			// 
			// lista1
			// 
			this->lista1->FormattingEnabled = true;
			this->lista1->ItemHeight = 16;
			this->lista1->Location = System::Drawing::Point(67, 173);
			this->lista1->Name = L"lista1";
			this->lista1->Size = System::Drawing::Size(484, 84);
			this->lista1->TabIndex = 24;
			// 
			// Comprobar
			// 
			this->Comprobar->Location = System::Drawing::Point(257, 144);
			this->Comprobar->Name = L"Comprobar";
			this->Comprobar->Size = System::Drawing::Size(94, 23);
			this->Comprobar->TabIndex = 23;
			this->Comprobar->Text = L"Comprobar";
			this->Comprobar->UseVisualStyleBackColor = true;
			this->Comprobar->Click += gcnew System::EventHandler(this, &MyForm::Comprobar_Click);
			// 
			// txtP1
			// 
			this->txtP1->Location = System::Drawing::Point(187, 116);
			this->txtP1->Name = L"txtP1";
			this->txtP1->Size = System::Drawing::Size(250, 22);
			this->txtP1->TabIndex = 22;
			// 
			// paro1
			// 
			this->paro1->AutoSize = true;
			this->paro1->Font = (gcnew System::Drawing::Font(L"Lucida Fax", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->paro1->Location = System::Drawing::Point(199, 78);
			this->paro1->Name = L"paro1";
			this->paro1->Size = System::Drawing::Size(222, 17);
			this->paro1->TabIndex = 21;
			this->paro1->Text = L"Ingrese la palabra que desee";
			// 
			// Paronimos
			// 
			this->Paronimos->AutoSize = true;
			this->Paronimos->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 22.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Paronimos->Location = System::Drawing::Point(196, 20);
			this->Paronimos->Name = L"Paronimos";
			this->Paronimos->Size = System::Drawing::Size(225, 42);
			this->Paronimos->TabIndex = 20;
			this->Paronimos->Text = L"Palíndromos";
			// 
			// tabPage4
			// 
			this->tabPage4->BackColor = System::Drawing::Color::WhiteSmoke;
			this->tabPage4->Controls->Add(this->label14);
			this->tabPage4->Controls->Add(this->tiempo6);
			this->tabPage4->Controls->Add(this->tiempo5);
			this->tabPage4->Controls->Add(this->label13);
			this->tabPage4->Controls->Add(this->label12);
			this->tabPage4->Controls->Add(this->label11);
			this->tabPage4->Controls->Add(this->convertidorecurs);
			this->tabPage4->Controls->Add(this->btOrigen);
			this->tabPage4->Controls->Add(this->convertido);
			this->tabPage4->Controls->Add(this->label6);
			this->tabPage4->Controls->Add(this->txtConv);
			this->tabPage4->Controls->Add(this->numconver);
			this->tabPage4->Controls->Add(this->destino);
			this->tabPage4->Controls->Add(this->txtDes);
			this->tabPage4->Controls->Add(this->origen);
			this->tabPage4->Controls->Add(this->baseO);
			this->tabPage4->Controls->Add(this->conversion);
			this->tabPage4->Location = System::Drawing::Point(4, 25);
			this->tabPage4->Name = L"tabPage4";
			this->tabPage4->Size = System::Drawing::Size(669, 449);
			this->tabPage4->TabIndex = 3;
			this->tabPage4->Text = L"Ejercicio 3";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label14->Location = System::Drawing::Point(157, 61);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(330, 16);
			this->label14->TabIndex = 26;
			this->label14->Text = L"(Bases Decimal, Binario, Octal y Hexadecimal)";
			// 
			// tiempo6
			// 
			this->tiempo6->AutoSize = true;
			this->tiempo6->Location = System::Drawing::Point(386, 375);
			this->tiempo6->Name = L"tiempo6";
			this->tiempo6->Size = System::Drawing::Size(91, 16);
			this->tiempo6->TabIndex = 25;
			this->tiempo6->Text = L"____________";
			// 
			// tiempo5
			// 
			this->tiempo5->AutoSize = true;
			this->tiempo5->Location = System::Drawing::Point(386, 322);
			this->tiempo5->Name = L"tiempo5";
			this->tiempo5->Size = System::Drawing::Size(91, 16);
			this->tiempo5->TabIndex = 24;
			this->tiempo5->Text = L"____________";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(354, 375);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(26, 16);
			this->label13->TabIndex = 23;
			this->label13->Text = L"En:";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(354, 322);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(26, 16);
			this->label12->TabIndex = 22;
			this->label12->Text = L"En:";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(102, 375);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(108, 16);
			this->label11->TabIndex = 21;
			this->label11->Text = L"Por recursividad:";
			// 
			// convertidorecurs
			// 
			this->convertidorecurs->AutoSize = true;
			this->convertidorecurs->Location = System::Drawing::Point(209, 375);
			this->convertidorecurs->Name = L"convertidorecurs";
			this->convertidorecurs->Size = System::Drawing::Size(112, 16);
			this->convertidorecurs->TabIndex = 20;
			this->convertidorecurs->Text = L"_______________";
			// 
			// btOrigen
			// 
			this->btOrigen->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btOrigen->Location = System::Drawing::Point(326, 265);
			this->btOrigen->Name = L"btOrigen";
			this->btOrigen->Size = System::Drawing::Size(100, 29);
			this->btOrigen->TabIndex = 19;
			this->btOrigen->Text = L"Convertir";
			this->btOrigen->UseVisualStyleBackColor = true;
			this->btOrigen->Click += gcnew System::EventHandler(this, &MyForm::btOrigen_Click);
			// 
			// convertido
			// 
			this->convertido->AutoSize = true;
			this->convertido->Location = System::Drawing::Point(216, 322);
			this->convertido->Name = L"convertido";
			this->convertido->Size = System::Drawing::Size(105, 16);
			this->convertido->TabIndex = 18;
			this->convertido->Text = L"______________";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(125, 322);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(85, 16);
			this->label6->TabIndex = 17;
			this->label6->Text = L"Por Iteracion:";
			// 
			// txtConv
			// 
			this->txtConv->Location = System::Drawing::Point(326, 166);
			this->txtConv->Name = L"txtConv";
			this->txtConv->Size = System::Drawing::Size(100, 22);
			this->txtConv->TabIndex = 16;
			// 
			// numconver
			// 
			this->numconver->AutoSize = true;
			this->numconver->Location = System::Drawing::Point(104, 166);
			this->numconver->Name = L"numconver";
			this->numconver->Size = System::Drawing::Size(179, 16);
			this->numconver->TabIndex = 15;
			this->numconver->Text = L"Ingrese el número a convertir";
			// 
			// destino
			// 
			this->destino->AutoSize = true;
			this->destino->Location = System::Drawing::Point(104, 232);
			this->destino->Name = L"destino";
			this->destino->Size = System::Drawing::Size(147, 16);
			this->destino->TabIndex = 14;
			this->destino->Text = L"Ingrese la base destino";
			// 
			// txtDes
			// 
			this->txtDes->Location = System::Drawing::Point(326, 226);
			this->txtDes->Name = L"txtDes";
			this->txtDes->Size = System::Drawing::Size(100, 22);
			this->txtDes->TabIndex = 13;
			// 
			// origen
			// 
			this->origen->AutoSize = true;
			this->origen->Location = System::Drawing::Point(104, 102);
			this->origen->Name = L"origen";
			this->origen->Size = System::Drawing::Size(141, 16);
			this->origen->TabIndex = 12;
			this->origen->Text = L"Ingrese la base origen";
			// 
			// baseO
			// 
			this->baseO->Location = System::Drawing::Point(326, 102);
			this->baseO->Name = L"baseO";
			this->baseO->Size = System::Drawing::Size(100, 22);
			this->baseO->TabIndex = 11;
			// 
			// conversion
			// 
			this->conversion->AutoSize = true;
			this->conversion->Font = (gcnew System::Drawing::Font(L"Lucida Fax", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->conversion->Location = System::Drawing::Point(164, 16);
			this->conversion->Name = L"conversion";
			this->conversion->Size = System::Drawing::Size(323, 26);
			this->conversion->TabIndex = 10;
			this->conversion->Text = L"Conversiones entre bases";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(673, 469);
			this->Controls->Add(this->tabControl1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->tabControl1->ResumeLayout(false);
			this->Inicio->ResumeLayout(false);
			this->Inicio->PerformLayout();
			this->Ejercicio1->ResumeLayout(false);
			this->Ejercicio1->PerformLayout();
			this->tabPage3->ResumeLayout(false);
			this->tabPage3->PerformLayout();
			this->tabPage4->ResumeLayout(false);
			this->tabPage4->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void boton1_Click(System::Object^ sender, System::EventArgs^ e) {

		int a, b;

		if (Int32::TryParse(txtb1->Text, a) && Int32::TryParse(txtb2->Text, b))
		{
			if (a == 0 && b == 0) {

				MessageBox::Show("MCD indefinido.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);

 			}
			else {


				// Aquí a y b contendrán los valores enteros ingresados correctamente

				Tiempo::tiempoInicial();

				int mcdResultado = MCD(a, b);
				int mcdResultado2 = REMCD1(a, b);

				tiempo1->Text = Tiempo::tiempoFinal() + " ms";
				res1->Text = mcdResultado.ToString();

				tiempo2->Text = Tiempo::tiempoFinal() + " ms";
				res2->Text = mcdResultado2.ToString();
			}
		}
		else
		{
			// Mostrar un mensaje de error si no se ingresó un entero válido
			MessageBox::Show("Ingresa números enteros válidos en las casillas.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
private: System::Void Comprobar_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ p1;
	static int contadorP = 0;
	p1 = txtP1->Text;
	p1 = p1->ToLower();

	Tiempo::tiempoInicial();

	if (REpalindromo(p1) && Palindromo(p1))
	{
		bool palabraRepetida = false;
		for (int i = 0; i < lista1->Items->Count; i++)
		{
			if (lista1->Items[i]->ToString() == (p1 + "  " + "es Palindromo"))
			{
				palabraRepetida = true;
				break;
			}
		}

		if (!palabraRepetida)
		{

			lista1->Items->Add(p1 + "  " + "es Palindromo");
			contadorP++;
		}
		tiempo3->Text = Tiempo::tiempoFinal() + " ms";
		tiempo4->Text = Tiempo::tiempoFinal() + " ms";
	}
	else
	{
		bool palabraRepetida = lista1->Items->Contains(p1 + "  " + "no es Palindromo");

		if (!palabraRepetida)
		{
			lista1->Items->Add(p1 + "  " + "no es Palindromo");
		}
	}
	cont1->Text = "El número de palabras palíndromas encontradas es: " + contadorP.ToString();
	
}
private: System::Void Finalizar_Click(System::Object^ sender, System::EventArgs^ e) {

	cont1->Visible = true;
	tiempo3->Visible = true;
	tiempo4->Visible = true;
}	
private: System::Void Reiniciar_Click(System::Object^ sender, System::EventArgs^ e) {
	cont1->Visible = false;
	tiempo3->Visible = false;
	tiempo4->Visible = false;
	lista1->Items->Clear();
}
private: System::Void btOrigen_Click(System::Object^ sender, System::EventArgs^ e) {

	String^ base = baseO->Text;
	String^ baseDestino = txtDes->Text;
	base = base->ToLower();
	base = base->Replace(" ", "");
	base = base->Trim();
	baseDestino = baseDestino->ToLower();
	baseDestino = baseDestino->Replace(" ", "");
	baseDestino = baseDestino->Trim();
	int num;
	String^ numero;


	if (base->Equals("decimal") || base->Equals("binario")||base->Equals("octal")|| base->Equals("hexadecimal"))
	{
		Tiempo::tiempoInicial();

		if (base == "decimal") {

			txtConv->Text = txtConv->Text->Replace(" ", "");
			
			if (Int32::TryParse(txtConv->Text, num))
			{
				

				if (baseDestino == "binario") {

					convertido->Text = DecimalBinario(num);

					convertidorecurs->Text = DecimalBinarioRecursivo(num);
				}
				else if (baseDestino == "octal")
				{
					convertido->Text = DecimalOctal(num);
					
					convertidorecurs->Text = DecimalOctalRecursivo(num);
				}
				else if (baseDestino == "hexadecimal") {

					convertido->Text = DecimalHexadecimal(num);
					convertidorecurs->Text = DecimalHexadecimalRecursivo(num);

				}
				else if (baseDestino == "decimal") {

					MessageBox::Show("No ingrese la misma base.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				}
				else {

					MessageBox::Show("Ingresa una base valida (Octal,Hexadecimal o Binario).", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				}
			}
			else {
				MessageBox::Show("Ingresa un número entero valido.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
		else if (base == "binario")
		{
			numero = txtConv->Text;
			numero = numero->Replace(" ", "");
			numero = numero->Trim();

			if (ComprobarBinario(numero)) {
				if (baseDestino == "decimal") {

					int Conversion = BinarioDecimal(numero);

					int Recursiva = BinarioDecimalRecursivo(numero,numero->Length - 1);

					System::String^ Conversionstring = System::Convert::ToString(Conversion);

					System::String^ Recursivastring = System::Convert::ToString(Recursiva);

					convertido->Text = Conversionstring;

					convertidorecurs->Text = Recursivastring;
				}
				else if (baseDestino == "octal")
				{
					convertido->Text = DecimalOctal(BinarioDecimal(numero));

					convertidorecurs->Text = DecimalOctalRecursivo(BinarioDecimalRecursivo(numero, numero->Length - 1));
				}
				else if (baseDestino == "hexadecimal") {

					convertido->Text = DecimalHexadecimal(BinarioDecimal(numero));
					convertidorecurs->Text = DecimalHexadecimalRecursivo(BinarioDecimalRecursivo(numero, numero->Length - 1));
				}
				else if (baseDestino == "binario")
				{
					MessageBox::Show("No ingrese la misma base.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				}
				else
				{
					MessageBox::Show("Ingresa una base valida (Decimal,Octal o Hexadecimal).", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				}
				
			}
			else {
				MessageBox::Show("Ingrese un número valido en binario en 1s y 0s.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
		else if (base == "octal") 
		{
			numero = txtConv->Text;
			numero = numero->Replace(" ", "");
			numero = numero->Trim();

			if (ComprobarOctal(numero)) 
			{
				if (baseDestino == "decimal") {

					int Conversion = OctalDecimal(numero);
					int Recursion = OctalDecimalRecursivo(numero, numero->Length - 1);

					System::String^ Conversionstring = System::Convert::ToString(Conversion);
					System::String^ RercusivaString = System::Convert::ToString(Conversion);

					convertido->Text = Conversionstring;
					convertidorecurs->Text = RercusivaString;
				}
				else if (baseDestino == "binario")
				{
					convertido->Text = DecimalBinario(OctalDecimal(numero));
					convertidorecurs->Text = DecimalBinarioRecursivo(OctalDecimalRecursivo(numero, numero->Length - 1));
				}
				else if (baseDestino == "hexadecimal") {

					convertido->Text = DecimalHexadecimal(OctalDecimal(numero));
					convertidorecurs->Text = DecimalHexadecimalRecursivo(OctalDecimalRecursivo(numero, numero->Length - 1));
				}
				else if (baseDestino == "octal")
				{
					MessageBox::Show("No ingrese la misma base.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				}
				else 
				{
					MessageBox::Show("Ingresa una base valida (Decimal,Hexadecimal o Binario).", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				}
				
			}
			else {
				MessageBox::Show("Ingrese un número valido en base octal.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}

			
		}
		else if (base == "hexadecimal")
		{
			numero = txtConv->Text;
			numero = numero->ToUpper();
			numero = numero->Replace(" ", "");
			numero = numero->Trim();

			if (ComprobarHexa(numero))
			{
				if (baseDestino == "decimal") {

					int Conversion = HexaDecimalDecimal(numero);
					int Recursiva = HexadecimalDecimalRecursivo(numero, numero->Length - 1);

					System::String^ Conversionstring = System::Convert::ToString(Conversion);
					System::String^ Recursion = System::Convert::ToString(Conversion);

					convertido->Text = Conversionstring;
					convertidorecurs->Text = Recursion;
				}
				else if (baseDestino == "binario")
				{
					convertido->Text = DecimalBinario(HexaDecimalDecimal(numero));
					convertidorecurs->Text = DecimalBinarioRecursivo(HexadecimalDecimalRecursivo(numero, numero->Length - 1));
				}
				else if (baseDestino == "octal") {

					convertido->Text = DecimalOctal(HexaDecimalDecimal(numero));
					convertidorecurs->Text = DecimalOctalRecursivo(HexadecimalDecimalRecursivo(numero, numero->Length - 1));
				}
				else if(baseDestino == "hexadecimal")
				{
					MessageBox::Show("No ingrese la misma base.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				}
				else {
					MessageBox::Show("Ingresa una base valida (Decimal, Binario o Octal.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				}
			}
			else {

				MessageBox::Show("Ingresa un número válido en base Hexadecimal.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			
		}
	}
	else {
		MessageBox::Show("Ingrese una base valida (Decimal,Binaria,Octal o Hexadecimal).", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}

	tiempo5->Text = Tiempo::tiempoFinalMinutos() + " min";
	tiempo6->Text = Tiempo::tiempoFinalMinutos() + " min";

}
};
}
