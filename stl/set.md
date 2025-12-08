-----

# C++ STL: The `std::set` Container

The `std::set` is an associative container that stores elements that are **unique** (no duplicates) and **sorted** (ascending order by default). It is implemented using Self-Balancing Binary Search Trees (usually Red-Black Trees).

[Image of binary search tree structure]

### 1\. Initialization and Declaration

To use sets, include the `<set>` header (or `<bits/stdc++.h>`).

```cpp
// 1. Empty set
set<int> st; 

// 2. Set with initial values (will be sorted automatically)
set<int> st1 = {1, 5, 2, 3}; // Stores: {1, 2, 3, 5}
```

-----

### 2\. Modifying the Set (Insert & Delete)

All insertion and deletion operations take **$O(\log N)$** time.

#### **Insertion**

```cpp
st.insert(1);       // Inserts 1
st.insert(5);       // Inserts 5
st.emplace(4);      // Inserts 4 (Slightly faster than insert due to in-place construction)

// Note: If you insert a duplicate, it is simply ignored.
```

#### **Erasure (Deletion)**

Deleting elements can be done by key, by iterator, or by range.

```cpp
// 1. By Iterator
st.erase(st.begin()); // Deletes the first element (smallest)

// 2. By Key
st.erase(3);          // Deletes the value 3 if it exists

// 3. By Range [start, end)
// Note: Set iterators do not support random access (e.g., begin() + 2 is invalid).
// You must use std::next or advance().
auto startIt = st.begin();
auto endIt = next(st.begin(), 2); 
st.erase(startIt, endIt); 
```

-----

### 3\. Traversal

You can iterate through a set using a range-based loop or iterators. The output will always be sorted.

```cpp
for(int element : st1) {
    cout << element << " "; 
}
// Output: 1 2 3
```

-----

### 4\. Lookup and Counting

#### **Find**

Returns an iterator to the element.

```cpp
auto it = st.find(2);

if(it != st.end()) {
    // Found
} else {
    // Not found (points to end)
}
```

#### **Count**

Since sets only contain unique elements, this is the best way to check existence.

```cpp
if (st.count(2)) {
    // Returns 1 -> Element exists
} else {
    // Returns 0 -> Element does not exist
}
```

-----

### 5\. Capacity and Utility

```cpp
// Returns the number of elements in the set
int s = st.size(); 

// Removes all elements from the set
st.clear();
```

-----

### 6\. Order-Based Queries (Binary Search)

This is one of the most powerful features of `std::set`. These operations run in **$O(\log N)$**.

| Function | Definition | Logic |
| :--- | :--- | :--- |
| **`lower_bound(x)`** | Iterator to first element **$\ge$ x** | If $x$ exists, points to $x$. If not, points to the next larger number. |
| **`upper_bound(x)`** | Iterator to first element **$>$ x** | Always points to the element *strictly after* $x$. |

```cpp
// Example Set: {10, 20, 30, 40}

auto it1 = st.lower_bound(20); // Points to 20 (>= 20)
auto it2 = st.lower_bound(25); // Points to 30 (>= 25)

auto it3 = st.upper_bound(20); // Points to 30 (> 20)
auto it4 = st.upper_bound(40); // Points to st.end()
```

> **Note:** If the element is not found (or if the bound exceeds the largest element), these functions return `st.end()`.

-----

### 7\. Custom Comparator (Descending Order)

By default, sets sort in ascending order (`std::less<int>`). You can change this to descending order.

```cpp
// Stores elements as: {5, 4, 3, 2, 1}
set<int, greater<int>> st_desc; 
```

-----

### Summary of Time Complexities

  * **Insert:** $O(\log N)$
  * **Find/Count:** $O(\log N)$
  * **Erase:** $O(\log N)$
  * **Lower/Upper Bound:** $O(\log N)$

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

    // declaring set.
    set<int> st;               // empty one.
    set<int> st1 = {1,2,3};    // having initial elements.


    // insert elements .
    st.inser(1);
    st.insert(5);
    st.emplace(4);    // a bit faster than insert().


    // printing the set.
    for(int it : st1){
        cout << it << " ";
    }

    // erasing elements.

    st.erase(st.begin());     // st.erase(iterator).
    st.erase(st.begin() , st.begin() + 2);     // st.erase(startIterator , endIterator).
    st.erase(3);         // st.erase(key).



    // finding elements.
    auto it = st.find(2);
    // Returns iterator to x if found
    // Returns st.end() otherwise



    // counting  the elements.
    // best to check if element exist or not.
    st.count(2);
    // return 1 -> if 2 exist.
    // return 0 -> if 2 not exist.


    //return the size of the set.
    st.size();



    // clear the whole set.
    st.clear();




    // Order-Based Queries (Very important!)

    // 1. lower_bound(x)
    //    -> Returns iterator to first element ≥ x
    //    -> if not then returns st.end().
    auto it = st.lower_bound(x);


    // 1. upper_bound(x)
    //    -> Returns iterator to first element > x
    //    -> if not then returns st.end().
    auto it = st.upper_bound(x);



    // for descending order set.
    set<int, greater<int>> st_desc;




    
    return 0;
}
```

**Would you like me to format any other raw code snippets for you?**
