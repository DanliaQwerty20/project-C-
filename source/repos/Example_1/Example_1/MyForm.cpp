#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

//решение заключается в том,что на 34 решаем для фикс матрицы 6 на 6
//решение на 44 произвольная матрица и выполняется проврка корректности исходных данных
//кнопки уже все добавил


[STAThreadAttribute]
void main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Example1::MyForm form;
	Application::Run(% form);
}

float** A, ** B;
int N_A, M_A;


System::Void Example1::MyForm::выходToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)//Кнопка выход из программы
{
	Application::Exit();
	return System::Void();
}

System::Void Example1::MyForm::обПрограммеToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)//кнопка об программе
{
	MessageBox::Show("Для матрицы M*N заменить все положительные элементы этой матрицы на максимальное значение в этой матрице", "Информация об программе");
	return System::Void();
}





System::Void Example1::MyForm::dataGridView1A_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)//оболочка матрицы А
{
	return System::Void();
}

System::Void Example1::MyForm::CreateMatrixA1_Click(System::Object^ sender, System::EventArgs^ e)//кнопка создать матрицу А
{
	//Размерность матрицы
	N_A =Convert::ToInt32(numericUpDown1N_A->Value);
	M_A = Convert::ToInt32(numericUpDown2M_A->Value);

	//создание матрицы
	A = new float* [N_A];
	for (int i = 0; i < N_A; i++) {
		A[i] = new float[M_A];
	}
	//Зануляем матрицу
	for (int i = 0; i < N_A; i++) {
		for (int j = 0; j < M_A; j++) {
			A[i][j] = 0;
		}
	}
	//Создаем таблицу




	return System::Void();
}

System::Void Example1::MyForm::CreateMatrixA2_Click(System::Object^ sender, System::EventArgs^ e)//кнопка сгенирировать матрицу А
{
	return System::Void();
}

System::Void Example1::MyForm::button1_Click(System::Object^ sender, System::EventArgs^ e)//кнопка очистить матрицу А
{
	return System::Void();
}

System::Void Example1::MyForm::numericUpDown1N_A_ValueChanged(System::Object^ sender, System::EventArgs^ e)//Размерность матрицы А(по N)
{
	return System::Void();
}

System::Void Example1::MyForm::numericUpDown2M_A_ValueChanged(System::Object^ sender, System::EventArgs^ e)//Размерность матрицы А(по M)
{
	return System::Void();
}

System::Void Example1::MyForm::button3_Click(System::Object^ sender, System::EventArgs^ e)//Кнопка результат "=>"
{
	return System::Void();
}

System::Void Example1::MyForm::dataGridView1B_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)//оболочка матрицы B(сам результат уже)
{
	return System::Void();
}


void Example1::MyForm::ShowA()
{
	throw gcnew System::NotImplementedException();
}


