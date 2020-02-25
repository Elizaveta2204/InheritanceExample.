// example 1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
class B {
	int a;
public:
	B() { cout << "object of " << typeid(*this).name() << " was created\n"; }
	B(int x) {
		a = x;
		cout << "object of " << typeid(*this).name() << " was created\n";
	}
	~B() { cout << "object of " << typeid(*this).name() << " was destroyed\n"; }
};
class D1 :virtual public B {
	int b;
public:

	D1(int x, int y) :B(y) {
		b = x;
		cout << "object of " << typeid(*this).name() << " was created\n";
	}
	~D1() { cout << "object of " << typeid(*this).name() << " was destroyed\n"; }
};
class D2 :virtual private B {
	int c;
public:
	D2(int x, int y) :B(y) {
		c = x;
		cout << "object of " << typeid(*this).name() << " was created\n";
	}
	~D2() { cout << "object of " << typeid(*this).name() << " was destroyed\n"; }
};
class D3 :private D1, public D2 {
	int d;
public:
	D3(int x, int y, int z, int i, int j) :D1(y, z), D2(i, j) {
		d = x;
		cout << "object of " << typeid(*this).name() << " was created\n";
	}
	~D3() { cout << "object of " << typeid(*this).name() << " was destroyed\n"; }
};
class D4 :private D1, public D2 {
	int e;
public:
	D4(int x, int y, int z, int i, int j) :D1(y, z), D2(i, j) {
		e = x;
		cout << "object of " << typeid(*this).name() << " was created\n";
	}
	~D4() { cout << "object of " << typeid(*this).name() << " was destroyed\n"; }
};

int main()
{
	D3 temp(100, 200, 300, 400, 500);
	D4 temp1(1, 2, 3, 4, 5);
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
