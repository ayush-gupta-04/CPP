Here is a complete guide to `std::bitset`.

### What is `std::bitset`?

A `bitset` is a container that stores bits (0s and 1s). You can think of it as a specialized array of `bools`, but optimized for **space** (uses 1 bit per element instead of 1 byte) and **speed** (allows bitwise operations on the whole set at once).

**Key Restriction:** The size of a bitset must be known at **compile time**.

-----

### 1\. Header and Initialization

Include `<bitset>` or `<bits/stdc++.h>`.

```cpp
// Syntax: bitset<size> variable_name;

// 1. All zeros (0000)
bitset<4> b1; 

// 2. From an Integer (Binary representation of 5 -> 0101)
bitset<4> b2(5); 

// 3. From a String ("1010")
bitset<4> b3("1010"); 
```

> **Note:** Indexing starts from the **Right** (Least Significant Bit).
> If `b = 1010`, then `b[0]` is 0, and `b[3]` is 1.

-----

### 2\. Modifying Bits

You can manipulate individual bits easily.

```cpp
bitset<8> b; // 00000000

// 1. Set (Turn to 1)
b[1] = 1;       // 00000010
b.set(5);       // 00100010 (Sets index 5 to 1)
b.set();        // Sets ALL bits to 1 (11111111)

// 2. Reset (Turn to 0)
b.reset(1);     // 00100000 (Sets index 1 to 0)
b.reset();      // Sets ALL bits to 0 (00000000)

// 3. Flip (Toggle 0->1 or 1->0)
b.flip(1);      // 00000010 (Toggles index 1)
b.flip();       // 11111101 (Toggles ALL bits)
```

-----

### 3\. Bitwise Operations (The Superpower)

This is why `bitset` is powerful. You can perform `&` (AND), `|` (OR), `^` (XOR) on the **entire** bitset at once.

```cpp
bitset<4> A("1010");
bitset<4> B("0101");

cout << (A & B) << endl; // 0000 (AND)
cout << (A | B) << endl; // 1111 (OR)
cout << (A ^ B) << endl; // 1111 (XOR)
cout << (~A)    << endl; // 0101 (NOT)

cout << (A << 1) << endl; // 0100 (Left Shift)
cout << (A >> 1) << endl; // 0101 (Right Shift)
```

-----

### 4\. Important Utility Functions

These functions make checking the state of bits very fast.

| Function | Description | Example (`b = 00101`) |
| :--- | :--- | :--- |
| **`count()`** | Number of set bits (1s) | `b.count()` $\to$ 2 |
| **`any()`** | True if *at least one* bit is 1 | `b.any()` $\to$ true |
| **`none()`** | True if *all* bits are 0 | `b.none()` $\to$ false |
| **`all()`** | True if *all* bits are 1 | `b.all()` $\to$ false |
| **`test(i)`** | Check if bit at index `i` is 1 | `b.test(2)` $\to$ true |
| **`size()`** | Total number of bits | `b.size()` $\to$ 5 |

-----

### 5\. Conversion Functions

Crucial for converting your bit manipulation results back to usable numbers or strings.

```cpp
bitset<8> b(5); // 00000101

// 1. To Integer (unsigned long)
unsigned long num = b.to_ulong(); // Returns 5

// 2. To String
string s = b.to_string(); // Returns "00000101"
```

-----

### 6\. Example: Simple Intersection Problem

Imagine you have two users, and you want to find how many common items they both like.

  * User 1 likes items: 0, 2, 3
  * User 2 likes items: 2, 3, 5

<!-- end list -->

```cpp
#include <iostream>
#include <bitset>
using namespace std;

int main() {
    // Assume we have up to 10 items
    bitset<10> user1; 
    bitset<10> user2;

    // Set preferences
    user1.set(0); user1.set(2); user1.set(3); // 0000001101
    user2.set(2); user2.set(3); user2.set(5); // 0000101100

    // Find intersection (Common items)
    bitset<10> common = user1 & user2; 

    cout << "Common items: " << common << endl; // 0000001100
    cout << "Count: " << common.count() << endl; // 2
    
    return 0;
}
```

### Summary Notes

  * **Size:** Fixed at compile time. `bitset<n> b;` where `n` must be a constant.
  * **Indexing:** `b[0]` is the rightmost bit.
  * **Speed:** Operations are extremely fast (often optimized to single CPU instructions).
  * **Use Case:** Boolean flags, Graph problems (visited sets), Subset operations.

**Would you like to learn about useful built-in bit manipulation functions like `__builtin_popcount` next?**
