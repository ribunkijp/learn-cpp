
#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <cctype>
#include <time.h>
#include <cstdlib> 
#include <array>
#include "ribunki.h"
#include "sort_array_ascending.h"



int main() 
{
	
	int datas[]{ 0,1,20,33,4, 2,4,6,7,8,22,3423,23,4,2,1,0 };

	int size = sizeof(datas) / sizeof(datas[0]);


	//sort_array_ascending(datas, size);

#if 0
	for (int i = 0; i < size; i++) {
		std::cout << datas[i] << '\n';
	}
#endif

#if 0
	std::cout << RIBUNKI << '\n';
#endif

	int data[2][3] = {
		{0, 1, 2},
		{3, 4, 5}
	};

	std::cout << data[1][1] << '\n';

	
	
	
	
	
	
	std::cin.ignore();
	std::cin.get();

	return 0;
}

