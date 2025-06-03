/*========================================================================================================

		main[main.cpp]

																				

																					Author: ribunki
																					Date:   2025/05/09
																		
==========================================================================================================*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <random>
#include <chrono>

struct Per {
	unsigned int attack_power{};
	unsigned int hp{};
	unsigned int mp{};
	std::string name{};
};
static void read_from_stream(std::vector<Per> pers) {
	std::ifstream inFile("pers_data.bin", std::ios::in | std::ios::binary);
	if (!inFile.is_open()) {
		std::cerr << "Error opening file for binary reading!" << std::endl;
		//return 1;
	}
	//string

}

static void write_to_stream(Per per) {
	std::ofstream outFile("pers_data.bin", std::ios::out | std::ios::binary | std::ios::app);//std::ios::app追加append
	if (!outFile.is_open()) {
		std::cerr << "Error opening file for binary writing!" << std::endl;
		//return 1;
	}
	
	//string
	int len = per.name.length();
	outFile.write(reinterpret_cast<const char*>(&len), sizeof(len));
	outFile.write(per.name.c_str(), len);
	//attack_power hp mp
	outFile.write(reinterpret_cast<const char*>(&per.attack_power), sizeof(per.attack_power));
	outFile.write(reinterpret_cast<const char*>(&per.hp), sizeof(per.hp));
	outFile.write(reinterpret_cast<const char*>(&per.mp), sizeof(per.mp));

	outFile.close();
}

Per get_property(std::string& str) {
	Per p;
	std::mt19937 mt{ static_cast<std::mt19937::result_type>(str.size())};

	std::uniform_int_distribution die8{ 100, 800 };
	
	p.name = str;
	p.attack_power = static_cast<unsigned>(die8(mt));
	p.hp = static_cast<unsigned>(die8(mt));
	p.mp = static_cast<unsigned>(die8(mt));

	return p;

}

int main()
{
	std::vector<Per> pers{};
	
	read_from_stream(pers);

	std::string input_str{};
	std::getline(std::cin, input_str);

	//write_to_stream(get_property(input_str));
	

	
	
	return 0;
	
	
}

