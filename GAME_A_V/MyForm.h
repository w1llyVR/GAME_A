#pragma once
#include "./Controller.h"
#include <iostream>
#include <string>
using namespace std;

namespace GAMEAV {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			g = this->CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(g, this->ClientRectangle);
			img = gcnew Bitmap("WhatsApp Image 2022-08-07 at 4.48.26 PM (5) (1) (4) (1) (2).png");
			fondo = gcnew Bitmap("MAPA.jpg");
			obj = new Controller();
			obj->init(img->Width / 5, img->Height / 4, g);
			bala1_seg = 0;
			balas_enemigo = 0;
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ timer1;
	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		Graphics^ g;
		BufferedGraphicsContext^ space;
		BufferedGraphics^ buffer;
		Bitmap^ img;
		Bitmap^ fondo;
		Controller* obj;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ label1;
		   int bala1_seg;
		   int balas_enemigo;
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(443, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(53, 47);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &MyForm::pictureBox1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::SystemColors::InactiveBorder;
			this->label1->Font = (gcnew System::Drawing::Font(L"Old English Text MT", 32, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(502, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(123, 51);
			this->label1->TabIndex = 1;
			this->label1->Text = L"label1";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1275, 639);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		buffer->Graphics->DrawImage(fondo, 0, 0);
		//buffer->Graphics->Clear(Color::White);
		obj->run(img,buffer->Graphics);
		buffer->Render(g);
		bala1_seg++;
		if (bala1_seg >= 50)
		{
			bala1_seg = 0;
			obj->crear_bala_p1(img->Width / 5, img->Height / 4, g);
		}
		this->label1->BackColor = System::Drawing::Color::Transparent;
		label1->Text = L"" + obj->get_n_disparos();
		balas_enemigo++;
		if (balas_enemigo >= 70)
		{
			balas_enemigo = 0;
			obj->crear_bala_enemigo(img->Width / 5, img->Height / 5, g);
		}
		if (obj->get_acabo())Close();
	}
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode)
		{
		case Keys::D: { obj->mover_personaje_1(g, 'D');  break; };
		case Keys::S: { obj->mover_personaje_1(g, 'S');  break; };
		case Keys::A: { obj->mover_personaje_1(g, 'A');  break; };
		case Keys::W: { obj->mover_personaje_1(g, 'W');  break; };
		case Keys::Space: { obj->crear_bala_disparo(img->Width / 5, img->Height / 4, g);  break; };
		default:
			break;
		}
	}
	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
