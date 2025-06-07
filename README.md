### コンフィギュレーション　configuration

```c++
プロパティ-> c/c++->
    全般->警告レベル: レベル４/w4
    コマンドライン: /Wall /w44365 /utf-8  追加
    外部インクルード-->外部ヘッダーの警告レベル: レベル３
        
言語標準　c++17
言語-->標拠モード: はい/permissive-
```

### 変数の代入と初期化 Variable assignment and initialization

```c++
//list-initialization
int c {0};
int c {};
int a {1}, b{2};


[[maybe_unused]] double pi { 3.14159 };  // Don't complain if pi is unused
[[maybe_unused]] double gravity { 9.8 }; // Don't complain if gravity is unused
[[maybe_unused]] double phi { 1.61803 }; // Don't complain if phi is unused

!!未初期化の変数と未定義の動作 Uninitialized variables and undefined behavior   undefined アンディファインド
    
識別子　変数名　アイデンティファイア　identifier　
キーワード keywords

式　エクスプレッション　expression 
文　ステートメント　statement
宣言　デクラレーション　declaration
定義 デフィニション　definition
演算子 オペレーター operator
```

### iostream

```c++
std::endl 改行　と　フラッシュバッファー(fluse buffer) \n より slow
\n お勧め
 std::cout << name << '\n';シングルクォート
     
#include <iomanip>//setw()
#include <conio.h>//_getch()
(void)_getch();//キーを押すごとに
std::cout << std::left << std::setw(static_cast<int>(rows)) << mahoujin_datas[i][j] << ' ';

std::cerr バッファリングされない（リアルタイムに出力される）という特徴があります
```

### 関数

```c++
//
ネストされた関数 nested function is not legal
プレースホルダー placeholder 仮の値

//
status codes:
    		0: success
    		
            #include <cstdlib>	
            EXIT_SUCESS: 	success  
            EXIT_FAILURE:	failure	 

//
仮引数　parameter
実引数　argument

//unnamed parameter:
void doSomething(int) // ok: unnamed parameter will not generate warning
{
}
//unreferenced parameters:
void doSomething(int count) // warning: unreferenced parameter count
{
    // This function used to do something with count but it is not used any longer
}

//
temporary object テンポラリーオブジェクト 一時的なオブジェクト

//
リファクタリング refactoring コードの整理／内部構造の改善
//

```

### ネーミングコリジョン / ネームスペースズ    naming collision / naming conflict

```c++
//
リンカーが実行する　linker executes
//
スコープ リージョン　scope region
//
```

### プリプロセッサ　preprocessor

```c++
//
directive ディレクティブ　指令

//
marco マクロ
    
//substitution text  サブテキスト(サブスティテューションテキスト) 置換テキスト  ！！！お勧めしない
#define MY_NAME "ribunki"

int main() {
    
	std::cout << MY_NAME << '\n';
}

//Conditional compilation コンディショナルコンパイルレーション 条件付きコンパイル
////ifdef
#define PRINT_RIBUNKI

int main() 
{
#ifdef PRINT_RIBUNKI //==#if defined(PRINT_RIBUNKI)
	std::cout << "RIBUNKI" << '\n';
#endif
#ifdef PRING_OBITO  //==#if defined(PRINT_OBITO)
	std::cout << "OBITO" << '\n';
#endif
}
////ifndef
#define PRINT_RIBUNKI

int main() 
{	
#ifndef PRINT_RIBUNKI //==#if !defined(PRINT_RIBUNKI)
	std::cout << "RIBUNKI" << '\n';
#endif
#ifndef PRING_OBITO  //== #if !defined(PRINT_OBITO)
	std::cout << "OBITO" << '\n';
#endif
}
//#if0  #if1
////
#if 0  //Don't compile anything starting here
	std::cout << "RIBUNKI" << '\n';
#endif //until this point
////
#if 1 //the following code will be compiled
	std::cout << "RIBUNKI" << '\n';
#endif

//
#define RP 0
int main()
{
#ifdef RP
	std::cout << RP << '\n';//0
#endif
}

// 
////ribunki.h
#ifndef RIBUNKI_H//// header guards
#define RIBUNKI_H//// header guards

#define RIBUNKI 55

#endif
////main.cpp
#include "ribunki.h"

int main()
{
#ifdef RIBUNKI
    std::cout << RIBUNKI << '\n';//55
#endif
}

//
```



### header files ヘッダーファイル

```c++
//ヘッダーガード header guards
//標準定義
////add.h
#ifndef ADD_H
#define ADD_H
int add(int a, int b);
#endif
////add.cpp
#include <add.h>
int add(int a, int b) {
    return a + b;
}
////main.cpp
#include <add.h>
add(1, 2);


//#pragma once
////add.h
#pragma once
int add(int a, int b);
////add.cpp
#include <add.h>
int add(int a, int b) {
    return a + b;
}
////main.cpp
#include <add.h>
add(1, 2);
```

### ログファイル logfile

