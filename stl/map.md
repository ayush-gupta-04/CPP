# C++ STL: The `std::map` Container

The `std::map` is an associative container that stores elements as **Key-Value Pairs** (`{key, value}`).

### 1\. Theory: Core Concepts

  * **Structure:** Stores pairs where **Key is unique** and **Keys are sorted** (ascending by default).
  * **Internal:** Built on a **Red-Black Tree** (Self-Balancing BST).
  * **Complexity:** Almost all operations (insert, find, erase) are **$O(\log N)$**.

-----

### 2\. Access and Insertion (The `[]` Operator vs `insert`)

This is critical for Competitive Programming.

#### **The `[]` Operator (Subscript)**

Think of this as **"Find or Create"**.

1.  If the key exists: It returns a reference to the value (allows overwriting).
2.  If the key **does not** exist: It **creates** a new entry with a default value (0 for ints, "" for strings) and returns a reference to it.

<!-- end list -->

```cpp
map<int, int> mp;

mp[2] = 10;      // Inserts {2, 10}
mp[3]++;         // Creates {3, 0}, then increments to {3, 1}
mp[7];           // Creates {7, 0} automatically! (Be careful)
```

#### **The `insert` Function**

Strict insertion. It does **not** overwrite if the key exists.

```cpp
mp.insert({2, 11}); // Ignored! Key 2 already exists with value 10.
```

-----

### 3\. Lookup and Traversal

#### **Find**

Returns an iterator pointing to the pair `{key, value}`.

```cpp
auto it = mp.find(2);

if(it != mp.end()) {
    // Access elements using arrow operator
    cout << "Key: " << it->first << ", Value: " << it->second;
}
```

#### **Count**

Checks existence only.

```cpp
if (mp.count(2)) { /* Key 2 exists */ }
```

#### **Iterating**

The map is always traversed in sorted order of keys.

```cpp
for(auto it : mp) {
    // 'it' is a pair<const Key, Value>
    cout << it.first << " -> " << it.second << endl;
}
```

-----

### 4\. Ordered Queries (Binary Search)

Since keys are sorted, we can perform binary search on them.

  * `lower_bound(k)`: Iterator to first key **$\ge k$**.
  * `upper_bound(k)`: Iterator to first key **$> k$**.

<!-- end list -->

```cpp
auto it1 = mp.lower_bound(2); 
```

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

    //MAP : theory.
    // 1. stores {key -> value}.
    // 2. by default , the keys are sorted in ascending order.
    // 3. keys are unique.
    // 4. O(log N) insert/find/erase
    // 5. Built on a balanced BST


    // initialisation.
    map<int , int> mp;


    // insert data.
    // [] operator.
    //    -> used heavily in cp.
    mp[2] = 10;            // inserts if not present, overwrites if present.
    mp[3] = mp[3] + 1;    // it creates {3 -> 0} first and then updates mp[3].
    mp[7];                // it will create {7 -> 0} automatically.

    // insert function.
    mp.insert({2,11});   // inserts {2 -> 11} if 2 not exist....ignore if key = 2 exist.




    // finding keys.
    // to get value for a key.
    auto it = mp.find(2);       // returns the iterator...or end() otherwise.
    if(it != mp.end()){
        cout << it->first << " -> " << it->second << endl;
    }

    // to know if a key exist or not.
    mp.count(2);    
    // returns 0 -> if key not exist.
    // returns 1 -> if key exists.



    mp.erase(3);         // by key
    mp.erase(mp.begin());         // by iterator
    mp.clear();          // remove all




    // iteration in order.
    for(auto it : mp){
        cout << it.first << " -> " << it.second << endl;
    }



    auto it1 = mp.lower_bound(2);  // first element with key >= x
    auto it2 = mp.upper_bound(3); // first element with key > x

    return 0;
}
```

**Would you like me to create a quick comparison between `std::map` and `std::unordered_map` next?**
