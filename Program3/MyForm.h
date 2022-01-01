#pragma once
#include "HelpForm.h"
#include "Maze.h"
#include <fstream>
#define CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

namespace Program3 {

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
			maze = nullptr;
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
	private: Maze* maze;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ File;
	private: System::Windows::Forms::ToolStripMenuItem^ OpenMaze;
	protected:


	private: System::Windows::Forms::ToolStripMenuItem^ Exit;
	private: System::Windows::Forms::ToolStripMenuItem^ Help;


	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::Button^ ShowOriginal;
	private: System::Windows::Forms::TextBox^ textBox1;



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
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->File = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->OpenMaze = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->Exit = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->Help = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->ShowOriginal = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->GripMargin = System::Windows::Forms::Padding(2, 2, 0, 2);
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(40, 40);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) { this->File, this->Help });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(520, 60);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"MenuStrip";
			// 
			// File
			// 
			this->File->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) { this->OpenMaze, this->Exit });
			this->File->Name = L"File";
			this->File->Size = System::Drawing::Size(87, 45);
			this->File->Text = L"File";
			// 
			// OpenMaze
			// 
			this->OpenMaze->Name = L"OpenMaze";
			this->OpenMaze->Size = System::Drawing::Size(338, 54);
			this->OpenMaze->Text = L"Open Maze";
			this->OpenMaze->Click += gcnew System::EventHandler(this, &MyForm::OpenMaze_Click);
			// 
			// Exit
			// 
			this->Exit->Name = L"Exit";
			this->Exit->Size = System::Drawing::Size(338, 54);
			this->Exit->Text = L"Exit";
			this->Exit->Click += gcnew System::EventHandler(this, &MyForm::Exit_Click);
			// 
			// Help
			// 
			this->Help->Name = L"Help";
			this->Help->Size = System::Drawing::Size(104, 45);
			this->Help->Text = L"Help";
			this->Help->Click += gcnew System::EventHandler(this, &MyForm::Help_Click);
			// 
			// panel1
			// 
			this->panel1->Location = System::Drawing::Point(13, 101);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(480, 480);
			this->panel1->TabIndex = 1;
			this->panel1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::panel1_MouseClick);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// ShowOriginal
			// 
			this->ShowOriginal->Location = System::Drawing::Point(22, 53);
			this->ShowOriginal->Name = L"ShowOriginal";
			this->ShowOriginal->Size = System::Drawing::Size(100, 25);
			this->ShowOriginal->TabIndex = 2;
			this->ShowOriginal->Text = L"Show Original";
			this->ShowOriginal->UseVisualStyleBackColor = true;
			this->ShowOriginal->Click += gcnew System::EventHandler(this, &MyForm::ShowOriginal_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(125, 53);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(350, 50);
			this->textBox1->TabIndex = 3;
			// 
			// MyForm
			// 
			this->ClientSize = System::Drawing::Size(520, 590);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->ShowOriginal);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"Program3";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
//opens help form
	private: System::Void Help_Click(System::Object^ sender, System::EventArgs^ e) {
		HelpForm^ f = gcnew HelpForm();
		f->ShowDialog();
	}
//opens file explore to open maze file
private: System::Void OpenMaze_Click(System::Object^ sender, System::EventArgs^ e) {
	openFileDialog1->Filter = "DATA Files|*.DAT";
	openFileDialog1->Title = "Select a Maze File";
	openFileDialog1->InitialDirectory = ".";
	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		char filename[1024];
		for (int i = 0; i < openFileDialog1->FileName->Length; i++)
		{
			filename[i] = openFileDialog1->FileName[i];
		}
		filename[openFileDialog1->FileName->Length] = '\0';
		ifstream ifs;
		ifs.open(filename);
		if (maze != nullptr)
			delete maze;
		maze = new Maze(panel1, ifs);
		ifs.close();
		if (maze != nullptr)
		{
			maze->ShowOriginal();
			if (maze->IsValid())
			{
				this->textBox1->Text = L"Maze Loaded! Great now your stuck. What you gonna do now?";
				this->ShowOriginal->Enabled = true;
			}
			else
			{
				this->textBox1->Text = L"Invalid Maze! How do you get out of a maze your not in?";
				this->ShowOriginal->Enabled = false;
			}
		}
	}
	else
	{
		this->textBox1->Text = L"File Explorer closed unexpectedly! No Maze for you.";
		this->ShowOriginal->Enabled = false;
	}

}
//exits program
private: System::Void Exit_Click(System::Object^ sender, System::EventArgs^ e) {
	if (maze != nullptr)
		delete maze;
	_CrtDumpMemoryLeaks();
	this->Close();
}
//solves maze based on where user clicks
private: System::Void panel1_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	if (maze != nullptr)
	{
		maze->Solve(e->X, e->Y);
		if (maze->IsValid())
		{
			if (maze->IsFree())
			{
				this->textBox1->Text = L"Exit Found! Time to go home have some pizza and take a nap.";
				this->ShowOriginal->Enabled = true;
			}
			else
			{
				this->textBox1->Text = L"No Exit Found! Guess you'll die of starvation :(";
				this->ShowOriginal->Enabled = true;
			}
		}
		else
		{
			this->textBox1->Text = L"Invalid Maze! How do you get out of a maze if you aren't in one?";
			this->ShowOriginal->Enabled = false;
		}
	}
}
//reverts maze back to original before solving attempt
private: System::Void ShowOriginal_Click(System::Object^ sender, System::EventArgs^ e) {
	if (maze != nullptr)
	{
		maze->ShowOriginal();
		this->textBox1->Text = L"Original Maze! Why are we going back to the start?";
	}
	else
	{
		this->textBox1->Text = L"Open a Maze First! Don't pick a hard one, I still have code to finish.";
	}

}
};
}
