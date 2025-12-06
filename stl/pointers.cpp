#include<bits/stdc++.h>
using namespace std;



int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt" , "r",stdin);
freopen("output.txt" , "w",stdout);
#endif

    // pointer : A variable that stores the address of another variable.
    int x = 10;
    int* p = &x;

    // x -> value 10
    // &x -> address of x.
    // p -> holds address of x.
    // *p -> value at that address : 10


    // change the value via pointer.
    // rule : 
    //     If you change *p, you also change the variable it points to.

    cout << "org val of x : " << x << endl;
    *p = 20;
    cout << "mod value of x : " << x << endl;



// ---------------------------------------------------------------------------------
// WHAT NOT TO DO :
    //    int* p;      // p points to a garbage location // dangerous.
    //    *p = 10;    // CRASH / undefined behavior


// WHAT CAN DO : 
    int* p1 = NULL; 
    int* p2 = nullptr;
    int* p3 = 0;

    // cout << *p1;          // CRASH.
    // cout << p1;           // safe
    // if (p != nullptr) {   // safe
    //     cout << *p;
    // }



    int& ref = x;
    cout << ref << endl;
    
    return 0;
}
