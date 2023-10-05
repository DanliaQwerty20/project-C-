#include <iostream>

#include <fstream>
#include <vector>
#include <string>
using namespace std;


bool ProverkaNaluch() {
	ofstream fout;//����� ��� ������
	ifstream fin;
	bool flag = false;
	fin.open("Analizator.txt", ofstream::app);
	if (!fin.is_open()) {
		cout << "�� �������� ����";
	}
	else {
		char ch;//��� ���������� � �����
		char ch1[256];
		int i_len_mass = 0;
		int count_len = 0;
		while (fin.get(ch)) {//���������� ���� ��� � ������ ch1
			ch1[i_len_mass] = ch;
			if (ch == '\n') {
				count_len++;
			}
			i_len_mass++;
		}

		for (int i = 0; i < i_len_mass; i++) {
			if (ch1[i] == '!') {
				cout << "� ���� ���� ������ ������� ��� �������� '!'\n";
				flag = true;
				break;
			}
		}
	}
	fin.close();
	return flag;


}

bool ProverkaPlaceLogOperBockRavno(char* FileAnalizator, int i_len_mass) {//���� ������� �������� �� ����������� ��������� !!!=
	bool ProverkaBockRavno = false;
	for (int i = 0; i < i_len_mass; i++) {
		if ((FileAnalizator[i] == '!') && (FileAnalizator[i + 1] == '=')) {
			//������ � ������������� ��������� !=
			ProverkaBockRavno = true;

		}
	}
	if (!ProverkaBockRavno) {
		cout << "� ��������� ��� ����������� � !=\n";
	}
	return ProverkaBockRavno;
}
bool ProverkaPlace(char* FileAnalizator, int i_len_mass) {
	bool ProverkaNaluchofValue = false;
	for (int i = 0; i < i_len_mass; i++) {
		if (((FileAnalizator[i] == '!') || (FileAnalizator[i - 1] == '!' && FileAnalizator[i] == '!')) && (((FileAnalizator[i + 1] >= 'A' && FileAnalizator[i + 1] <= 'Z')) || ((FileAnalizator[i + 1] >= 'a' && FileAnalizator[i + 1] <= 'z')))) {
			ProverkaNaluchofValue = true;
		}
	}
	if (!ProverkaNaluchofValue) {
		cout << "� ��������� ��� ����������� � !__name__\n";
	}
	
	return ProverkaNaluchofValue;
}



