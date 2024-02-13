#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <iomanip> 
#include <conio.h>
#include <sstream>
#include <Windows.h>
using namespace std;

class point2 {
private:
	double* px;
	double* py;
public:
	point2() :px(new double), py(new double) {}
	/*point2(double x, double y) { *px = x, *py = y; }*/
	point2(point2& z) { if (px != NULL)delete[] px; if (py != NULL)delete[] py; px = new double; *px = *z.px; py = new double; *py = *z.py; }
	point2& operator=(point2& z) { px = z.px; py = z.py; return *this; }
	friend istream& operator>>(istream& in, point2& z);
	friend ostream& operator<<(ostream& out, point2& z);
	double getx()
	{
		return *px;
	}
	double gety()
	{
		return *py;
	}
	point2& operator-() { *px = -*px; *py = -*py; return *this; }
	void output();
	double rast();
	double dist();
};

istream& operator>>(istream& in, point2& z)
{
	cout << "Введите x: ";
	in >> *z.px;

	cout << "Введите y: ";
	in >> *z.py;
	return in;
}
ostream& operator<<(ostream& out, point2& z)
{
	out << "x= " << *z.px << " y= " << *z.py;
	return out;
}
void point2::output()
{
	cout << "x= " << *px << " y= " << *py;
}
double point2::rast() {
	return (sqrt(pow(*px, 2) + pow(*py, 2)));
}
double point2::dist()
{

	double x, y;
	cout << "Введите x: ";
	cin >> x;
	cout << "Введите y: ";
	cin >> y;
	x = (*px) - x;
	y = (*py) - y;
	return (sqrt(pow(x, 2) + pow(y, 2)));
}

class mpoint2
{
private:
	point2 pp;
	double* pm;
public:
	mpoint2() : pm(new double) {}
	mpoint2(mpoint2& z) : pp(z.pp) { if (pm != NULL)delete[] pm; pm = new double; *pm = *z.pm; }
	mpoint2& operator=(mpoint2& z) { pp = z.pp; if (pm != NULL)delete pm; pm = new double; *pm = *z.pm; return *this; }
	mpoint2& operator-();
	friend istream& operator>>(istream& in, mpoint2& z);
	friend ostream& operator<<(ostream& out, mpoint2& z);
	double dist();
	void output();
	double rast();

	double getx()
	{
		return pp.getx();
	}
	double gety()
	{
		return pp.gety();
	}
	double getm()
	{
		return *pm;
	}
};

mpoint2& mpoint2:: operator-() {
	pp.operator-();
	*pm = *pm;
	return *this;
}
istream& operator >> (istream& in, mpoint2& z) {
	in >> z.pp;
	cout << "Введите массу: ";
	in >> *z.pm;
	return in;
}
ostream& operator<<(ostream& out, mpoint2& z) {
	out << z.pp;
	out << " масса точки = " << *z.pm;
	return out;
}
void mpoint2::output() {
	pp.output();
	cout << " " << "масса= " << *pm;
}
double mpoint2::rast() {
	return pp.rast();
}
double mpoint2::dist() {
	return pp.dist();
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "");
	mpoint2 aa;
	point2 a;
	int j;
	while (1)
	{
		system("cls");
		//Защита от неправильного ввода пункта меню
		if (cin.fail())
		{
			string l;
			cin.clear();
			cin >> l;
			cout << "Это не пункт меню\n"; system("pause");
			continue;//K следующей итерации
		}
		cout << "            Через агрегатный класс\n";
		cout << "1. Загрузка координат с клавиатуры\n";
		cout << "2. Вывод на экран дисплея данных \n";
		cout << "3. Конструктор копирования\n";
		cout << "4. Операция присваивания\n";
		cout << "5. Смена знака\n";
		cout << "6. Перегруженная операция вывода\n";
		cout << "7. Расстояние до начала системы\n";
		cout << "8. Расстояние между точками\n";
		cout << "9. Методы доступа к координатам (через get)\n";
		cout << "            Через базовый класс\n";
		cout << "10. Загрузка координат с клавиатуры\n";
		cout << "11. Вывод на экран дисплея данных \n";
		cout << "12. Конструктор копирования\n";
		cout << "13. Операция присваивания\n";
		cout << "14. Смена знака\n";
		cout << "15. Перегруженная операция вывода\n";
		cout << "16. Расстояние до начала системы\n";
		cout << "17. Расстояние между точками\n";
		cout << "18. Методы доступа к координатам (через get)\n";
		cout << "Ваш выбор (1-18):";
		cin >> j;
		switch (j)
		{
		case 1: cin >> aa; break;
		case 2: cout << aa;  break;
		case 3: {mpoint2 b(aa); cout << b << "\n" << aa; } break;
		case 4: {mpoint2 b, c; c = b = aa; cout << c << "\n" << b << "\n" << aa; } break;
		case 5: cout << -aa; break;
		case 6: aa.output(); break;
		case 7: cout << aa.rast(); break;
		case 8: cout << aa.dist(); break;
		case 9: cout << "x=" << aa.getx() << "\ny=" << aa.gety() << "\nm=" << aa.getm(); break;
		case 10: cin >> a; break;
		case 11: cout << a; break;
		case 12: {point2 b(a); cout << b << "\n" << a; } break;
		case 13: {point2 b, c; c = b = a; cout << c << "\n" << b << "\n" << a; } break;
		case 14: cout << -a; break;
		case 15: a.output(); break;
		case 16: cout << a.rast(); break;
		case 17: cout << a.dist(); break;
		case 18: cout << "x=" << a.getx() << "\ny=" << a.gety(); break;
		}
		cout << "\n";
		system("pause");
	}
}