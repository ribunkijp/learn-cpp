
#include <iostream>
#include <vector>
#include <iomanip>
#include <conio.h>
#include <string>
#include <cstring>

//ポインター
struct Shumi {
	std::string sakka{};
	std::string yakyuu{};
};
struct Employee {
	int id{};
	int age{};
	double wage{};
	Shumi shu{};
};

int main() 
{
	Employee ri{33, 33, 300.33};
	Employee bun{ 11, 11, 11111.11 };

	ri = bun;//代入
    
	Employee* ob = &ri;

	std::cout << (*ob).age << '\n';//11
    ////アロー　arrow -> 
    std::cout << ob -> wage << '\n';//1111.1
    
    ////
   Employee pers[]{
        {11, 111, 1111.1, {"サッカー1", "野球1"}},
        {22, 222, 2222.2, {"サッカー2", "野球2"}},
        {33, 333, 3333.3, {"サッカー3", "野球3"}},
        {44, 444, 4444.4, {"サッカー4", "野球4"}},
        {55, 555, 5555.5, {"サッカー5", "野球5"}}
    };
	std::cout << pers[3].id << '\n';//44
    std::cout << pers[2].shu.yakyuu << '\n';//野球3

	std::cin.seekg(0);
	std::cin.get();
	return 0;
}

