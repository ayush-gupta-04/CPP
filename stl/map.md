Here are your formatted notes for `std::map` and `std::unordered_map`. I have kept the theory crisp and focused on the differences that matter in Competitive Programming.

-----

# C++ STL: Maps (`std::map` vs `std::unordered_map`)

Maps are associative containers that store elements as **Key-Value Pairs** (`{key, value}`).

### 1\. `std::map` (Ordered Map)

#### **Theory & Internals**

  * **Structure:** Stores `{key, value}` pairs.
  * **Ordering:** Keys are **sorted** (ascending by default).
  * **Uniqueness:** Keys are **unique**.
  * **Implementation:** Self-Balancing BST (Red-Black Tree).
  * **Time Complexity:** $O(\log N)$ for almost all operations.

#### **Access & Insertion (Crucial for CP)**

**1. The `[]` Operator (Subscript)**
Functions as "Find or Create".

  * If key exists: Returns reference to value (overwrites).
  * If key missing: **Creates** the key with a default value ($0$ for int, `""` for string).

<!-- end list -->

```cpp
map<int, int> mp;

mp[2] = 10;       // Inserts {2, 10}
mp[3] = mp[3] + 1; // Creates {3, 0}, then increments to {3, 1}
mp[7];            // Creates {7, 0} automatically. Be careful!
```

**2. The `insert()` Function**
Strict insertion. Does **not** overwrite if key exists.

```cpp
mp.insert({2, 11}); // Ignored! Key 2 already exists.
```

#### **Lookup & Modifiers**

```cpp
// 1. Find (Returns iterator)
auto it = mp.find(2);
if(it != mp.end()) {
    cout << it->first << " -> " << it->second; 
}

// 2. Count (Returns 1 or 0)
// Best way to check existence without creating a default element.
if(mp.count(2)) { /* Key exists */ }

// 3. Erase
mp.erase(3);          // By Key
mp.erase(mp.begin()); // By Iterator

// 4. Utility
mp.size();   // Number of elements
mp.clear();  // Remove all elements
mp.empty();  // Check if empty
```

#### **Ordered Queries**

Since keys are sorted, we can use binary search logic:

  * `lower_bound(k)`: Iterator to first key $\ge k$.
  * `upper_bound(k)`: Iterator to first key $> k$.

-----

### 2\. `std::unordered_map` (Hash Map)

#### **Theory & Internals**

  * **Ordering:** None (Random/Undefined).
  * **Implementation:** Hash Table.
  * **Time Complexity:** $O(1)$ Average, $O(N)$ Worst Case (collisions).
  * **Missing Features:** No `lower_bound` or `upper_bound`.
  * **Keys:** Keys of unordered map can only be single element .. it cannot have pair<int,int> as keys.

<!-- end list -->

```cpp
unordered_map<int, int> mpp;

// Syntax is identical to map for insert/find/erase
mpp[2] = 5; 
mpp.insert({3, 10});
```

-----

### Summary Comparison

| Feature | `map` | `unordered_map` |
| :--- | :--- | :--- |
| **Order** | Sorted | Random |
| **Backend** | Red-Black Tree | Hash Table |
| **Time (Avg)** | $O(\log N)$ | $O(1)$ |
| **Time (Worst)** | $O(\log N)$ | $O(N)$ |
| **Use Case** | Need sorted data / Range queries | Need Speed / Just checking existence |

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
    mp[2] = 10;           // inserts if not present, overwrites if present.
    mp[3] = mp[3] + 1;    // it creates {3 -> 0} first and then updates mp[3].
    mp[7];                // it will create {7 -> 0} automatically.

    // insert function.
    mp.insert({2,11});   // inserts {2 -> 11} if 2 not exist....ignore if key = 2 exist.




    // finding keys.
    // to get value for a key.
    auto it = mp.find(2);      // returns the iterator...or end() otherwise.
    if(it != mp.end()){
        cout << it->first << " -> " << it->second << endl;
    }

    // to know if a key exist or not.
    mp.count(2);    
    // returns 0 -> if key not exist.
    // returns 1 -> if key exists.



    mp.erase(3);        // by key
    mp.erase(mp.begin());        // by iterator
    mp.clear();          // remove all
    mp.size();        // to get the size.
    mp.empty();     // to check if empty.




    // iteration in order.
    for(auto it : mp){
        cout << it.first << " -> " << it.second << endl;
    }



    auto it1 = mp.lower_bound(2);  // first element with key >= x
    auto it2 = mp.upper_bound(3); // first element with key > x




    // Unordered map :
    unordered_map<int , int> mpp;
    // 1. no order of the keys.
    // 2. almost O(1) in all cases.
    // 3. O(n) in worst cases.
    // 4. No lower_bound and upper_bound queries
    // 5. all functions are the same.

    return 0;
}
```

**Would you like to move on to `std::stack`, `std::queue`, or `priority_queue` next?**
