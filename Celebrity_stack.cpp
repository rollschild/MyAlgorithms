#include <iostream>
#include <stack>

using namespace std;

int MATRIX[4][4] = {{0, 0, 1, 0}, 
                  {0, 0, 1, 0}, 
                  {0, 0, 0, 0}, 
                  {0, 0, 1, 0}};

bool whoKnows(int M, int N) {
    return (MATRIX[M][N]);
}

int findCelebrity(int num) {
    stack<int> crowd;
    for(int i = 0; i < num; ++i) {
        crowd.push(i);
    }

    int p1 = crowd.top();
    crowd.pop();
    int p2 = crowd.top();
    crowd.pop();
    
    while(crowd.size() > 1) {
        if(whoKnows(p1, p2)) {
            // p1 knows p2
            p1 = crowd.top();
            crowd.pop();
        }
        else {
            p2 = crowd.top();
            crowd.pop();
        }
    }

    int vip = crowd.top();
    if(whoKnows(vip, p1)) {
        vip = p1;
    }
    if(whoKnows(vip, p2)) {
        vip = p2;
    }

    for(int i = 0; i < num; ++i) {
        if(i != vip && (whoKnows(vip, i) || !whoKnows(i, vip))) return -1;
    }
    return vip;
}

int main() {
    int n = 4;
    int id = findCelebrity(n);
    id == -1 ? cout << "NO VIP! " : 
    cout << "Celebrity is " << findCelebrity(n) << endl;
    return 0;
}

