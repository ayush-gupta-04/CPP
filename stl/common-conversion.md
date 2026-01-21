---

# ✅ C++ Type Conversion – One-Page Cheat Sheet

---

## 🔹 Integer ↔ String

```cpp
int x = 42;
string s = to_string(x);

int y = stoi("42");
long l = stol("42");
long long ll = stoll("42");
float f = stof("3.14");
double d = stod("3.14");
```

---

## 🔹 Char ↔ Integer (ASCII)

```cpp
char c = 'A';
int x = static_cast<int>(c);   // 65

int y = 65;
char d = static_cast<char>(y); // 'A'
```

---

## 🔹 Digit Char ↔ Integer (0–9)

```cpp
char c = '7';
int x = c - '0';   // 7

int y = 7;
char d = y + '0';  // '7'
```

---

## 🔹 Char ↔ String

```cpp
char c = 'A';
string s(1, c);

string t = "Hello";
char d = t[0];
```

---

## 🔹 Integer ↔ Binary String

### int → binary

```cpp
#include <bitset>

int x = 10;
string bin = bitset<8>(x).to_string();
// "00001010"
```

### binary → int

```cpp
int y = stoi("1010", nullptr, 2);
```

---

## 🔹 String (Base-N) → Integer

```cpp
int dec = stoi("42", nullptr, 10);
int bin = stoi("1010", nullptr, 2);
int oct = stoi("77", nullptr, 8);
int hex = stoi("FF", nullptr, 16);
```

---

## 🔹 C-String ↔ C++ String

```cpp
char cstr[] = "hello";
string s = cstr;

string t = "world";
const char* p = t.c_str();
```

---

## 🔹 Safe Casting (Preferred)

```cpp
int x = static_cast<int>('A');
double d = static_cast<double>(x);
```

---

## 🔹 Stream-Based (Flexible, Slower)

```cpp
#include <sstream>

int x = 42;
stringstream ss;
ss << x;

string s;
ss >> s;
```

---

## 🚀 Most-Used Summary

| Conversion      | Use This                 |
| --------------- | ------------------------ |
| int ↔ string    | `to_string`, `stoi`      |
| char ↔ int      | `static_cast<int>`       |
| digit ↔ int     | `+ '0'`, `- '0'`         |
| int ↔ binary    | `bitset`, `stoi(..., 2)` |
| string ↔ number | `stoi`, `stod`           |
| string ↔ char*  | `c_str()`                |

---

## ⚠️ Common Pitfalls & Gotchas

### ❌ 1. Forgetting `'0'` when converting digits

```cpp
char c = '5';
int x = c;      // WRONG → 53
int y = c - '0';// CORRECT → 5
```

---

### ❌ 2. `stoi` throws exceptions

```cpp
stoi("abc");    // throws invalid_argument
stoi("999999999999"); // throws out_of_range
```

👉 In competitive programming, inputs are usually safe — but in production code, wrap with `try/catch`.

---

### ❌ 3. `c_str()` becomes invalid

```cpp
const char* p = t.c_str();
t += "!";
printf("%s", p); // UNDEFINED BEHAVIOR
```

👉 `c_str()` is only valid **until the string is modified**.

---

### ❌ 4. Binary strings with leading bits

```cpp
bitset<8>(256); // becomes 00000000
```

👉 `bitset<N>` **truncates higher bits** silently.

---

### ❌ 5. Signed vs unsigned char confusion

```cpp
char c = 200;
int x = c; // may become negative
```

👉 Use `unsigned char` if dealing with raw byte values.

---

### ❌ 6. `stringstream` is slow

* Avoid in tight loops
* Prefer `stoi`, `to_string`, or manual parsing in CP

---

### ❌ 7. Mixing bases accidentally

```cpp
stoi("010");          // base 10 → 10
stoi("010", 0, 8);    // base 8  → 8
```

👉 Always specify the base if it matters.

---

### ❌ 8. Assuming `char` is numeric

```cpp
char c = 5;
cout << c; // prints non-printable character
```

👉 `char` is a **character type**, not a number.

---

⚠️ **Reminder:** This file assumes:

```cpp
using namespace std;
```
