#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	MatrixOfFormLaba2::MyForm form;
	Application::Run(% form);
}
float** A, ** B;
int N_A, M_A, N_B, M_B;
System::Void MatrixOfFormLaba2::MyForm::выходToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)//выход из проги
{
	Application::Exit();
	return System::Void();
}

System::Void MatrixOfFormLaba2::MyForm::обПрограммеToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)//кнопка "О программе"
{
	MessageBox::Show("Решение матрицы N*M,где заменяны все положительные элементы этой матрицы на максимальный элемент своей строки!", "Информация об программе!");
	return System::Void();
}

System::Void MatrixOfFormLaba2::MyForm::numericUpDownN1_ValueChanged(System::Object^ sender, System::EventArgs^ e)//Размерность, N у 1 матрицы
{
	return System::Void();
}

System::Void MatrixOfFormLaba2::MyForm::numericUpDownM2_ValueChanged(System::Object^ sender, System::EventArgs^ e)//Размерность, M у 1 матрицы
{
	return System::Void();
}

System::Void MatrixOfFormLaba2::MyForm::MatrixArr_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)//Сама матрица
{
	//Размерность матрицы Arr
	N_A =Convert::ToInt32(numericUpDownN1->Value);
	M_A = Convert::ToInt32(numericUpDownM2->Value);
	//создание матрицы
	A = new float*[M_A];
	for (int i = 0; i < N_A; i++) {
		A[i] = new float[M_A];
	}

	for (int i = 0; i < N_A; i++) {
		for (int j = 0; j < M_A; j++) {
			A[i][j] = 0;
		}
	}
	return System::Void();
}

System::Void MatrixOfFormLaba2::MyForm::numericUpDownM4_ValueChanged(System::Object^ sender, System::EventArgs^ e)//Размерность, M у 2 матрицыv
{
	return System::Void();
}

System::Void MatrixOfFormLaba2::MyForm::numericUpDownN3_ValueChanged(System::Object^ sender, System::EventArgs^ e)//Размерность, N у 2 матрицы
{
	return System::Void();
}



void MatrixOfFormLaba2::MyForm::ShowA()
{
	//Вывод матрицы Arr в таблицу
	for (int i = 0; i < N_A; i++) {
		for (int j = 0; j < M_A; j++) {
			//название таблицы в верхнем левом углу
			MatrixArr->TopLeftHeaderCell->Value = "Матрица А";
			
			//вывод номеров столбцов
			MatrixArr->Columns[j]->HeaderCell->Value = Convert::ToString(j + 1);

			//вывод номеров строк
			MatrixArr->Rows[i]->HeaderCell->Value= Convert::ToString(i + 1);

			MatrixArr->Rows[i]->Cells[j]->Value = A[i][j];
		}
	}
}
