#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

//������� ����������� � ���,��� �� 34 ������ ��� ���� ������� 6 �� 6
//������� �� 44 ������������ ������� � ����������� ������� ������������ �������� ������
//������ ��� ��� �������


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


System::Void Example1::MyForm::�����ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)//������ ����� �� ���������
{
	Application::Exit();
	return System::Void();
}

System::Void Example1::MyForm::�����������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)//������ �� ���������
{
	MessageBox::Show("��� ������� M*N �������� ��� ������������� �������� ���� ������� �� ������������ �������� � ���� �������", "���������� �� ���������");
	return System::Void();
}





System::Void Example1::MyForm::dataGridView1A_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)//�������� ������� �
{
	return System::Void();
}

System::Void Example1::MyForm::CreateMatrixA1_Click(System::Object^ sender, System::EventArgs^ e)//������ ������� ������� �
{
	//����������� �������
	N_A =Convert::ToInt32(numericUpDown1N_A->Value);
	M_A = Convert::ToInt32(numericUpDown2M_A->Value);

	//�������� �������
	A = new float* [N_A];
	for (int i = 0; i < N_A; i++) {
		A[i] = new float[M_A];
	}
	//�������� �������
	for (int i = 0; i < N_A; i++) {
		for (int j = 0; j < M_A; j++) {
			A[i][j] = 0;
		}
	}
	//������� �������




	return System::Void();
}

System::Void Example1::MyForm::CreateMatrixA2_Click(System::Object^ sender, System::EventArgs^ e)//������ ������������� ������� �
{
	return System::Void();
}

System::Void Example1::MyForm::button1_Click(System::Object^ sender, System::EventArgs^ e)//������ �������� ������� �
{
	return System::Void();
}

System::Void Example1::MyForm::numericUpDown1N_A_ValueChanged(System::Object^ sender, System::EventArgs^ e)//����������� ������� �(�� N)
{
	return System::Void();
}

System::Void Example1::MyForm::numericUpDown2M_A_ValueChanged(System::Object^ sender, System::EventArgs^ e)//����������� ������� �(�� M)
{
	return System::Void();
}

System::Void Example1::MyForm::button3_Click(System::Object^ sender, System::EventArgs^ e)//������ ��������� "=>"
{
	return System::Void();
}

System::Void Example1::MyForm::dataGridView1B_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)//�������� ������� B(��� ��������� ���)
{
	return System::Void();
}


void Example1::MyForm::ShowA()
{
	throw gcnew System::NotImplementedException();
}


