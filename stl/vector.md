# C++ STL: Vectors & Memory Limits

## 1\. Competitive Programming Memory Limits

Knowing the maximum array size prevents "Segmentation Fault" (Stack Overflow) or Memory Limit Exceeded.

| Data Type | Location | Max Size (Approx) | Power of 10 |
| :--- | :--- | :--- | :--- |
| **int / char / double** | Inside `main()` (Stack) | 1,000,000 | $10^6$ |
| **int / char / double** | Global (Heap/Data) | 10,000,000 | $10^7$ |
| **bool** | Inside `main()` (Stack) | 10,000,000 | $10^7$ |
| **bool** | Global (Heap/Data) | 100,000,000 | $10^8$ |

> **Rule of Thumb:** Always declare large arrays/vectors **globally** to avoid stack overflow.

-----

## 2\. Vector Initialization

`std::vector` is a dynamic array (like `ArrayList` in Java). It manages memory automatically.

```cpp
// 1. Empty Vector
vector<int> v1;             // {}

// 2. Size and Default Value
vector<int> v2(5, 0);       // {0, 0, 0, 0, 0}
vector<int> v3(5, 10);      // {10, 10, 10, 10, 10}

// 3. Initializer List
vector<int> v4 = {1, 2, 3}; // {1, 2, 3}
```

-----

## 3\. Adding & Removing Elements

| Operation | Syntax | Notes |
| :--- | :--- | :--- |
| **Add to End** | `v.push_back(x)` | Standard way to add. |
| **Add to End (Fast)**| `v.emplace_back(x)`| Faster. Constructs element in-place (no temporary copy). |
| **Insert** | `v.insert(pos, val)` | Slow ($O(N)$). Example: `v.insert(v.begin() + 1, 99);` |
| **Remove Last** | `v.pop_back()` | Removes the last element. |
| **Erase One** | `v.erase(pos)` | Slow ($O(N)$). Shifts elements. |
| **Erase Range** | `v.erase(start, end)` | `[start, end)` (excludes `end`). |
| **Clear** | `v.clear()` | Removes **all** elements. Size becomes 0. |

-----

## 4\. Access & Iteration

### Accessing Data

  * **`v[i]`**: **Unsafe.** Fast. If index is wrong, you get garbage or crash.
  * **`v.at(i)`**: **Safe.** Throws error if index is out of bounds.
  * **`v.back()`**: Fetches the last element.
  * **`v.front()`**: Fetches the first element.

### Iterating

```cpp
// Range-based for loop (Cleaner)
for(auto it : v1) {
    cout << it << " ";
}
```

-----

## 5\. Sorting (Ascending & Descending)

Vectors work seamlessly with `std::sort`.

```cpp
// Ascending (Small -> Big)
sort(v1.begin(), v1.end());

// Descending (Big -> Small)
// Uses reverse iterators
sort(v1.rbegin(), v1.rend()); 
```

-----

## 6\. Copying Vectors

```cpp
vector<int> source(5, 9); // {9, 9, 9, 9, 9}

// 1. Copy Constructor (Deep Copy)
vector<int> copy1(source); 

// 2. Iterator Copy (Full)
vector<int> copy2(source.begin(), source.end());

// 3. Partial Copy (First 3 elements)
vector<int> copy3(source.begin(), source.begin() + 3);
```

-----

## 7\. Multidimensional Vectors (2D & 3D)

This is essentially a "Vector of Vectors".

### 2D Vector

```cpp
// 1. Initialization List
vector<vector<int>> matrix = {
    {1, 2, 3},
    {4, 5, 6}
};

// 2. Size defined with default value
// A 10x20 grid filled with 99
// Syntax: vector<vector<int>> name(rows, vector<int>(cols, value));
vector<vector<int>> grid(10, vector<int>(20, 99));
```

### 3D Vector

```cpp
// 10 x 20 x 30 grid filled with 100
vector<vector<vector<int>>> cube(
    10, 
    vector<vector<int>>(20, vector<int>(30, 100))
);
```

-----

## 8\. Full Source Code

```cpp
#include<bits/stdc++.h>
using namespace std;

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt" , "r",stdin);
    freopen("output.txt" , "w",stdout);
#endif

    // --- INITIALIZATION ---
    vector<int> v1;             
    vector<int> v2(5 , 0);      
    vector<int> v4 = {1,2,3};   

    // --- ADDING ---
    v1.push_back(0); 
    v1.emplace_back(8);         // Faster than push_back
    v1.insert(v1.begin() + 1, 99); 

    // --- REMOVING ---
    v2.pop_back();              // Remove last
    v2.erase(v2.begin() + 2);   // Remove specific index
    
    // Remove range (First 3 elements)
    // Note: Use iterators from the SAME vector (v2)
    v2.erase(v2.begin(), v2.begin() + 3); 
    
    v2.clear(); // Empty the vector

    // --- ACCESSING ---
    // cout << v2[0];      // Unsafe
    // cout << v2.at(8);   // Safe (throws exception)
    cout << v1.front();    // First
    cout << v1.back();     // Last

    // --- SORTING ---
    sort(v1.begin(), v1.end());   // Ascending
    sort(v1.rbegin(), v1.rend()); // Descending

    // --- 2D VECTORS ---
    // 10 Rows, 20 Cols, filled with 99
    vector<vector<int>> v11(10, vector<int>(20, 99));

    return 0;
}
```
