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
System::Void MatrixOfFormLaba2::MyForm::�����ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)//����� �� �����
{
	Application::Exit();
	return System::Void();
}

System::Void MatrixOfFormLaba2::MyForm::�����������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)//������ "� ���������"
{
	MessageBox::Show("������� ������� N*M,��� �������� ��� ������������� �������� ���� ������� �� ������������ ������� ����� ������!", "���������� �� ���������!");
	return System::Void();
}

System::Void MatrixOfFormLaba2::MyForm::numericUpDownN1_ValueChanged(System::Object^ sender, System::EventArgs^ e)//�����������, N � 1 �������
{
	return System::Void();
}

System::Void MatrixOfFormLaba2::MyForm::numericUpDownM2_ValueChanged(System::Object^ sender, System::EventArgs^ e)//�����������, M � 1 �������
{
	return System::Void();
}

System::Void MatrixOfFormLaba2::MyForm::MatrixArr_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)//���� �������
{
	//����������� ������� Arr
	N_A =Convert::ToInt32(numericUpDownN1->Value);
	M_A = Convert::ToInt32(numericUpDownM2->Value);
	//�������� �������
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

System::Void MatrixOfFormLaba2::MyForm::numericUpDownM4_ValueChanged(System::Object^ sender, System::EventArgs^ e)//�����������, M � 2 �������v
{
	return System::Void();
}

System::Void MatrixOfFormLaba2::MyForm::numericUpDownN3_ValueChanged(System::Object^ sender, System::EventArgs^ e)//�����������, N � 2 �������
{
	return System::Void();
}



void MatrixOfFormLaba2::MyForm::ShowA()
{
	//����� ������� Arr � �������
	for (int i = 0; i < N_A; i++) {
		for (int j = 0; j < M_A; j++) {
			//�������� ������� � ������� ����� ����
			MatrixArr->TopLeftHeaderCell->Value = "������� �";
			
			//����� ������� ��������
			MatrixArr->Columns[j]->HeaderCell->Value = Convert::ToString(j + 1);

			//����� ������� �����
			MatrixArr->Rows[i]->HeaderCell->Value= Convert::ToString(i + 1);

			MatrixArr->Rows[i]->Cells[j]->Value = A[i][j];
		}
	}
}