```c++
#include <iostream>
#include <fstream>

int main() {
    std::ofstream error_log("error_log.txt");
    if (!error_log) {
        std::cerr << "ログファイルを開けませんでした" << std::endl;
        return 1;
    }

    // std::cerr をログファイルにリダイレクト
    std::cerr.rdbuf(error_log.rdbuf());

    // このエラーはログファイルに出力される
    std::cerr << "これはエラーメッセージです" << std::endl;

    return 0;
}
```



### constexpr コンステクスプル

```c++
constant expression

//constexpr
The value of the initializer must be known at compile-tim
定数式（constant expression）で使用できる
初期化子の値は コンパイル時に判明している必要があります
constexpr オブジェクトは、コンパイル時または実行時 に評価されることができます。   
//const
オブジェクトの初期化後にその値を変更できない
初期化子の値は、コンパイル時または実行時に判明している可能性があります
const オブジェクトは 実行時に評価される ことができます
    

    
//constexpr 関数
お勧め: ツール関数, 汎用アルゴリズム, パフォーマンスに敏感な処理 //コンパイル時
だめ: 入出力(I/O), システムコール, 動的メモリ確保　//実行時
```

### 構造体　ストラクト struct     ストラクチャー structure

```c++
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
//参照
struct Employee {
	int id {};
	int age {};
	double wage{};
};

void show(Employee &a);
int main() 
{
	Employee ri{33, 33, 300.33};
	Employee bun{ 11, 11, 11111.11 };

	ri = bun;

	Employee* ob = &ri;

	show(ri);

	std::cout << (*ob).age << '\n';

	std::cin.seekg(0);
	std::cin.get();
	return 0;
}
void show(Employee &a) {
	a.age = 888;
}
```

### enum 列挙

```c++
enum Color {
	red,//0
	yellow,//1
	blue,//2
	green,//3
	pink,//4
	black = 10,//default = 5;　10を代入して　＝10 
	white//default = 6; black = 10; white = 11;
};

Color kutsu{ black };
Color shatsu{ white };

std::cout << kutsu << '\n';//10
std::cout << shatsu << '\n';//11

switch (kutsu) {
	case black:
		std::cout << "黒い靴" << '\n';//
		break;
	case white:
		std::cout << "白い靴" << '\n';
		break;
	default:
		std::cout << "グレーの靴" << '\n';
		break;
}
```

### typedef

```c++
typedef unsigned long int Seisuu_long;
Seisuu_long num = 1;//unsigned long int num = 1;
```

### 乱数

```c++
#include <random>
#include <chrono>

////time
std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::chrono::steady_clock::now().time_since_epoch().count()) };
////device
std::mt19937 mt{ std::random_device{}() };

std::uniform_int_distribution die8{ 1, 8 };

std::cout << die8(mt) << '\n';

////Random.h
#ifndef RANDOM_H
#define RANDOM_H

#include <chrono>
#include <random>

namespace Random
{
	
	inline std::mt19937 generate()
	{
		std::random_device rd{};

		std::seed_seq ss{
			static_cast<std::seed_seq::result_type>(std::chrono::steady_clock::now().time_since_epoch().count()),
				rd(), rd(), rd(), rd(), rd(), rd(), rd() };

		return std::mt19937{ ss };
	}

	
	inline std::mt19937 mt{ generate() };

	
	inline int get(int min, int max)
	{
		return std::uniform_int_distribution{ min, max }(mt);
	}

	
	template <typename T>
	T get(T min, T max)
	{
		return std::uniform_int_distribution<T>{min, max}(mt);
	}

	
	template <typename R, typename S, typename T>
	R get(S min, T max)
	{
		return get<R>(static_cast<R>(min), static_cast<R>(max));
	}
}

#endif

#include "Random.h"
#include <cstddef> // for std::size_t
#include <iostream>
std::cout << Random::get<std::size_t>(1, 6u) << '\n';

```

### file I/0

```c++
//getline
#include <string>

std::string strBuf{};
std::getline(std::cin, strBuf);
std::cout << strBuf << '\n';
```





### string

```c++
#include <string>

//str to int   std::stoi(str, &pos, base)
str：変換したい文字列。
pos（省略可能）：変換後に、最初に変換されなかった文字の位置を格納するための size_t 型のポインタ。
base（省略可能）：変換に使用する基数（デフォルトは10進数で、2〜36の値を指定可能）。
std::string str = "123abc";
std::size_t pos;
int num = std::stoi(str, &pos);//pos 3
std::cout << num << '\n';//123

//str to long
std::stol
// str to long long 
std::stoll
    
//int double to string
std::string s = std::to_string(n);

//str.substr(pos, len)

//str.size()

//str.find(sub, start_pos)
std::string str = "hello 234a24";
std::size_t pos = str.find('2', 0);
std::cout << pos << '\n';//6

//str.replace(pos, len, new_string)
std::string str = "hello 234a24";
str.replace(3, 5, "ggggg");
std::cout << str << '\n';//helggggg4a24

//str.empty();

//str.insert(pos, count, char);

//c_str()
str.c_str()

```

