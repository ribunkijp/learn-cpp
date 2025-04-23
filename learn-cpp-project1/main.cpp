
#include <iostream>
#include <string>


int main() {


	/*std::string name = "名前：　LI WENHUI";

	bool a = 5 > 30;
	std::cout << a << std::endl;
	if (a) {
		std::cout << "真だよ" << std::endl;
	}
	else {
		std::cout << "偽だよ" << std::endl;
	}*/
	int a;
	std::cin >> a;
	a = a % 3;
	std::cout << a << std::endl;
	if (!(a % 3)) {
		std::cout << "true" << std::endl;
	}



	std::cin.ignore();
	std::cin.get();

	return 0;
}