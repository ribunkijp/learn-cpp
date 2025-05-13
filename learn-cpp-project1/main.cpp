
#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <cctype>
#include <time.h>
#include <cstdlib> 

//整数判断
static bool isInteger(const std::string& s) {
	if (s.empty()) return false;

	size_t i = 0;
	if (s[0] == '-' || s[0] == '+') i = 1;
	if (i == s.size()) return false;

	for (; i < s.size(); ++i) {
		if (!std::isdigit(static_cast<unsigned char>(s[i]))) return false;
	}
	return true;
}

int Add(int a, int b) {
	
	return a + b;
}

int main() {

	////title
	//std::cout << "数当てゲームへようこそ!!今回の神秘的な数字は１～1000の間の整数です。\n";
	////乱数生成	
	//srand((unsigned)time(nullptr));
	//int kotae = rand() % 1000 + 1;//answer
	//
	////ユーザーの入力
	//std::string str;
	//
	//
	//while(true) {
	//	
	//	std::cin >> str;
	//	
	//	if (!isInteger(str)) {
	//		std::cout << "1～1000の整数を入力してください" << std::endl;
	//	}
	//	else {
	//		int num = std::stoi(str);
	//		if (num <= 0 || num > 1000) {
	//			std::cout << "1～1000の整数を入力してください" << std::endl;
	//			continue;
	//		}
	//		//ユーザーの入力と答えの差
	//		int dist = num - kotae;
	//	
	//		//判断
	//		if (dist == 0) {
	//			std::cout << "当たったね、あなたは神様かもね";//当たった
	//			break;
	//		}
	//		else if (dist > 100) {
	//			std::cout << "数字が大きすぎました" << std::endl;
	//		}
	//		else if (dist < -100) {
	//			std::cout << "数字が小さすぎました" << std::endl;
	//		}
	//		else if (dist < 100 && dist > 0) {
	//			std::cout << "数字がちょっと大きかった" << std::endl;
	//		}
	//		else if (dist > -100 && dist < 0) {
	//			std::cout << "数字がちょっと小さかった" << std::endl;
	//		}
	//	}

	//	continue;
	//	
	//}

	int c = Add(3, 5);
	std::cout << c << '\n';

	std::cin.ignore();
	std::cin.get();

	return 0;
}