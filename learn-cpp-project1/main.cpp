
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


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
	/*int a;
	std::cin >> a;
	a = a % 3;
	std::cout << a << std::endl;
	if (!(a % 3)) {
		std::cout << "true" << std::endl;
	}*/
	/*char res;
	std::cin >> res;

	if (!(res % 2)) {
		std::cout << res << "は偶数です" << std::endl;
	}
	else {
		std::cout << res << "は奇数ですよ" << std::endl;
	}*/
	/*int a, b ,c;

	std::cout << "一つ目の数を入力してください" << std::endl;
	std::cin >> a;
	std::cout << "二つ目の数を入力してください" << std::endl;
	std::cin >> b;
	
	c = a - b;

	if (c == 0) {
		std::cout << "二つの数は同じです" << std::endl;
	}
	else if (c < 0) {
		std::cout << a << "より" << b << "のほうが大きい値です" << std::endl;
	}
	else {
		std::cout << a << "より" << b << "のほうが小さい値です" << std::endl;
	}*/
	//int a, b, c, d, e;
	//std::vector<std::string>words = //vertor　ベクター
	//{
	//	"もっと頑張りましょう",
	//	"もうすこしがんばりましょう",
	//	"さらに上を目指しましょう",
	//	"たいへんよくできました",
	//	"大変優秀です"

	//};
	//std::cout << "一つ目の成績を入力してください" << std::endl;
	//std::cin >> a;
	//std::cout << "二つ目の成績を入力してください" << std::endl;
	//std::cin >> b;
	//std::cout << "三つ目の成績を入力してください" << std::endl;
	//std::cin >> c;
	//std::cout << "四つ目の成績を入力してください" << std::endl;
	//std::cin >> d;
	//std::cout << "五つ目の成績を入力してください" << std::endl;
	//std::cin >> e;

	//std::vector<int>arr = { a, b, c, d, e };
	//std::sort(arr.begin(), arr.end());//std::sort(nums.begin(), nums.end(), std::greater<int>());降序
	//for (int n = 0; n < arr.size(); n++) {
	//	std::cout << arr[n] << " " << words[n] << "\n" << std::endl;
	//}
	//
	int a;
	std::cout << "入力してください" << std::endl;
	std::cin >> a;
	std::string suchi = std::to_string(a);

	


	std::cin.ignore();
	std::cin.get();

	return 0;
}