
#include <iostream>
#include <string>


int main() {


	std::string name = "名前：　LI WENHUI";

	int age = 33;

	std::string shumi = "趣味：　ジョギング　と　ゲーム";
	std::string sukina_game = "一番好きなゲーム：The Last of Us  ゼルダの伝説  sekiro\n";


	std::cout << name << "\n\n";
	std::cout << "年齢：　" << age << "歳\n\n";
	std::cout << shumi << "\n\n" << sukina_game << std::endl;





	std::cin.ignore();
	std::cin.get();

	return 0;
}