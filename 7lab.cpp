#include <vector>
#include <time.h>
#include <iostream>
#include <math.h>
using namespace std;
int main(int argc, char* argv[])  //  ��������� ������� main()
{
	vector<float> set(100), new_set(100);  //  ������ �� ��������� ���� float 
	vector<float>::iterator it;  //  ������� �������� ��� ������ it
	char Cont = 'y';
	int i = 0, j;
	float range[2], s = 0.0;
	bool c = true;  //  ���������� �������������
	while (toupper(Cont) == 'Y')  //  ������������� �������� ����� � ���������
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
	set.resize(i);  //  �������� ������ ������ �� i
	//  ������� 1
	j = 0;
	for (i = 0; i < set.size(); i++)
	{
		if (set[i]<range[0] || set[i]>range[1]) continue;
		new_set[j] = set[i];
		j++;
	}
	new_set.resize(j);  //  �������� ������ ������� ������ 
	cout << endl;
	cout << "1 task: " << endl;
	for (i = 0; i < new_set.size(); i++)
	{
		cout << "Elements from " << range[0] << " to " << range[1] << ": " << new_set[i] << endl;
	}
	// ������� 2
	for (it = set.begin(); it != set.end(); ++it)
	{
		if (((*it) == 0) && c) c = false;
		if (c) continue;
		s += fabs(*it);  //  ��������� ����� ����� �� ������
	}
	cout << "2 task: sum = " << s << endl;
	system("pause");
	return 0;
}



