
#include <iostream>
#include <vector>
#include <iomanip>
#include <conio.h>
#include <string>
#include <cstring>

int main()
{

	char str[6]{
		'a',
		'b',
		'c',
		'd',
		'e',
		'\0'
	};

	char str1[10];

	char str2[3]{
		'f',
		'g',
		'\0'
	};
	
	const char* val = &str[0];
	std::cout << val << '\n';//abcde
	std::cout << val[0] << '\n';//a

	val++;
	std::cout << *val << '\n';//b
	std::cout << val << '\n';//bcde
	std::cout << val[0] << '\n';//b

	val--;
	std::cout << strlen(val) << '\n';//5 null文字(/0)を除く長さを返す　戻り値の型はsize_t

	strcpy_s(str1, sizeof(str1), str);
	std::cout << str1 << '\n';


	errno_t concat_err = strcat_s(str1, sizeof(str1), str2);
	if (concat_err == 0) {
		std::cout << str1 << '\n';
	}
	else {
		std::cout << "Error concatenating strings.\n";
	}

	/*int hikaku_result{ 0 };
	errno_t hikaku_err = strcmp_s(str1, 10, str, &hikaku_result);*/

	std::cin.seekg(0);
	std::cin.get();
	return 0;
}

