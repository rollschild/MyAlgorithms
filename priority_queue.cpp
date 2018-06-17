#include <iostream>
#include <functional>
#include <queue>
#include <vector>
// priority_queue's first element is always the greatest
using namespace std;

template<typename T> void print_queue(T& q) {
    while(!q.empty()) {
        cout << q.top() << " ";
        q.pop();
    }
    cout << endl;
}

int main() {
    priority_queue<int> pq;
    for(int n : {1, 8, 5, 6, 3, 4, 0, 9, 7, 2}) {
        pq.push(n);
    }

    print_queue(pq);
    /*
     * 9 8 7 6 5 4 3 2 1 0
     */

    priority_queue<int, vector<int>, greater<int> > pqq;

    for(int n : {1, 8, 5, 6, 3, 4, 0, 9, 7, 2}) {
        pqq.push(n);
    }

    print_queue(pqq);
    /*
     * 0 1 2 3 4 5 6 7 8 9
     */

    auto cmp = [](int lhs, int rhs) {return (lhs ^ 1) < (rhs ^ 1);}; // what's this?
    priority_queue<int, vector<int>, decltype(cmp)> pqqq(cmp);

    for(int n : {1, 8, 5, 6, 3, 4, 0, 9, 7, 2}) {
        pqqq.push(n);
    }
    
    print_queue(pqqq);
    return 0;
}
