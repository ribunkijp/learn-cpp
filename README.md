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





### size_t

```c++
符号なし整数型（unsigned int や unsigned long に近い）で、メモリのサイズや配列のインデックスなどの非負の数値を表すために使用されます
```

### string to 整数

```c++
#include <string>

std::string s = "123";
int n = std::stoi(s);  // 文字列を整数に変換
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
#include <cmath>

//sqrt
double number = 4.0;
std::sqrt(number)//2
    
//pow
std::pow(number, 2);//16.0

//abs //fabs


```

### array

```c++
#include <array>

const array<string, 7> weekdays  = { "日曜日","月曜日", "火曜日", "水曜日", "木曜日", "金曜日", "土曜日" };
```

## ポインター vs 参照

```c++
動的メモリを管理するとき。newやdeleteでメモリを動的に確保・解放するときはポインターが必須。
ヌルを許容したいとき。ポインターは「何も指していない状態(null)を表せるので、存在しない可能性がある対象を扱う場合に便利。
ポインター変数は指す対象をあとから変えられるので、柔軟に使いたい場合。参照は一度決めたら変えられないので、意図が明確になる。
言語や低レベルなコードとの互換性が必要なとき、C言語は参照を持たないので、Cとの連携や古いコードの利用にポインターを使う。
```

### sizeof()

```c++
return バイト数
```

### 配列 array

```c++
//
添字　インデックス　index

//配列とポインター
int h[5]{10, 11, 12, 13, 14};
int* p = &h[0];//ポインターpはhの先頭要素ｎ
h = &h[0];//C/C++では、配列名は暗黙(あんもく)的に先頭の要素へのポインタに変換されます。
*(h + n) == h[n];
*(p + n) == p[n]; // p[n]は*(p + n)のシンタックスシュガー(Syntax sugar);!!!
*p == h[0];//10
p++;
*p == h[1];//11

p[4] = 400;//h[4] = 400;
//アルゴリズム　algorithm 算法

//安定ソート

//ソートsort 昇順・降順
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

### max min

```c++
#include <algorithm> 

int a = 10;
int b = 20;

int maximum = std::max(a, b);  // 20
int minimum = std::min(a, b);  // 10

#include <initializer_list>//イニシャライザリスト(初期化リスト)

auto vals = {10, 5, 20, 15};
int max_val = *std::max_element(vals.begin(), vals.end());
int min_val = *std::min_element(vals.begin(), vals.end());

```

