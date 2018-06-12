#include <iostream>
#include <queue>

using namespace std;
vector<int> vec;
void bfs(int num, int ele) {
    queue<int> q;
    q.push(ele);
    while(!q.empty()) {
        ele = q.front();
        q.pop();
        if(ele <= num) {
            cout << ele << " ";
            vec.push_back(ele);
            int last = ele%10;
            if(last == 0) {
                q.push(ele*10 + last+1);
            }
            else if(last == 9) {
                q.push(ele*10 + last-1);
            }
            else {
                q.push(ele*10 + last+1);
                q.push(ele*10 + last-1);
            }
        }
    }
}

int main() {
    int x = 20;
    // int x = 105;
    // int x = 40;
    cout << 0 << " ";
    for(int i = 1; i <=9 && i <= x; ++i) {
        bfs(x, i);
    }
    cout << endl;
    cout << vec.size() + 1 << " elements in total." << endl;
    return 0;
}
