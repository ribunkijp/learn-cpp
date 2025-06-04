/*========================================================================================================

		main[main.cpp]

																				

																					Author: ribunki
																					Date:   2025/06/04
																		
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
std::ostream& operator<<(std::ostream& os, const Per& p) {
	os << "Name: " << p.name << "\n"
		<< "Attack_Power: " << p.attack_power << "\n"
		<< "HP: " << p.hp << "\n"
		<< "MP: " << p.mp;
	return os;
}
static bool read_from_stream(std::vector<Per> &pers) {
	
	std::ifstream in_file("pers_data.bin", std::ios::in | std::ios::binary);
	if (!in_file.is_open()) {
		std::cerr << "Error opening file for binary reading!" << std::endl;
		return 1;
	}

	while (true) {
		Per per;
		//name
		int len;
		in_file.read(reinterpret_cast<char*>(&len), sizeof(len));
		//
		if (in_file.eof()) break;
		
		if (!in_file) return false;

		if (len > 0) {
			per.name.resize(len);
		
			in_file.read(&per.name[0], len);
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

static bool write_to_stream(Per per) {
	std::ofstream out_file("pers_data.bin", std::ios::out | std::ios::binary | std::ios::app);//std::ios::app追加append
	if (!out_file.is_open()) {
		std::cerr << "Error opening file for binary writing!" << std::endl;
		return false;
	}
	
	//name
	int len = per.name.length();
	out_file.write(reinterpret_cast<const char*>(&len), sizeof(len));
	out_file.write(per.name.c_str(), len);
	//attack_power hp mp
	out_file.write(reinterpret_cast<const char*>(&per.attack_power), sizeof(per.attack_power));
	out_file.write(reinterpret_cast<const char*>(&per.hp), sizeof(per.hp));
	out_file.write(reinterpret_cast<const char*>(&per.mp), sizeof(per.mp));

	out_file.close();

	return true;
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
	

	std::string input_str{};
	std::getline(std::cin, input_str);

	
	Per new_per = get_property(input_str);
	
	write_to_stream(new_per);
	
	read_from_stream(pers);
	
	for (const auto& p : pers) {
		std::cout << p << "\n------------------------------\n";
	}

	
	

	
	return 0;
	
}

