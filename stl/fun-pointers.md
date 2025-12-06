# C++ Parameter Passing & Competitive Programming Notes

## 1\. Quick Comparison Table

| Method | Syntax | Can modify original? | Copies data? | Analogies |
| :--- | :--- | :--- | :--- | :--- |
| **Pass by Value** | `func(int x)` | ❌ NO | ✅ Yes | "I give you a **copy**." |
| **Pass by Pointer** | `func(int* p)` | ✅ YES | ❌ No | "I give you the **address**." |
| **Pass by Reference** | `func(int& x)` | ✅ YES | ❌ No | "I give you the **variable itself**." |

-----

## 2\. Code Example

```cpp
#include<bits/stdc++.h>
using namespace std;

// 1. Pass by Value (Copy)
// Note: 'x' is a distinct copy. Changing 'x' does NOT change 'a'.
void byValue(int x){
    x = 99; 
}

// 2. Pass by Pointer (Address)
// Note: We go to the address of 'x' and change data there.
void byPointer(int* x){
    *x = 200;
}

// 3. Pass by Reference (Alias)
// Note: 'x' is just another name for the original variable.
void byReference(int &x){
    x = 100;
}

int main(){
    int a = 10;

    // --- Testing Value ---
    byValue(a);
    cout << a << endl;   // Output: 10 (Original did not change)

    // --- Testing Pointer ---
    byPointer(&a);       // Must pass address (&a)
    cout << a << endl;   // Output: 200 (Original changed)

    // --- Testing Reference ---
    byReference(a);      // Clean syntax, no symbols needed here
    cout << a << endl;   // Output: 100 (Original changed)
    
    return 0;
}
```

-----

## 3\. Detailed Breakdown

### A. Pass by Value

  * **Mechanism:** Makes a copy of the variable in the function.
  * **Effect:** The function changes only the local copy (`x`), NOT the original (`a`).
  * **When to use:**
      * When you don't want the original data to change.
      * When the variable is small (primitives) and cheap to copy.

### B. Pass by Pointer

  * **Mechanism:** We pass the **address** of the variable.
  * **Effect:** The function can modify the original variable via dereferencing (`*x`).
  * **Status:** Not preferred in modern C++ (mostly used in legacy C code). Pass by Reference is usually better.

### C. Pass by Reference (⭐ Preferred)

  * **Mechanism:** The parameter becomes an **alias** (another name) for the original variable.
  * **Effect:** The function modifies the original variable directly.
  * **When to use:**
      * When passing STL containers (Vectors, Maps, Strings).
      * When you want the original variable to be modified.

-----

## 4\. Competitive Programming (CP) Guide

### 1\. Primitives (`int`, `char`, `bool`, `double`)

  * **Default Behavior:** Pass-by-Value.
  * **Performance:** Fast (registers/stack).
  * **CP Strategy:** **Keep using Pass-by-Value.**
      * There is no speed benefit to passing an `int` by reference.
      * Only use `&` if you specifically need the logic to update the variable (e.g., a function `void updateMax(int &current_max)`).
        
        ```cpp
        // DEFAULT & CP (Same for primitives)
        void solve(int n) { 
            // 'n' is a copy. Changing it won't affect the outside 'n'.
            // This is fast enough.
        }
        ```


### 2\. STL Containers (`vector`, `string`, `set`, `map`)

  * **Default Behavior:** Pass-by-Value (Deep Copy).

      * **Danger:** C++ copies every single element. If a vector has $10^6$ elements, the function copies all of them.
      * **Result:** This is the \#1 cause of **TLE (Time Limit Exceeded)**.

  * **CP Strategy:** **Always use Reference.**

      * To modify data: `void func(vector<int> &v)`
      * To read-only (Standard CP practice): **Use `const` with `&`**.
      * *This passes a "view" of the data without copying.*

    <!-- end list -->

    ```cpp
    // Best Practice for CP
    void check(const vector<int> &v) { 
         // 'v' is a reference (fast). 
         // 'const' prevents accidental changes.
    }
    ```

### 3\. C-Style Arrays (`int arr[100]`)

  * **Default Behavior:** Decays to Pointer.

      * **Special Case:** You cannot pass a C-array by value. It always passes the address of the first element (`int*`).
      * **Warning:** The function loses size information (`sizeof(arr)` stops working inside the function).

  * **CP Strategy:** **Declare Arrays Globally.**

      * Passing C-arrays is messy because you must pass the size `N` manually.
      * In CP, declare arrays globally to avoid stack overflow and passing issues.

    <!-- end list -->

    ```cpp
    const int MAXN = 1e5+5;
    int arr[MAXN]; // Global declaration

    void solve() {
        arr[0] = 1; // Access directly
    }
    ```

-----