void ProverkaPlaceValiue(char* FileAnalizator, int i_len_mass) {//�������� ��������� ����� !=
	bool Pr_bykva = false;
	bool Pr_value = false;
	for (int i = 0; i < i_len_mass; i++) {
		int TempI = 0;
		if (FileAnalizator[i] == '!' && FileAnalizator[i + 1] == '=') {
			if ((((FileAnalizator[i - 3] == 't' && FileAnalizator[i - 4] == 'n' && FileAnalizator[i - 5] == 'i') || (FileAnalizator[i - 8] == 'd' && FileAnalizator[i - 7] == 'o' && FileAnalizator[i - 6] == 'u' && FileAnalizator[i - 5] == 'b' && FileAnalizator[i - 4] == 'l' && FileAnalizator[i - 3] == 'e') || (FileAnalizator[i - 3] == 'g' && FileAnalizator[i - 4] == 'n' && FileAnalizator[i - 5] == 'o' && FileAnalizator[i - 6] == 'l') || (FileAnalizator[i - 3] == 'r' && FileAnalizator[i - 4] == 'a' && FileAnalizator[i - 5] == 'h' && FileAnalizator[i - 6] == 'c') || (FileAnalizator[i-8]=='s' && FileAnalizator[i - 7] == 't' && FileAnalizator[i - 6] == 'r' && FileAnalizator[i - 5] == 'i' && FileAnalizator[i - 4] == 'n' && FileAnalizator[i - 3] == 'g')))) {
				if ((FileAnalizator[i - 3] == 't' && FileAnalizator[i - 4] == 'n' && FileAnalizator[i - 5] == 'i')) {
					TempI = i-5;
					cout << "\n����������� ����������,����� ���� ����������� ������������ ����������� ��������� c ����� int !\n";
					while (FileAnalizator[TempI] != '\n') {
						cout << FileAnalizator[TempI];
						TempI++;
					}
					cout << '\n';
				}
				if ((FileAnalizator[i - 8] == 'd' && FileAnalizator[i - 7] == 'o' && FileAnalizator[i - 6] == 'u' && FileAnalizator[i - 5] == 'b' && FileAnalizator[i - 4] == 'l' && FileAnalizator[i - 3] == 'e')) {
					TempI = i - 8;
					cout << "\n����������� ����������,����� ���� ����������� ������������ ����������� ��������� c ����� double !\n";
					while (FileAnalizator[TempI] != '\n') {
						cout << FileAnalizator[TempI];
						TempI++;
					}
					cout << '\n';
				}
				if ((FileAnalizator[i - 3] == 'g' && FileAnalizator[i - 4] == 'n' && FileAnalizator[i - 5] == 'o' && FileAnalizator[i - 6] == 'l')) {
					TempI = i -6;
					cout << "\n����������� ����������,����� ���� ����������� ������������ ����������� ��������� c ����� long !\n";
					while (FileAnalizator[TempI] != '\n') {
						cout << FileAnalizator[TempI];
						TempI++;
					}
					cout << '\n';
				}
				if ((FileAnalizator[i - 8] == 's' && FileAnalizator[i - 7] == 't' && FileAnalizator[i - 6] == 'r' && FileAnalizator[i - 5] == 'i' && FileAnalizator[i - 4] == 'n' && FileAnalizator[i - 3] == 'g')) {
					TempI = i - 8;
					cout << "\n����������� ����������,����� ���� ����������� ������������ ����������� ��������� c ����� string !\n";
					while (FileAnalizator[TempI] != '\n') {
						cout << FileAnalizator[TempI];
						TempI++;
					}
					cout << '\n';
				}
				if ((FileAnalizator[i - 3] == 'r' && FileAnalizator[i - 4] == 'a' && FileAnalizator[i - 5] == 'h' && FileAnalizator[i - 6] == 'c')) {
					TempI = i - 6;
					cout << "\n����������� ����������,����� ���� ����������� ������������ ����������� ��������� c ����� char !\n";
					while (FileAnalizator[TempI] != '\n') {
						cout << FileAnalizator[TempI];
						TempI++;
					}
					cout << '\n';
				}
				if ((FileAnalizator[i - 3] == 'l' && FileAnalizator[i - 4] == 'o' && FileAnalizator[i - 5] == 'o' && FileAnalizator[i - 6] == 'b')) {
					TempI = i - 5;
					cout << "\n����������� ����������,����� ���� ����������� ������������ ����������� ��������� c ����� bool !\n";
					while (FileAnalizator[TempI] != '\n') {
						cout << FileAnalizator[TempI];
						TempI++;
					}
					cout << '\n';
				}
				//��� ��������,���� � int,char � ������ � ���������� 1 ������

			}
			else {
				int TempI = 0;
				if ((FileAnalizator[i - 1] >= 'A' && FileAnalizator[i - 1] <= 'Z') || (FileAnalizator[i - 1] >= 'a' && FileAnalizator[i - 1] <= 'z')) {
					if ((FileAnalizator[i + 2] >= 'A' && FileAnalizator[i + 2] <= 'Z') || (FileAnalizator[i + 2] >= 'a' && FileAnalizator[i + 2] <= 'z')) {
						Pr_bykva = true;
					}
					else if ((FileAnalizator[i + 2] >= '1' && FileAnalizator[i + 2] <= '9')) {
						Pr_value = true;
					}
					else {
						cout << "\n1.����������� ����������� � ���������� !=\n";
						TempI = i - 1;
						while (FileAnalizator[TempI] != '\n') {
							cout << FileAnalizator[TempI];
							TempI++;
						}
						cout << '\n';
					}
				}
				else {
					cout << "\n2.����������� ����������� � ���������� !=  (����� � �����-�� ��������� ����������)\n";
					TempI = i - 1;
					while (FileAnalizator[TempI] != '\n') {
						cout << FileAnalizator[TempI];
						TempI++;
					}
					cout << '\n';
				}
			}
		}
	}//������ ���� ������ �������� �� ����������� !=    ->((__name__!=name))//��� ����� �� ����� � �������� �������� 
}

