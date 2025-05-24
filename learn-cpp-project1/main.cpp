
#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <iomanip>

std::vector<std::vector<int>> create_mahoujin(int rows, int cols, std::vector<std::vector<int>>& mahoujin_datas);

int main() 
{
	int rows{ 3 }, cols = { 3 };
	std::vector<std::vector<int>> mahoujin_datas(rows, std::vector<int>(cols, 0));
	
	create_mahoujin(3, 3, mahoujin_datas);

	std::cout << rows << "x" << cols << "奇数魔法陣\n";
	
	for (int i = 0; i < rows; i++) {

		for (int j = 0; j < cols; j++) {

			std::cout << std::setw(3) << mahoujin_datas[i][j] << ' ';
		}
		std::cout << '\n';
	}
	
	return 0;
}

std::vector<std::vector<int>> create_mahoujin(int rows, int cols, std::vector<std::vector<int>> &mahoujin_datas) {

	int num { 1 };
	int i{ 0 }, j{ rows / 2 };
	while (num <= rows * cols){
		mahoujin_datas[i][j] = num;

		int mi = (i - 1 + rows) % rows;
		int mj = (j + 1) % cols;


		if (mahoujin_datas[mi][mj] != 0) {
			i = (i + 1) % rows;
		}
		else {
			i = mi;
			j = mj;
		}

		num++;
	}

	return mahoujin_datas;
}