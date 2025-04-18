//ピラミッドプログラム
#include <iostream>

int main() {

	/*std::cout << "　　　　 ■\n";
	std::cout << "　　　 ■　■\n";
	std::cout << "　　 ■　■　■\n";
	std::cout << "　  ■　■　■　■\n";
	std::cout << "■　■　■　■ ■　■\n";*/
	/*int a = 100;*/
	
	/*size_t size = sizeof(_int64);
	std::cout << "サイズ = " << size << "byte\n";*/
	/*float x, y, z;
	x = 100;
	

	std::cin.get();*/

	//キーボードからの入力
	//int input = 0;

	//std::cin >> input;

	//std::cout << "入力された数値は" << input << "です\n";

	/*float a = 1.24f;

	std::cout << a << std::endl;*/
	/*float a = 10 % 3;
	std::cout << a << std::endl;*/
	char c = 100;
	int a = 200;

	c = a;
	std::cout << (int)c << std::endl;

	int num1, num2;
	
	std::cout << "整数１を入力してください\n";
	std::cin >> num1;

	std::cout << "整数2を入力してください\n";
	std::cin >> num2;

	std::cout << "割り算のけっか" << num1 / num2 << "です\n";

	std::cin.ignore();
	std::cin.get();

	return 0;
}