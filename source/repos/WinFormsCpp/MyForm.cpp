

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


System::Void FastnewForm3Laba2Programming::MyForm::�����ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)//������ �����
{
	Application::Exit();
	return System::Void();
}

System::Void FastnewForm3Laba2Programming::MyForm::�����������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)//������ �� ���������
{
	MessageBox::Show("...", "���������� �� ���������");
	return System::Void();
}

System::Void FastnewForm3Laba2Programming::MyForm::dataGridView1MatrixA_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)//�������� ������� �
{
	return System::Void();
}

System::Void FastnewForm3Laba2Programming::MyForm::ClearMatrixA_Click(System::Object^ sender, System::EventArgs^ e)//������ �������� ������� �
{
	N_A = Convert::ToInt32(numericUpDown1N_A->Value);
	M_A = Convert::ToInt32(numericUpDown2M_A->Value);

	//������� �������
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


	//�������
	dataGridView1MatrixA->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);//������
	dataGridView1MatrixA->AutoResizeColumns();//������
	return System::Void();
}

System::Void FastnewForm3Laba2Programming::MyForm::CreateMatrix1_Click(System::Object^ sender, System::EventArgs^ e)//������ ������� ������� �
{
	//����������� �������
	N_A =Convert::ToInt32(numericUpDown1N_A->Value);
	M_A = Convert::ToInt32(numericUpDown2M_A->Value);

	//������� �������
	A = new float* [N_A];
	for (int i = 0; i < N_A; i++) {
		A[i] = new float[M_A];
	}

	//������� �������
	for (int i = 0; i < N_A; i++) {
		for (int j = 0; j < M_A; j++) {
			A[i][j] = 0;
		}
	}

	//������� �������
	dataGridView1MatrixA->RowCount = N_A;
	dataGridView1MatrixA->ColumnCount = M_A;

	//�����
	ShowA();


	//�������
	dataGridView1MatrixA->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);//������
	dataGridView1MatrixA->AutoResizeColumns();//������
	
	return System::Void();

}

System::Void FastnewForm3Laba2Programming::MyForm::GenerateMatrixA_Click(System::Object^ sender, System::EventArgs^ e)//��������� ������� �
{
	if (N_A == 0 || M_A == 0) {
		MessageBox::Show("������� �����������!", "������!");
		return;
	}
	std::nullptr_t;
	std::srand(time(NULL));
	//��������� �������
	for (int i = 0; i < N_A; i++) {
		for (int j = 0; j < M_A; j++) {
			A[i][j] = rand() % 10+1;
		}
	}
	//�����
	ShowA();

	//�������
	dataGridView1MatrixA->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);//������
	dataGridView1MatrixA->AutoResizeColumns();//������

	return System::Void();
}

System::Void FastnewForm3Laba2Programming::MyForm::numericUpDown1N_A_ValueChanged(System::Object^ sender, System::EventArgs^ e)//������� ������� N
{
	return System::Void();
}

System::Void FastnewForm3Laba2Programming::MyForm::numericUpDown2M_A_ValueChanged(System::Object^ sender, System::EventArgs^ e)//������ ������� M
{
	return System::Void();
}

System::Void FastnewForm3Laba2Programming::MyForm::ResultOfMatrixAOfMatrixB_Click(System::Object^ sender, System::EventArgs^ e)//������ ��������� =>
{
	if (N_A == 0 || M_A == 0) {
		MessageBox::Show("������� �����������!", "������!");
		return;
	}
	//������� �������
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

	//�������
	dataGridView2MatrixB->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);//������
	dataGridView2MatrixB->AutoResizeColumns();//������
	return System::Void();
}

System::Void FastnewForm3Laba2Programming::MyForm::OutMaxMatrixB_Click(System::Object^ sender, System::EventArgs^ e)//����� ��������� 
{
	
	MessageBox::Show("","");
	return System::Void();
}

void FastnewForm3Laba2Programming::MyForm::ShowA()
{
	//����� ������� � � �������
	for (int i = 0; i < N_A; i++) {
		for (int j = 0; j < M_A; j++) {
			//�������� ������� � ������� ����� ����
			dataGridView1MatrixA->TopLeftHeaderCell->Value = "������� �";
			
			//����� ������� ��������
			dataGridView1MatrixA->Columns[j]->HeaderCell->Value = Convert::ToString(j + 1);
			
			//����� ������� �����
			dataGridView1MatrixA->Rows[i]->HeaderCell->Value = Convert::ToString(i + 1);

			//����� �������� �������
			dataGridView1MatrixA->Rows[i]->Cells[j]->Value = A[i][j];

		}
	}
}

void FastnewForm3Laba2Programming::MyForm::ShowResult(float** C)
{
	//����� ������� C � �������
	for (int i = 0; i < N_A; i++) {
		for (int j = 0; j < M_A; j++) {
			//�������� ������� � ������� ����� ����
			dataGridView2MatrixB->TopLeftHeaderCell->Value = "������� C";
			
			//����� ������� �����
			dataGridView2MatrixB->Rows[i]->HeaderCell->Value = Convert::ToString(i);
			//����� ������� ��������
			dataGridView2MatrixB->Columns[j]->HeaderCell->Value = Convert::ToString(j);



			//����� �������� �������
			dataGridView2MatrixB->Rows[i]->Cells[j]->Value = C[i][j];

		}
	}
}
