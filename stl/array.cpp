#include<bits/stdc++.h>
using namespace std;

// declaring an array.
// all elements will be 0;
array<int , 3> arr;

int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt" , "r",stdin);
freopen("output.txt" , "w",stdout);
#endif

    //initialising an array.
    array<int , 3> nums;     // all garbage values.
    int nums1[3];           // all garbage values.
    

    array<int , 5> nums2 = {1,2};  // {1,2,0,0,0}.
    array<int , 5> nums3 = {0};    // {0,0,0,0,0}.
    int nums4[5] = {1,2};  // {1,2,0,0,0}.
    int nums5[5] = {0};    // {0,0,0,0,0}.

    //filling an array with -1;
    array<int , 5> nums6;
    nums6.fill(-1);


    // accessing elements : 
    // array<int , 5> -> nums.at(i)  ... will throw index out of bound error.
    // int nums[5] -> nums[i] ... will not throw index out of bound error
    
    
    //size 
    nums.size();

    // first element 
    nums.front();

    // last element;
    nums.back();

    

    // ITERATORS ... arr = (x) (x + 1) (x + 2) (x + 3)   // these are array indexes.
    // these will point to.
    // begin() -> x
    // end() -> right after (x + 3)
    // rbegin() -> (x + 3)
    // rend() -> right before (x)

    array<int , 4> arr = {0};
    
    // for each loop..... loop from front to end.
    // works for string also.
    for(auto it : arr){
        cout << it << " ";
    }

    return 0;
}
