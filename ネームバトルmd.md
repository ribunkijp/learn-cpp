```c++
/*===================================================================================================

	main.cpp

																			Author：ribunki
																			Date  ：2025/6/5

----------------------------------------------------------------------------------------------------

===================================================================================================*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <random>
#include <chrono>


// Per
struct Per {
	unsigned int attack_power{};
	unsigned int hp{};
	unsigned int mp{};
	std::string name{};
};
std::ostream& operator<<(std::ostream& os, const Per& p) {
	os << "Name: " << p.name << "\n"
		<< "Attack_Power: " << p.attack_power << "\n"
		<< "HP: " << p.hp << "\n"
		<< "MP: " << p.mp;
	return os;
}

//stream から　read
static bool read_from_stream(std::vector<Per>& pers);

// write to stream
static bool write_to_stream(Per& per);


// property生成
Per get_property(std::string& str);


// ネームからper生成
unsigned create_per(std::vector<Per>& pers, std::string& str);



// main
int main()
{
	// per datas
	std::vector<Per> pers{};

	// 入力ネーム
	std::string input_str_1{};
	std::string input_str_2{};

	// 戦力
	unsigned power1{};
	unsigned power2{};

	// 一つ目のネーム入力処理
	std::cout << "一つ目のネームを入力してください" << '\n';
	while (true) {
		std::getline(std::cin, input_str_1);
		if (!input_str_1.empty()) {

			read_from_stream(pers);
			power1 = create_per(pers, input_str_1);
			break;
		}
		else {
			std::cout << "入力してください" << '\n';
		}
	}
	// 二つ目のネーム入力処理
	std::cout << "二つ目のネームを入力してください" << '\n';
	while (true) {
		std::getline(std::cin, input_str_2);
		if (!input_str_2.empty()) {

			if (input_str_1 == input_str_2) {
				std::cout << "一つ目のネームと違うネームを入力してください" << '\n';
			}
			else {

				power2 = create_per(pers, input_str_2);
				break;
			}
		}
		else {
			std::cout << "入力してください" << '\n';
		}
	}

	//バトル レギュレーション: attack_power * hp * mp
	std::cout << "バイトの結果は：" << '\n';
	if (power1 > power2) {
		std::cout << input_str_1 << "勝つ" << '\n';
	}
	else if (power1 < power2) {
		std::cout << input_str_2 << "勝つ" << '\n';
	}
	else {
		std::cout << input_str_1 << "引き分ける" << '\n';
	}




	return 0;

}


//stream から　read
static bool read_from_stream(std::vector<Per>& pers) {

	std::ifstream in_file("pers_data.bin", std::ios::in | std::ios::binary);
	if (!in_file.is_open()) return false;

	// empty?
	in_file.seekg(0, std::ios::end);
	if (in_file.tellg() == 0) {
		in_file.close();
		return false;
	}
	in_file.seekg(0, std::ios::beg);

	while (true) {
		Per per;
		//name
		size_t len;
		in_file.read(reinterpret_cast<char*>(&len), sizeof(len));
		//
		if (in_file.eof()) break;

		if (!in_file) return false;

		if (len > 0) {
			per.name.resize(len);

			in_file.read(&per.name[0], static_cast<std::streamsize>(len));
			if (!in_file) return false;
		}
		else {
			per.name.clear();
		}

		//attack_power
		in_file.read(reinterpret_cast<char*>(&per.attack_power), sizeof(per.attack_power));
		if (!in_file) return false;

		//hp
		in_file.read(reinterpret_cast<char*>(&per.hp), sizeof(per.hp));
		if (!in_file) return false;

		//mp
		in_file.read(reinterpret_cast<char*>(&per.mp), sizeof(per.mp));
		if (!in_file) return false;

		pers.push_back(per);
	}

	in_file.close();

	return true;
}

// write to stream
static bool write_to_stream(Per& per) {
	std::ofstream out_file("pers_data.bin", std::ios::out | std::ios::binary | std::ios::app);//std::ios::app追加append
	if (!out_file.is_open()) return false;

	//name
	size_t len = per.name.length();
	out_file.write(reinterpret_cast<const char*>(&len), sizeof(len));
	out_file.write(per.name.c_str(), static_cast<std::streamsize>(len));
	//attack_power hp mp
	out_file.write(reinterpret_cast<const char*>(&per.attack_power), sizeof(per.attack_power));
	out_file.write(reinterpret_cast<const char*>(&per.hp), sizeof(per.hp));
	out_file.write(reinterpret_cast<const char*>(&per.mp), sizeof(per.mp));

	out_file.close();

	return true;
}

// property生成
Per get_property(std::string& str) {
	Per p;
	std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::chrono::steady_clock::now().time_since_epoch().count()) };

	std::uniform_int_distribution die8{ 100, 800 };

	p.name = str;
	p.attack_power = static_cast<unsigned>(die8(mt));
	p.hp = static_cast<unsigned>(die8(mt));
	p.mp = static_cast<unsigned>(die8(mt));

	return p;

}

// ネームからper生成
unsigned create_per(std::vector<Per>& pers, std::string& str) {
	unsigned power { 0 };

	bool found_name = false;
	for (const auto& p : pers) {
		if (str == p.name) {

			found_name = true;
			std::cout << "\n------------------------------\n" << p << "\n------------------------------\n";

			power = p.attack_power * p.hp * p.mp;

			break;

		}
	}
	//データにないなら、create
	if (!found_name) {
		Per new_per = get_property(str);
		power = new_per.attack_power * new_per.hp * new_per.mp;

		write_to_stream(new_per);

		std::cout << "\n------------------------------\n" << new_per << "\n------------------------------\n";
	}

	return power;
}

```

