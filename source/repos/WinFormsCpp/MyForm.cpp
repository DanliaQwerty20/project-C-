

#include "MyForm.h"
#include <iostream>

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	FastnewForm3Laba2Programming::MyForm form;
	Application::Run(% form);
}

float** A, ** B;
int N_A=0, M_A=0,max1;


System::Void FastnewForm3Laba2Programming::MyForm::выходToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)//кнопка выход
{
	Application::Exit();
	return System::Void();
}

System::Void FastnewForm3Laba2Programming::MyForm::обПрограммеToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)//кнопка об программе
{
	MessageBox::Show("...", "Информация об программе");
	return System::Void();
}

System::Void FastnewForm3Laba2Programming::MyForm::dataGridView1MatrixA_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)//Оболочка матрицы А
{
	return System::Void();
}

System::Void FastnewForm3Laba2Programming::MyForm::ClearMatrixA_Click(System::Object^ sender, System::EventArgs^ e)//кнопка очистить матрицу А
{
	N_A = Convert::ToInt32(numericUpDown1N_A->Value);
	M_A = Convert::ToInt32(numericUpDown2M_A->Value);

	//Создаем матрицы
	A = new float* [N_A];
	for (int i = 0; i < N_A; i++) {
		A[i] = new float[M_A];
	}
	for (int i = 0; i < N_A; i++) {
		for (int j = 0; j < M_A; j++) {
			A[i][j] = 0;
		}
	}
	ShowA();


	//Ровняем
	dataGridView1MatrixA->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);//ячейки
	dataGridView1MatrixA->AutoResizeColumns();//столбы
	return System::Void();
}

System::Void FastnewForm3Laba2Programming::MyForm::CreateMatrix1_Click(System::Object^ sender, System::EventArgs^ e)//кнопка создать матрицу А
{
	//Размерность матрицы
	N_A =Convert::ToInt32(numericUpDown1N_A->Value);
	M_A = Convert::ToInt32(numericUpDown2M_A->Value);

	//Создаем матрицы
	A = new float* [N_A];
	for (int i = 0; i < N_A; i++) {
		A[i] = new float[M_A];
	}

	//Занулим матрицу
	for (int i = 0; i < N_A; i++) {
		for (int j = 0; j < M_A; j++) {
			A[i][j] = 0;
		}
	}

	//создаем таблицу
	dataGridView1MatrixA->RowCount = N_A;
	dataGridView1MatrixA->ColumnCount = M_A;

	//вывод
	ShowA();


	//Ровняем
	dataGridView1MatrixA->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);//ячейки
	dataGridView1MatrixA->AutoResizeColumns();//столбы
	
	return System::Void();

}

System::Void FastnewForm3Laba2Programming::MyForm::GenerateMatrixA_Click(System::Object^ sender, System::EventArgs^ e)//генератор матрицы А
{
	if (N_A == 0 || M_A == 0) {
		MessageBox::Show("Матрица отсутствует!", "Ошибка!");
		return;
	}
	std::nullptr_t;
	std::srand(time(NULL));
	//Генерация матрицы
	for (int i = 0; i < N_A; i++) {
		for (int j = 0; j < M_A; j++) {
			A[i][j] = rand() % 10+1;
		}
	}
	//вывод
	ShowA();

	//Ровняем
	dataGridView1MatrixA->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);//ячейки
	dataGridView1MatrixA->AutoResizeColumns();//столбы

	return System::Void();
}

System::Void FastnewForm3Laba2Programming::MyForm::numericUpDown1N_A_ValueChanged(System::Object^ sender, System::EventArgs^ e)//столбцы матрицы N
{
	return System::Void();
}

System::Void FastnewForm3Laba2Programming::MyForm::numericUpDown2M_A_ValueChanged(System::Object^ sender, System::EventArgs^ e)//строки матрицы M
{
	return System::Void();
}

System::Void FastnewForm3Laba2Programming::MyForm::ResultOfMatrixAOfMatrixB_Click(System::Object^ sender, System::EventArgs^ e)//Кнопка результат =>
{
	if (N_A == 0 || M_A == 0) {
		MessageBox::Show("Матрица отсутствует!", "Ошибка!");
		return;
	}
	//создаем таблицу
	dataGridView2MatrixB->RowCount = N_A;
	dataGridView2MatrixB->ColumnCount = M_A;
	float** C;
	C = new float* [N_A];
	for (int i = 0; i < N_A; i++) {
		C[i] = new float[M_A];
	}
	float max = 0;
	for (int i = 0; i < N_A; i++) {
		for (int j = 0; j < M_A; j++) {
			if (max <= A[i][j]) {
				max = A[i][j];
			}
		}
	}
	max1 = max;
	for (int i = 0; i < N_A; i++) {
		for (int j = 0; j < M_A; j++) {
			if (A[i][j] > 0) {
				C[i][j] = max;
			}
			else {
				C[i][j] = C[i][j];
			}
		}
	}
	ShowResult(C);

	//Ровняем
	dataGridView2MatrixB->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);//ячейки
	dataGridView2MatrixB->AutoResizeColumns();//столбы
	return System::Void();
}

System::Void FastnewForm3Laba2Programming::MyForm::OutMaxMatrixB_Click(System::Object^ sender, System::EventArgs^ e)//Вывод максимума 
{
	
	MessageBox::Show("","");
	return System::Void();
}

void FastnewForm3Laba2Programming::MyForm::ShowA()
{
	//Вывод матрицы А в таблицу
	for (int i = 0; i < N_A; i++) {
		for (int j = 0; j < M_A; j++) {
			//Название таблицы в верхнем левом углу
			dataGridView1MatrixA->TopLeftHeaderCell->Value = "Матрица А";
			
			//Вывод номеров столбцов
			dataGridView1MatrixA->Columns[j]->HeaderCell->Value = Convert::ToString(j + 1);
			
			//Вывод номеров строк
			dataGridView1MatrixA->Rows[i]->HeaderCell->Value = Convert::ToString(i + 1);

			//Вывод значения матрицы
			dataGridView1MatrixA->Rows[i]->Cells[j]->Value = A[i][j];

		}
	}
}

void FastnewForm3Laba2Programming::MyForm::ShowResult(float** C)
{
	//Вывод матрицы C в таблицу
	for (int i = 0; i < N_A; i++) {
		for (int j = 0; j < M_A; j++) {
			//Название таблицы в верхнем левом углу
			dataGridView2MatrixB->TopLeftHeaderCell->Value = "Матрица C";
			
			//Вывод номеров строк
			dataGridView2MatrixB->Rows[i]->HeaderCell->Value = Convert::ToString(i);
			//Вывод номеров столбцов
			dataGridView2MatrixB->Columns[j]->HeaderCell->Value = Convert::ToString(j);



			//Вывод значения матрицы
			dataGridView2MatrixB->Rows[i]->Cells[j]->Value = C[i][j];

		}
	}
}
