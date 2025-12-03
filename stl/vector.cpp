// for array of int , double , char etc.
//     inside main() -> max size = 10^6
//     globally      -> max size = 10^7
// for array of bool
//     inside main() -> max size = 10^7
//     globally      -> max size = 10^8



#include<bits/stdc++.h>
using namespace std;



int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt" , "r",stdin);
freopen("output.txt" , "w",stdout);
#endif

    // VECTOR
    // like ArrayList.

    vector<int> v1;            // {}
    vector<int> v2(5 , 0);     // size 5, all values = 0
    vector<int> v3(5, 10);     // size 5, all values = 10
    vector<int> v4 = {1,2,3};  // initializer list

// --------------------------------------------------------------

    // ADDING ELEMENTS :-

    //adding to the back;
    v1.push_back(0);  // {0}
    v1.push_back(2);  // {0,2}
    v1.emplace_back(8);    // takes less time than push_back.

    // Inserting at specific position.
    v1.insert(v1.begin() + 1, 99);  // insert 99 at index 1


// ---------------------------------------------------------------------------

    // REMOVING ELEMENTS :- 

    //removing from the back
    v2.pop_back();

    // remove from specific position :
    v2.erase(v2.begin() + 2);     // removes element at index 2

    //remove a range
    v2.erase(v1.begin(), v1.begin()+3); // remove first 3 elements

    // clear whole vector.
    v2.clear();


// ------------------------------------------------------------------

    // ACCESSING ELEMENTS :-

    // bound not safe.
    cout << v2[0];

    // bound safe.
    cout << v2.at(8);

    // first element.
    cout << v1.front();

    //last element;
    cout << v1.back();


// ------------------------------------------------------------------------   
    
    // ITERATOR
    for(auto it : v1){
        cout << it<< " ";
    }

// ------------------------------------------------------------------------

    // SORTING

    // asc
    sort(v1.begin() , v1.end());
    // desc
    sort(v1.rbegin() , v1.rend());


// ---------------------------------------------------------------------

    // EXTRA
    
    //size
    v1.size();

    //capacity 
    v1.capacity();

// -----------------------------------------------------------------

    // copy whole vec5 into vec6(new)
    vector<int> v5(5,9);

    vector<int> v6(v5.begin() , v5.end());    // way 1
    vector<int> v7(v5);     //way 2

    for(auto it : v6){
        cout << it;
    }
    cout << endl;


    // copy 0-3 of v5 into v8
    vector<int> v8(v5.begin() , v5.begin() + 3);
    for(auto it : v8){
        cout << it;
    }



// ----------------------------------------------------------------------

    // 2-d vectors.

    // definition.
    vector<vector<int>> v9;   // empty vector.
    
    // initialised : 
    vector<vector<int>> v10 = {
        {1,2,3},
        {4,5,6}
    };

    
    // vector of size 10 x 20 filled with 99
    vector<vector<int>> v11(10 , vector<int> (20 , 99));

    // vector of size 10 x 20 x 30 filled with 100

    vector<vector<vector<int>>> v12(10 , vector<vector<int>> (20 , vector<int> (30 , 100)));
    
    
    return 0;
}
