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

### \n vs std::endl

```c++
std::endl 改行　と　フラッシュバッファー(fluse buffer) \n より slow
\n お勧め
 std::cout << name << '\n';シングルクォート
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
ポインター
    動的メモリを管理するとき。newやdeleteでメモリを動的に確保・解放するときはポインターが必須。
  	ヌルを許容したいとき。ポインターは「何も指していない状態(null)を表せるので、存在しない可能性がある対象をあつかう場合に便利
    
    
    動的メモリ管理をするとき
newやdeleteでメモリを動的に確保・解放するときはポインターが必須。
例：動的配列やツリー構造の実装など。

ヌル（nullptr）を許容したいとき

ポインターは「何も指していない状態（null）」を表せるので、存在しない可能性がある対象を扱う場合に便利。

ポインター演算（アドレスの加算など）を使うとき

メモリ上の連続した要素を移動したり、バッファを操作するとき。

複数のアドレスを切り替えたいとき

ポインター変数は指す対象をあとから変えられるので、柔軟に使いたい場合。

C言語や低レベルなコードとの互換性が必要なとき

C言語は参照を持たないので、Cとの連携や古いコードの利用にポインターを使う。

参照を使う場合
関数の引数や戻り値で「実体を直接操作」したいとき

参照は使いやすくて安全なので、関数に渡すときはよく参照が使われる。
例：

cpp
コピーする
編集する
void increment(int& x) { x++; }
ポインターのヌルチェックやアドレス操作が不要な場合

参照は必ず有効な実体を指すので、ヌルや無効チェックを減らせる。

コードを簡潔にしたいとき

参照は変数のように使えるので読みやすい。

初期化後に別の対象に参照を変えたくない場合

参照は一度決めたら変えられないので、意図が明確になる。
    
    
```

### sizeof()

```c++
return バイト数
```

### ポインター && 配列

```c++
int h[5] = {10, 11, 12, 13, 14};
int* p = &h[0];//ポインターpはhの先頭要素ｎ
h = &h[0];//C/C++では、配列名は暗黙(あんもく)的に先頭の要素へのポインタに変換されます。
*(h + n) == h[n];
*(p + n) == p[n]; // p[n]は*(p + n)のシンタックスシュガー(Syntax sugar);
*p == h[0];//10
p++;
*p == h[1];//11

p[4] = 400;//h[4] = 400;

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

