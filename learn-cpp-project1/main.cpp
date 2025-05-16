
#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <cctype>
#include <time.h>
#include <cstdlib> 
#include <array>

using namespace std;

int d = 0;
double c = 0.0;



int main() {
	
	
	int h[5] = { 10, 11, 12, 13, 14 };

	int* p = &h[0];
	cout << *p << '\n';
	p--;

	//p[4] = 200;
	
	cout << *p << '\n';

	/*string kamoku[5] = {
		"算数",
		"国語",
		"英語",
		"社会",
		"理科"

	};
	int total = 0;

	for (int i = 0; i < 5; i++) {
		cout << kamoku[i] << "の成績を入力してください\n";
		int input = 0;
		cin >> input;
		total += input;
	}
	
	cout << total / 5 << '\n';*/



	std::cin.ignore();
	std::cin.get();

	return 0;
}

