-----

# C++ STL: The `std::unordered_set` Container

The `std::unordered_set` is an associative container that stores **unique** elements in **no particular order**. Unlike `std::set`, it is not implemented using trees, but rather using **Hash Tables**.

### 1\. Theory: Why and When to Use?

#### **Internal Working**

  * It uses a **Hash Table**.
  * Every element is passed through a **Hash Function** which generates a generic "key" (bucket index) where the element is stored.
  * If two elements generate the same hash (a "collision"), they are usually stored in a linked list at that specific bucket (Chaining).

#### **When to use `unordered_set` over `set`?**

Use `unordered_set` when:

1.  **Order does not matter:** You just need to store elements and check if they exist.
2.  **Speed is critical:** You need faster than $O(\log N)$ performance.
3.  **No Range Queries:** You do not need `lower_bound`, `upper_bound`, or print in sorted order.

#### **Time Complexity Analysis**

| Operation | Average Case | Worst Case | Why Worst Case? |
| :--- | :--- | :--- | :--- |
| **Insert** | $O(1)$ | $O(N)$ | Many Hash Collisions (all elements map to same bucket). |
| **Find/Count** | $O(1)$ | $O(N)$ | Poor Hash Function or resizing. |
| **Erase** | $O(1)$ | $O(N)$ | same as above. |

> **Note:** The worst case $O(N)$ is extremely rare in competitive programming if a good hash function is used (or the default one for standard types). For most practical purposes, treat it as **$O(1)$**.

-----

### 2\. Initialization and Syntax

To use it, include `<unordered_set>` (or `<bits/stdc++.h>`).

```cpp
// 1. Empty unordered_set
unordered_set<int> st; 

// 2. Initial elements (Order inside will be random/hashed)
unordered_set<int> st1 = {1, 2, 3}; 
```

-----

### 3\. Basic Operations

#### **Insertion ($O(1)$ avg)**

```cpp
st.insert(1); 
st.insert(5); 
st.emplace(4); // Slightly faster
```

#### **Traversal**

**Warning:** The output order is undefined and random. It depends on the hash values.

```cpp
for(int it : st1) {
    cout << it << " "; // Output might be "3 1 2" or "1 3 2", etc.
}
```

#### **Erasure ($O(1)$ avg)**

```cpp
st.erase(3); // Deletes element by key
```

-----

### 4\. Lookup and Counting

These are the primary reasons to use this container.

#### **Find**

```cpp
auto it = st.find(2);
if(it != st.end()) {
    // Found
}
```

#### **Count**

Returns 1 if found, 0 if not.

```cpp
if(st.count(2)) {
    // Element exists
}
```

-----

### 5\. Important: What `unordered_set` CANNOT Do

In your raw code, you included sections on `lower_bound`, `upper_bound`, and `greater<int>`. **These do not exist for `unordered_set`.**

  * **No Lower/Upper Bound:** Binary search requires sorted data. Since a hash table is unsorted, `st.lower_bound(x)` will throw a compilation error.
  * **No Custom Sorting:** You cannot pass `greater<int>` to `unordered_set`. If you need a specific order, you **must** use `std::set`.

| Feature | `std::set` | `std::unordered_set` |
| :--- | :--- | :--- |
| **Ordering** | Sorted | Random/Undefined |
| **Implementation** | BST (Red-Black Tree) | Hash Table |
| **Search Time** | $O(\log N)$ | $O(1)$ Average |
| **lower\_bound** | Supported | **Not Supported** |

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
    unordered_set<int> st;               // empty one.
    unordered_set<int> st1 = {1,2,3};    // having initial elements.


    // insert elements .
    st.insert(1);
    st.insert(5);
    st.emplace(4);    // a bit faster than insert().


    // printing the set.
    for(int it : st1){
        cout << it << " ";
    }

    // erasing elements.
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

**Would you like me to clarify how to handle "custom types" (like pairs or structs) inside an `unordered_set`?**
