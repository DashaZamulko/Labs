#include <iostream>
#include <list>
#include <vector>

using namespace std;

class MyClass {
protected:
	virtual void showInf() = 0;
};

class Result : public MyClass {
protected:
public:
	list<char> El = { 'd','e','v','e','l' };
	void showInf() override {
		cout << "list: ";
		for (char n : El) {
			cout << n << " ";
		}
		cout << endl;
	}
	char& operator [] (const int index);
	list<char>& operator +(const list<char> second) {
		auto iter2 = second.begin();
		for (char n : second) {
			El.emplace_back(*iter2);
			++iter2;
		}
		return El;
	}
	bool operator !=(const list<char> second) {
		auto iter = El.begin();
		auto iter2 = second.begin();
		for (char n : second) {
			if (*iter != *iter2) {
				return false;
			}
		}
		return true;
	}
	int begin;
};

char& Result::operator[](const int index) {
	auto iter = El.begin();
	for (int i = 0; i < index; i++) {
		iter++;
	}
	return *iter;
}


int main() {
	Result List;
	Result result;
	list<char> second = { 'o','p','e','r' };
	list<char> me = { 'd','e','v','e','l','o','p','e','r' };
	List.showInf();
	List + second;
	List.showInf();

	if (List != second) {
		cout << "Yes" << endl;
	}
	else
		cout << "No" << endl;

	if (List != me) {
		cout << "Yes" << endl;
	}
	else
		cout << "No" << endl;

	cout << "List[6]: " << List[6] << endl;
	system("pause");
	return 0;
}