### vector ベクター

```c++
//vectorのインデックスはsize_t型
    
```



### isInteger

```c++
#include <string>   // std::string
#include <cctype>   // std::isdigit

static bool isInteger(const std::string& s) {
	if (s.empty()) return false;

	size_t i = 0;
	if (s[0] == '-' || s[0] == '+') i = 1;
	if (i == s.size()) return false;

	for (; i < s.size(); ++i) {
		if (!std::isdigit(static_cast<unsigned char>(s[i]))) return false;
	}
	return true;
}

//size_t
符号なし整数型（unsigned int や unsigned long に近い）で、メモリのサイズや配列のインデックスなどの非負の数値を表すために使用されます
```

### isDecimal

```c++
#include <string>   // std::string
#include <cctype>   // std::isdigit

bool isDecimal(const std::string& s) {
    size_t i = 0;
    bool pointSeen = false;

    if (s.empty()) return false;
    if (s[0] == '-' || s[0] == '+') i = 1;
    if (i == s.size()) return false;

    for (; i < s.size(); ++i) {
        if (s[i] == '.') {
            if (pointSeen) return false;
            pointSeen = true;
        }
        else if (!std::isdigit(static_cast<unsigned char>(s[i]))) {
            return false;
        }
    }
    return pointSeen;
}
```

### Math

```c++
//max min
#include <algorithm> 

int a = 10;
int b = 20;

int maximum = std::max(a, b);  // 20
int minimum = std::min(a, b);  // 10

#include <initializer_list>//イニシャライザリスト(初期化リスト)

auto vals = {10, 5, 20, 15};
int max_val = *std::max_element(vals.begin(), vals.end());
int min_val = *std::min_element(vals.begin(), vals.end());

//
#include <cmath>

////sqrt
double number = 4.0;
std::sqrt(number)//2
    
////pow
std::pow(number, 2);//16.0

////abs //fabs

```



### 配列

```c++
//
添字　インデックス　index

//配列とポインター
int h[5]{10, 11, 12, 13, 14};
int* p = &h[0];//ポインターpはhの先頭要素ｎ
std::cout << p << '\n';//0000004883CFFA38
std::cout << *p << '\n';//10
std::cout << h << '\n'//0000004883CFFA38
h = &h[0];//C/C++では、配列名は暗黙(あんもく)的に先頭の要素へのポインタに変換されます。
*(h + n) == h[n];
*(p + n) == p[n]; // p[n]は*(p + n)のシンタックスシュガー(Syntax sugar);!!!
*p == h[0];//10
p++;
*p == h[1];//11

p[4] = 400;//h[4] = 400;
//アルゴリズム　algorithm 算法

//安定ソート

//バブルソートsort 昇順・降順
///ソート昇順
void sort_array_ascending(int* arr, int size) 
{
	for (int i=0; i < size-1; i++)
	{
		int temp = arr[0];
		for (int j = 0; j < size-i-1; j++)
		{
			if (arr[j] > arr[j+1]) {
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}

	}
}

int datas[]{ 0,1,20,33,4, 2,4,6,7,8,22,3423,23,4,2,1,0 };
size_t size = sizeof(datas) / sizeof(datas[0]);
sort_array_descending(datas, size);
////ソート降順
void sort_array_descending()

//reverse リバース 反転
void sort_array_reverse()
    
//多次元配列
////
int data[2][3] = {
    {0, 1, 2},
    {3, 4, 5}
}
////
in data[2][3][5] {
    {
        {0, 1, 2, 3, 4},
    	{5, 6, 7, 8, 9},
        {10, 11, 12, 13, 14}
    },
    {
        
    	{0, 1, 2, 3, 4},
    	{5, 6, 7, 8, 9},
        {10, 11, 12, 13, 14}
    } 
};

```

### 文字列

```c++
//初期化
char str[4]{ 'A', 'B', 'C', '\0'};
const char str[4] = "ABC";//ABCnull

//ポインターで扱う
const char* str = "hello";
std::cout << *str << '\n';//h
std::cout << str << '\n';//hello --> std::cout は const char* を受け取ると、そのポインタが指す ヌル終端文字列を文字列として表示します。
std::cout << str[1] << '\n';//e
str++;
std::cout << *str << '\n';//e
std::cout << str << '\n';//ello
std::cout << str[1] << '\n';//l

////
#define _CRT_SECURE_NO_WARNINGS
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
	////strncpy
    strncpy(str1, str, sizeof(str1) - 1);//\0を除く
    str1[sizeof(str1) - 1] = '\0';//安全策
    std::cout << str1 << '\n';
	////strncat(str1, str2, str2から追加する最大文字数(\0数えない))
    strncat(str1, str2, sizeof(str2) - 1);//\0を除く
    std::cout << str1 << '\n';
   	////strncmp(str1, str, 比較文字数)
    int hikaku_result = strncmp(str1, str, 10);
	std::cout << hikaku_result << '\n';
    
	std::cin.seekg(0);
	std::cin.get();
	return 0;
}
```

