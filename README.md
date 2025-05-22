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

//
unnamed parameter:
void doSomething(int) // ok: unnamed parameter will not generate warning
{
}
unreferenced parameters:
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

### プリプロセッサ preprocessor

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
#define RIBUNKI 55
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

### 配列 array

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

//
#include <iostream>
#include <vector>     // std::vector を使う場合
#include <array>      // std::array を使う場合
#include <algorithm>  // std::sort を使うため

int main() {
    //--- Cスタイル配列の場合 ---
    int arr[] = {5, 2, 8, 1, 9, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    std::sort(arr, arr + n); // 配列の先頭と末尾の次を指すポインタを指定

    std::cout << "ソート後のCスタイル配列: ";
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    //--- std::vector の場合 ---
    std::vector<int> vec = {7, 3, 0, 6, 2};
    std::sort(vec.begin(), vec.end()); // begin() と end() イテレータを指定

    std::cout << "ソート後のstd::vector: ";
    for (int x : vec) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    //--- std::array の場合 ---
    std::array<int, 5> arr_std = {4, 1, 7, 3, 5};
    std::sort(arr_std.begin(), arr_std.end()); // begin() と end() イテレータを指定

    std::cout << "ソート後のstd::array: ";
    for (int x : arr_std) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}

//
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

### 文字列

```c++
//初期化
char str[4]{ 'A', 'B', 'C', '\0'};
const char str[4] = "ABC";

//ポインターで扱う
const char* str = "hello";
std::cout << *str << '\n';//h
std::cout << str << '\n';//hello --> std::cout は const char* を受け取ると、そのポインタが指す ヌル終端文字列を文字列として表示します。
std::cout << str[1] << '\n';//e
str++;
std::cout << *str << '\n';//e
std::cout << str << '\n';//ello
std::cout << str[1] << '\n';//l
#include <cstring>
std::size_t len = strlen(str);//len=5;hello /nを除いて

```
