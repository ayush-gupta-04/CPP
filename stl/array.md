# C++ Arrays: `std::array` vs. C-Style Arrays

## 1\. Initialization & Memory

How you declare an array determines what values are inside it initially.

| Scope / Method | Syntax | Resulting Values |
| :--- | :--- | :--- |
| **Global** | `array<int, 3> arr;` | **All 0s** (Global memory is zero-initialized). |
| **Local (Empty)** | `array<int, 3> arr;` | **Garbage Values** (Random memory leftovers). |
| **Partial Init** | `array<int, 5> arr = {1, 2};` | `{1, 2, 0, 0, 0}` (Rest are filled with 0). |
| **Zero Init** | `array<int, 5> arr = {0};` | `{0, 0, 0, 0, 0}` (Safest way to init). |

> **Note:** The `fill()` function is exclusive to `std::array`.
> `arr.fill(-1);` sets **all** elements to -1.

-----

## 2\. Accessing Elements: Safety vs. Speed

| Method | Syntax | Safety | Notes |
| :--- | :--- | :--- | :--- |
| **Operator `[]`** | `arr[i]` | ❌ Unsafe | Fast. No bounds checking. If `i > size`, it accesses invalid memory (Undefined Behavior). |
| **Function `.at()`** | `arr.at(i)` | ✅ Safe | Slower. Checks if `i` is valid. Throws `out_of_range` exception if invalid. |

-----

## 3\. Essential Member Functions

Unlike C-style arrays, `std::array` knows its own size and boundaries.

  * **`arr.size()`**: Returns the number of elements.
  * **`arr.front()`**: Returns the **first** element (same as `arr[0]`).
  * **`arr.back()`**: Returns the **last** element (same as `arr[n-1]`).

-----

## 4\. Iterators (The Pointer Logic)

Iterators are objects that point to elements within a container.

Given an array: `[ 10, 20, 30, 40 ]`

  * **`begin()`**: Points to **10** (First element).
  * **`end()`**: Points to the memory **right after 40** (Past-the-last).
      * *Warning:* Never dereference `end()`.
  * **`rbegin()`**: Points to **40** (Last element). "Reverse Begin".
  * **`rend()`**: Points to the memory **right before 10**. "Reverse End".

-----

## 5\. Loops

The `auto` keyword automatically detects the data type.

```cpp
// "For every element 'it' inside 'arr'"
for(auto it : arr) {
    cout << it << " ";
}
```

-----

## 6\. Source Code

```cpp
#include<bits/stdc++.h>
using namespace std;

// 1. GLOBAL DECLARATION
// Rule: Global variables are automatically initialized to 0.
array<int , 3> global_arr; // {0, 0, 0}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt" , "r",stdin);
    freopen("output.txt" , "w",stdout);
#endif

    // 2. LOCAL DECLARATION (Uninitialized)
    // Rule: Local variables contain "garbage" unless initialized.
    array<int , 3> garbage_stl;   // Random values e.g., {412, -8589, 0}
    int garbage_c[3];             // Random values

    // 3. INITIALIZATION TRICKS
    // Rule: If you specify ANY value, the rest become 0.
    array<int , 5> nums2 = {1, 2}; // {1, 2, 0, 0, 0}
    array<int , 5> nums3 = {0};    // {0, 0, 0, 0, 0} (All Zero)
    
    // Works the same for C-style arrays
    int nums4[5] = {1, 2};         // {1, 2, 0, 0, 0}
    int nums5[5] = {0};            // {0, 0, 0, 0, 0}

    // 4. THE FILL FUNCTION (STL Only)
    // Very useful for initializing to -1 or specific values
    array<int , 5> nums6;
    nums6.fill(-1);                // {-1, -1, -1, -1, -1}


    // 5. ACCESS & SAFETY
    // nums6.at(10); // CRASH (Exception): terminates program safely with error message.
    // nums6[10];    // DANGER (Undefined): might read garbage, might crash silently.
    
    // 6. HELPER FUNCTIONS
    cout << "Size: " << nums6.size() << endl;
    cout << "First: " << nums6.front() << endl;
    cout << "Last: " << nums6.back() << endl;

    // 7. ITERATORS & LOOPS
    array<int , 4> arr = {10, 20, 30, 40};
    
    // Range-based for loop (The modern C++ way)
    // 'it' is a COPY of the element. 
    // Use 'auto &it' if you want to modify elements.
    for(auto it : arr){
        cout << it << " ";
    }
    // Output: 10 20 30 40

    return 0;
}
```
