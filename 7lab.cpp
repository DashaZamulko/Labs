#include <vector>
#include <time.h>
#include <iostream>
#include <math.h>
using namespace std;
int main(int argc, char* argv[])  //  параметры функции main()
{
	vector<float> set(100), new_set(100);  //  вектор из элементов типа float 
	vector<float>::iterator it;  //  создали итератор под именем it
	char Cont = 'y';
	int i = 0, j;
	float range[2], s = 0.0;
	bool c = true;  //  копирующая инициализация
	while (toupper(Cont) == 'Y')  //  преобразовать строчную букву в прописную
	{
		cout << "Enter the symbol: ";
		cin >> set[i];
		cout << "continue?(y): ";
		cin >> Cont;
		i++;
	}
	cout << "Enter the range:  from ";
	cin >> range[0];
	cout << "to ";
	cin >> range[1];
	set.resize(i);  //  изменяет размер набора до i
	//  задание 1
	j = 0;
	for (i = 0; i < set.size(); i++)
	{
		if (set[i]<range[0] || set[i]>range[1]) continue;
		new_set[j] = set[i];
		j++;
	}
	new_set.resize(j);  //  изменяет размер другого набора 
	cout << endl;
	cout << "1 task: " << endl;
	for (i = 0; i < new_set.size(); i++)
	{
		cout << "Elements from " << range[0] << " to " << range[1] << ": " << new_set[i] << endl;
	}
	// задание 2
	for (it = set.begin(); it != set.end(); ++it)
	{
		if (((*it) == 0) && c) c = false;
		if (c) continue;
		s += fabs(*it);  //  вычисляет сумму числа по модулю
	}
	cout << "2 task: sum = " << s << endl;
	system("pause");
	return 0;
}



