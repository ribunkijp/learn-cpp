
#include <iostream>
#include <vector>
#include <iomanip>
#include <conio.h>
#include <string>

enum Color {
	red,
	yellow,
	blue,
	green,
	pink,
	black = 10,
	white
};
int main() 
{
	Color kutsu{ black };
	Color shatsu{ white };
	
	std::cout << kutsu << '\n';
	std::cout << shatsu << '\n';
	
	switch (kutsu) {
		case black:
			std::cout << "黒い靴" << '\n';
			break;
		case white:
			std::cout << "白い靴" << '\n';
			break;
		default:
			std::cout << "グレーの靴" << '\n';
			break;
	}
	
	


	std::cin.seekg(0);
	std::cin.get();
	return 0;
}


