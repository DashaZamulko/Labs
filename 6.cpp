#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<iostream>
#include<Windows.h>
#include<string>

using namespace std;

class TranspVehicle  // ������� �����
{
public:
	static  TranspVehicle* beg;   //��������� �� ������ ������
	TranspVehicle* next = NULL;
	static void ShowList()  //������
	{
		TranspVehicle* p = beg;
		while (p)
		{
			p->show();
			p = p->next;
		}
	}
	TranspVehicle()  //��� �����
	{
		name = new char[81];
	}
	TranspVehicle(const char* NAME, int EXPERIENCE)  //� �����
	{
		// ��������� ������ ��� name. ������ ���������� ������ = ����� ������ NAME
		name = new char[strlen(NAME) + 1];
		strcpy(name, NAME);
		experience = EXPERIENCE;

	}
	virtual ~TranspVehicle()  // ����������� ����������
	{
		delete[] name;
	}
	virtual void show() = 0;  //������ ����������� �������
	virtual void input() = 0;

protected:
	char* name;
	int experience;
};

TranspVehicle* TranspVehicle::beg = NULL; //������������� ����������� ����������

class car :public TranspVehicle   // ����������� �����
{
public:
	car() : TranspVehicle() {}   //��� �����
	car(const char* STAMP, int EXPERIENCE, bool AddToList = false) :TranspVehicle(STAMP, EXPERIENCE) //� �����
	{
		if (AddToList)
		{
			TranspVehicle* p = beg;
			while (p->next)
			{
				p = p->next;
			}
			p->next = this;
		}
	}
	void show()
	{
		cout << "\n �����: ����������";
		cout << "\n ��� ��������: " << name;
		cout << "\n ������������ ����:" << experience;
		cout << "\n";
	}
	void input()
	{
		cout << "\n ��� �������� ����������: ";
		cin >> name;
		cout << "\n ������������ ����:";
		cin >> experience;
		cout << "\n";
		cout << "---------------------------------\n";
	}
};

class train :public TranspVehicle  // ����������� �����
{
public:
	train() : TranspVehicle() {}

	train(const char* NAME, int EXPERIENCE, bool AddToList = false) :TranspVehicle(NAME, EXPERIENCE)
	{
		if (AddToList)
		{
			TranspVehicle* p = beg;
			while (p->next)
			{
				p = p->next;
			}
			p->next = this;
		}

	}
	void show()
	{
		cout << "\n�����: �����";
		cout << "\n ��� ��������: " << name;
		cout << "\n ������������ ����:" << experience;
		cout << "\n";
	}
	void input()
	{
		cout << "\n ��� �������� ������: ";
		cin >> name;
		cout << "\n ������������ ����:";
		cin >> experience;
		cout << "\n";
		cout << "---------------------------------\n";
	}
};

class express :public train  // ����������� �����
{
public:
	express() : train() {}

	express(const char* NAME, int EXPERIENCE, bool AddToList = false) :train(NAME, EXPERIENCE)
	{
		if (AddToList)
		{
			TranspVehicle* p = beg;
			while (p->next)
			{
				p = p->next;
			}
			p->next = this;
		}
	}
	void show()
	{
		cout << "\n �����: ��������";
		cout << "\n ��� ��������: " << name;
		cout << "\n ������������ ����:" << experience;
		cout << "\n";
	}
	void input()
	{
		cout << "\n ��� �������� ��������: ";
		cin >> name;
		cout << "\n ������������ ����:";
		cin >> experience;
		cout << "\n";
	}

};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	car* x1;
	train* x2;
	express* x3;
	x1 = new car;
	x2 = new train;
	x3 = new express;
	x1->input();
	x2->input();
	x3->input();
	cout << "_______________________________________________\n";
	TranspVehicle::beg = x1;
	x1->next = x2;
	x2->next = x3;
	express* x4 = new express("�����", 5, true); // �������� ������� ������
	TranspVehicle::ShowList();
	return 0;
}
