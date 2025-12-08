#include<bits/stdc++.h>
using namespace std;


// COMPARATOR FUNCTION.
// to sort in asc order.
bool comp(int a ,int b){
    return a <= b;
}

// return true -> a , b ... they are already in sorted order .. no swap.
// return false -> a , b .. they should be swapped.


// Comparator Class
class Compare{
public : 
    // for desc order.
    bool operator()(int a , int b){
        return a <= b;
    }
};



int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt" , "r",stdin);
freopen("output.txt" , "w",stdout);
#endif

    // arrays , vector.
    int n = 5;
    int arr[n] = {4,3,5,2,1};
    vector<int> vec = {3,2,4,1,5};

    // sort arrays , vector.
    sort(arr , arr + n , comp);
    sort(vec.begin() , vec.end() , comp);
    

    set<int,Compare> st;
    map<int , int , Compare> mp;
    priority_queue<int , vector<int>  , Compare> pq;

    // for Priority Queue : 
    // -> if order is ASC . . . first element < last element.
    // -> top of the pq is the last element always.
    // TL;DR 
    // -> ASC order Comparator : Max Heap.
    // -> DSC order Comparator : Min Heap.

    return 0;
}




