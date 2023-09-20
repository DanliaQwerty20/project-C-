#pragma once

namespace MatrixOfFormLaba2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form{
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
	private: System::Windows::Forms::Label^ NameMatrixArr;
	private: System::Windows::Forms::DataGridView^ MatrixArr;
	private: System::Windows::Forms::NumericUpDown^ numericUpDownN1;
	private: System::Windows::Forms::NumericUpDown^ numericUpDownM2;





	private: System::Windows::Forms::Label^ MatrixNArr;
	private: System::Windows::Forms::Label^ MatrixMArr;
	private: System::Windows::Forms::Button^ buttonArr2;





	private: System::Windows::Forms::Button^ buttonArr1;




	private: System::Windows::Forms::GroupBox^ MatrixBox1Arr;
	private: System::Windows::Forms::GroupBox^ MatrixBox2Brr;



	private: System::Windows::Forms::DataGridView^ MatrixBrr;

	private: System::Windows::Forms::Button^ buttonBrr1;
	private: System::Windows::Forms::Label^ NameMatrixBrr;


	private: System::Windows::Forms::Button^ buttonBrr2;
	private: System::Windows::Forms::NumericUpDown^ numericUpDownN3;


	private: System::Windows::Forms::Label^ MatrixMBrr;
	private: System::Windows::Forms::NumericUpDown^ numericUpDownM4;


