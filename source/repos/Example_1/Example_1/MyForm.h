#pragma once

namespace Example1 {

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
	private: System::Windows::Forms::Label^ NameMatrix_A;
	private: System::Windows::Forms::DataGridView^ dataGridView1A;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown1N_A;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown2M_A;
	private: System::Windows::Forms::Button^ CreateMatrixA1;
	private: System::Windows::Forms::Button^ CreateMatrixA2;



	private: System::Windows::Forms::GroupBox^ groupBox1MatrixA;
	private: System::Windows::Forms::GroupBox^ groupBox2MatrixB;


	private: System::Windows::Forms::DataGridView^ dataGridView1B;
	private: System::Windows::Forms::Label^ NameMatrix_B;










	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ выходToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ обПрограммеToolStripMenuItem;

	protected:

	protected:




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
			this->NameMatrix_A = (gcnew System::Windows::Forms::Label());
			this->dataGridView1A = (gcnew System::Windows::Forms::DataGridView());
			this->numericUpDown1N_A = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown2M_A = (gcnew System::Windows::Forms::NumericUpDown());
			this->CreateMatrixA1 = (gcnew System::Windows::Forms::Button());
			this->CreateMatrixA2 = (gcnew System::Windows::Forms::Button());
			this->groupBox1MatrixA = (gcnew System::Windows::Forms::GroupBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->groupBox2MatrixB = (gcnew System::Windows::Forms::GroupBox());
			this->dataGridView1B = (gcnew System::Windows::Forms::DataGridView());
			this->NameMatrix_B = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->выходToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->обПрограммеToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1A))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1N_A))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2M_A))->BeginInit();
			this->groupBox1MatrixA->SuspendLayout();
			this->groupBox2MatrixB->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1B))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// NameMatrix_A
			// 
			this->NameMatrix_A->AutoSize = true;
			this->NameMatrix_A->Font = (gcnew System::Drawing::Font(L"Mongolian Baiti", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Italic | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->NameMatrix_A->Location = System::Drawing::Point(179, 1);
			this->NameMatrix_A->Name = L"NameMatrix_A";
			this->NameMatrix_A->Size = System::Drawing::Size(71, 16);
			this->NameMatrix_A->TabIndex = 0;
			this->NameMatrix_A->Text = L"Матрица А";
			// 
			// dataGridView1A
			// 
			this->dataGridView1A->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1A->Location = System::Drawing::Point(6, 19);
			this->dataGridView1A->Name = L"dataGridView1A";
			this->dataGridView1A->Size = System::Drawing::Size(240, 150);
			this->dataGridView1A->TabIndex = 1;
			this->dataGridView1A->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView1A_CellContentClick);
			// 
			// numericUpDown1N_A
			// 
			this->numericUpDown1N_A->Location = System::Drawing::Point(150, 175);
			this->numericUpDown1N_A->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown1N_A->Name = L"numericUpDown1N_A";
			this->numericUpDown1N_A->Size = System::Drawing::Size(96, 20);
			this->numericUpDown1N_A->TabIndex = 2;
			this->numericUpDown1N_A->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown1N_A->ValueChanged += gcnew System::EventHandler(this, &MyForm::numericUpDown1N_A_ValueChanged);
			// 
			// numericUpDown2M_A
			// 
			this->numericUpDown2M_A->Location = System::Drawing::Point(150, 201);
			this->numericUpDown2M_A->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown2M_A->Name = L"numericUpDown2M_A";
			this->numericUpDown2M_A->Size = System::Drawing::Size(96, 20);
			this->numericUpDown2M_A->TabIndex = 3;
			this->numericUpDown2M_A->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown2M_A->ValueChanged += gcnew System::EventHandler(this, &MyForm::numericUpDown2M_A_ValueChanged);
			// 
			// CreateMatrixA1
			// 
			this->CreateMatrixA1->Font = (gcnew System::Drawing::Font(L"Mongolian Baiti", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Italic | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->CreateMatrixA1->Location = System::Drawing::Point(6, 175);
			this->CreateMatrixA1->Name = L"CreateMatrixA1";
			this->CreateMatrixA1->Size = System::Drawing::Size(75, 23);
			this->CreateMatrixA1->TabIndex = 4;
			this->CreateMatrixA1->Text = L"Создать";
			this->CreateMatrixA1->UseVisualStyleBackColor = true;
			this->CreateMatrixA1->Click += gcnew System::EventHandler(this, &MyForm::CreateMatrixA1_Click);
			// 
			// CreateMatrixA2
			// 
			this->CreateMatrixA2->Font = (gcnew System::Drawing::Font(L"Mongolian Baiti", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Italic | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->CreateMatrixA2->Location = System::Drawing::Point(6, 198);
			this->CreateMatrixA2->Name = L"CreateMatrixA2";
			this->CreateMatrixA2->Size = System::Drawing::Size(125, 23);
			this->CreateMatrixA2->TabIndex = 5;
			this->CreateMatrixA2->Text = L"Сгенерировать";
			this->CreateMatrixA2->UseVisualStyleBackColor = true;
			this->CreateMatrixA2->Click += gcnew System::EventHandler(this, &MyForm::CreateMatrixA2_Click);
			// 
			// groupBox1MatrixA
			// 
			this->groupBox1MatrixA->Controls->Add(this->button1);
			this->groupBox1MatrixA->Controls->Add(this->dataGridView1A);
			this->groupBox1MatrixA->Controls->Add(this->CreateMatrixA2);
			this->groupBox1MatrixA->Controls->Add(this->NameMatrix_A);
			this->groupBox1MatrixA->Controls->Add(this->CreateMatrixA1);
			this->groupBox1MatrixA->Controls->Add(this->numericUpDown1N_A);
			this->groupBox1MatrixA->Controls->Add(this->numericUpDown2M_A);
			this->groupBox1MatrixA->Location = System::Drawing::Point(12, 68);
			this->groupBox1MatrixA->Name = L"groupBox1MatrixA";
			this->groupBox1MatrixA->Size = System::Drawing::Size(256, 312);
			this->groupBox1MatrixA->TabIndex = 6;
			this->groupBox1MatrixA->TabStop = false;
			this->groupBox1MatrixA->Text = L"Матрица А";
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Mongolian Baiti", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Italic | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(6, 227);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(125, 23);
			this->button1->TabIndex = 10;
			this->button1->Text = L"Очистить";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// groupBox2MatrixB
			// 
			this->groupBox2MatrixB->Controls->Add(this->dataGridView1B);
			this->groupBox2MatrixB->Controls->Add(this->NameMatrix_B);
			this->groupBox2MatrixB->Location = System::Drawing::Point(390, 69);
			this->groupBox2MatrixB->Name = L"groupBox2MatrixB";
			this->groupBox2MatrixB->Size = System::Drawing::Size(256, 198);
			this->groupBox2MatrixB->TabIndex = 7;
			this->groupBox2MatrixB->TabStop = false;
			this->groupBox2MatrixB->Text = L"Матрица B(Результат)";
			// 
			// dataGridView1B
			// 
			this->dataGridView1B->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1B->Location = System::Drawing::Point(6, 20);
			this->dataGridView1B->Name = L"dataGridView1B";
			this->dataGridView1B->Size = System::Drawing::Size(240, 150);
			this->dataGridView1B->TabIndex = 1;
			this->dataGridView1B->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView1B_CellContentClick);
			// 
			// NameMatrix_B
			// 
			this->NameMatrix_B->AutoSize = true;
			this->NameMatrix_B->Font = (gcnew System::Drawing::Font(L"Mongolian Baiti", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Italic | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->NameMatrix_B->Location = System::Drawing::Point(171, 1);
			this->NameMatrix_B->Name = L"NameMatrix_B";
			this->NameMatrix_B->Size = System::Drawing::Size(75, 16);
			this->NameMatrix_B->TabIndex = 0;
			this->NameMatrix_B->Text = L"Матрица B";
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button3->Location = System::Drawing::Point(291, 214);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 8;
			this->button3->Text = L"=>";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->выходToolStripMenuItem,
					this->обПрограммеToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(718, 24);
			this->menuStrip1->TabIndex = 9;
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
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(718, 408);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->groupBox2MatrixB);
			this->Controls->Add(this->groupBox1MatrixA);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Матрицы";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1A))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1N_A))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2M_A))->EndInit();
			this->groupBox1MatrixA->ResumeLayout(false);
			this->groupBox1MatrixA->PerformLayout();
			this->groupBox2MatrixB->ResumeLayout(false);
			this->groupBox2MatrixB->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1B))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		private: System::Void выходToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);//Кнопка выход из программы
		private: System::Void обПрограммеToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);//кнопка об программе
		private: System::Void dataGridView1A_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);//оболочка матрицы А
		private: System::Void CreateMatrixA1_Click(System::Object^ sender, System::EventArgs^ e);//кнопка создать матрицу А
		private: System::Void CreateMatrixA2_Click(System::Object^ sender, System::EventArgs^ e);//кнопка сгенирировать матрицу А
		private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);//кнопка очистить матрицу А
		private: System::Void numericUpDown1N_A_ValueChanged(System::Object^ sender, System::EventArgs^ e);//Размерность матрицы А(по N)
		private: System::Void numericUpDown2M_A_ValueChanged(System::Object^ sender, System::EventArgs^ e);//Размерность матрицы А(по M)
		private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e);//Кнопка результат "=>"
		private: System::Void dataGridView1B_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);//оболочка матрицы B(сам результат уже)


		private:void ShowA();
	};
}
