// Task 1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

class B1
{
	int a;
public:
	B1() { cout << "object of " << typeid(*this).name() << " was created\n"; }
	B1(int x)
	{
		a = x;
		cout << "object of " << typeid(*this).name() << " was created\n";
	}
	~B1() { cout << "object of " << typeid(*this).name() << " was destroyed\n"; }
};
class B2
{
	int b;
public:
	B2() { cout << "object of " << typeid(*this).name() << " was created\n"; }
	B2(int x)
	{
		b = x;
		cout << "object of " << typeid(*this).name() << " was created\n";
	}
	~B2() { cout << "object of " << typeid(*this).name() << " was destroyed\n"; }
};
class B3
{
	int c;
public:
	B3() { cout << "object of " << typeid(*this).name() << " was created\n"; }
	B3(int x)
	{
		c = x;
		cout << "object of " << typeid(*this).name() << " was created\n";
	}
	~B3() { cout << "object of " << typeid(*this).name() << " was destroyed\n"; }
};
class D1 :private B1, public B2, virtual protected B3
{
	int d;
public:
	D1(int x, int y, int i, int j) :B1(y), B2(i), B3(j)
	{
		d = x;
		cout << "object of " << typeid(*this).name() << " was created\n";
	}
	~D1() { cout << "object of " << typeid(*this).name() << " was destroyed\n"; }
};
class D3 :virtual public B3
{
	int e;
public:
	D3(int x, int y) :B3(y)
	{
		e = x;
		cout << "object of " << typeid(*this).name() << " was created\n";
	}
	~D3() { cout << "object of " << typeid(*this).name() << " was destroyed\n"; }
};
class D2 :public D1, private D3
{
	int f;
public:
	D2(int x, int y, int i, int j, int w, int z, int k) :D1(y, i, j, w), D3(z, k)
	{
		f = x;

		cout << "object of " << typeid(*this).name() << " was created\n";
	}
	~D2() { cout << "object of " << typeid(*this).name() << " was destroyed\n"; }
};

class D4 :protected D2
{
	int g;
public:
	D4(int x, int y, int i, int j, int w, int z, int k, int m) :D2(y, i, j, w, z, k, m)
	{
		g = x;
		cout << "object of " << typeid(*this).name() << " was created\n";
	}
	~D4() { cout << "object of " << typeid(*this).name() << " was destroyed\n"; }

};

int main()
{
	D3(5, 6);
	D4(2, 5, 6, 4, 3, 5, 7, 5);
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
