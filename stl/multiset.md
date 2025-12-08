-----

# C++ STL: The `std::multiset` Container

The `std::multiset` is an associative container that stores elements in **sorted order** (like a set) but allows **duplicate elements**. It is also implemented using Self-Balancing Binary Search Trees (Red-Black Trees).

### 1\. Theory: Why and When to Use?

#### **Key Characteristics**

  * **Sorted:** Elements are always stored in ascending order (by default).
  * **Duplicates Allowed:** Unlike `std::set`, you can store multiple instances of the same value (e.g., `{1, 2, 2, 5}`).
  * **Associative:** Elements are identified by their value.

#### **When to use `multiset`?**

Use it when you need a priority queue-like structure but also need to:

1.  **Search** for arbitrary elements (not just top/bottom).
2.  **Delete** arbitrary elements.
3.  **Traverse** the elements in sorted order.
4.  **Count** frequency of elements dynamically.

#### **Time Complexity**

| Operation | Complexity | Notes |
| :--- | :--- | :--- |
| **Insert** | $O(\log N)$ | Adds duplicate next to existing ones. |
| **Find** | $O(\log N)$ | Finds the *first* occurrence. |
| **Erase (Key)** | $O(\log N + K)$ | **Warning:** Removes **ALL** copies of the key (where $K$ is count). |
| **Erase (Iterator)** | $O(1)$ amortized | Removes **ONE** specific copy. |

-----

### 2\. Initialization and Syntax

```cpp
#include <set> // multiset is defined here

// 1. Empty multiset
multiset<int> ms; 

// 2. Initial elements (Sorted automatically)
multiset<int> ms1 = {1, 5, 5, 2}; // Stores: {1, 2, 5, 5}
```

-----

### 3\. Modifying the Multiset

#### **Insertion**

```cpp
ms.insert(1); 
ms.insert(1); // Duplicates are fine
ms.emplace(2); // Slightly faster
```

#### **Erasure (CRITICAL DIFFERENCE)**

This is the most important part of `multiset` theory. There is a huge difference between erasing by **value** and erasing by **iterator**.

```cpp
// multiset<int> ms = {1, 1, 1, 2};

// Method 1: Erase by Value (Deletes ALL occurrences)
ms.erase(1); 
// Result: {2} -> All 1s are gone!

// Method 2: Erase by Iterator (Deletes ONLY ONE occurrence)
auto it = ms.find(1); // Finds the first '1'
ms.erase(it); 
// Result: {1, 1, 2} -> Only one '1' is removed.
```

-----

### 4\. Lookup and Counting

#### **Find**

Returns an iterator to the **first** element found.

```cpp
auto it = ms.find(3); 
// If {2, 3, 3, 3, 4}, 'it' points to the first '3'.
```

#### **Count**

Returns the number of times an element appears.

```cpp
int cnt = ms.count(3); // Returns 3 for the example above.
```

-----

### 5\. Order-Based Queries

Just like `std::set`, `multiset` supports binary search operations efficiently.

  * **`lower_bound(x)`**: Iterator to first element $\ge x$.
  * **`upper_bound(x)`**: Iterator to first element $> x$.

<!-- end list -->

```cpp
// ms = {10, 20, 20, 30}

auto it = ms.lower_bound(20); // Points to the FIRST 20.
auto it2 = ms.upper_bound(20); // Points to 30.
```

-----

-----

## Appendix: Original Raw Notes

```cpp
#include<bits/stdc++.h>
using namespace std;

int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt" , "r",stdin);
freopen("output.txt" , "w",stdout);
#endif

    // MULTISET :
    // 1. stores duplicates also.
    // 2. Stores in sorted order.


    // initialisation.
    multiset<int> ms;
    multiset<int> ms1 = {1,5,4,3};

    // inserting.
    ms.insert(2);
    ms.insert(3);
    ms.emplace(4);  // a bit fast then insert.



    ms.find(3);     // returns iterator to the first occurance .. end otherwise.
    ms.erase(x);    // deletes all occurances of x.
    ms.erase(ms.begin());    // only erase the first element.
    ms.erase(ms.begin() , ms.begin() + 2) ;   // erase in range.

    ms.count(x);   // count occurances.
    ms.size();    // size of the multiset.
    ms.clear();   // clear whole multiset.

    ms.lower_bound(3);     // returns iterator of first element >= x.
    ms.upper_bound(3);     // returns iterator of first element > x.
    
    return 0;
}
```

**Would you like me to create a comparison table ("Cheat Sheet") showing the differences between `set`, `unordered_set`, and `multiset` side-by-side?**
