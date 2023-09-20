#include <iostream>

#include <fstream>
#include <vector>
#include <string>
using namespace std;


bool ProverkaNaluch() {
	ofstream fout;//поток для записи
	ifstream fin;
	bool flag = false;
	fin.open("Analizator.txt", ofstream::app);
	if (!fin.is_open()) {
		cout << "Не открылся файл";
	}
	else {
		char ch;//для считывания с файла
		char ch1[256];
		int i_len_mass = 0;
		int count_len = 0;
		while (fin.get(ch)) {//записываем весь код в массив ch1
			ch1[i_len_mass] = ch;
			if (ch == '\n') {
				count_len++;
			}
			i_len_mass++;
		}

		for (int i = 0; i < i_len_mass; i++) {
			if (ch1[i] == '!') {
				cout << "В коде есть нужный элемент для проверки '!'\n";
				flag = true;
				break;
			}
		}
	}
	fin.close();
	return flag;


}

bool ProverkaPlaceLogOperBockRavno(char* FileAnalizator, int i_len_mass) {//надл сделать проверку на невозможное написания !!!=
	bool ProverkaBockRavno = false;
	for (int i = 0; i < i_len_mass; i++) {
		if ((FileAnalizator[i] == '!') && (FileAnalizator[i + 1] == '=')) {
			//случай с употреблением сочетания !=
			ProverkaBockRavno = true;

		}
	}
	if (!ProverkaBockRavno) {
		cout << "В программе нет конструкций с !=\n";
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
		cout << "В программе нет конструкций с !__name__\n";
	}
	
	return ProverkaNaluchofValue;
}



void ProverkaPlaceValiue(char* FileAnalizator, int i_len_mass) {//подробно разбираем конст !=
	bool Pr_bykva = false;
	bool Pr_value = false;
	for (int i = 0; i < i_len_mass; i++) {
		int TempI = 0;
		if (FileAnalizator[i] == '!' && FileAnalizator[i + 1] == '=') {
			if ((((FileAnalizator[i - 3] == 't' && FileAnalizator[i - 4] == 'n' && FileAnalizator[i - 5] == 'i') || (FileAnalizator[i - 8] == 'd' && FileAnalizator[i - 7] == 'o' && FileAnalizator[i - 6] == 'u' && FileAnalizator[i - 5] == 'b' && FileAnalizator[i - 4] == 'l' && FileAnalizator[i - 3] == 'e') || (FileAnalizator[i - 3] == 'g' && FileAnalizator[i - 4] == 'n' && FileAnalizator[i - 5] == 'o' && FileAnalizator[i - 6] == 'l') || (FileAnalizator[i - 3] == 'r' && FileAnalizator[i - 4] == 'a' && FileAnalizator[i - 5] == 'h' && FileAnalizator[i - 6] == 'c') || (FileAnalizator[i-8]=='s' && FileAnalizator[i - 7] == 't' && FileAnalizator[i - 6] == 'r' && FileAnalizator[i - 5] == 'i' && FileAnalizator[i - 4] == 'n' && FileAnalizator[i - 3] == 'g')))) {
				if ((FileAnalizator[i - 3] == 't' && FileAnalizator[i - 4] == 'n' && FileAnalizator[i - 5] == 'i')) {
					TempI = i-5;
					cout << "\nНевозможная кострукция,после типа невозможное употребление логического оператора c типом int !\n";
					while (FileAnalizator[TempI] != '\n') {
						cout << FileAnalizator[TempI];
						TempI++;
					}
					cout << '\n';
				}
				if ((FileAnalizator[i - 8] == 'd' && FileAnalizator[i - 7] == 'o' && FileAnalizator[i - 6] == 'u' && FileAnalizator[i - 5] == 'b' && FileAnalizator[i - 4] == 'l' && FileAnalizator[i - 3] == 'e')) {
					TempI = i - 8;
					cout << "\nНевозможная кострукция,после типа невозможное употребление логического оператора c типом double !\n";
					while (FileAnalizator[TempI] != '\n') {
						cout << FileAnalizator[TempI];
						TempI++;
					}
					cout << '\n';
				}
				if ((FileAnalizator[i - 3] == 'g' && FileAnalizator[i - 4] == 'n' && FileAnalizator[i - 5] == 'o' && FileAnalizator[i - 6] == 'l')) {
					TempI = i -6;
					cout << "\nНевозможная кострукция,после типа невозможное употребление логического оператора c типом long !\n";
					while (FileAnalizator[TempI] != '\n') {
						cout << FileAnalizator[TempI];
						TempI++;
					}
					cout << '\n';
				}
				if ((FileAnalizator[i - 8] == 's' && FileAnalizator[i - 7] == 't' && FileAnalizator[i - 6] == 'r' && FileAnalizator[i - 5] == 'i' && FileAnalizator[i - 4] == 'n' && FileAnalizator[i - 3] == 'g')) {
					TempI = i - 8;
					cout << "\nНевозможная кострукция,после типа невозможное употребление логического оператора c типом string !\n";
					while (FileAnalizator[TempI] != '\n') {
						cout << FileAnalizator[TempI];
						TempI++;
					}
					cout << '\n';
				}
				if ((FileAnalizator[i - 3] == 'r' && FileAnalizator[i - 4] == 'a' && FileAnalizator[i - 5] == 'h' && FileAnalizator[i - 6] == 'c')) {
					TempI = i - 6;
					cout << "\nНевозможная кострукция,после типа невозможное употребление логического оператора c типом char !\n";
					while (FileAnalizator[TempI] != '\n') {
						cout << FileAnalizator[TempI];
						TempI++;
					}
					cout << '\n';
				}
				if ((FileAnalizator[i - 3] == 'l' && FileAnalizator[i - 4] == 'o' && FileAnalizator[i - 5] == 'o' && FileAnalizator[i - 6] == 'b')) {
					TempI = i - 5;
					cout << "\nНевозможная кострукция,после типа невозможное употребление логического оператора c типом bool !\n";
					while (FileAnalizator[TempI] != '\n') {
						cout << FileAnalizator[TempI];
						TempI++;
					}
					cout << '\n';
				}
				//все работает,пока в int,char и других в переменной 1 символ

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
						cout << "\n1.Невозможная конструкция с оператором !=\n";
						TempI = i - 1;
						while (FileAnalizator[TempI] != '\n') {
							cout << FileAnalizator[TempI];
							TempI++;
						}
						cout << '\n';
					}
				}
				else {
					cout << "\n2.Невозможная конструкция с оператором !=  (Нужно с каким-то элементом сравнивать)\n";
					TempI = i - 1;
					while (FileAnalizator[TempI] != '\n') {
						cout << FileAnalizator[TempI];
						TempI++;
					}
					cout << '\n';
				}
			}
		}
	}//теперь идет полная проверка на конструкцию !=    ->((__name__!=name))//без типов не будет в принципе работать 
}

