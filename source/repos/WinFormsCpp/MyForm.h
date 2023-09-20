#pragma once

namespace FastnewForm3Laba2Programming {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^ выходToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ обПрограммеToolStripMenuItem;
	private: System::Windows::Forms::Label^ NameMatrixA;
	private: System::Windows::Forms::DataGridView^ dataGridView1MatrixA;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown1N_A;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown2M_A;
	private: System::Windows::Forms::Button^ CreateMatrix1;


	private: System::Windows::Forms::Button^ GenerateMatrixA;
	private: System::Windows::Forms::Button^ ClearMatrixA;
	private: System::Windows::Forms::Button^ ResultOfMatrixAOfMatrixB;
	private: System::Windows::Forms::GroupBox^ GroupBox1MatrixA;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::GroupBox^ groupBox2;

	private: System::Windows::Forms::DataGridView^ dataGridView2MatrixB;
	private: System::Windows::Forms::Label^ NameMatrixB;



	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->выходToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->обПрограммеToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->NameMatrixA = (gcnew System::Windows::Forms::Label());
			this->dataGridView1MatrixA = (gcnew System::Windows::Forms::DataGridView());
			this->numericUpDown1N_A = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown2M_A = (gcnew System::Windows::Forms::NumericUpDown());
			this->CreateMatrix1 = (gcnew System::Windows::Forms::Button());
			this->GenerateMatrixA = (gcnew System::Windows::Forms::Button());
			this->ClearMatrixA = (gcnew System::Windows::Forms::Button());
			this->ResultOfMatrixAOfMatrixB = (gcnew System::Windows::Forms::Button());
			this->GroupBox1MatrixA = (gcnew System::Windows::Forms::GroupBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->dataGridView2MatrixB = (gcnew System::Windows::Forms::DataGridView());
			this->NameMatrixB = (gcnew System::Windows::Forms::Label());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1MatrixA))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1N_A))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2M_A))->BeginInit();
			this->GroupBox1MatrixA->SuspendLayout();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2MatrixB))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->выходToolStripMenuItem,
					this->обПрограммеToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(679, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// выходToolStripMenuItem
			// 
			this->выходToolStripMenuItem->Name = L"выходToolStripMenuItem";
			this->выходToolStripMenuItem->Size = System::Drawing::Size(54, 20);
			this->выходToolStripMenuItem->Text = L"Выход";
			this->выходToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::выходToolStripMenuItem_Click);
			// 
			// обПрограммеToolStripMenuItem
			// 
			this->обПрограммеToolStripMenuItem->Name = L"обПрограммеToolStripMenuItem";
			this->обПрограммеToolStripMenuItem->Size = System::Drawing::Size(101, 20);
			this->обПрограммеToolStripMenuItem->Text = L"Об программе";
			this->обПрограммеToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::обПрограммеToolStripMenuItem_Click);
			// 
			// NameMatrixA
			// 
			this->NameMatrixA->AutoSize = true;
			this->NameMatrixA->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->NameMatrixA->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 14.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->NameMatrixA->Location = System::Drawing::Point(69, 15);
			this->NameMatrixA->Name = L"NameMatrixA";
			this->NameMatrixA->Size = System::Drawing::Size(96, 22);
			this->NameMatrixA->TabIndex = 3;
			this->NameMatrixA->Text = L"Матрица А";
			// 
			// dataGridView1MatrixA
			// 
			this->dataGridView1MatrixA->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1MatrixA->Location = System::Drawing::Point(6, 40);
			this->dataGridView1MatrixA->Name = L"dataGridView1MatrixA";
			this->dataGridView1MatrixA->Size = System::Drawing::Size(240, 150);
			this->dataGridView1MatrixA->TabIndex = 5;
			this->dataGridView1MatrixA->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView1MatrixA_CellContentClick);
			// 
			// numericUpDown1N_A
			// 
			this->numericUpDown1N_A->Location = System::Drawing::Point(126, 254);
			this->numericUpDown1N_A->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown1N_A->Name = L"numericUpDown1N_A";
			this->numericUpDown1N_A->Size = System::Drawing::Size(120, 20);
			this->numericUpDown1N_A->TabIndex = 7;
			this->numericUpDown1N_A->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown1N_A->ValueChanged += gcnew System::EventHandler(this, &MyForm::numericUpDown1N_A_ValueChanged);
			// 
			// numericUpDown2M_A
			// 
			this->numericUpDown2M_A->Location = System::Drawing::Point(126, 280);
			this->numericUpDown2M_A->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown2M_A->Name = L"numericUpDown2M_A";
			this->numericUpDown2M_A->Size = System::Drawing::Size(120, 20);
			this->numericUpDown2M_A->TabIndex = 8;
			this->numericUpDown2M_A->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown2M_A->ValueChanged += gcnew System::EventHandler(this, &MyForm::numericUpDown2M_A_ValueChanged);
			// 
			// CreateMatrix1
			// 
			this->CreateMatrix1->Font = (gcnew System::Drawing::Font(L"Myanmar Text", 9.75F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->CreateMatrix1->Location = System::Drawing::Point(172, 196);
			this->CreateMatrix1->Name = L"CreateMatrix1";
			this->CreateMatrix1->Size = System::Drawing::Size(75, 23);
			this->CreateMatrix1->TabIndex = 9;
			this->CreateMatrix1->Text = L"Создать";
			this->CreateMatrix1->UseVisualStyleBackColor = true;
			this->CreateMatrix1->Click += gcnew System::EventHandler(this, &MyForm::CreateMatrix1_Click);
			// 
			// GenerateMatrixA
			// 
			this->GenerateMatrixA->Font = (gcnew System::Drawing::Font(L"Myanmar Text", 9.75F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->GenerateMatrixA->Location = System::Drawing::Point(126, 225);
			this->GenerateMatrixA->Name = L"GenerateMatrixA";
			this->GenerateMatrixA->Size = System::Drawing::Size(120, 23);
			this->GenerateMatrixA->TabIndex = 10;
			this->GenerateMatrixA->Text = L"Сгенерировать";
			this->GenerateMatrixA->UseVisualStyleBackColor = true;
			this->GenerateMatrixA->Click += gcnew System::EventHandler(this, &MyForm::GenerateMatrixA_Click);
			// 
			// ClearMatrixA
			// 
			this->ClearMatrixA->Font = (gcnew System::Drawing::Font(L"Myanmar Text", 9.75F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ClearMatrixA->Location = System::Drawing::Point(6, 196);
			this->ClearMatrixA->Name = L"ClearMatrixA";
			this->ClearMatrixA->Size = System::Drawing::Size(101, 23);
			this->ClearMatrixA->TabIndex = 11;
			this->ClearMatrixA->Text = L"Очистить";
			this->ClearMatrixA->UseVisualStyleBackColor = true;
			this->ClearMatrixA->Click += gcnew System::EventHandler(this, &MyForm::ClearMatrixA_Click);
			// 
			// ResultOfMatrixAOfMatrixB
			// 
			this->ResultOfMatrixAOfMatrixB->Font = (gcnew System::Drawing::Font(L"Myanmar Text", 9.75F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ResultOfMatrixAOfMatrixB->Location = System::Drawing::Point(287, 143);
			this->ResultOfMatrixAOfMatrixB->Name = L"ResultOfMatrixAOfMatrixB";
			this->ResultOfMatrixAOfMatrixB->Size = System::Drawing::Size(75, 23);
			this->ResultOfMatrixAOfMatrixB->TabIndex = 12;
			this->ResultOfMatrixAOfMatrixB->Text = L"=>";
			this->ResultOfMatrixAOfMatrixB->UseVisualStyleBackColor = true;
			this->ResultOfMatrixAOfMatrixB->Click += gcnew System::EventHandler(this, &MyForm::ResultOfMatrixAOfMatrixB_Click);
			// 
			// GroupBox1MatrixA
			// 
			this->GroupBox1MatrixA->Controls->Add(this->button2);
			this->GroupBox1MatrixA->Controls->Add(this->button1);
			this->GroupBox1MatrixA->Controls->Add(this->dataGridView1MatrixA);
			this->GroupBox1MatrixA->Controls->Add(this->NameMatrixA);
			this->GroupBox1MatrixA->Controls->Add(this->numericUpDown2M_A);
			this->GroupBox1MatrixA->Controls->Add(this->GenerateMatrixA);
			this->GroupBox1MatrixA->Controls->Add(this->numericUpDown1N_A);
			this->GroupBox1MatrixA->Controls->Add(this->ClearMatrixA);
			this->GroupBox1MatrixA->Controls->Add(this->CreateMatrix1);
			this->GroupBox1MatrixA->Location = System::Drawing::Point(12, 37);
			this->GroupBox1MatrixA->Name = L"GroupBox1MatrixA";
			this->GroupBox1MatrixA->Size = System::Drawing::Size(253, 311);
			this->GroupBox1MatrixA->TabIndex = 13;
			this->GroupBox1MatrixA->TabStop = false;
			this->GroupBox1MatrixA->Text = L"Матрица А";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(86, 280);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(34, 20);
			this->button2->TabIndex = 15;
			this->button2->Text = L"M:";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(86, 254);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(34, 20);
			this->button1->TabIndex = 12;
			this->button1->Text = L"N:";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->dataGridView2MatrixB);
			this->groupBox2->Controls->Add(this->NameMatrixB);
			this->groupBox2->Location = System::Drawing::Point(377, 37);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(253, 311);
			this->groupBox2->TabIndex = 14;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Матрица В";
			// 
			// dataGridView2MatrixB
			// 
			this->dataGridView2MatrixB->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2MatrixB->Location = System::Drawing::Point(6, 40);
			this->dataGridView2MatrixB->Name = L"dataGridView2MatrixB";
			this->dataGridView2MatrixB->Size = System::Drawing::Size(240, 150);
			this->dataGridView2MatrixB->TabIndex = 5;
			// 
			// NameMatrixB
			// 
			this->NameMatrixB->AutoSize = true;
			this->NameMatrixB->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->NameMatrixB->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 14.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->NameMatrixB->Location = System::Drawing::Point(69, 15);
			this->NameMatrixB->Name = L"NameMatrixB";
			this->NameMatrixB->Size = System::Drawing::Size(95, 22);
			this->NameMatrixB->TabIndex = 3;
			this->NameMatrixB->Text = L"Матрица В";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(679, 408);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->GroupBox1MatrixA);
			this->Controls->Add(this->ResultOfMatrixAOfMatrixB);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"Матрица";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1MatrixA))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1N_A))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2M_A))->EndInit();
			this->GroupBox1MatrixA->ResumeLayout(false);
			this->GroupBox1MatrixA->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2MatrixB))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private: System::Void выходToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void обПрограммеToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);

		private: System::Void dataGridView1MatrixA_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);
		private: System::Void ClearMatrixA_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void CreateMatrix1_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void GenerateMatrixA_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void numericUpDown1N_A_ValueChanged(System::Object^ sender, System::EventArgs^ e);
		private: System::Void numericUpDown2M_A_ValueChanged(System::Object^ sender, System::EventArgs^ e);
		private: System::Void ResultOfMatrixAOfMatrixB_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void OutMaxMatrixB_Click(System::Object^ sender, System::EventArgs^ e);


		private: void ShowA();
		private: void ShowResult(float** C);
		  
};
}
