#include<bits/stdc++.h>
using namespace std;

int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt" , "r",stdin);
freopen("output.txt" , "w",stdout);
#endif

// ----------------------------------------------------------------------
// STACK

    // Theory : 
    // 1. O(1) for all operation.
    // 2. lifo ds.

    stack<int> st;

    st.push(2);         // push element to top of the stack.
    st.pop();           // deletes element .. does not return popped val.
    st.top();          // returns the element at top of the stack.
    st.size();        
    st.empty();       // check for emptyness.


    // there is no clear functions.
    // to clear the whole stack.
    while (!st.empty()){
        st.pop();
    }


// -----------------------------------------------------------------------
// QUEUE.

    queue<int> q;   // ex. {1,2,3};
    q.push(1);
    q.push(2);

    q.push(2);
    q.pop();
    q.front();    // prints 1.
    q.back();    // prints 3.
    q.size();
    q.empty();

     // there is no clear functions.
    // to clear the whole stack.
    while (!q.empty()){
        q.pop();
    }



// ----------------------------------------------------------------
// PRIORITY QUEUE.

    // - default is descending order.
    // 

    priority_queue<int> pq;

    pq.push(2);
    pq.pop();    // pops the largest .. does'nt return anything.
    pq.top();    // returns the largest in O(1) time.
    pq.empty();
    pq.size();

    // for min heap .. use comparator.



    deque<int> dq;

    dq.push_back(2); dq.push_front(3);
    dq.pop_back(); dq.pop_front();
    dq.front(); dq.back();
    dq.begin(); dq.end();dq.rbegin();dq.rend();
    dq.size();
    dq.clear();
    dq.empty();
    dq.at(1);      // diff from list.


    list<int> lt;
    lt.push_back(2); lt.push_front(3); 
    lt.pop_back(); lt.pop_front();
    lt.front(); lt.back();
    lt.begin(); lt.end();lt.rbegin();lt.rend();
    lt.size();
    lt.clear();
    lt.empty();
    lt.remove(2);    // in O(1) time  // diff from dequeue.
    

    






    


    return 0;
}