//проверка на !__name__
void ProverkaPlaceValue(char* FileAnalizator, int i_len_mass) {
	bool Pr_Place = false;
	int TempI = 0;
	bool flag = false;
	for (int i = 0; i < i_len_mass; i++) {
		if (FileAnalizator[i] == '!') {
			if (((((FileAnalizator[i - 1] >= 'A' && FileAnalizator[i - 1] <= 'Z')) || ((FileAnalizator[i - 1] >= 'a' && FileAnalizator[i - 1] <= 'z')) && FileAnalizator[i+1]!='='))) {
				cout << "\nНевозможная конструкция\n";
				cout << "__name__!";
			}
			else if (FileAnalizator[i + 1] == ' ') {
				cout << "Невозможное употребление логического опереатора !\n";
				cout<<"!";
			}
			if ((FileAnalizator[i - 2] == 't' && FileAnalizator[i - 3] == 'n' && FileAnalizator[i - 4] == 'i') || (FileAnalizator[i - 7] == 'd' && FileAnalizator[i - 6] == 'o' && FileAnalizator[i - 5] == 'u' && FileAnalizator[i - 4] == 'b' && FileAnalizator[i - 3] == 'l' && FileAnalizator[i - 2] == 'e') || (FileAnalizator[i - 2] == 'g' && FileAnalizator[i - 3] == 'n' && FileAnalizator[i - 4] == 'o' && FileAnalizator[i - 5] == 'l') || (FileAnalizator[i - 2] == 'r' && FileAnalizator[i - 3] == 'a' && FileAnalizator[i - 4] == 'h' && FileAnalizator[i - 5] == 'c') || (FileAnalizator[i - 7] == 's' && FileAnalizator[i - 6] == 't' && FileAnalizator[i - 5] == 'r' && FileAnalizator[i - 4] == 'i' && FileAnalizator[i - 3] == 'n' && FileAnalizator[i - 2] == 'g') || (FileAnalizator[i - 2] == 'l' && FileAnalizator[i - 3] == 'o' && FileAnalizator[i - 4] == 'o' && FileAnalizator[i - 5] == 'b')) {
				if ((FileAnalizator[i - 2] == 't' && FileAnalizator[i - 3] == 'n' && FileAnalizator[i - 4] == 'i')) {
					TempI = i - 4;
					cout << "\n1.Невозможная кострукция,после типа int невозможное употребление логического оператора !\n";
					while (FileAnalizator[TempI] != '\n') {
						cout << FileAnalizator[TempI];
						TempI++;
					}
					cout << '\n';
				}
				if ((FileAnalizator[i - 7] == 'd' && FileAnalizator[i - 6] == 'o' && FileAnalizator[i - 5] == 'u' && FileAnalizator[i - 4] == 'b' && FileAnalizator[i - 3] == 'l' && FileAnalizator[i - 2] == 'e')) {
					TempI = i - 7;
					cout << "\nНевозможная кострукция,после типа невозможное употребление логического оператора c типом double !\n";
					while (FileAnalizator[TempI] != '\n') {
						cout << FileAnalizator[TempI];
						TempI++;
					}
					cout << '\n';
				}
				if ((FileAnalizator[i - 2] == 'g' && FileAnalizator[i - 3] == 'n' && FileAnalizator[i - 4] == 'o' && FileAnalizator[i - 5] == 'l')) {
					TempI = i - 6;
					cout << "\nНевозможная кострукция,после типа невозможное употребление логического оператора c типом long !\n";
					while (FileAnalizator[TempI] != '\n') {
						cout << FileAnalizator[TempI];
						TempI++;
					}
					cout << '\n';
				}
				if ((FileAnalizator[i - 7] == 's' && FileAnalizator[i - 6] == 't' && FileAnalizator[i - 5] == 'r' && FileAnalizator[i - 4] == 'i' && FileAnalizator[i - 3] == 'n' && FileAnalizator[i - 2] == 'g')) {
					TempI = i - 8;
					cout << "\nНевозможная кострукция,после типа невозможное употребление логического оператора c типом string !\n";
					while (FileAnalizator[TempI] != '\n') {
						cout << FileAnalizator[TempI];
						TempI++;
					}
					cout << '\n';
				}
				if ((FileAnalizator[i - 2] == 'r' && FileAnalizator[i - 3] == 'a' && FileAnalizator[i - 4] == 'h' && FileAnalizator[i - 5] == 'c')) {
					TempI = i - 6;
					cout << "\nНевозможная кострукция,после типа невозможное употребление логического оператора c типом char !\n";
					while (FileAnalizator[TempI] != '\n') {
						cout << FileAnalizator[TempI];
						TempI++;
					}
					cout << '\n';
				}
				if ((FileAnalizator[i - 2] == 'l' && FileAnalizator[i - 3] == 'o' && FileAnalizator[i - 4] == 'o' && FileAnalizator[i - 5] == 'b')) {
					TempI = i - 5;
					cout << "\nНевозможная кострукция,после типа невозможное употребление логического оператора c типом bool !\n";
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

void StringPr(char* FileAnalizator, int i_len_mass) {//ВОТ ТУТ ПРОВЕРКА КИРИЛЛ 
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
		cout << "Невозможно сравнивать с данным типом справа\n";
	}
	if (PrLevo) {
		cout << "Невозможно сравнивать с данным типом слево\n";
	}
}


int main() {
	setlocale(LC_ALL, "rus");
	bool flag = false;
	flag = ProverkaNaluch();
	if (flag) {
		ifstream fin;
		fin.open("Analizator.txt", ofstream::app);
		char ch;//для считывания с файла
		char FileAnalizator[256];
		int i_len_mass = 0;
		int count_len = 0;
		while (fin.get(ch)) {//записываем весь код в массив ch1
			FileAnalizator[i_len_mass] = ch;
			if (ch == '\n') {
				count_len++;//количество строк
			}
			i_len_mass++;//количество символов
		}
		bool ProverkaBockRavno;
		bool ProverkaNaluchofValue;

		bool PrString;
		//Сначала проверим на корректность написания !
		ProverkaBockRavno = ProverkaPlaceLogOperBockRavno(FileAnalizator, i_len_mass);
		ProverkaNaluchofValue = ProverkaPlace(FileAnalizator, i_len_mass);

		//Если оба будут false,то есть 3 возможных исхода 
		//Неверное местоположение !,либо '!' стоит во время объявления переменной

		if (ProverkaBockRavno) {
			ProverkaPlaceValiue(FileAnalizator, i_len_mass);
		}
		if (ProverkaNaluchofValue) {
			//тут будет проверка на правильное местопопложение !
			ProverkaPlaceValue(FileAnalizator,i_len_mass);
		}
		ProverkaPlaceValue(FileAnalizator, i_len_mass);
		PrString = CountString(FileAnalizator, i_len_mass);
		if (CountString(FileAnalizator, i_len_mass)) {
			StringPr(FileAnalizator, i_len_mass);
		}

	}
	else {
		cout << "Нет в коде нужного логического оператора.";
	}

}