	private: System::Windows::Forms::Label^ MatrixNBrr;
	private: System::Windows::Forms::Button^ button1;








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
			this->NameMatrixArr = (gcnew System::Windows::Forms::Label());
			this->MatrixArr = (gcnew System::Windows::Forms::DataGridView());
			this->numericUpDownN1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDownM2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->MatrixNArr = (gcnew System::Windows::Forms::Label());
			this->MatrixMArr = (gcnew System::Windows::Forms::Label());
			this->buttonArr2 = (gcnew System::Windows::Forms::Button());
			this->buttonArr1 = (gcnew System::Windows::Forms::Button());
			this->MatrixBox1Arr = (gcnew System::Windows::Forms::GroupBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->MatrixBox2Brr = (gcnew System::Windows::Forms::GroupBox());
			this->MatrixBrr = (gcnew System::Windows::Forms::DataGridView());
			this->buttonBrr1 = (gcnew System::Windows::Forms::Button());
			this->NameMatrixBrr = (gcnew System::Windows::Forms::Label());
			this->buttonBrr2 = (gcnew System::Windows::Forms::Button());
			this->numericUpDownN3 = (gcnew System::Windows::Forms::NumericUpDown());
			this->MatrixMBrr = (gcnew System::Windows::Forms::Label());
			this->numericUpDownM4 = (gcnew System::Windows::Forms::NumericUpDown());
			this->MatrixNBrr = (gcnew System::Windows::Forms::Label());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MatrixArr))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownN1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownM2))->BeginInit();
			this->MatrixBox1Arr->SuspendLayout();
			this->MatrixBox2Brr->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MatrixBrr))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownN3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownM4))->BeginInit();
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
			this->menuStrip1->Size = System::Drawing::Size(692, 24);
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
			// NameMatrixArr
			// 
			this->NameMatrixArr->AutoSize = true;
			this->NameMatrixArr->BackColor = System::Drawing::SystemColors::ControlLight;
			this->NameMatrixArr->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 8.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->NameMatrixArr->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->NameMatrixArr->Location = System::Drawing::Point(89, 25);
			this->NameMatrixArr->Name = L"NameMatrixArr";
			this->NameMatrixArr->Size = System::Drawing::Size(81, 16);
			this->NameMatrixArr->TabIndex = 1;
			this->NameMatrixArr->Text = L"Матрица Arr:";
			this->NameMatrixArr->Click += gcnew System::EventHandler(this, &MyForm::NameMatrixArr_Click);
			// 
			// MatrixArr
			// 
			this->MatrixArr->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->MatrixArr->Location = System::Drawing::Point(20, 44);
			this->MatrixArr->Name = L"MatrixArr";
			this->MatrixArr->Size = System::Drawing::Size(249, 150);
			this->MatrixArr->TabIndex = 2;
			this->MatrixArr->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::MatrixArr_CellContentClick);
			// 
			// numericUpDownN1
			// 
			this->numericUpDownN1->Location = System::Drawing::Point(175, 200);
			this->numericUpDownN1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDownN1->Name = L"numericUpDownN1";
			this->numericUpDownN1->Size = System::Drawing::Size(94, 20);
			this->numericUpDownN1->TabIndex = 3;
			this->numericUpDownN1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDownN1->ValueChanged += gcnew System::EventHandler(this, &MyForm::numericUpDownN1_ValueChanged);
			// 
			// numericUpDownM2
			// 
			this->numericUpDownM2->Location = System::Drawing::Point(175, 227);
			this->numericUpDownM2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDownM2->Name = L"numericUpDownM2";
			this->numericUpDownM2->Size = System::Drawing::Size(94, 20);
			this->numericUpDownM2->TabIndex = 4;
			this->numericUpDownM2->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDownM2->ValueChanged += gcnew System::EventHandler(this, &MyForm::numericUpDownM2_ValueChanged);
			// 
			// MatrixNArr
			// 
			this->MatrixNArr->AutoSize = true;
			this->MatrixNArr->BackColor = System::Drawing::SystemColors::ControlLight;
			this->MatrixNArr->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 8.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->MatrixNArr->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->MatrixNArr->Location = System::Drawing::Point(150, 204);
			this->MatrixNArr->Name = L"MatrixNArr";
			this->MatrixNArr->Size = System::Drawing::Size(19, 16);
			this->MatrixNArr->TabIndex = 5;
			this->MatrixNArr->Text = L"N:";
			this->MatrixNArr->Click += gcnew System::EventHandler(this, &MyForm::MatrixNArr_Click);
			// 
			// MatrixMArr
			// 
			this->MatrixMArr->AutoSize = true;
			this->MatrixMArr->BackColor = System::Drawing::SystemColors::ControlLight;
			this->MatrixMArr->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 8.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->MatrixMArr->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->MatrixMArr->Location = System::Drawing::Point(148, 227);
			this->MatrixMArr->Name = L"MatrixMArr";
			this->MatrixMArr->Size = System::Drawing::Size(21, 16);
			this->MatrixMArr->TabIndex = 6;
			this->MatrixMArr->Text = L"M:";
			this->MatrixMArr->Click += gcnew System::EventHandler(this, &MyForm::MatrixMArr_Click);
			// 
			// buttonArr2
			// 
			this->buttonArr2->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->buttonArr2->Font = (gcnew System::Drawing::Font(L"Mongolian Baiti", 14.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Italic | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->buttonArr2->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->buttonArr2->Location = System::Drawing::Point(183, 253);
			this->buttonArr2->Name = L"buttonArr2";
			this->buttonArr2->Size = System::Drawing::Size(86, 29);
			this->buttonArr2->TabIndex = 13;
			this->buttonArr2->Text = L"Создать";
			this->buttonArr2->UseVisualStyleBackColor = false;
			this->buttonArr2->Click += gcnew System::EventHandler(this, &MyForm::buttonArr2_Click);
			// 
			// buttonArr1
			// 
			this->buttonArr1->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->buttonArr1->Font = (gcnew System::Drawing::Font(L"Mongolian Baiti", 14.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Italic | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->buttonArr1->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->buttonArr1->Location = System::Drawing::Point(20, 253);
			this->buttonArr1->Name = L"buttonArr1";
			this->buttonArr1->Size = System::Drawing::Size(125, 29);
			this->buttonArr1->TabIndex = 14;
			this->buttonArr1->Text = L"Сгенерировать";
			this->buttonArr1->UseVisualStyleBackColor = false;
			this->buttonArr1->Click += gcnew System::EventHandler(this, &MyForm::buttonArr1_Click);
			// 
			// MatrixBox1Arr
			// 
			this->MatrixBox1Arr->Controls->Add(this->button1);
			this->MatrixBox1Arr->Controls->Add(this->MatrixArr);
			this->MatrixBox1Arr->Controls->Add(this->buttonArr1);
			this->MatrixBox1Arr->Controls->Add(this->NameMatrixArr);
			this->MatrixBox1Arr->Controls->Add(this->buttonArr2);
			this->MatrixBox1Arr->Controls->Add(this->numericUpDownN1);
			this->MatrixBox1Arr->Controls->Add(this->MatrixMArr);
			this->MatrixBox1Arr->Controls->Add(this->numericUpDownM2);
			this->MatrixBox1Arr->Controls->Add(this->MatrixNArr);
			this->MatrixBox1Arr->Location = System::Drawing::Point(12, 36);
			this->MatrixBox1Arr->Name = L"MatrixBox1Arr";
			this->MatrixBox1Arr->Size = System::Drawing::Size(297, 292);
			this->MatrixBox1Arr->TabIndex = 15;
			this->MatrixBox1Arr->TabStop = false;
			this->MatrixBox1Arr->Text = L"Матрица 1";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->button1->Font = (gcnew System::Drawing::Font(L"Mongolian Baiti", 14.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Italic | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button1->Location = System::Drawing::Point(20, 214);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(125, 29);
			this->button1->TabIndex = 17;
			this->button1->Text = L"Очистить";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// MatrixBox2Brr
			// 
			this->MatrixBox2Brr->Controls->Add(this->MatrixBrr);
			this->MatrixBox2Brr->Controls->Add(this->buttonBrr1);
			this->MatrixBox2Brr->Controls->Add(this->NameMatrixBrr);
			this->MatrixBox2Brr->Controls->Add(this->buttonBrr2);
			this->MatrixBox2Brr->Controls->Add(this->numericUpDownN3);
			this->MatrixBox2Brr->Controls->Add(this->MatrixMBrr);
			this->MatrixBox2Brr->Controls->Add(this->numericUpDownM4);
			this->MatrixBox2Brr->Controls->Add(this->MatrixNBrr);
			this->MatrixBox2Brr->Location = System::Drawing::Point(337, 36);
			this->MatrixBox2Brr->Name = L"MatrixBox2Brr";
			this->MatrixBox2Brr->Size = System::Drawing::Size(297, 292);
			this->MatrixBox2Brr->TabIndex = 16;
			this->MatrixBox2Brr->TabStop = false;
			this->MatrixBox2Brr->Text = L"Матрица 2";
			// 
			// MatrixBrr
			// 
			this->MatrixBrr->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->MatrixBrr->Location = System::Drawing::Point(20, 44);
			this->MatrixBrr->Name = L"MatrixBrr";
			this->MatrixBrr->Size = System::Drawing::Size(249, 150);
			this->MatrixBrr->TabIndex = 2;
			this->MatrixBrr->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::MatrixBrr_CellContentClick);
			// 
			// buttonBrr1
			// 
			this->buttonBrr1->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->buttonBrr1->Font = (gcnew System::Drawing::Font(L"Mongolian Baiti", 14.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Italic | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->buttonBrr1->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->buttonBrr1->Location = System::Drawing::Point(20, 253);
			this->buttonBrr1->Name = L"buttonBrr1";
			this->buttonBrr1->Size = System::Drawing::Size(125, 29);
			this->buttonBrr1->TabIndex = 14;
			this->buttonBrr1->Text = L"Рассчитать";
			this->buttonBrr1->UseVisualStyleBackColor = false;
			this->buttonBrr1->Click += gcnew System::EventHandler(this, &MyForm::buttonBrr1_Click);
			// 
			// NameMatrixBrr
			// 
			this->NameMatrixBrr->AutoSize = true;
			this->NameMatrixBrr->BackColor = System::Drawing::SystemColors::ControlLight;
			this->NameMatrixBrr->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 8.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->NameMatrixBrr->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->NameMatrixBrr->Location = System::Drawing::Point(89, 25);
			this->NameMatrixBrr->Name = L"NameMatrixBrr";
			this->NameMatrixBrr->Size = System::Drawing::Size(81, 16);
			this->NameMatrixBrr->TabIndex = 1;
			this->NameMatrixBrr->Text = L"Матрица Brr:";

			// 
			// buttonBrr2
			// 
			this->buttonBrr2->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->buttonBrr2->Font = (gcnew System::Drawing::Font(L"Mongolian Baiti", 14.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Italic | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->buttonBrr2->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->buttonBrr2->Location = System::Drawing::Point(183, 253);
			this->buttonBrr2->Name = L"buttonBrr2";
			this->buttonBrr2->Size = System::Drawing::Size(86, 29);
			this->buttonBrr2->TabIndex = 13;
			this->buttonBrr2->Text = L"Создать";
			this->buttonBrr2->UseVisualStyleBackColor = false;
			this->buttonBrr2->Click += gcnew System::EventHandler(this, &MyForm::buttonBrr2_Click);
			// 
			// numericUpDownN3
			// 
			this->numericUpDownN3->Location = System::Drawing::Point(175, 200);
			this->numericUpDownN3->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDownN3->Name = L"numericUpDownN3";
			this->numericUpDownN3->Size = System::Drawing::Size(94, 20);
			this->numericUpDownN3->TabIndex = 3;
			this->numericUpDownN3->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDownN3->ValueChanged += gcnew System::EventHandler(this, &MyForm::numericUpDownN3_ValueChanged);
			// 
			// MatrixMBrr
			// 
			this->MatrixMBrr->AutoSize = true;
			this->MatrixMBrr->BackColor = System::Drawing::SystemColors::ControlLight;
			this->MatrixMBrr->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 8.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->MatrixMBrr->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->MatrixMBrr->Location = System::Drawing::Point(148, 227);
			this->MatrixMBrr->Name = L"MatrixMBrr";
			this->MatrixMBrr->Size = System::Drawing::Size(21, 16);
			this->MatrixMBrr->TabIndex = 6;
			this->MatrixMBrr->Text = L"M:";
			this->MatrixMBrr->Click += gcnew System::EventHandler(this, &MyForm::MatrixMBrr_Click);
			// 
			// numericUpDownM4
			// 
			this->numericUpDownM4->Location = System::Drawing::Point(175, 227);
			this->numericUpDownM4->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDownM4->Name = L"numericUpDownM4";
			this->numericUpDownM4->Size = System::Drawing::Size(94, 20);
			this->numericUpDownM4->TabIndex = 4;
			this->numericUpDownM4->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDownM4->ValueChanged += gcnew System::EventHandler(this, &MyForm::numericUpDownM4_ValueChanged);
			// 
			// MatrixNBrr
			// 
			this->MatrixNBrr->AutoSize = true;
			this->MatrixNBrr->BackColor = System::Drawing::SystemColors::ControlLight;
			this->MatrixNBrr->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 8.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->MatrixNBrr->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->MatrixNBrr->Location = System::Drawing::Point(150, 204);
			this->MatrixNBrr->Name = L"MatrixNBrr";
			this->MatrixNBrr->Size = System::Drawing::Size(19, 16);
			this->MatrixNBrr->TabIndex = 5;
			this->MatrixNBrr->Text = L"N:";
			this->MatrixNBrr->Click += gcnew System::EventHandler(this, &MyForm::MatrixNBrr_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(692, 387);
			this->Controls->Add(this->MatrixBox2Brr);
			this->Controls->Add(this->MatrixBox1Arr);
			this->Controls->Add(this->menuStrip1);
			this->ForeColor = System::Drawing::SystemColors::AppWorkspace;
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Матрицы";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MatrixArr))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownN1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownM2))->EndInit();
			this->MatrixBox1Arr->ResumeLayout(false);
			this->MatrixBox1Arr->PerformLayout();
			this->MatrixBox2Brr->ResumeLayout(false);
			this->MatrixBox2Brr->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MatrixBrr))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownN3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownM4))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private: System::Void выходToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void обПрограммеToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void buttonArr1_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void buttonArr2_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void numericUpDownN1_ValueChanged(System::Object^ sender, System::EventArgs^ e);
		private: System::Void numericUpDownM2_ValueChanged(System::Object^ sender, System::EventArgs^ e);
		private: System::Void MatrixMArr_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void MatrixNArr_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void MatrixArr_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);
		private: System::Void NameMatrixArr_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void buttonBrr1_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void buttonBrr2_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void numericUpDownM4_ValueChanged(System::Object^ sender, System::EventArgs^ e);
		private: System::Void numericUpDownN3_ValueChanged(System::Object^ sender, System::EventArgs^ e);
		private: System::Void MatrixMBrr_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void MatrixNBrr_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void MatrixBrr_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);
			
			private: void ShowA();
	};
}
