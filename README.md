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
bool isDecimal(const std::string& s) {
	size_t i = 0;
	bool pointSeen = false;

	if (s[0] == '-' || s[0] == '+') i = 1;
	if (i == s.size()) return false;

	for (; i < s.size(); ++i) {
		if (s[i] == '.') {
			if (pointSeen) return false;
			pointSeen = true;
		}
		else if (!std::isdigit(s[i])) {
			return false;
		}
	}
	return pointSeen;
}
```

