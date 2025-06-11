#include <iostream>
#include "sorter.h"




int main() {

	int datas[]{ 0,1,20,33,4, 2,4,6,7,8,22,3423,23,4,2,1,0 };
	size_t size = sizeof(datas) / sizeof(datas[0]);
	sort_array_ascending(datas, size);


}