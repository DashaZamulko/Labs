#include <iostream>
#include <fstream>
#include <vector>
#include <string>
int main() {
	std::ifstream fin;
	std::ofstream fout;
	std::vector<std::string> keyWords{ "for", "while", "if" };
	fin.open("1.txt");
	fout.open("2.txt", std::ios::trunc);
	if (fin.is_open() && fout.is_open()) {
		while (!fin.eof())
		{
			std::string temp;
			std::getline(fin, temp);
			fout << temp;
			for (int i = 0; i < 3; i++) {
				if (temp.find(keyWords[i]) != std::string::npos) {
					std::string temp2;
					std::getline(fin, temp2);
					fout << "{" << std::endl;
					fout << temp2 << std::endl << "\t}" << std::endl;
				}
				else {

				}
			}
			fout << std::endl;
		}
	}
	return 0;
}

