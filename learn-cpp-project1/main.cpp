
#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <cctype>
#include <time.h>
#include <cstdlib> 
#include <array>

using namespace std;

bool isUruu(int year);
static string get_new_year_weekday(int year);

int get_month_days(int year, int month);

string get_year_month_weekday(int year, int month);

int main() {
	/*int input;

	string result;
	
	cout << "年を入力\n";

	cin >> input;
	
	result = get_new_year_weekday(input);

	cout << result << '\n';*/

	int input_year, input_month;

	string result;

	cout << "年を入力\n";

	cin >> input_year;
	
	cout << "月を入力\n";

	cin >> input_month;

	result = get_year_month_weekday(input_year, input_month);

	cout << result << '\n';

	

	std::cin.ignore();
	std::cin.get();

	return 0;
}

bool isUruu(int year) {

	return (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));

}

static string get_new_year_weekday(int year) {
	const array<string, 7> weekdays  = { "日曜日","月曜日", "火曜日", "水曜日", "木曜日", "金曜日", "土曜日" };
	int days = 0;
	for (int i = 1900; i < year; i++) {
		if (isUruu(i)) {
			days += 366;
		}
		else {
			days += 365;
		}
		
	}
	return weekdays[(days+1) % 7];

}
int get_month_days(int year, int month) {
	if (month == 2) {
		return isUruu(year) ? 29 : 28;
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11) {
		return 30;
	}
	return 31;
}

string get_year_month_weekday(int year, int month) {
	const array<string, 7> weekdays = { "日曜日","月曜日", "火曜日", "水曜日", "木曜日", "金曜日", "土曜日" };
	int days = 0;
	for (int i = 1900; i < year; i++) {
		if (isUruu(i)) {
			days += 366;
		}
		else {
			days += 365;
		}

	}
	for (int i = 1; i < month; i++) {
		days += get_month_days(year, i);
	}
	
	

	return weekdays[(days + 1) % 7];
}