//�������� �� !__name__
void ProverkaPlaceValue(char* FileAnalizator, int i_len_mass) {
	bool Pr_Place = false;
	int TempI = 0;
	bool flag = false;
	for (int i = 0; i < i_len_mass; i++) {
		if (FileAnalizator[i] == '!') {
			if (((((FileAnalizator[i - 1] >= 'A' && FileAnalizator[i - 1] <= 'Z')) || ((FileAnalizator[i - 1] >= 'a' && FileAnalizator[i - 1] <= 'z')) && FileAnalizator[i+1]!='='))) {
				cout << "\n����������� �����������\n";
				cout << "__name__!";
			}
			else if (FileAnalizator[i + 1] == ' ') {
				cout << "����������� ������������ ����������� ���������� !\n";
				cout<<"!";
			}
			if ((FileAnalizator[i - 2] == 't' && FileAnalizator[i - 3] == 'n' && FileAnalizator[i - 4] == 'i') || (FileAnalizator[i - 7] == 'd' && FileAnalizator[i - 6] == 'o' && FileAnalizator[i - 5] == 'u' && FileAnalizator[i - 4] == 'b' && FileAnalizator[i - 3] == 'l' && FileAnalizator[i - 2] == 'e') || (FileAnalizator[i - 2] == 'g' && FileAnalizator[i - 3] == 'n' && FileAnalizator[i - 4] == 'o' && FileAnalizator[i - 5] == 'l') || (FileAnalizator[i - 2] == 'r' && FileAnalizator[i - 3] == 'a' && FileAnalizator[i - 4] == 'h' && FileAnalizator[i - 5] == 'c') || (FileAnalizator[i - 7] == 's' && FileAnalizator[i - 6] == 't' && FileAnalizator[i - 5] == 'r' && FileAnalizator[i - 4] == 'i' && FileAnalizator[i - 3] == 'n' && FileAnalizator[i - 2] == 'g') || (FileAnalizator[i - 2] == 'l' && FileAnalizator[i - 3] == 'o' && FileAnalizator[i - 4] == 'o' && FileAnalizator[i - 5] == 'b')) {
				if ((FileAnalizator[i - 2] == 't' && FileAnalizator[i - 3] == 'n' && FileAnalizator[i - 4] == 'i')) {
					TempI = i - 4;
					cout << "\n1.����������� ����������,����� ���� int ����������� ������������ ����������� ��������� !\n";
					while (FileAnalizator[TempI] != '\n') {
						cout << FileAnalizator[TempI];
						TempI++;
					}
					cout << '\n';
				}
				if ((FileAnalizator[i - 7] == 'd' && FileAnalizator[i - 6] == 'o' && FileAnalizator[i - 5] == 'u' && FileAnalizator[i - 4] == 'b' && FileAnalizator[i - 3] == 'l' && FileAnalizator[i - 2] == 'e')) {
					TempI = i - 7;
					cout << "\n����������� ����������,����� ���� ����������� ������������ ����������� ��������� c ����� double !\n";
					while (FileAnalizator[TempI] != '\n') {
						cout << FileAnalizator[TempI];
						TempI++;
					}
					cout << '\n';
				}
				if ((FileAnalizator[i - 2] == 'g' && FileAnalizator[i - 3] == 'n' && FileAnalizator[i - 4] == 'o' && FileAnalizator[i - 5] == 'l')) {
					TempI = i - 6;
					cout << "\n����������� ����������,����� ���� ����������� ������������ ����������� ��������� c ����� long !\n";
					while (FileAnalizator[TempI] != '\n') {
						cout << FileAnalizator[TempI];
						TempI++;
					}
					cout << '\n';
				}
				if ((FileAnalizator[i - 7] == 's' && FileAnalizator[i - 6] == 't' && FileAnalizator[i - 5] == 'r' && FileAnalizator[i - 4] == 'i' && FileAnalizator[i - 3] == 'n' && FileAnalizator[i - 2] == 'g')) {
					TempI = i - 8;
					cout << "\n����������� ����������,����� ���� ����������� ������������ ����������� ��������� c ����� string !\n";
					while (FileAnalizator[TempI] != '\n') {
						cout << FileAnalizator[TempI];
						TempI++;
					}
					cout << '\n';
				}
				if ((FileAnalizator[i - 2] == 'r' && FileAnalizator[i - 3] == 'a' && FileAnalizator[i - 4] == 'h' && FileAnalizator[i - 5] == 'c')) {
					TempI = i - 6;
					cout << "\n����������� ����������,����� ���� ����������� ������������ ����������� ��������� c ����� char !\n";
					while (FileAnalizator[TempI] != '\n') {
						cout << FileAnalizator[TempI];
						TempI++;
					}
					cout << '\n';
				}
				if ((FileAnalizator[i - 2] == 'l' && FileAnalizator[i - 3] == 'o' && FileAnalizator[i - 4] == 'o' && FileAnalizator[i - 5] == 'b')) {
					TempI = i - 5;
					cout << "\n����������� ����������,����� ���� ����������� ������������ ����������� ��������� c ����� bool !\n";
					while (FileAnalizator[TempI] != '\n') {
						cout << FileAnalizator[TempI];
						TempI++;
					}
					cout << '\n';
				}
			}

		}
	}
}

