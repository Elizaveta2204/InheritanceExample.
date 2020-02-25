// Task 2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include<string>
#include<clocale>
using namespace std;

class ComputerGameObject
{
 private:
	string title;
 protected:
	ComputerGameObject(const string& _title) :title(_title) {}
	ComputerGameObject(const ComputerGameObject& obj) : title(obj.title) {}
	virtual ~ComputerGameObject() { cout << "Computer game object deleted" << endl; }
	virtual void  _print() const { cout << "title: " << title; }
 public:
	virtual void draw() = 0;
	void  print() const
	{
		cout << typeid(*this).name() << ": (";
		_print();
		cout << ")\n\n";
	}
};
class Creature :public ComputerGameObject
{
private:
	int health_points;
    int endurance;
	int coordinateX;
	int coordinateY;
	
public:
	Creature(const string& _title, int _healthPoints, int _endurance) :ComputerGameObject(_title), health_points(_healthPoints), endurance(_endurance), coordinateX(0), coordinateY(0) {}
	Creature(const Creature& obj) :
		ComputerGameObject(obj), health_points(obj.health_points), coordinateX(obj.coordinateX), coordinateY(obj.coordinateY), endurance(obj.endurance) {}
	Creature(const string& _title, int _healthPoints, int _coordinateX, int _coordinateY, int _endurance) :
		ComputerGameObject(_title), health_points(_healthPoints), coordinateX(_coordinateX), coordinateY(_coordinateY), endurance(_endurance) {}
	void _move(int X, int Y) 
	{
		coordinateX = X;
		coordinateY = Y;
	}
	int getX() { return coordinateX; }
	int getY() { return coordinateY; }
	~Creature() { cout << "Creature deleted" << endl; }
protected:
	virtual void move(int, int) = 0;
	void  _print()const override
	{
		ComputerGameObject::_print();
		cout << ", health points: " << health_points << ", coordinateX: " << coordinateX << ", coordinateY: " << coordinateY << ", endurance: " << endurance;
	}
};
class MythicalAnimal :public Creature
{
private:
	bool wool;
public:
	MythicalAnimal(const string& _title, int _healthPoints, int _endurance, bool _wool) :Creature(_title, _healthPoints, _endurance), wool(_wool) {}
	MythicalAnimal(const MythicalAnimal& obj) : Creature(obj), wool(obj.wool) {}
	MythicalAnimal(const string& _title, int _healthPoints, int _coordinateX, int _coordinateY, int _endurance, bool _wool) :
		Creature(_title, _healthPoints, _coordinateX, _coordinateY, _endurance), wool(_wool) {}
	~MythicalAnimal() { cout << "Mythical animal deleted" << endl; }
	void move(int X, int Y) override {
		Creature::_move(X, Y);
		cout << "Mythical animal has changed place: (" << getX() << ";" << getY() << ")" << endl;
	}
	void draw()
	{
		cout << "Location of a mythical animal: (" << getX() << ";" << getY() << ")\n";
	}
protected:

	void _print()const override
	{
		Creature::_print();
		cout << ", wool: " << wool;
	}
};
class Human :public Creature
{
private:
	int weaponCount;
	int height;
public:
	Human(const string& _title, int _healthPoints, int _endurance, int _weaponCount, int _height) :Creature(_title, _healthPoints, _endurance), weaponCount(_weaponCount), height(_height) {}
	Human(const Human& obj) : Creature(obj), weaponCount(obj.weaponCount), height(obj.height) {}
	Human(const string& _title, int _healthPoints, int _coordinateX, int _coordinateY, int _endurance, int _weaponCount, int _height) :
		Creature(_title, _healthPoints, _coordinateX, _coordinateY, _endurance), weaponCount(_weaponCount), height(_height) {}
	~Human() { cout << "Human character deleted" << endl; }
	void move(int X, int Y) override {
		Creature::_move(X, Y);
		cout << "Human has changed place: (" << getX() << ";" << getY() << ")" << endl;
	}
	void draw() override
	{
		cout << "Location of a human character: (" << getX() << ";" << getY() << ")\n";
	}
protected:

	void _print()const override
	{
		Creature::_print();
		cout << ", number of weapons: " << weaponCount << ", height: " << height;
	}
};
class MagicCharacter :public Creature
{
private:
	string Element;
public:
	MagicCharacter(const string& _title, int _healthPoints, int _endurance, string _kindOfMagic) :Creature(_title, _healthPoints, _endurance), Element(_kindOfMagic) {}
	MagicCharacter(const MagicCharacter& obj) : Creature(obj), Element(obj.Element) {}
	MagicCharacter(const string& _title, int _healthPoints, int _coordinateX, int _coordinateY, int _endurance, string _kindOfMagic) :
		Creature(_title, _healthPoints, _coordinateX, _coordinateY, _endurance), Element(_kindOfMagic) {}
	~MagicCharacter() { cout << "Magic character deleted" << endl; }
	void move(int X, int Y) override {
		Creature::_move(X, Y);
		cout << "Magic character has changed place: (" << getX() << ";" << getY() << ")" << endl;
	}
	void draw() override
	{
		cout << "Location of a magic character: (" << getX() << ";" << getY() << ")\n";
	}
protected:

	void _print()const override
	{
		Creature::_print();
		cout << ", Element: " << Element;
	}
};
class MagicItem :public ComputerGameObject
{
private:
	int value;//value to the owner of this item
	int price;
	int coordinateX;
	int coordinateY;
public:
	MagicItem(const string& _title) :ComputerGameObject(_title), coordinateX(0), coordinateY(0), value(0), price(0) {}
	MagicItem(const string& _title, int _value, int _price) :ComputerGameObject(_title), value(_value), price(_price), coordinateX(0), coordinateY(0) {}
	MagicItem(const string& _title, int _value, int _price, int _coordinateX, int _coordinateY) :
		ComputerGameObject(_title), value(_value), price(_price), coordinateX(_coordinateX), coordinateY(_coordinateY) {}
	MagicItem(const MagicItem& obj) :ComputerGameObject(obj), coordinateX(obj.coordinateX), coordinateY(obj.coordinateY), value(obj.value), price(obj.price) {}
	~MagicItem() { cout << "Magic item deleted\n"; }
	void draw() override
	{
		cout << "Location of a magic item: (" << coordinateX << ";" << coordinateY << ")\n";
	}
protected:
	void _print()const override
	{
		ComputerGameObject::_print();
		cout << ", value: " << value << ", price: " << price << ", coordinateX: " << coordinateX << ", coordinateY: " << coordinateY;
	}
};

int main()
{
	setlocale(LC_ALL, "ru");
	MagicItem cloakofinvisibility("Мантия-невидимка", 1, 2);
	cloakofinvisibility.print();
	cloakofinvisibility.draw();
	MythicalAnimal fox("Лис", 100, 200, 1);
	fox.move(100, 150);
	fox.draw();
	fox.print();
	Human Mccloud("МакКлауд", 12, 100, 150, 2, 1000, 185);
	Mccloud.draw();
	Mccloud.move(234, 567);
	Mccloud.print();
	MagicCharacter Fire("Огонь", 100, 56, "");
	Fire.draw();
	Fire.move(234, 567);
	Fire.print();
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
