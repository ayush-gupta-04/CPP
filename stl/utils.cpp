#include<bits/stdc++.h>
using namespace std;

int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt" , "r",stdin);
freopen("output.txt" , "w",stdout);
#endif

    // arrays , vector.
    int n = 5;
    int arr[n] = {4,3,5,2,1};
    vector<int> vec = {3,2,4,1,5};

    // 1. SORTING
    sort(arr,arr + n);               // name of the array is the start iterator itself.
    sort(vec.begin() , vec.end());

    // 2. REVERSING
    reverse(arr , arr + n);
    reverse(vec.begin() , vec.end());

    
    // 3. MAX & MIN Element.
    int max = *max_element(arr , arr + n);   // don't forget the *
    int min = *min_element(arr , arr + n);

    int maxv = *max_element(vec.begin() , vec.end());
    int minv = *min_element(vec.begin() , vec.end());

    // 4. Count of an element.
    //    count(start , end , x).
    int cntv = count(vec.begin() , vec.end(), 1);  
    int cnt = count(arr , arr + n , 1); 
    
    // 5. Binary search.
    //    -> true -> if x present.
    //    -> false -> if x not present;
    bool res = binary_search(arr , arr + n , 0);
    bool resv = binary_search(vec.begin() , vec.end(), 1);

    // 6. Lower and Upper bound.
    //    -> lower_bound : returns the first iterator >= x....else end() iterator.
    //    -> upper_bound : returns the first iterator > x . . . else end() iterator.

    auto lb1 = lower_bound(arr , arr +n , 4);
    int idx1 = lb1 - arr;

    auto lb2 = lower_bound(vec.begin() , vec.end() , 3);
    int idx2 = lb2 - vec.begin();


    auto ub1 = upper_bound(arr , arr + n , 3);

    

    // 7. Next Permutation.
    //    -> change the permutation to next permutation and returns true.
    //    -> returns false if cannot next permute.
    //    -> O(N) time complexity.
    
    // finding all the permutations of an array.
    sort(arr , arr + n);
    do
    {
        for(auto it : arr){
            cout << it <<" ";
        }
        cout << endl;
    } while (next_permutation(arr , arr + n));


    // 8. we also have the prev_permutation().

    return 0;
}