bool CountString(char* FileAnalizator, int i_len_mass) {
	bool StringName = false;
	for (int i = 0; i < i_len_mass; i++) {
		if (FileAnalizator[i - 7] == 's' && FileAnalizator[i - 6] == 't' && FileAnalizator[i - 5] == 'r' && FileAnalizator[i - 4] == 'i' && FileAnalizator[i - 3] == 'n' && FileAnalizator[i - 2] == 'g') {
			StringName = true;
		}
		
	}
	return StringName;
}

void StringPr(char* FileAnalizator, int i_len_mass) {//��� ��� �������� ������ 
	string StringName;
	int TempI1 = 0;
	int countPr111 = 0;
	for (int i = 0; i < i_len_mass; i++) {
		if (FileAnalizator[i - 7] == 's' && FileAnalizator[i - 6] == 't' && FileAnalizator[i - 5] == 'r' && FileAnalizator[i - 4] == 'i' && FileAnalizator[i - 3] == 'n' && FileAnalizator[i - 2] == 'g' && FileAnalizator[i] != '!' && FileAnalizator[i + 1] != '!') {
			TempI1 = i;
			if (FileAnalizator[i - 1] == ' ') {

				while (FileAnalizator[TempI1] != '=' && FileAnalizator[TempI1] != ';') {
					StringName += FileAnalizator[TempI1];
					TempI1++;
				}
				StringName += ' ';
			}
		}
		if (FileAnalizator[i] == '!' && FileAnalizator[i + 1] == '=') {
			countPr111++;
		}
	}
	int countPr = 0;
	bool PrCprava = false;
	bool PrLevo= false;
	bool flag = true;
	int TempI = 0;
	for (int i = 0; i < i_len_mass; i++) {
 		if (FileAnalizator[i] == '!' && FileAnalizator[i + 1] == '=') {
			for (int i1 = 0; i1 < StringName.size(); i1++) {
				for (int j1 = 0; j1 < StringName.size(); j1++) {
					if ((FileAnalizator[i - 1] == StringName[i1] && FileAnalizator[i + 2] != StringName[j1]) || (FileAnalizator[i+2]==StringName[i1])) {
						if (FileAnalizator[i + 2] != StringName[j1]) {
							PrCprava = true;
							TempI = i - 2;
							while (FileAnalizator[TempI] != '\n' && flag) {
								cout << FileAnalizator[TempI];
								TempI++;
							}cout << '\n';
							flag = false;
						}
						if (FileAnalizator[i - 1] != StringName[j1]) {
							PrLevo= true;
							TempI = i - 1;
							while (FileAnalizator[TempI] != '\n' && flag) {
								cout << FileAnalizator[TempI];
								TempI++;
							}cout << '\n';
							flag = false;
						}
					}
				}
			}
		}
	}
	if (PrCprava) {
		cout << "���������� ���������� � ������ ����� ������\n";
	}
	if (PrLevo) {
		cout << "���������� ���������� � ������ ����� �����\n";
	}
}


int main() {
	setlocale(LC_ALL, "rus");
	bool flag = false;
	flag = ProverkaNaluch();
	if (flag) {
		ifstream fin;
		fin.open("Analizator.txt", ofstream::app);
		char ch;//��� ���������� � �����
		char FileAnalizator[256];
		int i_len_mass = 0;
		int count_len = 0;
		while (fin.get(ch)) {//���������� ���� ��� � ������ ch1
			FileAnalizator[i_len_mass] = ch;
			if (ch == '\n') {
				count_len++;//���������� �����
			}
			i_len_mass++;//���������� ��������
		}
		bool ProverkaBockRavno;
		bool ProverkaNaluchofValue;

		bool PrString;
		//������� �������� �� ������������ ��������� !
		ProverkaBockRavno = ProverkaPlaceLogOperBockRavno(FileAnalizator, i_len_mass);
		ProverkaNaluchofValue = ProverkaPlace(FileAnalizator, i_len_mass);

		//���� ��� ����� false,�� ���� 3 ��������� ������ 
		//�������� �������������� !,���� '!' ����� �� ����� ���������� ����������

		if (ProverkaBockRavno) {
			ProverkaPlaceValiue(FileAnalizator, i_len_mass);
		}
		if (ProverkaNaluchofValue) {
			//��� ����� �������� �� ���������� ��������������� !
			ProverkaPlaceValue(FileAnalizator,i_len_mass);
		}
		ProverkaPlaceValue(FileAnalizator, i_len_mass);
		PrString = CountString(FileAnalizator, i_len_mass);
		if (CountString(FileAnalizator, i_len_mass)) {
			StringPr(FileAnalizator, i_len_mass);
		}

	}
	else {
		cout << "��� � ���� ������� ����������� ���������.";
	}

}