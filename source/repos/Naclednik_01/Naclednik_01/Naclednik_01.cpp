#include <iostream>
#include <cctype> 
#include <math.h>
#include <cstdlib>
#include <string>

using namespace std;

class Point_plane {
protected:
    double x1;
    double y1;

    double distance_plane_name;
public:
    //точка в плоскости
    Point_plane() {
    }
    Point_plane(double copy_x1, double copy_y1) {
        this->x1 = copy_x1;
        this->y1 = copy_y1;
    }
    void distance_plane() {
        distance_plane_name=sqrt(pow(x1, 2) + pow(y1, 2));
    }

    double getdistance_plane() {
        distance_plane();
        return distance_plane_name;
        
    }
};


class Point_space : public Point_plane {//первый владеет всеми функциями второго
private:
    double z1;
    double distance_space_name;
    double distance;//получение расстояния в плоскости
public:
    Point_space() {
    }
    Point_space(double copy_x1, double copy_y1, double copy_z1)
    {
        this->x1 = copy_x1;
        this->y1 = copy_y1;
        this->z1 = copy_z1;
    }
    void dis() {
        distance = getdistance_plane();
    }
    double getdistance_space() {
        return distance_space_name = sqrt(distance + pow(z1, 2));
    }
    
};

//исправить наследование,чтобы pow(x1, 2) + pow(y1, 2) на distance_plane()
bool isNumeric(string const& str) {//проверка
    for (int i = 0; i < str.length(); i++) {
        if (((int(str[i]) < 48 || int(str[i]) > 58) && int(str[i]) != 46) && (int(str[i]) != 45)) {   //проверка на цифры
            return false;
        }
    }
    return true;
}
    
int main() {
    setlocale(LC_ALL, "rus");
    string x1, y1, z1;
    bool proverka = true;
    while (proverka) {
        cout << "Введите x\n";
        getline(cin, x1);
        cout << "Введите y\n";
        getline(cin, y1);
        cout << "Введите z\n";
        getline(cin, z1);
        if (!isNumeric(x1) || !isNumeric(y1) || !isNumeric(z1)) {
            cout << "Введенные данные некорректны, повторите ввод\n";
        }
        else {
            proverka = false;
        }
        
    }
    //указатель на string,перевод в double


    double x_1 = atoi(x1.c_str());
    double y_1 = atoi(y1.c_str());
    double z_1 = atoi(z1.c_str());
    double plane, space;
    Point_plane point_spane(x_1, y_1);
    Point_space point_space1(x_1, y_1, z_1);
    point_spane.distance_plane();
    point_space1.dis();
    cout << "Расстояние на плоскости:\n";
    cout << point_space1.getdistance_plane() << endl;
    cout << "Расстояние в пространстве:\n";
    cout << point_space1.getdistance_space();
    return 0;
}
//Создать класс, описывающий точку на плоскости.
//Определить расстояние от точки до начала координат.Создать класс - наследник, описывающий точку в пространстве.Определить расстояние от точки до начала координат.

