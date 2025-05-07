
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

//static bool isInteger(const std::string& s) {
//	size_t i = 0;
//	if (s[0] == '-' || s[0] == '+') i = 1;
//	if (i == s.size()) return false;
//
//	for (; i < s.size(); ++i) {
//		if (!std::isdigit(s[i])) return false;
//	}
//	return true;
//}
//static bool isDecimal(const std::string& s) {
//	size_t i = 0;
//	bool pointSeen = false;
//
//	if (s[0] == '-' || s[0] == '+') i = 1;
//	if (i == s.size()) return false;
//
//	for (; i < s.size(); ++i) {
//		if (s[i] == '.') {
//			if (pointSeen) return false;
//			pointSeen = true;
//		}
//		else if (!std::isdigit(s[i])) {
//			return false;
//		}
//	}
//	return pointSeen;
//}


int main() {

	//std::string firNUM;
	//std::string secNum;

	//int num1, num2;

	/*while (true) {

		std::cout << "一つ目の整数を入力してください" << std::endl;
		std::cin >> firNUM;
		std::cout << "二つ目の整数を入力してください" << std::endl;
		std::cin >> secNum;

		if (isInteger(firNUM) && isInteger(secNum)) {
			num1 = std::stoi(firNUM);
			num2 = std::stoi(secNum);
			if (num2 == 0) {
				std::cout << "0割り算は計算不可です " << std::endl;
			}
			else {
				std::cout << num1 << "+" << num2 << "=" << (num1 + num2) << "\n" << std::endl;
				std::cout << num1 << "-" << num2 << "=" << (num1 - num2) << "\n" << std::endl;
				std::cout << num1 << "*" << num2 << "=" << (num1 * num2) << "\n" << std::endl;
				std::cout << num1 << "/" << num2 << "=" << (num1 / num2) << "\n" << std::endl;
				std::cout << num1 << "%" << num2 << "=" << (num1 % num2) << "\n" << std::endl;
				
				break;
			}
		}
		else if ((isDecimal(firNUM) && isDecimal(secNum)) || (isDecimal(firNUM) && isInteger(secNum)) || (isDecimal(secNum) && isInteger(firNUM))) {
			std::cout << "整数だけを入力してください。小数は入力しないでください" << std::endl;
		}
		else {
			std::cout << "これは数値ではありません。数値だけを入力してください" << std::endl;
		}

		continue;
	}*/
	
	/*std::string val = "+33";
	int num = std::stoi(val);
	num = num / 5;
	std::cout << num << std::endl;*/

	int takasa;

	std::cin >> takasa;
	
	for (int i = 0; i <= takasa; i++) {
		std::string str;
		std::string space;
		for (int j = 0; j < i; j++) {
			str += "■ ";
		}
		for (int k = 0; k < takasa - i; k++) {
			space += " ";
		}
		std::cout << space <<  str << "\n" << std::endl;
		str.clear();
		
	}



	std::cin.ignore();
	std::cin.get();

	return 0;
}